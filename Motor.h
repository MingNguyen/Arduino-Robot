#ifndef Motor_h
#define Motor_h
#define MAX_SPEED 255
/**
 * Class Motor is in charge of Motor function
 * 
 * 
*/
class Motor
{
private:
    int analogPin;
    int digitalPin;
    bool IsAnalogForward;
public:
    Motor();
    /**
     * Constructor:
     * @param analogPin: the analog pin of arduino connecting to the driver
     * @param analogPin: the digital pin of arduino connecting to the driver
     * @param forwardPin: Among 2 above pin, which one cause the moving forward if it is high
    */
    Motor(int analogPin, int digitalPin, int forwardPin);

    /**
     * The function to demmand the rotation of the motor
     * @param value: the analog value represent the speed. In the range 0-255
     * @param dir: the direction of the motor
    */
    void speedControl(int value,bool dir);
};

#endif
