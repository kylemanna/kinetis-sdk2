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
#include "fsl_common.h"

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Initialize all pins used in this example
 *
 * initialization or not.
 */

port_pin_config_t i2c_pin_config = {0};

void BOARD_InitPins(void)
{
    /* Initialize UART1 pins below */
    /* Ungate the port clock */
    CLOCK_EnableClock(kCLOCK_PortB);
    CLOCK_EnableClock(kCLOCK_PortC);
    CLOCK_EnableClock(kCLOCK_PortD);

    /* Affects PORTD_PCR8 register */
    PORT_SetPinMux(PORTD, 8u, kPORT_MuxAlt3);
    /* Affects PORTD_PCR9 register */
    PORT_SetPinMux(PORTD, 9u, kPORT_MuxAlt3);

    /* Configure sai pins */
    /* Tx BCLK */
    PORT_SetPinMux(PORTB, 18u, kPORT_MuxAlt4);
    /* Tx Frame sync */
    PORT_SetPinMux(PORTB, 19u, kPORT_MuxAlt4);
    /* Master clock */
    PORT_SetPinMux(PORTC, 8u, kPORT_MuxAlt4);
    /* Tx data */
    PORT_SetPinMux(PORTC, 1u, kPORT_MuxAlt6);

    /* Configure I2C1 */
    i2c_pin_config.pullSelect = kPORT_PullUp;
#if defined(FSL_FEATURE_PORT_HAS_OPEN_DRAIN) && FSL_FEATURE_PORT_HAS_OPEN_DRAIN
    i2c_pin_config.openDrainEnable = kPORT_OpenDrainEnable;
    i2c_pin_config.mux = kPORT_MuxAlt2;
#endif /* FSL_FEATURE_PORT_HAS_OPEN_DRAIN */

    /* I2C SCL */
    PORT_SetPinConfig(PORTC, 10u, &i2c_pin_config);
    /* I2C SDA */
    PORT_SetPinConfig(PORTC, 11u, &i2c_pin_config);
}
