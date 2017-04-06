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
#define BOARD_DEBUG_UART_RX_PERIPHERAL                                     UART5   /*!< Device name: UART5 */
#define BOARD_DEBUG_UART_RX_SIGNAL                                            RX   /*!< UART5 signal: RX */
#define BOARD_DEBUG_UART_RX_PIN_NAME                                    UART5_RX   /*!< Pin name */
#define BOARD_DEBUG_UART_RX_LABEL                      "J14[A43]/U2[3]/UART5_RX"   /*!< Label */
#define BOARD_DEBUG_UART_RX_NAME                                 "DEBUG_UART_RX"   /*!< Identifier name */

/* PORTD9 (coord A9), J14[A44]/UART5_TX */
#define BOARD_DEBUG_UART_TX_PERIPHERAL                                     UART5   /*!< Device name: UART5 */
#define BOARD_DEBUG_UART_TX_SIGNAL                                            TX   /*!< UART5 signal: TX */
#define BOARD_DEBUG_UART_TX_PIN_NAME                                    UART5_TX   /*!< Pin name */
#define BOARD_DEBUG_UART_TX_LABEL                            "J14[A44]/UART5_TX"   /*!< Label */
#define BOARD_DEBUG_UART_TX_NAME                                 "DEBUG_UART_TX"   /*!< Identifier name */

/* PORTA5 (coord K7), J14[B23] */
#define BOARD_USB_CLKIN_GPIO                                               GPIOA   /*!< GPIO device name: GPIOA */
#define BOARD_USB_CLKIN_PORT                                               PORTA   /*!< PORT device name: PORTA */
#define BOARD_USB_CLKIN_GPIO_PIN                                              5U   /*!< PORTA pin index: 5 */
#define BOARD_USB_CLKIN_PIN_NAME                                            PTA5   /*!< Pin name */
#define BOARD_USB_CLKIN_LABEL                                         "J14[B23]"   /*!< Label */
#define BOARD_USB_CLKIN_NAME                                         "USB_CLKIN"   /*!< Identifier name */

/* PORTD11 (coord C2), J14[A9]/UART5_CTS */
#define BOARD_SDHC0_CLKIN_GPIO                                             GPIOD   /*!< GPIO device name: GPIOD */
#define BOARD_SDHC0_CLKIN_PORT                                             PORTD   /*!< PORT device name: PORTD */
#define BOARD_SDHC0_CLKIN_GPIO_PIN                                           11U   /*!< PORTD pin index: 11 */
#define BOARD_SDHC0_CLKIN_PIN_NAME                                         PTD11   /*!< Pin name */
#define BOARD_SDHC0_CLKIN_LABEL                              "J14[A9]/UART5_CTS"   /*!< Label */
#define BOARD_SDHC0_CLKIN_NAME                                     "SDHC0_CLKIN"   /*!< Identifier name */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

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
