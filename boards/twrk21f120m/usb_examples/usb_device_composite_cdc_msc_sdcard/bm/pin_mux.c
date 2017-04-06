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

#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port */
#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */
#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port */
#define PIN4_IDX                         4u   /*!< Pin number for pin 4 in a port */
#define PIN5_IDX                         5u   /*!< Pin number for pin 5 in a port */
#define PIN8_IDX                         8u   /*!< Pin number for pin 8 in a port */
#define PIN9_IDX                         9u   /*!< Pin number for pin 9 in a port */
#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitPins:
- options: {prefix: BOARD_, coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: A10, peripheral: UART5, signal: RX, pin_signal: PTD8/I2C0_SCL/UART5_RX/FBa_A16}
  - {pin_num: A9, peripheral: UART5, signal: TX, pin_signal: PTD9/I2C0_SDA/UART5_TX/FBa_A17}
  - {pin_num: E4, peripheral: SDHC, signal: 'DATA, 1', pin_signal: ADC1_SE4a/PTE0/SPI1_PCS1/UART1_TX/SDHC0_D1/TRACE_CLKOUT/I2C1_SDA/RTC_CLKOUT, slew_rate: fast, open_drain: disable,
    drive_strength: high, pull_select: up, pull_enable: enable, passive_filter: disable}
  - {pin_num: E3, peripheral: SDHC, signal: 'DATA, 0', pin_signal: ADC1_SE5a/PTE1/LLWU_P0/SPI1_SOUT/UART1_RX/SDHC0_D0/TRACE_D3/I2C1_SCL/SPI1_SIN, slew_rate: fast,
    open_drain: disable, drive_strength: high, pull_select: up, pull_enable: enable, passive_filter: disable}
  - {pin_num: E2, peripheral: SDHC, signal: DCLK, pin_signal: ADC0_DP2/ADC1_SE6a/PTE2/LLWU_P1/SPI1_SCK/UART1_CTS_b/SDHC0_DCLK/TRACE_D2, slew_rate: fast, open_drain: disable,
    drive_strength: high, pull_select: up, pull_enable: enable, passive_filter: disable}
  - {pin_num: F4, peripheral: SDHC, signal: CMD, pin_signal: ADC0_DM2/ADC1_SE7a/PTE3/SPI1_SIN/UART1_RTS_b/SDHC0_CMD/TRACE_D1/SPI1_SOUT, slew_rate: fast, open_drain: disable,
    drive_strength: high, pull_select: up, pull_enable: enable, passive_filter: disable}
  - {pin_num: H7, peripheral: SDHC, signal: 'DATA, 3', pin_signal: PTE4/LLWU_P2/SPI1_PCS0/UART3_TX/SDHC0_D3/TRACE_D0, slew_rate: fast, open_drain: disable, drive_strength: high,
    pull_select: up, pull_enable: enable, passive_filter: disable}
  - {pin_num: G4, peripheral: SDHC, signal: 'DATA, 2', pin_signal: PTE5/SPI1_PCS2/UART3_RX/SDHC0_D2/FTM3_CH0, slew_rate: fast, open_drain: disable, drive_strength: high,
    pull_select: up, pull_enable: enable, passive_filter: disable}
  - {pin_num: B4, peripheral: GPIOC, signal: 'GPIO, 18', pin_signal: PTC18/UART3_RTS_b/FBa_TBST_b/FBa_CS2_b/FBa_BE15_8_BLS23_16_b, slew_rate: fast, open_drain: disable,
    drive_strength: low, pull_select: up, pull_enable: enable, passive_filter: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortD);                           /* Port D Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortE);                           /* Port E Clock Gate Control: Clock enabled */

  const port_pin_config_t portc18_pinB4_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTC18 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTC, PIN18_IDX, &portc18_pinB4_config); /* PORTC18 (pin B4) is configured as PTC18 */
  PORT_SetPinMux(PORTD, PIN8_IDX, kPORT_MuxAlt3);            /* PORTD8 (pin A10) is configured as UART5_RX */
  PORT_SetPinMux(PORTD, PIN9_IDX, kPORT_MuxAlt3);            /* PORTD9 (pin A9) is configured as UART5_TX */
  const port_pin_config_t porte0_pinE4_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
    kPORT_MuxAlt4,                                           /* Pin is configured as SDHC0_D1 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTE, PIN0_IDX, &porte0_pinE4_config);  /* PORTE0 (pin E4) is configured as SDHC0_D1 */
  const port_pin_config_t porte1_pinE3_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
    kPORT_MuxAlt4,                                           /* Pin is configured as SDHC0_D0 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTE, PIN1_IDX, &porte1_pinE3_config);  /* PORTE1 (pin E3) is configured as SDHC0_D0 */
  const port_pin_config_t porte2_pinE2_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
    kPORT_MuxAlt4,                                           /* Pin is configured as SDHC0_DCLK */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTE, PIN2_IDX, &porte2_pinE2_config);  /* PORTE2 (pin E2) is configured as SDHC0_DCLK */
  const port_pin_config_t porte3_pinF4_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
    kPORT_MuxAlt4,                                           /* Pin is configured as SDHC0_CMD */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTE, PIN3_IDX, &porte3_pinF4_config);  /* PORTE3 (pin F4) is configured as SDHC0_CMD */
  const port_pin_config_t porte4_pinH7_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
    kPORT_MuxAlt4,                                           /* Pin is configured as SDHC0_D3 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTE, PIN4_IDX, &porte4_pinH7_config);  /* PORTE4 (pin H7) is configured as SDHC0_D3 */
  const port_pin_config_t porte5_pinG4_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
    kPORT_MuxAlt4,                                           /* Pin is configured as SDHC0_D2 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTE, PIN5_IDX, &porte5_pinG4_config);  /* PORTE5 (pin G4) is configured as SDHC0_D2 */
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
