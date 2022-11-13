#include "Wheels.h"

class LineFollow{
private:
    int IR1, IR2, IR3, IR4, IR5;
    int _s1, _s2, _s3, _s4, _s5;

public:
    LineFollow();
    LineFollow(int IR1, int IR2, int IR3, int IR4, int IR5);

    int linePos();
    int PID();
    void follow(Wheels myWheels, int kp, int speed);
    bool inLine();

};