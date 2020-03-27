#pragma once

#include "Arduino.h"

#define PIN_SW0 0
#define PIN_SW1 1
#define PIN_SW2 4
#define PIN_SW3 12
#define PIN_SW4 6
#define PIN_SW5 SCK
#define PIN_SW6 MOSI
#define PIN_SW7 MISO
#define PIN_SW8 8
#define PIN_SW9 9
#define PIN_SW10 10
#define PIN_SW11 11
#define PIN_SW12 A5
#define PIN_SW13 A4
#define PIN_SW14 A3
#define PIN_SW15 A2

#define PIN_LIGHT_SENSOR A1

#include <Wire.h>

class SwitchManager {
private:
	uint8_t pinmap[16];

public:
	SwitchManager() {
		pinmap = { \
		PIN_SW0, PIN_SW1, PIN_SW2, PIN_SW3, \
		PIN_SW4, PIN_SW5, PIN_SW6, PIN_SW7, \
		PIN_SW8, PIN_SW9, PIN_SW10, PIN_SW11, \
		PIN_SW12, PIN_SW13, PIN_SW14, PIN_SW15 \
		};
	}
} SwitchManager;

// https://www.nxp.com/docs/en/data-sheet/PCA9635.pdf

class LEDController {
private:
	uint16_t brightness[16] = { 0 };
	uint8_t addr;

public:
	LEDController() {

	}

	void setAddr(uint8_t addr) {
		this->addr = addr;
	}

	bool init() {

		return true;
	}

	void set(uint8_t idx, uint16_t brightness) {
		this->brightness[idx] = brightness;
	}

	void get(uint8_t idx) {
		return brightness[idx];
	}

	void update() {

	}

} LED;