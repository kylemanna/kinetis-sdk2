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

/* PORTE1 (coord E3), J1[20]/P200[7]/SDCH0_D0/TRACE_D3 */
#define BOARD_SDHC0_D0_PERIPHERAL                                           SDHC   /*!< Device name: SDHC */
#define BOARD_SDHC0_D0_SIGNAL                                               DATA   /*!< SDHC signal: DATA */
#define BOARD_SDHC0_D0_CHANNEL                                                 0   /*!< SDHC DATA channel: 0 */
#define BOARD_SDHC0_D0_PIN_NAME                                         SDHC0_D0   /*!< Pin name */
#define BOARD_SDHC0_D0_LABEL                  "J1[20]/P200[7]/SDCH0_D0/TRACE_D3"   /*!< Label */
#define BOARD_SDHC0_D0_NAME                                           "SDHC0_D0"   /*!< Identifier name */

/* PORTE2 (coord E2), J1[18]/P200[5]/SDHC0_DCLK/TRACE_D2 */
#define BOARD_SDHC0_DCLK_PERIPHERAL                                         SDHC   /*!< Device name: SDHC */
#define BOARD_SDHC0_DCLK_SIGNAL                                             DCLK   /*!< SDHC signal: DCLK */
#define BOARD_SDHC0_DCLK_PIN_NAME                                     SDHC0_DCLK   /*!< Pin name */
#define BOARD_SDHC0_DCLK_LABEL              "J1[18]/P200[5]/SDHC0_DCLK/TRACE_D2"   /*!< Label */
#define BOARD_SDHC0_DCLK_NAME                                       "SDHC0_DCLK"   /*!< Identifier name */

/* PORTE3 (coord F4), J1[16]/P200[2]/SDCH0_CMD/TRACE_D1 */
#define BOARD_SDHC0_CMD_PERIPHERAL                                          SDHC   /*!< Device name: SDHC */
#define BOARD_SDHC0_CMD_SIGNAL                                               CMD   /*!< SDHC signal: CMD */
#define BOARD_SDHC0_CMD_PIN_NAME                                       SDHC0_CMD   /*!< Pin name */
#define BOARD_SDHC0_CMD_LABEL                "J1[16]/P200[2]/SDCH0_CMD/TRACE_D1"   /*!< Label */
#define BOARD_SDHC0_CMD_NAME                                         "SDHC0_CMD"   /*!< Identifier name */

/* PORTE4 (coord H7), J1[14]/P200[1]/SDCH0_D3/TRACE_D0 */
#define BOARD_SDHC0_D3_PERIPHERAL                                           SDHC   /*!< Device name: SDHC */
#define BOARD_SDHC0_D3_SIGNAL                                               DATA   /*!< SDHC signal: DATA */
#define BOARD_SDHC0_D3_CHANNEL                                                 3   /*!< SDHC DATA channel: 3 */
#define BOARD_SDHC0_D3_PIN_NAME                                         SDHC0_D3   /*!< Pin name */
#define BOARD_SDHC0_D3_LABEL                  "J1[14]/P200[1]/SDCH0_D3/TRACE_D0"   /*!< Label */
#define BOARD_SDHC0_D3_NAME                                           "SDHC0_D3"   /*!< Identifier name */

/* PORTE5 (coord G4), J14[B56]/J14[A10]/P200[9]/SDCH0_D2 */
#define BOARD_SDHC0_D2_PERIPHERAL                                           SDHC   /*!< Device name: SDHC */
#define BOARD_SDHC0_D2_SIGNAL                                               DATA   /*!< SDHC signal: DATA */
#define BOARD_SDHC0_D2_CHANNEL                                                 2   /*!< SDHC DATA channel: 2 */
#define BOARD_SDHC0_D2_PIN_NAME                                         SDHC0_D2   /*!< Pin name */
#define BOARD_SDHC0_D2_LABEL                "J14[B56]/J14[A10]/P200[9]/SDCH0_D2"   /*!< Label */
#define BOARD_SDHC0_D2_NAME                                           "SDHC0_D2"   /*!< Identifier name */

/* PORTC18 (coord B4), J20[11]/P200[10]/SD_CARD_DETECT */
#define BOARD_SD_CARD_CD_GPIO                                              GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_SD_CARD_CD_PORT                                              PORTC   /*!< PORT device name: PORTC */
#define BOARD_SD_CARD_CD_GPIO_PIN                                            18U   /*!< PORTC pin index: 18 */
#define BOARD_SD_CARD_CD_PIN_NAME                                          PTC18   /*!< Pin name */
#define BOARD_SD_CARD_CD_LABEL                 "J20[11]/P200[10]/SD_CARD_DETECT"   /*!< Label */
#define BOARD_SD_CARD_CD_NAME                                       "SD_CARD_CD"   /*!< Identifier name */

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
