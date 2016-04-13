/*
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* o Redistributions of source code must retain the above copyright notice, this list
*   of conditions and the following disclaimer.
*
* o Redistributions in binary form must reproduce the above copyright notice, this
*   list of conditions and the following disclaimer in the documentation and/or
*   other materials provided with the distribution.
*
* o Neither the name of Freescale Semiconductor, Inc. nor the names of its
*   contributors may be used to endorse or promote products derived from this
*   software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "fsl_debug_console.h"
#include "fsl_spi.h"
#include "fsl_flexio_spi_dma.h"
#include "fsl_dma_manager.h"
#include "board.h"

#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_FLEXIO_BASE FLEXIO
#define FLEXIO_SPI_MOSI_PIN 6U
#define FLEXIO_SPI_MISO_PIN 7U
#define FLEXIO_SPI_SCK_PIN 5U
#define FLEXIO_SPI_PCS0_PIN 4U
#define FLEXIO_CLOCK_FREQUENCY 48000000U
#define FLEXIO_DMA_REQUEST_BASE kDmaRequestMux0FlexIOChannel0

#define BOARD_SPI_SLAVE_BASE SPI0
#define SLAVE_SPI_IRQ SPI0_IRQn
#define MASTER_SPI_IRQ UART2_FLEXIO_IRQn
#define TRANSFER_SIZE 256U        /*! Transfer dataSize */
#define TRANSFER_BAUDRATE 500000U /*! Transfer baudrate - 500k */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* SPI user callback */
void FLEXIO_SPI_MasterUserCallback(FLEXIO_SPI_Type *base,
                                   flexio_spi_master_dma_handle_t *handle,
                                   status_t status,
                                   void *userData);
void SPI_SlaveUserCallback(SPI_Type *base, spi_slave_handle_t *handle, status_t status, void *userData);

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint8_t masterTxData[TRANSFER_SIZE] = {0U};
uint8_t slaveRxData[TRANSFER_SIZE] = {0U};

FLEXIO_SPI_Type spiDev;
flexio_spi_master_dma_handle_t g_m_handle;
spi_slave_handle_t g_s_handle;

dma_handle_t txHandle;
dma_handle_t rxHandle;

volatile bool isTransferCompleted = false;

/*******************************************************************************
 * Code
 ******************************************************************************/

void FLEXIO_SPI_MasterUserCallback(FLEXIO_SPI_Type *base,
                                   flexio_spi_master_dma_handle_t *handle,
                                   status_t status,
                                   void *userData)
{
    if (status == kStatus_Success)
    {
        __NOP();
    }
}

void SPI_SlaveUserCallback(SPI_Type *base, spi_slave_handle_t *handle, status_t status, void *userData)
{
    if (status == kStatus_Success)
    {
        __NOP();
    }

    isTransferCompleted = true;

    PRINTF("This is SPI slave call back.\r\n");
}

int main(void)
{
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    CLOCK_SetFlexio0Clock(1U);

    PRINTF("FLEXIO Master dma - SPI Slave interrupt example start.\r\n");
    PRINTF("This example use one flexio spi as master and one spi instance as slave on one board.\r\n");
    PRINTF("Master uses dma and slave uses interrupt way.\r\n");
    PRINTF("Please make sure you make the correct line connection. Basically, the connection is:\r\n");
    PRINTF("FLEXIO_SPI_master -- SPI_slave \r\n");
    PRINTF("   SCK      --    SCK  \r\n");
    PRINTF("   PCS0     --    PCS0 \r\n");
    PRINTF("   MOSI     --    MOSI \r\n");
    PRINTF("   MISO     --    MISO \r\n");

    uint32_t errorCount;
    uint32_t i;
    flexio_spi_master_config_t masterConfig;
    spi_slave_config_t slaveConfig;
    flexio_spi_transfer_t masterXfer;
    spi_transfer_t slaveXfer;
    dma_request_source_t dma_request_source_tx;
    dma_request_source_t dma_request_source_rx;

    /* Master config */
    /*
     * masterConfig.enableMaster = true;
     * masterConfig.enableInDoze = false;
     * masterConfig.enableInDebug = true;
     * masterConfig.enableFastAccess = false;
     * masterConfig.baudRate_Bps = 500000U;
     * masterConfig.phase = kFLEXIO_SPI_ClockPhaseFirstEdge;
     * masterConfig.dataMode = kFLEXIO_SPI_8BitMode;
     */
    FLEXIO_SPI_MasterGetDefaultConfig(&masterConfig);
    masterConfig.baudRate_Bps = 500000U;

    spiDev.flexioBase = BOARD_FLEXIO_BASE;
    spiDev.SDOPinIndex = FLEXIO_SPI_MOSI_PIN;
    spiDev.SDIPinIndex = FLEXIO_SPI_MISO_PIN;
    spiDev.SCKPinIndex = FLEXIO_SPI_SCK_PIN;
    spiDev.CSnPinIndex = FLEXIO_SPI_PCS0_PIN;
    spiDev.shifterIndex[0] = 0U;
    spiDev.shifterIndex[1] = 1U;
    spiDev.timerIndex[0] = 0U;
    spiDev.timerIndex[1] = 1U;

    FLEXIO_SPI_MasterInit(&spiDev, &masterConfig, FLEXIO_CLOCK_FREQUENCY);

    /* Slave config */
    /*
     * slaveConfig.polarity = kSPI_ClockPolarityActiveHigh;
     * slaveConfig.phase = kSPI_ClockPhaseFirstEdge;
     * slaveConfig.direction = kSPI_MsbFirst;
     * slaveConfig.enableStopInWaitMode = false;
     * slaveConfig.dataMode = kSPI_8BitMode;
     * slaveConfig.txWatermark = kSPI_TxFifoOneHalfEmpty;
     * slaveConfig.rxWatermark = kSPI_RxFifoOneHalfFull;
     */
    SPI_SlaveGetDefaultConfig(&slaveConfig);
    SPI_SlaveInit(BOARD_SPI_SLAVE_BASE, &slaveConfig);

    /* Set spi slave interrupt priority higher. */
    NVIC_SetPriority(MASTER_SPI_IRQ, 1U);
    NVIC_SetPriority(SLAVE_SPI_IRQ, 0U);

    /* Set up the transfer data */
    for (i = 0U; i < TRANSFER_SIZE; i++)
    {
        masterTxData[i] = i % 256U;
        slaveRxData[i] = 0U;
    }

    isTransferCompleted = false;
    /* Set up slave first */
    SPI_SlaveTransferCreateHandle(BOARD_SPI_SLAVE_BASE, &g_s_handle, SPI_SlaveUserCallback, NULL);

    /*Set slave transfer ready to receive/send data*/
    slaveXfer.txData = NULL;
    slaveXfer.rxData = slaveRxData;
    slaveXfer.dataSize = TRANSFER_SIZE;

    SPI_SlaveTransferNonBlocking(BOARD_SPI_SLAVE_BASE, &g_s_handle, &slaveXfer);

    /*Init DMA for example.*/
    DMAMGR_Init();

    dma_request_source_tx = (dma_request_source_t)(FLEXIO_DMA_REQUEST_BASE + spiDev.shifterIndex[0]);
    dma_request_source_rx = (dma_request_source_t)(FLEXIO_DMA_REQUEST_BASE + spiDev.shifterIndex[1]);

    /* Request DMA channels for TX & RX. */
    if (dma_request_source_tx < 0x200)
    {
        DMAMGR_RequestChannel((dma_request_source_t)dma_request_source_tx, 0, &txHandle);
        DMAMGR_RequestChannel((dma_request_source_t)dma_request_source_rx, 1, &rxHandle);
    }
    else
    {
        DMAMGR_RequestChannel((dma_request_source_t)dma_request_source_tx, 16, &txHandle);
        DMAMGR_RequestChannel((dma_request_source_t)dma_request_source_rx, 17, &rxHandle);
    }

    /* Set up master transfer */
    FLEXIO_SPI_MasterTransferCreateHandleDMA(&spiDev, &g_m_handle, FLEXIO_SPI_MasterUserCallback, NULL, &txHandle,
                                             &rxHandle);

    /*Start master transfer*/
    masterXfer.txData = masterTxData;
    masterXfer.rxData = NULL;
    masterXfer.dataSize = TRANSFER_SIZE;
    masterXfer.flags = kFLEXIO_SPI_8bitMsb;

    FLEXIO_SPI_MasterTransferDMA(&spiDev, &g_m_handle, &masterXfer);

    /* Wait slave received all data. */
    while (!isTransferCompleted)
    {
    }

    errorCount = 0U;
    for (i = 0U; i < TRANSFER_SIZE; i++)
    {
        if (masterTxData[i] != slaveRxData[i])
        {
            errorCount++;
        }
    }
    if (errorCount == 0U)
    {
        PRINTF("FLEXIO SPI master <-> SPI slave transfer all data matched!\r\n");
    }
    else
    {
        PRINTF("Error occured in FLEXIO SPI master <-> SPI slave transfer!\r\n");
    }

    FLEXIO_SPI_MasterDeinit(&spiDev);
    SPI_Deinit(BOARD_SPI_SLAVE_BASE);

    while (1)
    {
    }
}
