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
 *
 */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
PinsProfile:
- !!product 'Pins v1.0'
- !!processor 'MK22FN512xxx12'
- !!package 'MK22FN512VLH12'
- !!mcu_data 'ksdk2_0'
- !!processor_version '1.0.0'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

#define PIN0_IDX 0u                    /*!< Pin number for pin 0 in a port */
#define PIN1_IDX 1u                    /*!< Pin number for pin 1 in a port */
#define PIN2_IDX 2u                    /*!< Pin number for pin 2 in a port */
#define PIN5_IDX 5u                    /*!< Pin number for pin 5 in a port */
#define SOPT5_UART1TXSRC_UART_TX 0x00u /*!< UART 1 transmit data source select: UART1_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitPins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '23', peripheral: GPIOA, signal: 'GPIO, 1', pin_signal: PTA1/UART0_RX/FTM0_CH6/JTAG_TDI/EZP_DI}
  - {pin_num: '24', peripheral: GPIOA, signal: 'GPIO, 2', pin_signal: PTA2/UART0_TX/FTM0_CH7/JTAG_TDO/TRACE_SWO/EZP_DO}
  - {pin_num: '62', peripheral: GPIOD, signal: 'GPIO, 5', pin_signal:
ADC0_SE6b/PTD5/SPI0_PCS2/UART0_CTS_b/FTM0_CH5/FBa_AD1/EWM_OUT_b/SPI1_SCK}
  - {pin_num: '1', peripheral: UART1, signal: TX, pin_signal:
ADC1_SE4a/PTE0/CLKOUT32K/SPI1_PCS1/UART1_TX/I2C1_SDA/RTC_CLKOUT}
  - {pin_num: '2', peripheral: UART1, signal: RX, pin_signal:
ADC1_SE5a/PTE1/LLWU_P0/SPI1_SOUT/UART1_RX/I2C1_SCL/SPI1_SIN}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void)
{
    CLOCK_EnableClock(kCLOCK_PortA); /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD); /* Port D Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE); /* Port E Clock Gate Control: Clock enabled */

    PORT_SetPinMux(PORTA, PIN1_IDX, kPORT_MuxAsGpio); /* PORTA1 (pin 23) is configured as PTA1 */
    PORT_SetPinMux(PORTA, PIN2_IDX, kPORT_MuxAsGpio); /* PORTA2 (pin 24) is configured as PTA2 */
    PORT_SetPinMux(PORTD, PIN5_IDX, kPORT_MuxAsGpio); /* PORTD5 (pin 62) is configured as PTD5 */
    PORT_SetPinMux(PORTE, PIN0_IDX, kPORT_MuxAlt3);   /* PORTE0 (pin 1) is configured as UART1_TX */
    PORT_SetPinMux(PORTE, PIN1_IDX, kPORT_MuxAlt3);   /* PORTE1 (pin 2) is configured as UART1_RX */
    SIM->SOPT5 =
        ((SIM->SOPT5 & (~(SIM_SOPT5_UART1TXSRC_MASK)))    /* Mask bits to zero which are setting */
         | SIM_SOPT5_UART1TXSRC(SOPT5_UART1TXSRC_UART_TX) /* UART 1 transmit data source select: UART1_TX pin */
         );
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
