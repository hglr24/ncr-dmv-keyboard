#include "Arduino.h"
#include "KeyboardQueue.h"
#include "NcrKeyboardInterface.h"

#define PIN_TX_MINUS A0
#define PIN_TX_PLUS A1
#define PIN_RX_PLUS A2

#define SERIAL_BAUD_SPEED 115200
// #define DEBUG_MODE		1
// DEBUG being enabled may cause missed inputs

KeyboardQueue queue;
NcrKeyboardInterface ncrInt(&queue);

void setup()
{
	Serial.begin(SERIAL_BAUD_SPEED);
}

void loop()
{
	while (Serial.available())
	{
		int key = Serial.read();
#ifdef DEBUG_MODE
		uint8_t convkey = ncrInt.Push(key);
		Serial.print("[ ");
		Serial.print(key);
		Serial.print(" --> ");
		Serial.print(convkey);
		Serial.println(" ]");
#else
		ncrInt.Push(key);
#endif
	}
#ifdef DEBUG_MODE
	if (queue.HasKeypress()) {
		uint8_t key = queue.Pop();
		Serial.print("<<  ");
		Serial.println(key);
	}
#endif
}
