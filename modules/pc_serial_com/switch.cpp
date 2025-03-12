//=====[Libraries]=============================================================
#include "mbed.h"
#include "switch.h"

//=====[Declaration of private global variables]================================

static DigitalIn doorSwitch(D10);

//=====[Implementations of public functions]===================================

void switchInit()
{
}

bool isDoorClosed()
{
    return doorSwitch.read() == 1;
}

bool isDoorOpen()
{
    return doorSwitch.read() == 0;
}
