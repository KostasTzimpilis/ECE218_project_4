//=====[#include guards - begin]===============================================


#ifndef _MOTOR_H_
#define _MOTOR_H_


//=====[Declaration of public defines]=========================================


//=====[Declaration of public data types]======================================


typedef enum {
    COOKING,
    PAUSED
} microwaveDirection_t;


//=====[Declarations (prototypes) of public functions]=========================


void motorControlInit();
void motorDirectionWrite( microwaveDirection_t direction );


microwaveDirection_t motorDirectionRead();


void motorControlUpdate();


//=====[#include guards - end]=================================================


#endif // _MOTOR_H_
