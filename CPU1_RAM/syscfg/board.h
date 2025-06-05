/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************
//
// GPIO20 - GPIO Settings
//
#define led_GPIO_PIN_CONFIG GPIO_20_GPIO20
//
// GPIO23 - GPIO Settings
//
#define sw_GPIO_PIN_CONFIG GPIO_23_GPIO23
//
// GPIO30 - GPIO Settings
//
#define cs1_GPIO_PIN_CONFIG GPIO_30_GPIO30
//
// GPIO47 - GPIO Settings
//
#define cs2_GPIO_PIN_CONFIG GPIO_47_GPIO47

//
// SCIA -> mySCIA Pinmux
//
//
// SCIA_RX - GPIO Settings
//
#define GPIO_PIN_SCIA_RX 28
#define mySCIA_SCIRX_GPIO 28
#define mySCIA_SCIRX_PIN_CONFIG GPIO_28_SCIA_RX
//
// SCIA_TX - GPIO Settings
//
#define GPIO_PIN_SCIA_TX 29
#define mySCIA_SCITX_GPIO 29
#define mySCIA_SCITX_PIN_CONFIG GPIO_29_SCIA_TX

//
// SPIB -> mySPIS Pinmux
//
//
// SPIB_PICO - GPIO Settings
//
#define GPIO_PIN_SPIB_PICO 60
#define mySPIS_SPIPICO_GPIO 60
#define mySPIS_SPIPICO_PIN_CONFIG GPIO_60_SPIB_SIMO
//
// SPIB_POCI - GPIO Settings
//
#define GPIO_PIN_SPIB_POCI 61
#define mySPIS_SPIPOCI_GPIO 61
#define mySPIS_SPIPOCI_PIN_CONFIG GPIO_61_SPIB_SOMI
//
// SPIB_CLK - GPIO Settings
//
#define GPIO_PIN_SPIB_CLK 58
#define mySPIS_SPICLK_GPIO 58
#define mySPIS_SPICLK_PIN_CONFIG GPIO_58_SPIB_CLK
//
// SPIB_PTE - GPIO Settings
//
#define GPIO_PIN_SPIB_PTE 27
#define mySPIS_SPIPTE_GPIO 27
#define mySPIS_SPIPTE_PIN_CONFIG GPIO_27_SPIB_STE

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define led 20
void led_init();
#define sw 23
void sw_init();
#define cs1 30
void cs1_init();
#define cs2 47
void cs2_init();

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
#define myINPUTXBARINPUT0_SOURCE 23
#define myINPUTXBARINPUT0_INPUT XBAR_INPUT4
void myINPUTXBARINPUT0_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_sw_XINT
// ISR need to be defined for the registered interrupts
#define INT_sw_XINT INT_XINT1
#define INT_sw_XINT_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_sw_XINT_ISR(void);

// Interrupt Settings for INT_mySCIA_RX
// ISR need to be defined for the registered interrupts
#define INT_mySCIA_RX INT_SCIA_RX
#define INT_mySCIA_RX_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP9
extern __interrupt void INT_mySCIA_RX_ISR(void);

// Interrupt Settings for INT_mySPIS_RX
// ISR need to be defined for the registered interrupts
#define INT_mySPIS_RX INT_SPIB_RX
#define INT_mySPIS_RX_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP6
extern __interrupt void INT_mySPIS_RX_ISR(void);

// Interrupt Settings for INT_mySPIS_TX
// ISR need to be defined for the registered interrupts
#define INT_mySPIS_TX INT_SPIB_TX
#define INT_mySPIS_TX_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP6
extern __interrupt void INT_mySPIS_TX_ISR(void);

//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
#define mySCIA_BASE SCIA_BASE
#define mySCIA_BAUDRATE 115200
#define mySCIA_CONFIG_WLEN SCI_CONFIG_WLEN_8
#define mySCIA_CONFIG_STOP SCI_CONFIG_STOP_ONE
#define mySCIA_CONFIG_PAR SCI_CONFIG_PAR_NONE
#define mySCIA_FIFO_TX_LVL SCI_FIFO_TX0
#define mySCIA_FIFO_RX_LVL SCI_FIFO_RX10
void mySCIA_init();

//*****************************************************************************
//
// SPI Configurations
//
//*****************************************************************************
#define mySPIS_BASE SPIB_BASE
#define mySPIS_BITRATE 1000000
#define mySPIS_DATAWIDTH 16
void mySPIS_init();

//*****************************************************************************
//
// SYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// XINT Configurations
//
//*****************************************************************************
#define sw_XINT GPIO_INT_XINT1
#define sw_XINT_TYPE GPIO_INT_TYPE_FALLING_EDGE
void sw_XINT_init();

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	GPIO_init();
void	INPUTXBAR_init();
void	INTERRUPT_init();
void	SCI_init();
void	SPI_init();
void	SYSCTL_init();
void	XINT_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
