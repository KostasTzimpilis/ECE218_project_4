//=====[Libraries]=============================================================


#include "mbed.h"
#include "arm_book_lib.h"


#include "start_button.h"


//=====[Declaration of private defines]========================================


//=====[Declaration of private data types]=====================================


//=====[Declaration and initialization of public global objects]===============


DigitalIn startButtonPin(D11);


//=====[Declaration of external public global variables]=======================


//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============


static bool buttonState;


//=====[Declarations (prototypes) of private functions]========================


//=====[Implementations of public functions]===================================


void startButtonInit()
{
    buttonState = OFF;      
}


void startButtonUpdate()
{
    if ( startButtonPin == HIGH )
    {
        buttonState = ON;
    }


    else
    {
        buttonState = OFF;
    }
}


bool startButtonRead()
{
    return buttonState;
}


//=====[Implementations of private functions]==================================
