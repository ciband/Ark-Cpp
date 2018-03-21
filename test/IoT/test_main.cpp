#include <ArduinoUnit.h>

#ifdef UNIT_TEST

void setup() {
    Serial.begin(9600);
	while (!Serial); // for the Arduino Leonardo/Micro only
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop() {
   Test::run();
}

#endif
