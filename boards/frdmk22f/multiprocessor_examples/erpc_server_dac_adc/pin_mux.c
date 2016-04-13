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
- !!processor 'MK82FN256xxx15'
- !!package 'MK82FN256VLQ15'
- !!mcu_data 'ksdk2_0'
- !!processor_version '1.0.0'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

#define PIN0_IDX 0u /*!< Pin number for pin 0 in a port */
#define PIN1_IDX 1u /*!< Pin number for pin 1 in a port */
#define PIN2_IDX 2u /*!< Pin number for pin 2 in a port */
#define PIN5_IDX 5u /*!< Pin number for pin 5 in a port */

#define SOPT5_LPUART0TXSRC_LPUART_TX 0x00u /*!< UART 0 transmit data source select: UART0_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitPins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '113', peripheral: GPIOC, signal: 'GPIO, 8', pin_signal:
CMP0_IN2/PTC8/FTM3_CH4/I2S0_MCLK/FB_AD7/SDRAM_A15/FXIO0_D16, direction: OUTPUT}
  - {pin_num: '114', peripheral: GPIOC, signal: 'GPIO, 9', pin_signal:
CMP0_IN3/PTC9/FTM3_CH5/I2S0_RX_BCLK/FB_AD6/SDRAM_A14/FTM2_FLT0/FXIO0_D17, direction: OUTPUT}
  - {pin_num: '115', peripheral: GPIOC, signal: 'GPIO, 10', pin_signal:
PTC10/I2C1_SCL/FTM3_CH6/I2S0_RX_FS/FB_AD5/SDRAM_A13/FXIO0_D18, direction: OUTPUT}
  - {pin_num: '51', peripheral: I2C3, signal: SDA, pin_signal:
TSI0_CH2/PTA1/LPUART0_RX/FTM0_CH6/I2C3_SDA/FXIO0_D11/EMVSIM0_IO/JTAG_TDI}
  - {pin_num: '52', peripheral: I2C3, signal: SCL, pin_signal:
TSI0_CH3/PTA2/LPUART0_TX/FTM0_CH7/I2C3_SCL/FXIO0_D12/EMVSIM0_PD/JTAG_TDO/TRACE_SWO}
  - {pin_num: '40', peripheral: DAC0, signal: OUT, pin_signal: DAC0_OUT/CMP1_IN3/ADC0_SE23}
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
    CLOCK_EnableClock(kCLOCK_PortD); /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE); /* Port C Clock Gate Control: Clock enabled */

    PORT_SetPinMux(PORTA, PIN1_IDX, kPORT_MuxAsGpio); /* PORTC10 (pin 115) is configured as PTC10 */
    PORT_SetPinMux(PORTA, PIN2_IDX, kPORT_MuxAsGpio); /* PORTC8 (pin 113) is configured as PTC8 */
    PORT_SetPinMux(PORTD, PIN5_IDX, kPORT_MuxAsGpio); /* PORTC9 (pin 114) is configured as PTC9 */

    PORT_SetPinMux(PORTE, PIN0_IDX, kPORT_MuxAlt3); /* PORTE0 (pin 1) is configured as UART1_TX */
    PORT_SetPinMux(PORTE, PIN1_IDX, kPORT_MuxAlt3); /* PORTE1 (pin 2) is configured as UART1_RX */
}

/*!< Open Drain Enable: Open drain output is enabled on the corresponding pin, if the pin is configured as a digital
 * output. */
#define PCR_ODE_ENABLED 0x01u
/*!< Pull Enable: Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as
 * a digital input. */
#define PCR_PE_ENABLED 0x01u
/*!< Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
#define PCR_PS_UP 0x01u
#define PIN2_IDX 2u /*!< Pin number for pin 2 in a port */
#define PIN3_IDX 3u /*!< Pin number for pin 3 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_I2C_ConfigurePins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '37', peripheral: I2C0, signal: SCL, pin_signal: ADC0_SE12/PTB2/I2C0_SCL/UART0_RTS_b/FTM0_FLT3,
open_drain: enable, pull_select: up, pull_enable: enable}
  - {pin_num: '38', peripheral: I2C0, signal: SDA, pin_signal: ADC0_SE13/PTB3/I2C0_SDA/UART0_CTS_b/FTM0_FLT0,
open_drain: enable, pull_select: up, pull_enable: enable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_I2C_ConfigurePins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_I2C_ConfigurePins(void)
{
    CLOCK_EnableClock(kCLOCK_PortB); /* Port B Clock Gate Control: Clock enabled */

    PORT_SetPinMux(PORTB, PIN2_IDX, kPORT_MuxAlt2); /* PORTB2 (pin 37) is configured as I2C0_SCL */
    PORTB->PCR[2] =
        ((PORTB->PCR[2] & (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ODE_MASK |
                             PORT_PCR_ISF_MASK))) /* Mask bits to zero which are setting */
         | PORT_PCR_PS(PCR_PS_UP) /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                                     corresponding PE field is set. */
         | PORT_PCR_PE(PCR_PE_ENABLED)   /* Pull Enable: Internal pullup or pulldown resistor is enabled on the
                                            corresponding pin, if the pin is configured as a digital input. */
         | PORT_PCR_ODE(PCR_ODE_ENABLED) /* Open Drain Enable: Open drain output is enabled on the corresponding pin, if
                                            the pin is configured as a digital output. */
         );
    PORT_SetPinMux(PORTB, PIN3_IDX, kPORT_MuxAlt2); /* PORTB3 (pin 38) is configured as I2C0_SDA */
    PORTB->PCR[3] =
        ((PORTB->PCR[3] & (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ODE_MASK |
                             PORT_PCR_ISF_MASK))) /* Mask bits to zero which are setting */
         | PORT_PCR_PS(PCR_PS_UP) /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                                     corresponding PE field is set. */
         | PORT_PCR_PE(PCR_PE_ENABLED)   /* Pull Enable: Internal pullup or pulldown resistor is enabled on the
                                            corresponding pin, if the pin is configured as a digital input. */
         | PORT_PCR_ODE(PCR_ODE_ENABLED) /* Open Drain Enable: Open drain output is enabled on the corresponding pin, if
                                            the pin is configured as a digital output. */
         );
}

#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
UART0_InitPins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '23', peripheral: UART0, signal: RX, pin_signal: PTA1/UART0_RX/FTM0_CH6/JTAG_TDI/EZP_DI}
  - {pin_num: '24', peripheral: SIM, signal: UART0_MOD_OUT, pin_signal: PTA2/UART0_TX/FTM0_CH7/JTAG_TDO/TRACE_SWO/EZP_DO}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : UART0_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void UART0_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN1_IDX, kPORT_MuxAlt2);            /* PORTA1 (pin 23) is configured as UART0_RX */
  PORT_SetPinMux(PORTA, PIN2_IDX, kPORT_MuxAlt2);            /* PORTA2 (pin 24) is configured as UART0_TX */
}


#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */
/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
UART0_DeinitPins:
- options: {coreID: singlecore, enableClock: 'false'}
- pin_list:
  - {pin_num: '23', peripheral: n/a, signal: disabled, pin_signal: PTA1/UART0_RX/FTM0_CH6/JTAG_TDI/EZP_DI}
  - {pin_num: '24', peripheral: n/a, signal: disabled, pin_signal: PTA2/UART0_TX/FTM0_CH7/JTAG_TDO/TRACE_SWO/EZP_DO}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : UART0_DeinitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void UART0_DeinitPins(void) {
  PORT_SetPinMux(PORTA, PIN1_IDX, kPORT_PinDisabledOrAnalog); /* PORTA1 (pin 23) is disabled */
  PORT_SetPinMux(PORTA, PIN2_IDX, kPORT_PinDisabledOrAnalog); /* PORTA2 (pin 24) is disabled */
}


#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port */
#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
UART1_InitPins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '1', peripheral: SIM, signal: UART1_MOD_OUT, pin_signal: ADC1_SE4a/PTE0/CLKOUT32K/SPI1_PCS1/UART1_TX/I2C1_SDA/RTC_CLKOUT}
  - {pin_num: '2', peripheral: UART1, signal: RX, pin_signal: ADC1_SE5a/PTE1/LLWU_P0/SPI1_SOUT/UART1_RX/I2C1_SCL/SPI1_SIN}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : UART1_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void UART1_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_PortE);                           /* Port E Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTE, PIN0_IDX, kPORT_MuxAlt3);            /* PORTE0 (pin 1) is configured as UART1_TX */
  PORT_SetPinMux(PORTE, PIN1_IDX, kPORT_MuxAlt3);            /* PORTE1 (pin 2) is configured as UART1_RX */
}


#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port */
#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
UART1_DeinitPins:
- options: {coreID: singlecore, enableClock: 'false'}
- pin_list:
  - {pin_num: '1', peripheral: ADC1, signal: 'SE, 4a', pin_signal: ADC1_SE4a/PTE0/CLKOUT32K/SPI1_PCS1/UART1_TX/I2C1_SDA/RTC_CLKOUT}
  - {pin_num: '2', peripheral: ADC1, signal: 'SE, 5a', pin_signal: ADC1_SE5a/PTE1/LLWU_P0/SPI1_SOUT/UART1_RX/I2C1_SCL/SPI1_SIN}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : UART1_DeinitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void UART1_DeinitPins(void) {
  PORT_SetPinMux(PORTE, PIN0_IDX, kPORT_PinDisabledOrAnalog); /* PORTE0 (pin 1) is configured as ADC1_SE4a */
  PORT_SetPinMux(PORTE, PIN1_IDX, kPORT_PinDisabledOrAnalog); /* PORTE1 (pin 2) is configured as ADC1_SE5a */
}


#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */
#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
UART2_InitPins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '59', peripheral: UART2, signal: RX, pin_signal: PTD2/LLWU_P13/SPI0_SOUT/UART2_RX/FTM3_CH2/FBa_AD4/LPUART0_RX/I2C0_SCL}
  - {pin_num: '60', peripheral: UART2, signal: TX, pin_signal: PTD3/SPI0_SIN/UART2_TX/FTM3_CH3/FBa_AD3/LPUART0_TX/I2C0_SDA}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : UART2_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void UART2_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_PortD);                           /* Port D Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTD, PIN2_IDX, kPORT_MuxAlt3);            /* PORTD2 (pin 59) is configured as UART2_RX */
  PORT_SetPinMux(PORTD, PIN3_IDX, kPORT_MuxAlt3);            /* PORTD3 (pin 60) is configured as UART2_TX */
}


#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */
#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port */
/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
UART2_DeinitPins:
- options: {coreID: singlecore, enableClock: 'false'}
- pin_list:
  - {pin_num: '59', peripheral: n/a, signal: disabled, pin_signal: PTD2/LLWU_P13/SPI0_SOUT/UART2_RX/FTM3_CH2/FBa_AD4/LPUART0_RX/I2C0_SCL}
  - {pin_num: '60', peripheral: n/a, signal: disabled, pin_signal: PTD3/SPI0_SIN/UART2_TX/FTM3_CH3/FBa_AD3/LPUART0_TX/I2C0_SDA}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : UART2_DeinitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void UART2_DeinitPins(void) {
  PORT_SetPinMux(PORTD, PIN2_IDX, kPORT_PinDisabledOrAnalog); /* PORTD2 (pin 59) is disabled */
  PORT_SetPinMux(PORTD, PIN3_IDX, kPORT_PinDisabledOrAnalog); /* PORTD3 (pin 60) is disabled */
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
