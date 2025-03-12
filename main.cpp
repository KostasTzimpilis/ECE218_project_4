#include "mbed.h"
#include "microwave_system.h"

int main() {
    microwaveSystemInit();
    
    while (true) {
        microwaveSystemRun();
    }
}
