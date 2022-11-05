#ifndef ROBOT_ENCODER_H
#define ROBOT_ENCODER_H

class Encoder{
private:
    int rpm;
    int _enPin;
    int _counter;
    int _previousMillis;
public:
    Encoder();
    Encoder(int enPin);

    void countPulse();
    int getSpeed();
};

#endif //ROBOT_ENCODER_H

