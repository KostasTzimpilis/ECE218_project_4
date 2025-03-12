#ifndef _MICROWAVE_SYSTEM_H_
#define _MICROWAVE_SYSTEM_H_

#include "display.h"
#include "matrix_keypad.h"
#include "start_button.h"
#include "switch.h"
#include "siren.h"
#include "motor.h"

extern bool cookingDone;

void microwaveSystemInit();
void microwaveSystemRun();
void microwaveStartCooking(int cookingTime);

#endif // _MICROWAVE_SYSTEM_H_
