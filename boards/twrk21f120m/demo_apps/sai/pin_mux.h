/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
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
 * o Neither the name of the copyright holder nor the names of its
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

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/* PORTD8 (coord A10), J14[A43]/U2[3]/UART5_RX */
#define BOARD_INITPINS_DEBUG_UART_RX_PERIPHERAL                            UART5   /*!< Device name: UART5 */
#define BOARD_INITPINS_DEBUG_UART_RX_SIGNAL                                   RX   /*!< UART5 signal: RX */
#define BOARD_INITPINS_DEBUG_UART_RX_PIN_NAME                           UART5_RX   /*!< Pin name */
#define BOARD_INITPINS_DEBUG_UART_RX_LABEL             "J14[A43]/U2[3]/UART5_RX"   /*!< Label */
#define BOARD_INITPINS_DEBUG_UART_RX_NAME                        "DEBUG_UART_RX"   /*!< Identifier name */

/* PORTD9 (coord A9), J14[A44]/UART5_TX */
#define BOARD_INITPINS_DEBUG_UART_TX_PERIPHERAL                            UART5   /*!< Device name: UART5 */
#define BOARD_INITPINS_DEBUG_UART_TX_SIGNAL                                   TX   /*!< UART5 signal: TX */
#define BOARD_INITPINS_DEBUG_UART_TX_PIN_NAME                           UART5_TX   /*!< Pin name */
#define BOARD_INITPINS_DEBUG_UART_TX_LABEL                   "J14[A44]/UART5_TX"   /*!< Label */
#define BOARD_INITPINS_DEBUG_UART_TX_NAME                        "DEBUG_UART_TX"   /*!< Identifier name */

/* PORTC8 (coord A7), J14[A21]/J14[A73]/U205[2]/J23[1]/K21_USB_FLGA */
#define BOARD_INITPINS_USB_FLAG_PERIPHERAL                                  I2S0   /*!< Device name: I2S0 */
#define BOARD_INITPINS_USB_FLAG_SIGNAL                                      MCLK   /*!< I2S0 signal: MCLK */
#define BOARD_INITPINS_USB_FLAG_PIN_NAME                               I2S0_MCLK   /*!< Pin name */
#define BOARD_INITPINS_USB_FLAG_LABEL "J14[A21]/J14[A73]/U205[2]/J23[1]/K21_USB_FLGA" /*!< Label */
#define BOARD_INITPINS_USB_FLAG_NAME                                  "USB_FLAG"   /*!< Identifier name */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

/* PORTC11 (coord C5), J3[4]/J14[A8]/J14[A60]/J14[B51]/J14[B71]/U7[6]/I2C1_SDA */
#define BOARD_I2C_CONFIGUREPINS_ACCL_SDA_PERIPHERAL                         I2C1   /*!< Device name: I2C1 */
#define BOARD_I2C_CONFIGUREPINS_ACCL_SDA_SIGNAL                              SDA   /*!< I2C1 signal: SDA */
#define BOARD_I2C_CONFIGUREPINS_ACCL_SDA_PIN_NAME                       I2C1_SDA   /*!< Pin name */
#define BOARD_I2C_CONFIGUREPINS_ACCL_SDA_LABEL "J3[4]/J14[A8]/J14[A60]/J14[B51]/J14[B71]/U7[6]/I2C1_SDA" /*!< Label */
#define BOARD_I2C_CONFIGUREPINS_ACCL_SDA_NAME                         "ACCL_SDA"   /*!< Identifier name */

/*!
 *
 */
void BOARD_I2C_ConfigurePins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
