/*
 * uart.c
 *
 *  Created on: 03-Jul-2024
 *      Author: petla
 */
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "board.h"
#include "uart.h"
#include "rte.h"
#include "../../Mcal/fsl_lpuart.h"
#include "../../Services/freertos-kernel/include/FreeRTOS.h"
#include "../../Services/freertos-kernel/include/task.h"



static uint16_t rxUartIndex; /* Index of the data to send out. */
#define BLE_UART_BUFFER_SIZE 200

static uint8_t BLEUartBuffer[BLE_UART_BUFFER_SIZE];

phoneStatus phnSts = {0};
navigationDetails navDtls = {0};
callFrame incCallFrm = {0}, ongCallFrm = {0};
uint8_t callEndStatus = 0;
uint8_t BLEStatus = 0;
uint8_t setmissedCallNotify = 0;
uint8_t resetMisCallNotify = 0;
uint8_t removeNavNotify = 0;
uint8_t uartDatareceived = 0;
uint8_t frameType = 0;

uint8_t flag1 = 0;
uint8_t flag2 = 0;

static void parseUartData(const uint8_t uartBuffer[], uint16_t rxLenght)
{
//	PRINTF("%s\n", __func__);
	if(uartBuffer[0] == 0xE6)
	{
		if(uartBuffer[1] == BLE_STATUS)
		{
			setFrameType(uartBuffer[1]);
			if(uartBuffer[2] == BLE_STATUS_LEN)
			{
				setBLEStatus(uartBuffer[3]);
				uartDatareceived = 1;
			}
			else
			{
				setFrameType(0);
				//invalid len
			}
		}
		else if(uartBuffer[1] == PHONE_STATUS)
		{
			setFrameType(uartBuffer[1]);
			if(uartBuffer[2] == PHONE_STATUS_LEN)
			{
				setPhnStatus(uartBuffer+2);
				uartDatareceived = 1;
			}
			else
			{
				setFrameType(0);
				//invalid len
			}
		}
		else if(uartBuffer[1] == NAV_DETAILS)
		{
			setFrameType(uartBuffer[1]);
			if(uartBuffer[2] == NAV_DETAILS_LEN)
			{
				setNavDetails(uartBuffer+2);
				resetNavNotify(0);
				uartDatareceived = 1;
			}
			else
			{
				setFrameType(0);
				//invalid len
			}
		}
		else if(uartBuffer[1] == INC_CALL)
		{
			resetNavNotify(1);
			setFrameType(uartBuffer[1]);
			if(uartBuffer[2] == INC_CALL_LEN)
			{
				setincCallFrame(uartBuffer+2);
				uartDatareceived = 1;
			}
			else
			{
				setFrameType(0);
				//invalid len
			}
		}
		else if(uartBuffer[1] == ONG_CALL)
		{
			resetNavNotify(1);
			setFrameType(uartBuffer[1]);
			if(uartBuffer[2] == ONG_CALL_LEN)
			{
				setOngCallFrame(uartBuffer+2);
				uartDatareceived = 1;
			}
			else
			{
				setFrameType(0);
				//invalid len
			}
		}
		else if(uartBuffer[1] == CALL_END)
		{
			resetNavNotify(1);
			setFrameType(uartBuffer[1]);
			setCallEnd(1);
			uartDatareceived = 1;
		}
		else if(uartBuffer[1] == MIS_CALL_NTFY)
		{
			setFrameType(uartBuffer[1]);
			setMissedCallNotify(1);
			uartDatareceived = 1;
		}
		else if(uartBuffer[1] == RM_MIS_CALL_NTFY)
		{
			setFrameType(uartBuffer[1]);
			resetMissedCallNotify(1);
			uartDatareceived = 1;
		}
		else if(uartBuffer[1] == RM_NAV_DETAILS)
		{
			setFrameType(uartBuffer[1]);
			resetNavNotify(1);
			uartDatareceived = 1;
		}
		else
		{
			setFrameType(0);
			//invalid frame type
		}
	}
	else
	{
		//invalid data
	}
}

void BLE_LPUART_IRQHandler(void)
{
	uint8_t data;
    /* If new data arrived. */
	flag1 = 1;
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(BLE_LPUART))
    {
        data = LPUART_ReadByte(BLE_LPUART);
        if(data == 0xE6) {
//        	PRINTF("data receive begin\n");
        	rxUartIndex = 0;
        }
        BLEUartBuffer[rxUartIndex] = data;
        rxUartIndex++;
        if(data == 0xEB) {
        	flag2 = 98;
//        	PRINTF("data received \n");
        	parseUartData(BLEUartBuffer, rxUartIndex);
        	rxUartIndex = 0;
        }
    }
}

void UART_AppTask()
{
	lpuart_config_t config;
    LPUART_GetDefaultConfig(&config);
    config.baudRate_Bps = BOARD_DEBUG_UART_BAUDRATE;
    config.enableTx     = true;
    config.enableRx     = true;

    if(LPUART_Init(BLE_LPUART, &config, BLE_LPUART_CLK_FREQ) != kStatus_Success) {
    	while(1);
    }

    LPUART_EnableInterrupts(BLE_LPUART, kLPUART_RxDataRegFullInterruptEnable);
    EnableIRQ(BLE_LPUART_IRQn);

    for(;;) {
//    	if(flag2==98){
////    		LPUART_WriteBlocking(BLE_LPUART, BLEUartBuffer, rxUartIndex);
//    	}

    }
}


