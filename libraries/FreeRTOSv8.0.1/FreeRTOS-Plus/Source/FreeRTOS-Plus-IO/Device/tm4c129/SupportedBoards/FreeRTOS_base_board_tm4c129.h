/*
 * FreeRTOS+IO V1.0.1 (C) 2012 Real Time Engineers ltd.
 *
 * FreeRTOS+IO is an add-on component to FreeRTOS.  It is not, in itself, part
 * of the FreeRTOS kernel.  FreeRTOS+IO is licensed separately from FreeRTOS,
 * and uses a different license to FreeRTOS.  FreeRTOS+IO uses a dual license
 * model, information on which is provided below:
 *
 * - Open source licensing -
 * FreeRTOS+IO is a free download and may be used, modified and distributed
 * without charge provided the user adheres to version two of the GNU General
 * Public license (GPL) and does not remove the copyright notice or this text.
 * The GPL V2 text is available on the gnu.org web site, and on the following
 * URL: http://www.FreeRTOS.org/gpl-2.0.txt
 *
 * - Commercial licensing -
 * Businesses and individuals who wish to incorporate FreeRTOS+IO into
 * proprietary software for redistribution in any form must first obtain a low
 * cost commercial license - and in-so-doing support the maintenance, support
 * and further development of the FreeRTOS+IO product.  Commercial licenses can
 * be obtained from http://shop.freertos.org and do not require any source files
 * to be changed.
 *
 * FreeRTOS+IO is distributed in the hope that it will be useful.  You cannot
 * use FreeRTOS+IO unless you agree that you use the software 'as is'.
 * FreeRTOS+IO is provided WITHOUT ANY WARRANTY; without even the implied
 * warranties of NON-INFRINGEMENT, MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. Real Time Engineers Ltd. disclaims all conditions and terms, be they
 * implied, expressed, or statutory.
 *
 * 1 tab == 4 spaces!
 *
 * http://www.FreeRTOS.org
 * http://www.FreeRTOS.org/FreeRTOS-Plus
 *
 */
 
#ifndef FREERTOS_BASE_BOARD_TM4C129_H
#define FREERTOS_BASE_BOARD_TM4C129_H

/* Header files for all the driver libraries that can be used with this BSP. */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/uart.h"
#include "driverlib/ssi.h"

/*******************************************************************************
 * Definitions used by FreeRTOS+IO to determine the peripherals that are
 * available on the board, and the functions used to interface with the target
 * specific peripheral drivers.
 ******************************************************************************/

/*******************************************************************************
 * Definitions used by the UART-interrupt-driven-command-console.c example file.
 *
 * See http://www.freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_IO/Board_Support_Packages.shtml
 *
 ******************************************************************************/
#define boardAVAILABLE_DEVICES_LIST												\
{																				\
	{ ( const int8_t * const ) "/UART0/", eUART_TYPE, ( uint32_t ) UART0_BASE },\
    { ( const int8_t * const ) "/SPI3/", eSSP_TYPE, ( uint32_t ) SSI3_BASE }    \
}

/*******************************************************************************
 * Map the FreeRTOS+IO interface to the TM4C129 specific functions.
 ******************************************************************************/
portBASE_TYPE vFreeRTOS_tm4c129_PopulateFunctionPointers( const Peripheral_Types_t ePeripheralType, Peripheral_Control_t * const pxPeripheralControl );
#define boardFreeRTOS_PopulateFunctionPointers vFreeRTOS_tm4c129_PopulateFunctionPointers

/*******************************************************************************
 * These define the number of peripherals available on the microcontroller -
 * not the number of peripherals that are supported by the software
 ******************************************************************************/
#define boardNUM_SSPS				4 /* SSI0 to SSI3. */
#define boardNUM_UARTS				8 /* UART0 to UART7. */

/*******************************************************************************
 * Set the default baud rate used by a UART.
 ******************************************************************************/
#define boardDEFAULT_UART_BAUD		115200

/*******************************************************************************
 * Command console definitions.
 ******************************************************************************/
#define boardCOMMAND_CONSOLE_UART       ( const int8_t * const ) "/UART0/"

/*******************************************************************************
 * SD card wiring.
 ******************************************************************************/
#define boardSD_CARD_SSP_PORT	        ( const int8_t * const ) "/SPI3/"

/* Peripheral definitions for DK-TM4C129X board */
/* SSI port */
#define SDC_SSI_BASE            SSI3_BASE
#define SDC_SSI_SYSCTL_PERIPH   SYSCTL_PERIPH_SSI3

/* GPIO for SSI pins */
/* CLK pin */
#define SDC_SSI_CLK_GPIO_PORT_BASE   GPIO_PORTQ_BASE
#define SDC_SSI_CLK             GPIO_PIN_0
/* TX pin */
#define SDC_SSI_TX_GPIO_PORT_BASE   GPIO_PORTF_BASE
#define SDC_SSI_TX              GPIO_PIN_0
/* RX pin */
#define SDC_SSI_RX_GPIO_PORT_BASE   GPIO_PORTQ_BASE
#define SDC_SSI_RX              GPIO_PIN_2
/* CS pin */
#define SDC_SSI_FSS_GPIO_PORT_BASE   GPIO_PORTH_BASE
#define SDC_SSI_FSS             GPIO_PIN_4

extern uint32_t g_ui32SysClock;

// missing detect pint: set SD_CARD_DETECT equal to SD_CARD_INSERTED
#define boardSD_CARD_DETECT()	        ( 0 )
#define boardSD_CARD_INSERTED		    ( 0 )                                        
#define boardSD_CARD_DEASSERT_CS()      ROM_GPIOPinWrite(SDC_SSI_FSS_GPIO_PORT_BASE, SDC_SSI_FSS, SDC_SSI_FSS)
#define boardSD_CARD_ASSERT_CS()	    ROM_GPIOPinWrite(SDC_SSI_FSS_GPIO_PORT_BASE, SDC_SSI_FSS, 0)

/*******************************************************************************
 * SSP/SPI port configuration definitions.
 ******************************************************************************/
#define boardSSP_DATABIT_8 							( 8 )
#define boardSPI_MASTER_MODE 						( SSI_MODE_MASTER )
#define boardSSP_FRAME_SPI 							( SSI_FRF_MOTO_MODE_0 )
#define boardDEFAULT_READ_MUTEX_TIMEOUT				( ( portTickType ) 1000 )
#define boardSD_INTERFACE_FAST_CLOCK				10000000UL

/* SSP specific ioctl requests. */
#define ioctlSET_SSP_FRAME_FORMAT			1000
    
#endif /* FREERTOS_BASE_BOARD_TM4C129_H */