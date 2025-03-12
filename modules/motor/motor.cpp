//=====[Libraries]=============================================================


#include "mbed.h"
#include "arm_book_lib.h"


#include "motor.h"


//=====[Declaration of private defines]========================================


#define MOTOR_UPDATE_TIME 9


//=====[Declaration of private data types]=====================================


//=====[Declaration and initialization of public global objects]===============


DigitalInOut motorM1Pin(PF_2);
DigitalInOut motorM2Pin(PE_3);


//=====[Declaration of external public global variables]=======================


//=====[Declaration and initialization of public global variables]=============


microwaveDirection_t microwaveDirection;
microwaveDirection_t microwaveState;


//=====[Declaration and initialization of private global variables]============


//=====[Declarations (prototypes) of private functions]========================


//=====[Implementations of public functions]===================================


void motorControlInit()
{
    motorM1Pin.mode(OpenDrain);
    motorM2Pin.mode(OpenDrain);
   
    motorM1Pin.input();
    motorM2Pin.input();


   
    microwaveState = PAUSED;
}


microwaveDirection_t motorDirectionRead()
{
    return microwaveDirection;
}


void motorDirectionWrite( microwaveDirection_t direction )
{
    microwaveDirection = direction;
}


void motorControlUpdate()
{
    static int motorUpdateCounter = 0;
   
    motorUpdateCounter++;
   
    if ( motorUpdateCounter > MOTOR_UPDATE_TIME ) {
       
        motorUpdateCounter = 0;
       
        switch ( microwaveState ) {
            case COOKING:
                if ( microwaveDirection == PAUSED ) {
                    motorM1Pin.input();
                    motorM2Pin.input();
                    microwaveState = PAUSED;
                }
            break;
   
            case PAUSED:
            default:
                if ( microwaveDirection == COOKING ) {
                    motorM2Pin.input();
                    motorM1Pin.output();
                    microwaveState = COOKING;
                }    
            break;
        }
    }              
}


//=====[Implementations of private functions]==================================
