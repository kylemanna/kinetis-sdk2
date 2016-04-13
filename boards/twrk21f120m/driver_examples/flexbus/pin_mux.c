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

#include "fsl_common.h"
#include "fsl_port.h"

/*******************************************************************************
 * Code
 ******************************************************************************/

/* Function Name : BOARD_InitPins */
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

    /* Address pins */
    PORT_SetPinMux(PORTD, 6U, kPORT_MuxAlt5);  /* FB_AD0 */
    PORT_SetPinMux(PORTD, 5U, kPORT_MuxAlt5);  /* FB_AD1 */
    PORT_SetPinMux(PORTD, 4U, kPORT_MuxAlt5);  /* FB_AD2 */
    PORT_SetPinMux(PORTD, 3U, kPORT_MuxAlt5);  /* FB_AD3 */
    PORT_SetPinMux(PORTD, 2U, kPORT_MuxAlt5);  /* FB_AD4 */
    PORT_SetPinMux(PORTC, 10U, kPORT_MuxAlt5); /* FB_AD5 */
    PORT_SetPinMux(PORTC, 9U, kPORT_MuxAlt5);  /* FB_AD6 */
    PORT_SetPinMux(PORTC, 8U, kPORT_MuxAlt5);  /* FB_AD7 */
    PORT_SetPinMux(PORTC, 7U, kPORT_MuxAlt5);  /* FB_AD8 */
    PORT_SetPinMux(PORTC, 6U, kPORT_MuxAlt5);  /* FB_AD9 */
    PORT_SetPinMux(PORTC, 5U, kPORT_MuxAlt5);  /* FB_AD10 */
    /* Comment out for UART1 purpose.*/
    PORT_SetPinMux(PORTC, 2U, kPORT_MuxAlt5);  /* FB_AD12 */
    PORT_SetPinMux(PORTC, 1U, kPORT_MuxAlt5);  /* FB_AD13 */
    PORT_SetPinMux(PORTC, 0U, kPORT_MuxAlt5);  /* FB_AD14 */
    PORT_SetPinMux(PORTB, 18U, kPORT_MuxAlt5); /* FB_AD15 */
    PORT_SetPinMux(PORTB, 17U, kPORT_MuxAlt5); /* FB_AD16 */
    PORT_SetPinMux(PORTB, 16U, kPORT_MuxAlt5); /* FB_AD17 */
    PORT_SetPinMux(PORTB, 11U, kPORT_MuxAlt5); /* FB_AD18 */
    PORT_SetPinMux(PORTB, 10U, kPORT_MuxAlt5); /* FB_AD19 */
    PORT_SetPinMux(PORTC, 15U, kPORT_MuxAlt5); /* FB_AD24 */
    PORT_SetPinMux(PORTC, 14U, kPORT_MuxAlt5); /* FB_AD25 */
    PORT_SetPinMux(PORTC, 13U, kPORT_MuxAlt5); /* FB_AD26 */
    PORT_SetPinMux(PORTC, 12U, kPORT_MuxAlt5); /* FB_AD27 */
    PORT_SetPinMux(PORTB, 23U, kPORT_MuxAlt5); /* FB_D28 */
    PORT_SetPinMux(PORTB, 22U, kPORT_MuxAlt5); /* FB_D29 */
    PORT_SetPinMux(PORTB, 21U, kPORT_MuxAlt5); /* FB_D30 */
    PORT_SetPinMux(PORTB, 20U, kPORT_MuxAlt5); /* FB_D31 */

    /* RW */
    PORT_SetPinMux(PORTC, 11U, kPORT_MuxAlt5); /* FB_R/W_B */

    /* OE */
    PORT_SetPinMux(PORTB, 19U, kPORT_MuxAlt5); /* FB_OE_B */

    /* CS0 */
    PORT_SetPinMux(PORTD, 1U, kPORT_MuxAlt5); /* FB_CS0 */

    /* ALE */
    PORT_SetPinMux(PORTD, 0U, kPORT_MuxAlt5); /* ALE */
}
