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
#include "driverlib/uart.h"
//#include "driverlib/ssi.h"
//#include "driverlib/i2c.h"

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
	{ ( const int8_t * const ) "/UART3/", eUART_TYPE, ( void * ) LPC_UART3 }	\
	//{ ( const int8_t * const ) "/SSP1/", eSSP_TYPE, ( void * ) LPC_SSP1 },		\
	//{ ( const int8_t * const ) "/I2C2/", eI2C_TYPE, ( void * ) LPC_I2C2 }		\
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
//#define boardNUM_SSPS				2 /* SSP0 to SSP1. */
#define boardNUM_UARTS				8 /* UART0 to UART7. */
//#define boardNUM_I2CS				3 /* I2C0 to I2C2. */


/*******************************************************************************
 * Configure port UART port pins to be correct for the wiring of the
 * base board.
 ******************************************************************************/
#define boardCONFIGURE_UART_PINS( cPeripheralNumber, xPinConfig )					\
	switch( ( cPeripheralNumber ) )													\
	{																				\
		case 3	:	( xPinConfig ).Funcnum = 2;										\
					( xPinConfig ).Pinnum = 0;										\
					( xPinConfig ).Portnum = 0;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					( xPinConfig ).Pinnum = 1;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					break;															\
																					\
		default	:	/* These are either not implemented yet, or not available		\
					on this board.  Force an assert failure. */						\
					configASSERT( ( cPeripheralNumber ) - ( cPeripheralNumber ) );	\
					break;															\
	}

/*******************************************************************************
 * Configure port SSP port pins to be correct for the wiring of the
 *  base board.
 ******************************************************************************/
#define boardCONFIGURE_SSP_PINS( cPeripheralNumber, xPinConfig )					\
	switch( ( cPeripheralNumber ) )													\
	{																				\
		case 1	:	( xPinConfig ).Funcnum = 2;										\
					( xPinConfig ).OpenDrain = 0;									\
					( xPinConfig ).Pinmode = 0;										\
					( xPinConfig ).Portnum = 0;										\
					( xPinConfig ).Pinnum = 7;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					( xPinConfig ).Pinnum = 8;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					( xPinConfig ).Pinnum = 9;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					( xPinConfig ).Funcnum = 0;										\
					( xPinConfig ).Portnum = 2;										\
					( xPinConfig ).Pinnum = 2;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					break;															\
																					\
		default	:	/* These are either not implemented yet, or not available		\
					on this board.  Force an assert failure. */						\
					configASSERT( ( cPeripheralNumber ) - ( cPeripheralNumber ) );	\
					break;															\
	}

/*******************************************************************************
 * Configure port I2C port pins to be correct for the wiring of the
 * base board.
 ******************************************************************************/
#define boardCONFIGURE_I2C_PINS( cPeripheralNumber, xPinConfig )					\
	switch( ( cPeripheralNumber ) )													\
	{																				\
		case 2	:	( xPinConfig ).Funcnum = 2;										\
					( xPinConfig ).Pinnum = 10;										\
					( xPinConfig ).Portnum = 0;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					( xPinConfig ).Pinnum = 11;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					break;															\
																					\
		default	:	/* These are either not implemented yet, or not available		\
					on this board.  Force an assert failure. */						\
					configASSERT( ( cPeripheralNumber ) - ( cPeripheralNumber ) );	\
					break;															\
	}

/*******************************************************************************
 * Set the default baud rate used by a UART.
 ******************************************************************************/
#define boardDEFAULT_UART_BAUD		115200

/*******************************************************************************
 * Command console definitions.
 ******************************************************************************/
#define boardCOMMAND_CONSOLE_UART	( const int8_t * const ) "/UART3/"

/* SSP specific ioctl requests. */
#define ioctlSET_SSP_FRAME_FORMAT			1000
    
#endif /* FREERTOS_BASE_BOARD_TM4C129_H */