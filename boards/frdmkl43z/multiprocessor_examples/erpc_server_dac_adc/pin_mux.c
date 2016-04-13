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
- !!processor 'MK64FN1M0xxx12'
- !!package 'MK64FN1M0VLL12'
- !!mcu_data 'ksdk2_0'
- !!processor_version '0.1.19'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

#define PIN1_IDX 1u                        /*!< Pin number for pin 22 in a port */
#define PIN2_IDX 2u                        /*!< Pin number for pin 22 in a port */
#define PIN5_IDX 5u                        /*!< Pin number for pin 22 in a port */
#define PIN24_IDX 24u                      /*!< Pin number for pin 17 in a port */
#define PIN25_IDX 25u                      /*!< Pin number for pin 16 in a port */
#define PIN31_IDX 31u                      /*!< Pin number for pin 17 in a port */
#define SOPT5_UART0TXSRC_UART_TX 0x00u     /*!< UART 0 transmit data source select: UART0_TX pin */
#define SOPT5_LPUART0RXSRC_LPUART_RX 0x00u /*!< LPUART0 Receive Data Source Select: LPUART_RX pin */
#define SOPT5_LPUART0TXSRC_LPUART_TX 0x00u /*!< LPUART0 Transmit Data Source Select: LPUART0_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitPins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '23', peripheral: LPUART0, signal: RX, pin_signal: PTA1/LPUART0_RX/TPM2_CH0}
  - {pin_num: '24', peripheral: LPUART0, signal: TX, pin_signal: PTA2/LPUART0_TX/TPM2_CH1}
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
    CLOCK_EnableClock(kCLOCK_PortE); /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD); /* Port D Clock Gate Control: Clock enabled */

    PORT_SetPinMux(PORTA, PIN1_IDX, kPORT_MuxAlt2);    /* PORTA1 (pin 23) is configured as LPUART0_RX */
    PORT_SetPinMux(PORTA, PIN2_IDX, kPORT_MuxAlt2);    /* PORTA2 (pin 24) is configured as LPUART0_TX */
    PORT_SetPinMux(PORTE, PIN31_IDX, kPORT_MuxAsGpio); /* PORTB22 RED LED*/
    PORT_SetPinMux(PORTD, PIN5_IDX, kPORT_MuxAsGpio);  /* PORTE26 GREEN LED*/
    PORT_SetPinMux(PORTE, PIN24_IDX, kPORT_MuxAlt5);   /* PORTE24 (pin 20) is configured as I2C0_SCL */
    PORT_SetPinMux(PORTE, PIN25_IDX, kPORT_MuxAlt5);   /* PORTE25 (pin 21) is configured as I2C0_SDA */
    SIM->SOPT5 =
        ((SIM->SOPT5 &
          (~(SIM_SOPT5_LPUART0TXSRC_MASK | SIM_SOPT5_LPUART0RXSRC_MASK))) /* Mask bits to zero which are setting */
         |
         SIM_SOPT5_LPUART0TXSRC(SOPT5_LPUART0TXSRC_LPUART_TX) /* LPUART0 Transmit Data Source Select: LPUART0_TX pin */
         | SIM_SOPT5_LPUART0RXSRC(SOPT5_LPUART0RXSRC_LPUART_RX) /* LPUART0 Receive Data Source Select: LPUART_RX pin */
         );
}

/*!< Open Drain Enable: Open drain output is enabled on the corresponding pin, if the pin is configured as a digital
 * output. */
#define PCR_ODE_ENABLED 0x01u
/*!< Pull Enable: Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as
 * a digital input. */
#define PCR_PE_ENABLED 0x01u
/*!< Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
#define PCR_PS_UP 0x01u

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_I2C_ConfigurePins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: C9, peripheral: I2C0, signal: SCL, pin_signal: PTD8/LLWU_P24/I2C0_SCL/LPUART0_RX/FB_A16, open_drain:
enable, pull_select: up, pull_enable: enable}
  - {pin_num: B9, peripheral: I2C0, signal: SDA, pin_signal: PTD9/I2C0_SDA/LPUART0_TX/FB_A17, open_drain: enable,
pull_select: up, pull_enable: enable}
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
    CLOCK_EnableClock(kCLOCK_PortE); /* Port E Clock Gate Control: Clock enabled */

    const port_pin_config_t porte24_pin20_config = {
        kPORT_PullUp,               /* Internal pull-up resistor is enabled */
        kPORT_FastSlewRate,         /* Fast slew rate is configured */
        kPORT_PassiveFilterDisable, /* Passive filter is disabled */
        kPORT_LowDriveStrength,     /* Low drive strength is configured */
        kPORT_MuxAlt5,              /* Pin is configured as I2C0_SCL */
    };
    const port_pin_config_t porte25_pin21_config = {
        kPORT_PullUp,               /* Internal pull-up resistor is enabled */
        kPORT_FastSlewRate,         /* Fast slew rate is configured */
        kPORT_PassiveFilterDisable, /* Passive filter is disabled */
        kPORT_LowDriveStrength,     /* Low drive strength is configured */
        kPORT_MuxAlt5,              /* Pin is configured as I2C0_SDA */
    };
    PORT_SetPinConfig(PORTE, PIN24_IDX, &porte24_pin20_config); /* PORTE24 (pin 20) is configured as I2C0_SCL */
    PORT_SetPinConfig(PORTE, PIN25_IDX, &porte25_pin21_config); /* PORTE25 (pin 21) is configured as I2C0_SDA */
}

#define PIN1_IDX 1u                        /*!< Pin number for pin 1 in a port */
#define PIN2_IDX 2u                        /*!< Pin number for pin 2 in a port */
#define SOPT5_LPUART0RXSRC_LPUART_RX 0x00u /*!< LPUART0 Receive Data Source Select: LPUART_RX pin */
#define SOPT5_LPUART0TXSRC_LPUART_TX 0x00u /*!< LPUART0 Transmit Data Source Select: LPUART0_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
LPUART0_InitPins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '23', peripheral: LPUART0, signal: RX, pin_signal: PTA1/LPUART0_RX/TPM2_CH0}
  - {pin_num: '24', peripheral: LPUART0, signal: TX, pin_signal: PTA2/LPUART0_TX/TPM2_CH1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : LPUART0_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void LPUART0_InitPins(void)
{
    CLOCK_EnableClock(kCLOCK_PortA); /* Port A Clock Gate Control: Clock enabled */

    PORT_SetPinMux(PORTA, PIN1_IDX, kPORT_MuxAlt2); /* PORTA1 (pin 23) is configured as LPUART0_RX */
    PORT_SetPinMux(PORTA, PIN2_IDX, kPORT_MuxAlt2); /* PORTA2 (pin 24) is configured as LPUART0_TX */
    SIM->SOPT5 =
        ((SIM->SOPT5 &
          (~(SIM_SOPT5_LPUART0TXSRC_MASK | SIM_SOPT5_LPUART0RXSRC_MASK))) /* Mask bits to zero which are setting */
         |
         SIM_SOPT5_LPUART0TXSRC(SOPT5_LPUART0TXSRC_LPUART_TX) /* LPUART0 Transmit Data Source Select: LPUART0_TX pin */
         | SIM_SOPT5_LPUART0RXSRC(SOPT5_LPUART0RXSRC_LPUART_RX) /* LPUART0 Receive Data Source Select: LPUART_RX pin */
         );
}

#define PIN1_IDX 1u /*!< Pin number for pin 1 in a port */
#define PIN2_IDX 2u /*!< Pin number for pin 2 in a port */
                    /*
                     * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
                    LPUART0_DeinitPins:
                    - options: {coreID: singlecore, enableClock: 'false'}
                    - pin_list:
                      - {pin_num: '24', peripheral: n/a, signal: disabled, pin_signal: PTA2/LPUART0_TX/TPM2_CH1}
                      - {pin_num: '23', peripheral: n/a, signal: disabled, pin_signal: PTA1/LPUART0_RX/TPM2_CH0}
                     * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
                     */

/*FUNCTION**********************************************************************
 *
 * Function Name : LPUART0_DeinitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void LPUART0_DeinitPins(void)
{
    PORT_SetPinMux(PORTA, PIN1_IDX, kPORT_PinDisabledOrAnalog); /* PORTA1 (pin 23) is disabled */
    PORT_SetPinMux(PORTA, PIN2_IDX, kPORT_PinDisabledOrAnalog); /* PORTA2 (pin 24) is disabled */
}

#define PIN18_IDX 18u                      /*!< Pin number for pin 18 in a port */
#define PIN30_IDX 30u                      /*!< Pin number for pin 30 in a port */
#define SOPT5_LPUART1RXSRC_LPUART_RX 0x00u /*!< LPUART1 Receive Data Source Select: LPUART1_RX pin */
#define SOPT5_LPUART1TXSRC_LPUART_TX 0x00u /*!< LPUART1 Transmit Data Source Select: LPUART1_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
LPUART1_InitPins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '32', peripheral: LPUART1, signal: RX, pin_signal: EXTAL0/PTA18/LPUART1_RX/TPM_CLKIN0}
  - {pin_num: '18', peripheral: LPUART1, signal: TX, pin_signal:
DAC0_OUT/ADC0_SE23/CMP0_IN4/PTE30/TPM0_CH3/TPM_CLKIN1/LPUART1_TX/LPTMR0_ALT1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : LPUART1_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void LPUART1_InitPins(void)
{
    CLOCK_EnableClock(kCLOCK_PortA); /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE); /* Port E Clock Gate Control: Clock enabled */

    PORT_SetPinMux(PORTA, PIN18_IDX, kPORT_MuxAlt3); /* PORTA18 (pin 32) is configured as LPUART1_RX */
    PORT_SetPinMux(PORTE, PIN30_IDX, kPORT_MuxAlt5); /* PORTE30 (pin 18) is configured as LPUART1_TX */
    SIM->SOPT5 =
        ((SIM->SOPT5 &
          (~(SIM_SOPT5_LPUART1TXSRC_MASK | SIM_SOPT5_LPUART1RXSRC_MASK))) /* Mask bits to zero which are setting */
         |
         SIM_SOPT5_LPUART1TXSRC(SOPT5_LPUART1TXSRC_LPUART_TX) /* LPUART1 Transmit Data Source Select: LPUART1_TX pin */
         | SIM_SOPT5_LPUART1RXSRC(SOPT5_LPUART1RXSRC_LPUART_RX) /* LPUART1 Receive Data Source Select: LPUART1_RX pin */
         );
}

#define PIN18_IDX 18u /*!< Pin number for pin 18 in a port */
#define PIN30_IDX 30u /*!< Pin number for pin 30 in a port */
                      /*
                       * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
                      LPUART1_DeinitPins:
                      - options: {coreID: singlecore, enableClock: 'false'}
                      - pin_list:
                        - {pin_num: '32', peripheral: OSC0, signal: EXTAL0, pin_signal: EXTAL0/PTA18/LPUART1_RX/TPM_CLKIN0}
                        - {pin_num: '18', peripheral: ADC0, signal: 'SE, 23', pin_signal:
                      DAC0_OUT/ADC0_SE23/CMP0_IN4/PTE30/TPM0_CH3/TPM_CLKIN1/LPUART1_TX/LPTMR0_ALT1}
                       * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
                       */

/*FUNCTION**********************************************************************
 *
 * Function Name : LPUART1_DeinitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void LPUART1_DeinitPins(void)
{
    PORT_SetPinMux(PORTA, PIN18_IDX, kPORT_PinDisabledOrAnalog); /* PORTA18 (pin 32) is configured as EXTAL0 */
    PORT_SetPinMux(PORTE, PIN30_IDX, kPORT_PinDisabledOrAnalog); /* PORTE30 (pin 18) is configured as ADC0_SE23 */
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
