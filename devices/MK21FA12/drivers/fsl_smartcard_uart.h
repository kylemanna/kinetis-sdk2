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

#ifndef _FSL_SMARTCARD_UART_H_
#define _FSL_SMARTCARD_UART_H_

#include "fsl_smartcard.h"

/*!
 * @addtogroup smartcard_uart_driver
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief EMV RX NACK interrupt generation threshold */
#define SMARTCARD_EMV_RX_NACK_THRESHOLD (5u)

/*! @brief EMV TX NACK interrupt generation threshold */
#define SMARTCARD_EMV_TX_NACK_THRESHOLD (3u)

/*! @brief EMV TX & RX GUART TIME default value */
#define SMARTCARD_EMV_RX_TO_TX_GUARD_TIME_T0 (0x0u)

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Fill in smartcard_card_params structure with default values according EMV 4.3 specification.
 *
 * @param cardParams The configuration structure of type smartcard_interface_config_t.
 * Function fill in members:
 *        Fi = 372;
 *        Di = 1;
 *        currentD = 1;
 *        WI = 0x0A;
 *        GTN = 0x00;
 * with default values.
 */
void SMARTCARD_UART_GetDefaultConfig(smartcard_card_params_t *cardParams);

/*!
 * @brief Initializes an UART peripheral for smart card/ISO-7816 operation.
 *
 * This function Un-gate UART clock, initializes the module to EMV default settings,
 * configures the IRQ, enables the module-level interrupt to the core and initialize driver context.
 *
 * @param base The UART peripheral base address.
 * @param context A pointer to a smart card driver context structure.
 * @param srcClock_Hz Smart card clock generation module source clock.
 *
 * @return An error code or kStatus_SMARTCARD_Success.
 */
status_t SMARTCARD_UART_Init(UART_Type *base, smartcard_context_t *context, uint32_t srcClock_Hz);

/*!
 * @brief This function disables the UART interrupts, disables the transmitter and receiver, and
 * flushes the FIFOs (for modules that support FIFOs) and gates UART clock in SIM.
 *
 * @param base The UART peripheral base address.
 */
void SMARTCARD_UART_Deinit(UART_Type *base);

/*!
 * @brief Returns whether the previous UART transfer has finished.
 *
 * When performing an async transfer, call this function to ascertain the context of the
 * current transfer: in progress (or busy) or complete (success). If the
 * transfer is still in progress, the user can obtain the number of words that have not been transferred,
 * by reading xSize of smart card context structure.
 *
 * @param base The UART peripheral base address.
 * @param context A pointer to a smart card driver context structure.
 *
 * @return The number of bytes not transferred.
 */
int32_t SMARTCARD_UART_GetTransferRemainingBytes(UART_Type *base, smartcard_context_t *context);

/*!
 * @brief Terminates an asynchronous UART transfer early.
 *
 * During an async UART transfer, the user can terminate the transfer early
 * if the transfer is still in progress.
 *
 * @param base The UART peripheral base address.
 * @param context A pointer to a smart card driver context structure.
 *
 * @retval kStatus_SMARTCARD_Success The transfer abort was successful.
 * @retval kStatus_SMARTCARD_NoTransmitInProgress No transmission is currently in progress.
 */
status_t SMARTCARD_UART_AbortTransfer(UART_Type *base, smartcard_context_t *context);

/*!
 * @brief Transfer data using interrupts.
 *
 * A non-blocking (also known as asynchronous) function means that the function returns
 * immediately after initiating the transfer function. The application has to get the
 * transfer status to see when the transfer is complete. In other words, after calling non-blocking
 * (asynchronous) transfer function, the application must get the transfer status to check if transmit
 * is completed or not.
 *
 * @param base The UART peripheral base address.
 * @param context A pointer to a smart card driver context structure.
 * @param xfer A pointer to smart card transfer structure where are linked buffers and sizes.
 *
 * @return An error code or kStatus_SMARTCARD_Success.
 */
status_t SMARTCARD_UART_TransferNonBlocking(UART_Type *base, smartcard_context_t *context, smartcard_xfer_t *xfer);

/*!
 * @brief Controls UART module as per different user request.
 *
 * @param base The UART peripheral base address.
 * @param context A pointer to a smart card driver context structure.
 * @param control Smart card command type.
 * @param param Integer value of specific to control command.
 *
 * return An kStatus_SMARTCARD_OtherError in case of error
 * return kStatus_SMARTCARD_Success in success
 */
status_t SMARTCARD_UART_Control(UART_Type *base,
                                smartcard_context_t *context,
                                smartcard_control_t control,
                                uint32_t param);

/*!
 * @brief Interrupt handler for UART.
 *
 * This handler uses the buffers stored in the smartcard_context_t structures to transfer
 * data. Smart card driver requires this function to call when UART interrupt occurs.
 *
 * @param base The UART peripheral base address.
 * @param context A pointer to a smart card driver context structure.
 */
void SMARTCARD_UART_IRQHandler(UART_Type *base, smartcard_context_t *context);

/*!
 * @brief Error Interrupt handler for UART.
 *
 * This function handles error conditions during transfer.
 *
 * @param base The UART peripheral base address.
 * @param context A pointer to a smart card driver context structure.
 */
void SMARTCARD_UART_ErrIRQHandler(UART_Type *base, smartcard_context_t *context);

/*!
 * @brief Handles initial TS character timer time-out event.
 *
 * @param base The UART peripheral base address.
 * @param context A pointer to a smart card driver context structure.
 */
void SMARTCARD_UART_TSExpiryCallback(UART_Type *base, smartcard_context_t *context);
/*@}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/
#endif /* _FSL_SMARTCARD_UART_H_*/
