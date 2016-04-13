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

#define PCR_PE_ENABLED 0x01u /*!< Pull Enable: Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input. */
#define PCR_PS_UP 0x01u /*!< Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
#define PIN0_IDX 0u /*!< Pin number for pin 0 in a port */
#define PIN1_IDX 1u /*!< Pin number for pin 1 in a port */
#define PIN2_IDX 2u /*!< Pin number for pin 2 in a port */
#define PIN4_IDX 4u /*!< Pin number for pin 4 in a port */
#define PIN5_IDX 5u /*!< Pin number for pin 5 in a port */
#define PIN6_IDX 6u /*!< Pin number for pin 6 in a port */
#define PIN7_IDX 7u /*!< Pin number for pin 7 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitPins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '1', peripheral: SIM, signal: UART1_MOD_OUT, pin_signal:
ADC1_SE4a/PTE0/CLKOUT32K/SPI1_PCS1/UART1_TX/I2C1_SDA/RTC_CLKOUT}
  - {pin_num: '2', peripheral: UART1, signal: RX, pin_signal:
ADC1_SE5a/PTE1/LLWU_P0/SPI1_SOUT/UART1_RX/I2C1_SCL/SPI1_SIN}
  - {pin_num: '49', peripheral: SPI0, signal: PCS0_SS, pin_signal:
PTC4/LLWU_P8/SPI0_PCS0/UART1_TX/FTM0_CH3/FBa_AD11/CMP1_OUT/LPUART0_TX}
  - {pin_num: '50', peripheral: SPI0, signal: SCK, pin_signal:
PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/I2S0_RXD0/FBa_AD10/CMP0_OUT/FTM0_CH2}
  - {pin_num: '51', peripheral: SPI0, signal: SOUT, pin_signal:
CMP0_IN0/PTC6/LLWU_P10/SPI0_SOUT/PDB0_EXTRG/I2S0_RX_BCLK/FBa_AD9/I2S0_MCLK}
  - {pin_num: '52', peripheral: SPI0, signal: SIN, pin_signal: CMP0_IN1/PTC7/SPI0_SIN/USB_SOF_OUT/I2S0_RX_FS/FBa_AD8}
  - {pin_num: '71', peripheral: GPIOC, signal: 'GPIO, 1', pin_signal:
ADC0_SE15/PTC1/LLWU_P6/SPI0_PCS3/UART1_RTS_b/FTM0_CH0/FBa_AD13/I2S0_TXD0/LPUART0_RTS_b, pull_select: up, pull_enable:
enable}
  - {pin_num: '55', peripheral: GPIOB, signal: 'GPIO, 2', pin_signal: ADC0_SE12/PTB2/I2C0_SCL/UART0_RTS_b/FTM0_FLT3}
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
    CLOCK_EnableClock(kCLOCK_PortB); /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC); /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE); /* Port E Clock Gate Control: Clock enabled */

    PORT_SetPinMux(PORTC, PIN1_IDX, kPORT_MuxAsGpio); /* PORTC1 (pin 71) is configured as PTC1 */
    PORTC->PCR[1] =
        ((PORTC->PCR[1] &
          (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK))) /* Mask bits to zero which are setting */
         | PORT_PCR_PS(PCR_PS_UP) /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                                     corresponding PE field is set. */
         | PORT_PCR_PE(PCR_PE_ENABLED) /* Pull Enable: Internal pullup or pulldown resistor is enabled on the
                                          corresponding pin, if the pin is configured as a digital input. */
         );
    PORT_SetPinMux(PORTB, PIN2_IDX, kPORT_MuxAsGpio); /* PORTB2 (pin 55) is configured as PTB2 */
    PORT_SetPinMux(PORTC, PIN4_IDX, kPORT_MuxAlt2);   /* PORTC4 (pin 49) is configured as SPI0_PCS0 */
    PORT_SetPinMux(PORTC, PIN5_IDX, kPORT_MuxAlt2);   /* PORTC5 (pin 50) is configured as SPI0_SCK */
    PORT_SetPinMux(PORTC, PIN6_IDX, kPORT_MuxAlt2);   /* PORTC6 (pin 51) is configured as SPI0_SOUT */
    PORT_SetPinMux(PORTC, PIN7_IDX, kPORT_MuxAlt2);   /* PORTC7 (pin 52) is configured as SPI0_SIN */
    PORT_SetPinMux(PORTE, PIN0_IDX, kPORT_MuxAlt3);   /* PORTE0 (pin 1) is configured as UART1_TX */
    PORT_SetPinMux(PORTE, PIN1_IDX, kPORT_MuxAlt3);   /* PORTE1 (pin 2) is configured as UART1_RX */
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
