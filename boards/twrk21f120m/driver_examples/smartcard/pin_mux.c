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

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
PinsProfile:
- !!product 'Pins v2.0'
- !!processor 'MK21FN1M0Axxx12'
- !!package 'MK21FN1M0AVMC12'
- !!mcu_data 'ksdk2_0'
- !!processor_version '1.0.1'
- !!board 'TWR-K21F120M'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port */
#define PIN5_IDX                         5u   /*!< Pin number for pin 5 in a port */
#define PIN8_IDX                         8u   /*!< Pin number for pin 8 in a port */
#define PIN9_IDX                         9u   /*!< Pin number for pin 9 in a port */
#define PIN10_IDX                       10u   /*!< Pin number for pin 10 in a port */
#define PIN11_IDX                       11u   /*!< Pin number for pin 11 in a port */
#define PIN14_IDX                       14u   /*!< Pin number for pin 14 in a port */
#define PORT_DFER_DFE_10_MASK       0x0400u   /*!< Digital Filter Enable Mask for item 10. */
#define PORT_DFER_DFE_11_MASK       0x0800u   /*!< Digital Filter Enable Mask for item 11. */
#define PORT_DFER_DFE_14_MASK       0x4000u   /*!< Digital Filter Enable Mask for item 14. */
#define SOPT5_UART0TXSRC_UART_TX      0x00u   /*!< UART 0 transmit data source select: UART0_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitPins:
- options: {prefix: BOARD_, coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: A10, peripheral: UART5, signal: RX, pin_signal: PTD8/I2C0_SCL/UART5_RX/FBa_A16}
  - {pin_num: A9, peripheral: UART5, signal: TX, pin_signal: PTD9/I2C0_SDA/UART5_TX/FBa_A17}
  - {pin_num: K9, peripheral: UART0, signal: TX, pin_signal: PTA14/SPI0_PCS0/UART0_TX/I2C2_SCL/I2S0_RX_BCLK/I2S0_TXD1}
  - {pin_num: D8, peripheral: FTM0, signal: 'CH, 0', pin_signal: ADC0_SE15/PTC1/LLWU_P6/SPI0_PCS3/UART1_RTS_b/FTM0_CH0/FBa_AD13/I2S0_TXD0, slew_rate: fast, open_drain: disable,
    drive_strength: high, pull_select: down, pull_enable: disable, passive_filter: disable}
  - {pin_num: B8, peripheral: GPIOC, signal: 'GPIO, 3', pin_signal: CMP1_IN1/PTC3/LLWU_P7/SPI0_PCS1/UART1_RX/FTM0_CH2/CLKOUTa/CLKOUT/I2S0_TX_BCLK, slew_rate: fast,
    open_drain: disable, drive_strength: high, pull_select: down, pull_enable: enable, passive_filter: disable}
  - {pin_num: K7, peripheral: GPIOA, signal: 'GPIO, 5', pin_signal: PTA5/USB_CLKIN/FTM0_CH2/CMP2_OUT/I2S0_TX_BCLK/JTAG_TRST_b, slew_rate: fast, open_drain: disable,
    drive_strength: high, pull_select: up, pull_enable: enable, passive_filter: disable}
  - {pin_num: C2, peripheral: GPIOD, signal: 'GPIO, 11', pin_signal: PTD11/SPI2_PCS0/UART5_CTS_b/SDHC0_CLKIN/FBa_A19, slew_rate: fast, open_drain: disable, drive_strength: high,
    pull_select: up, pull_enable: enable, passive_filter: disable, digital_filter: disable}
  - {pin_num: D1, peripheral: GPIOD, signal: 'GPIO, 14', pin_signal: PTD14/SPI2_SIN/SDHC0_D6/FBa_A22, slew_rate: fast, open_drain: disable, drive_strength: high,
    pull_select: up, pull_enable: enable, passive_filter: disable, digital_filter: disable}
  - {pin_num: B1, peripheral: GPIOD, signal: 'GPIO, 10', pin_signal: PTD10/UART5_RTS_b/FBa_A18, slew_rate: fast, open_drain: disable, drive_strength: high, pull_select: up,
    pull_enable: enable, passive_filter: disable, digital_filter: disable}
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
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortD);                           /* Port D Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN14_IDX, kPORT_MuxAlt3);           /* PORTA14 (pin K9) is configured as UART0_TX */
  const port_pin_config_t porta5_pinK7_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTA5 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTA, PIN5_IDX, &porta5_pinK7_config);  /* PORTA5 (pin K7) is configured as PTA5 */
  const port_pin_config_t portc1_pinD8_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
    kPORT_MuxAlt4,                                           /* Pin is configured as FTM0_CH0 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTC, PIN1_IDX, &portc1_pinD8_config);  /* PORTC1 (pin D8) is configured as FTM0_CH0 */
  const port_pin_config_t portc3_pinB8_config = {
    kPORT_PullDown,                                          /* Internal pull-down resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTC3 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTC, PIN3_IDX, &portc3_pinB8_config);  /* PORTC3 (pin B8) is configured as PTC3 */
  PORT_EnablePinsDigitalFilter(                              /* Configure digital filter */
    PORTD,                                                   /* Digital filter is configured on port D */
      PORT_DFER_DFE_10_MASK                                  /* Digital filter is configured for PORTD0 */
    | PORT_DFER_DFE_11_MASK                                  /* Digital filter is configured for PORTD1 */
    | PORT_DFER_DFE_14_MASK,                                 /* Digital filter is configured for PORTD2 */
    false                                                    /* Disable digital filter */
  );
  const port_pin_config_t portd10_pinB1_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTD10 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTD, PIN10_IDX, &portd10_pinB1_config); /* PORTD10 (pin B1) is configured as PTD10 */
  const port_pin_config_t portd11_pinC2_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTD11 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTD, PIN11_IDX, &portd11_pinC2_config); /* PORTD11 (pin C2) is configured as PTD11 */
  const port_pin_config_t portd14_pinD1_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTD14 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTD, PIN14_IDX, &portd14_pinD1_config); /* PORTD14 (pin D1) is configured as PTD14 */
  PORT_SetPinMux(PORTD, PIN8_IDX, kPORT_MuxAlt3);            /* PORTD8 (pin A10) is configured as UART5_RX */
  PORT_SetPinMux(PORTD, PIN9_IDX, kPORT_MuxAlt3);            /* PORTD9 (pin A9) is configured as UART5_TX */
  SIM->SOPT5 = ((SIM->SOPT5 &
    (~(SIM_SOPT5_UART0TXSRC_MASK)))                          /* Mask bits to zero which are setting */
      | SIM_SOPT5_UART0TXSRC(SOPT5_UART0TXSRC_UART_TX)       /* UART 0 transmit data source select: UART0_TX pin */
    );
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
