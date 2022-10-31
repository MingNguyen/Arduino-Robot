#include "Wheels.h"
#include "Arduino.h"

Wheels::Wheels(){
    FR = Motor();
    FL = Motor();
    BR = Motor();
    BL = Motor();
};
void Wheels::updateFR(int analogPin, int digitalPin, int forward) FR