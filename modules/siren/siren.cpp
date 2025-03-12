//=====[Libraries]=============================================================


#include "mbed.h"
#include "arm_book_lib.h"


#include "siren.h"
#include "microwave_system.h"
#include "switch.h"



//=====[Declaration of private defines]========================================


//=====[Declaration of private data types]=====================================


#define SYSTEM_TIME_INCREMENT_MS 10; // need to figure this out


//=====[Declaration and initialization of public global objects]===============


DigitalOut sirenPin(PE_10);


//=====[Declaration of external public global variables]=======================


//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============


static bool sirenState = OFF;


//=====[Declarations (prototypes) of private functions]========================


//=====[Implementations of public functions]===================================


void sirenInit()
{
    sirenPin = ON;
}


bool sirenStateRead()
{
    return sirenState;
}


void sirenStateWrite( bool state )
{
    sirenState = state;
}


void sirenUpdate( int strobeTime )
{
    static int accumulatedTimeAlarm = 0;
    accumulatedTimeAlarm = accumulatedTimeAlarm + SYSTEM_TIME_INCREMENT_MS;
   
    if(cookingDone = true && isDoorClosed) {
        sirenPin = OFF;
    }
    else {
        sirenPin = ON;
    }
}




//=====[Implementations of private functions]==================================
