#include "Speed.h"
#include "Encoder.h"
#include "Arduino.h"
#include "Wheels.h"

Speed::Speed() {
    _FL = Encoder();
    _FR = Encoder();
    _BL = Encoder();
    _BR = Encoder();
}

void Speed::setFL(int enPin) {
    _FL = Encoder(enPin);
}

void Speed::setFR(int enPin) {
    _FR = Encoder(enPin);
}

void Speed::setBL(int enPin) {
    _BL = Encoder(enPin);
}

void Speed::setBR(int enPin) {
    _BR = Encoder(enPin);
}

void Speed::updateFL(Wheels myWheels, int set_speed, int alpha) {
    int real_speed = _FL.getSpeed();

    if(real_speed > set_speed){
        myWheels.FL.updateSpeed(-alpha);
    }
}
