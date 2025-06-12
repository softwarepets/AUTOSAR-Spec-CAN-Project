/*
 * uart.h
 *
 *  Created on: 03-Jul-2024
 *      Author: petla
 */

#ifndef APPLICATION_UART_UART_H_
#define APPLICATION_UART_UART_H_

#define BLE_LPUART            LPUART1
#define BLE_LPUART_CLK_FREQ   BOARD_DebugConsoleSrcFreq()
#define BLE_LPUART_IRQn       LPUART1_IRQn
#define BLE_LPUART_IRQHandler LPUART1_IRQHandler


extern void UART_TaskCreate();
void UART_AppTask();
#endif /* APPLICATION_UART_UART_H_ */
