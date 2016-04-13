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
- !!processor 'MKL43Z256xxx4'
- !!package 'MKL43Z256VLH4'
- !!mcu_data 'ksdk2_0'
- !!processor_version '1.0.0'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port */
#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */
#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port */
#define PIN4_IDX                         4u   /*!< Pin number for pin 4 in a port */
#define PIN6_IDX                         6u   /*!< Pin number for pin 6 in a port */
#define PIN7_IDX                         7u   /*!< Pin number for pin 7 in a port */
#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port */
#define PIN19_IDX                       19u   /*!< Pin number for pin 19 in a port */
#define PIN20_IDX                       20u   /*!< Pin number for pin 20 in a port */
#define PIN21_IDX                       21u   /*!< Pin number for pin 21 in a port */
#define SOPT5_LPUART0RXSRC_LPUART_RX  0x00u   /*!< LPUART0 Receive Data Source Select: LPUART_RX pin */
#define SOPT5_LPUART0TXSRC_LPUART_TX  0x00u   /*!< LPUART0 Transmit Data Source Select: LPUART0_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitPins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '23', peripheral: LPUART0, signal: RX, pin_signal: PTA1/LPUART0_RX/TPM2_CH0}
  - {pin_num: '24', peripheral: LPUART0, signal: TX, pin_signal: PTA2/LPUART0_TX/TPM2_CH1}
  - {pin_num: '9', peripheral: LCD, signal: 'P, 59', pin_signal: LCD_P59/ADC0_DP0/ADC0_SE0/PTE20/TPM1_CH0/LPUART0_TX/FXIO0_D4}
  - {pin_num: '10', peripheral: LCD, signal: 'P, 60', pin_signal: LCD_P60/ADC0_DM0/ADC0_SE4a/PTE21/TPM1_CH1/LPUART0_RX/FXIO0_D5}
  - {pin_num: '41', peripheral: LCD, signal: 'P, 14', pin_signal: LCD_P14/PTB18/TPM2_CH0/I2S0_TX_BCLK}
  - {pin_num: '42', peripheral: LCD, signal: 'P, 15', pin_signal: LCD_P15/PTB19/TPM2_CH1/I2S0_TX_FS}
  - {pin_num: '43', peripheral: LCD, signal: 'P, 20', pin_signal: LCD_P20/ADC0_SE14/PTC0/EXTRG_IN/USB_SOF_OUT/CMP0_OUT/I2S0_TXD0}
  - {pin_num: '53', peripheral: LCD, signal: 'P, 24', pin_signal: LCD_P24/PTC4/LLWU_P8/SPI0_SS/LPUART1_TX/TPM0_CH3/I2S0_MCLK}
  - {pin_num: '55', peripheral: LCD, signal: 'P, 26', pin_signal: LCD_P26/CMP0_IN0/PTC6/LLWU_P10/SPI0_MOSI/EXTRG_IN/I2S0_RX_BCLK/SPI0_MISO/I2S0_MCLK}
  - {pin_num: '56', peripheral: LCD, signal: 'P, 27', pin_signal: LCD_P27/CMP0_IN1/PTC7/SPI0_MISO/USB_SOF_OUT/I2S0_RX_FS/SPI0_MOSI}
  - {pin_num: '57', peripheral: LCD, signal: 'P, 40', pin_signal: LCD_P40/PTD0/SPI0_SS/TPM0_CH0/FXIO0_D0}
  - {pin_num: '59', peripheral: LCD, signal: 'P, 42', pin_signal: LCD_P42/PTD2/SPI0_MOSI/UART2_RX/TPM0_CH2/SPI0_MISO/FXIO0_D2}
  - {pin_num: '60', peripheral: LCD, signal: 'P, 43', pin_signal: LCD_P43/PTD3/SPI0_MISO/UART2_TX/TPM0_CH3/SPI0_MOSI/FXIO0_D3}
  - {pin_num: '61', peripheral: LCD, signal: 'P, 44', pin_signal: LCD_P44/PTD4/LLWU_P14/SPI1_SS/UART2_RX/TPM0_CH4/FXIO0_D4}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortD);                           /* Port D Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortE);                           /* Port E Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN1_IDX, kPORT_MuxAlt2);            /* PORTA1 (pin 23) is configured as LPUART0_RX */
  PORT_SetPinMux(PORTA, PIN2_IDX, kPORT_MuxAlt2);            /* PORTA2 (pin 24) is configured as LPUART0_TX */
  PORT_SetPinMux(PORTB, PIN18_IDX, kPORT_PinDisabledOrAnalog); /* PORTB18 (pin 41) is configured as LCD_P14 */
  PORT_SetPinMux(PORTB, PIN19_IDX, kPORT_PinDisabledOrAnalog); /* PORTB19 (pin 42) is configured as LCD_P15 */
  PORT_SetPinMux(PORTC, PIN0_IDX, kPORT_PinDisabledOrAnalog); /* PORTC0 (pin 43) is configured as LCD_P20 */
  PORT_SetPinMux(PORTC, PIN4_IDX, kPORT_PinDisabledOrAnalog); /* PORTC4 (pin 53) is configured as LCD_P24 */
  PORT_SetPinMux(PORTC, PIN6_IDX, kPORT_PinDisabledOrAnalog); /* PORTC6 (pin 55) is configured as LCD_P26 */
  PORT_SetPinMux(PORTC, PIN7_IDX, kPORT_PinDisabledOrAnalog); /* PORTC7 (pin 56) is configured as LCD_P27 */
  PORT_SetPinMux(PORTD, PIN0_IDX, kPORT_PinDisabledOrAnalog); /* PORTD0 (pin 57) is configured as LCD_P40 */
  PORT_SetPinMux(PORTD, PIN2_IDX, kPORT_PinDisabledOrAnalog); /* PORTD2 (pin 59) is configured as LCD_P42 */
  PORT_SetPinMux(PORTD, PIN3_IDX, kPORT_PinDisabledOrAnalog); /* PORTD3 (pin 60) is configured as LCD_P43 */
  PORT_SetPinMux(PORTD, PIN4_IDX, kPORT_PinDisabledOrAnalog); /* PORTD4 (pin 61) is configured as LCD_P44 */
  PORT_SetPinMux(PORTE, PIN20_IDX, kPORT_PinDisabledOrAnalog); /* PORTE20 (pin 9) is configured as LCD_P59 */
  PORT_SetPinMux(PORTE, PIN21_IDX, kPORT_PinDisabledOrAnalog); /* PORTE21 (pin 10) is configured as LCD_P60 */
  SIM->SOPT5 = ((SIM->SOPT5 &
    (~(SIM_SOPT5_LPUART0TXSRC_MASK | SIM_SOPT5_LPUART0RXSRC_MASK))) /* Mask bits to zero which are setting */
      | SIM_SOPT5_LPUART0TXSRC(SOPT5_LPUART0TXSRC_LPUART_TX) /* LPUART0 Transmit Data Source Select: LPUART0_TX pin */
      | SIM_SOPT5_LPUART0RXSRC(SOPT5_LPUART0RXSRC_LPUART_RX) /* LPUART0 Receive Data Source Select: LPUART_RX pin */
    );
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
