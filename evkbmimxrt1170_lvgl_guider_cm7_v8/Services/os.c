#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "board.h"
#include "uart.h"
#include "rte.h"
#include "../Services/freertos-kernel/include/FreeRTOS.h"
#include "../Services/freertos-kernel/include/task.h"


void UART_TaskCreate()
{
	BaseType_t status;

	status = xTaskCreate(UART_AppTask, "UART", configMINIMAL_STACK_SIZE + 800, NULL, tskIDLE_PRIORITY + 1, NULL);
	if (pdPASS != status)
	{
		PRINTF("Failed to create uart task");
		while (1)
			;
	}
}
