/*
 Name:		RAVPO_RA.ino
 Created:	2019-12-02 오후 12:26:29
 Author:	user
*/
// the setup function runs once when you press reset or power the board

#include "RAVPO.h"
INITS initmode;
MOVING moving;
void setup() {
	initmode.j1E = true;
	initmode.j2E = true;
	initmode.roE = true;

	initmode.RAVPO_init(initmode, 1000);
}

// the loop function runs over and over again until power down or reset
void loop() {
	moving.MOVING_XY(500, 500);
	delay(1000);
	moving.MOVING_XY(0, 0);
	delay(1000);
}


SIGNAL(TIMER1_COMPA_vect) {
	moving.RUNNING_STEPMOTOR(MOVING_SELECT_X);
}


SIGNAL(TIMER3_COMPA_vect) {
	moving.RUNNING_STEPMOTOR(MOVING_SELECT_Y);
}