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

#include "fsl_port.h"
#include "pin_mux.h"
#include "fsl_gpio.h"

/*******************************************************************************
 * Code
 ******************************************************************************/
void BOARD_InitPins(void)
{
    port_pin_config_t i2c_pin_config = {0};

    i2c_pin_config.pullSelect = kPORT_PullUp;
    i2c_pin_config.slewRate = kPORT_FastSlewRate;
    i2c_pin_config.mux = kPORT_MuxAlt2;
    i2c_pin_config.openDrainEnable = kPORT_OpenDrainEnable;

    /* Initialize UART1 pins below */
    /* Ungate the port clock */
    CLOCK_EnableClock(kCLOCK_PortE);
    /* Affects PORTE_PCR0 register */
    PORT_SetPinMux(PORTE, 0U, kPORT_MuxAlt3);
    /* Affects PORTE_PCR1 register */
    PORT_SetPinMux(PORTE, 1U, kPORT_MuxAlt3);

    /* Ungate the port clock */
    CLOCK_EnableClock(kCLOCK_PortB);

    /* Release I2C bus */
    BOARD_I2C_ReleaseBus();

    /* I2C0 pull up resistor setting */
    PORT_SetPinConfig(PORTB, 2U, &i2c_pin_config);
    PORT_SetPinConfig(PORTB, 3U, &i2c_pin_config);

    /* Initialize FTM0 pins below */
    /* Ungate the port clock */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Affects PORTA_PCR1 register */
    PORT_SetPinMux(PORTA, 1U, kPORT_MuxAlt3);
    PORT_SetPinMux(PORTA, 2U, kPORT_MuxAsGpio);
    /* Ungate the port clock */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Affects PORTA_PCR1 register */
    PORT_SetPinMux(PORTD, 5U, kPORT_MuxAlt4);
}

void BOARD_I2C_ReleaseBus(void)
{
    port_pin_config_t i2c_pin_config = {0};
    gpio_pin_config_t pin_config;
    uint8_t i = 0;
    uint8_t j = 0;

    /* Config pin mux as gpio */
    i2c_pin_config.pullSelect = kPORT_PullUp;
    i2c_pin_config.mux = kPORT_MuxAsGpio;

    pin_config.pinDirection = kGPIO_DigitalOutput;
    pin_config.outputLogic = 1U;

    PORT_SetPinConfig(PORTB, 2U, &i2c_pin_config);
    PORT_SetPinConfig(PORTB, 3U, &i2c_pin_config);

    GPIO_PinInit(GPIOB, 2U, &pin_config);
    GPIO_PinInit(GPIOB, 3U, &pin_config);

    /* Send 9 pulses on SCL and keep SDA high */
    for (i = 0; i < 9; i++)
    {
        GPIO_WritePinOutput(GPIOB, 2U, 0U);
        for (j = 0; j < 255; j++)
        {
            __asm("nop");
        }
        GPIO_WritePinOutput(GPIOB, 2U, 1U);
        for (j = 0; j < 255; j++)
        {
            __asm("nop");
        }
    }
    /* Send STOP */
    GPIO_WritePinOutput(GPIOB, 2U, 1U);
    GPIO_WritePinOutput(GPIOB, 3U, 1U);
}
