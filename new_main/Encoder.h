#ifndef ROBOT_ENCODER_H
#define ROBOT_ENCODER_H

class Encoder{
private:
    int rpm;
    int _enPin;
    static int _counter;
    int _previousMillis;
    int taskID;
public:
    Encoder();
    Encoder(int enPin);

    static void countPulse();
    int getSpeed();
};

#endif //ROBOT_ENCODER_H

