#include "header/rte.h"
#include "uart.h"
#include "../../Mcal/fsl_lpuart.h"

 void setFrameType(const uint8_t type)
{
//	PRINTF("%s %d\n", __func__,type);
	frameType = type;
}

 void setBLEStatus(const uint8_t status)
{
//	PRINTF("%s\n", __func__);
	BLEStatus = status;
}

 void setPhnStatus(const uint8_t uartBuffer[])
{
//	PRINTF("%s\n", __func__);
	if(uartBuffer[0] == PHONE_STATUS_LEN)
	{
		phnSts.signalStrenght = uartBuffer[1];
		phnSts.batterylevel = uartBuffer[2];
		phnSts.hour = uartBuffer[3];
		phnSts.min = uartBuffer[4];
		phnSts.sec = uartBuffer[5];
		memcpy(phnSts.Mer, uartBuffer+6, 2);
	}
	else
	{
		//invalid len
	}
}

 void setNavDetails(const uint8_t uartBuffer[])
{
//	PRINTF("%s\n", __func__);
	if(uartBuffer[0] == NAV_DETAILS_LEN)
	{
		navDtls.destLen = uartBuffer[1];
		if(navDtls.destLen != 0) {
			memcpy(navDtls.destination, uartBuffer+2, navDtls.destLen);
		} else {
			memset(navDtls.destination, 0, sizeof(navDtls.destination));
		}

		navDtls.ttLen = uartBuffer[17];
		if(navDtls.ttLen != 0) {
			memcpy(navDtls.travelTime, uartBuffer+18, navDtls.ttLen);
		} else {
			memset(navDtls.travelTime, 0, sizeof(navDtls.travelTime));
		}

		navDtls.etaLen = uartBuffer[33];
		if(navDtls.etaLen != 0) {
			memcpy(navDtls.ETA, uartBuffer+34, navDtls.etaLen);
		} else {
			memset(navDtls.ETA, 0, sizeof(navDtls.ETA));
		}

		navDtls.ddLen = uartBuffer[44];
		if(navDtls.ddLen != 0) {
			memcpy(navDtls.dirDist, uartBuffer+45, navDtls.ddLen);
		} else {
			memset(navDtls.dirDist, 0, sizeof(navDtls.dirDist));
		}

		navDtls.dirLen = uartBuffer[55];
		if(navDtls.dirLen != 0) {
			memcpy(navDtls.dir, uartBuffer+56, navDtls.dirLen);
		} else {
			memset(navDtls.dir, 0, sizeof(navDtls.dir));
		}

		navDtls.iconIdx = uartBuffer[86];
	}
	else
	{
		//invalid len
	}
}

 void setincCallFrame(const uint8_t uartBuffer[])
{
//	PRINTF("%s\n", __func__);
	 LPUART_WriteBlocking(BLE_LPUART, "ABCD", 4);
	if(uartBuffer[0] == INC_CALL_LEN)
	{
		LPUART_WriteBlocking(BLE_LPUART, "EFGH", 4);
		incCallFrm.nameLen = uartBuffer[1];
		if(incCallFrm.nameLen != 0) {
			memcpy(incCallFrm.name, uartBuffer+2, incCallFrm.nameLen);
		} else {
			memset(incCallFrm.name, 0, sizeof(incCallFrm.name));
		}

		incCallFrm.numberLen = uartBuffer[32];
		if(incCallFrm.numberLen != 0) {
			memcpy(incCallFrm.number, uartBuffer+33, incCallFrm.numberLen);
		} else {
			memset(incCallFrm.number, 0, sizeof(incCallFrm.number));
		}
	}
	else
	{
		//invalid len
	}
}

 void setOngCallFrame(const uint8_t uartBuffer[])
{
//	PRINTF("%s\n", __func__);
	if(uartBuffer[0] == ONG_CALL_LEN)
	{

		ongCallFrm.nameLen = uartBuffer[1];
		if(ongCallFrm.nameLen != 0) {
			memcpy(ongCallFrm.name, uartBuffer+2, ongCallFrm.nameLen);
		} else {
			memset(ongCallFrm.name, 0, sizeof(ongCallFrm.name));
		}

		ongCallFrm.numberLen = uartBuffer[32];
		if(ongCallFrm.numberLen != 0) {
			memcpy(ongCallFrm.number, uartBuffer+33, ongCallFrm.numberLen);
		} else {
			memset(ongCallFrm.number, 0, sizeof(ongCallFrm.number));
		}
	}
	else
	{
		//invalid len
	}
}

 void setCallEnd(const uint8_t status)
{
//	PRINTF("%s\n", __func__);
	callEndStatus = status;
}

 void setMissedCallNotify(const uint8_t status)
{
//	PRINTF("%s\n", __func__);
	setmissedCallNotify = status;
}

 void resetMissedCallNotify(const uint8_t status)
{
//	PRINTF("%s\n", __func__);
	resetMisCallNotify = status;
}

 void resetNavNotify(const uint8_t status)
{
//	PRINTF("%s\n", __func__);
	removeNavNotify = status;
}
