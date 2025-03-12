#include "mbed.h"
#include "microwave_system.h"


//=====[Global Variables]======================================================
static int cookingTime = 0;
static int remainingTime = 0;
bool cookingDone = false;


//=====[Function Implementations]=============================================

void microwaveSystemInit() {
    displayInit();
    matrixKeypadInit(10);
    startButtonInit();
    switchInit();
    sirenInit();
    motorControlInit();
}

void microwaveSystemRun() {
    char key = matrixKeypadUpdate();
    if (key != '\0') {
        if (key >= '0' && key <= '9') {
            cookingTime = (cookingTime * 10) + (key - '0');
            displayCharPositionWrite(7, 1);
            displayStringWrite("Time: ");
            char timeBuffer[6];
            snprintf(timeBuffer, sizeof(timeBuffer), "%02d:%02d", cookingTime / 60, cookingTime % 60);
            displayStringWrite(timeBuffer);
        }
    }
    
    startButtonUpdate();
    if (startButtonRead() == true && isDoorClosed()) {
        microwaveStartCooking(cookingTime);
    } else if (startButtonRead() == true && isDoorOpen()) {
        displayCharPositionWrite(0, 1);
        displayStringWrite("Close Door");
    }
}

void microwaveStartCooking(int cookingTimeInSeconds) {
    cookingTime = cookingTimeInSeconds;
    remainingTime = cookingTimeInSeconds;
    cookingDone = false;
    
    displayStringWrite("Cooking");
    displayCharPositionWrite(0, 1);
    displayStringWrite("Time: ");
    displayCharPositionWrite(7, 1);
    displayStringWrite("00:00");
    
    motorDirectionWrite(COOKING);
    
    while (remainingTime > 0) {
        remainingTime--;
        
        int minutes = remainingTime / 60;
        int seconds = remainingTime - (minutes * 60);        
        char timeBuffer[6];
        snprintf(timeBuffer, sizeof(timeBuffer), "%02d:%02d", minutes, seconds);
        
        displayCharPositionWrite(7, 1);
        displayStringWrite(timeBuffer);
        
        
        if (isDoorOpen()) {
            motorDirectionWrite(PAUSED);
            displayCharPositionWrite(0, 1);
            displayStringWrite("Door Open");
            sirenStateWrite(true);
            break;
        }
    }

    if (remainingTime == 0) {
        cookingDone = true;
        displayCharPositionWrite(0, 1);
        displayStringWrite("Cooking Done");
        sirenUpdate(0);
        sirenStateWrite(false);
    }
    
    motorDirectionWrite(PAUSED);
    
    sirenUpdate(0);
    displayCharPositionWrite(0, 1);
    displayStringWrite("Cooking Done");
}



