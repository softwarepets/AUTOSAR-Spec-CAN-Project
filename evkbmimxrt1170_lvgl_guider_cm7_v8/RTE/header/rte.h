#include <stdint.h>


enum frameTypes {
	BLE_STATUS = 1,
	PHONE_STATUS,
	NAV_DETAILS,
	INC_CALL,
	ONG_CALL,
	CALL_END,
	MIS_CALL_NTFY,
	RM_MIS_CALL_NTFY,
	RM_NAV_DETAILS
};

typedef struct {
	uint8_t signalStrenght;
	uint8_t batterylevel;
	uint8_t hour;
	uint8_t min;
	uint8_t sec;
	uint8_t Mer[2];
}phoneStatus;

typedef struct {
	uint8_t destLen;
	uint8_t destination[15];
	uint8_t ttLen;
	uint8_t travelTime[15];
	uint8_t etaLen;
	uint8_t ETA[10];
	uint8_t ddLen;
	uint8_t dirDist[10];
	uint8_t dirLen;
	uint8_t dir[30];
	uint8_t iconIdx;
}navigationDetails;

typedef struct {
	uint8_t nameLen;
	uint8_t name[30];
	uint8_t numberLen;
	uint8_t number[18];
}callFrame;

extern phoneStatus phnSts;
extern navigationDetails navDtls;
extern callFrame incCallFrm, ongCallFrm;
extern uint8_t callEndStatus;
extern uint8_t BLEStatus;
extern uint8_t uartDatareceived;
extern uint8_t frameType;
extern uint8_t setmissedCallNotify;
extern uint8_t resetMisCallNotify;
extern uint8_t removeNavNotify;
 void setFrameType(const uint8_t type);
 void setPhnStatus(const uint8_t uartBuffer[]);
 void setNavDetails(const uint8_t uartBuffer[]);
 void setincCallFrame(const uint8_t uartBuffer[]);
 void setBLEStatus(const uint8_t status);
 void setOngCallFrame(const uint8_t uartBuffer[]);
 void setCallEnd(const uint8_t status);
 void setMissedCallNotify(const uint8_t status);
 void resetMissedCallNotify(const uint8_t status);
 void resetNavNotify(const uint8_t status);



#define BLE_STATUS_LEN		1
#define PHONE_STATUS_LEN	7
#define NAV_DETAILS_LEN		86
#define INC_CALL_LEN		50
#define ONG_CALL_LEN		50
