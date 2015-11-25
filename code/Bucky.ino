
////////////////////////////////////////////////////
// FIRST PROOF OF CONCEPT
////////////////////////////////////////////////////

#include <Servo.h>
#include "bucky.h"

#define SEVO_PIN_1 9
#define SEVO_PIN_2 10
#define SEVO_PIN_3 11
#define N_SERVOS 3

Servo Servo[N_SERVOS];

class Bucky {
public:
    void jump (int t) {
        Servo[0].write(high_lim);
        Servo[1].write(high_lim);
        Servo[2].write(high_lim);
        delay(100);

        Servo[0].write(low_lim);
        Servo[1].write(low_lim);
        Servo[2].write(low_lim);
        delay(t);
    }
    void flex(int t) {
        for (int i = low_lim; i < high_lim; i++) {
            Servo[0].write(i);
            Servo[1].write(i);
            Servo[2].write(i);
            delay(t);
        }
        for (int i = high_lim; i >= low_lim; i--) {
            Servo[0].write(i);
            Servo[1].write(i);
            Servo[2].write(i);
            delay(t);
        }
    }

private:
    const int low_lim = 110;
    const int high_lim = 179;
};

Bucky bucky;

void setup()
{
    Serial.begin(9600);

    Servo[0].attach(SEVO_PIN_1);
    Servo[1].attach(SEVO_PIN_2);
    Servo[2].attach(SEVO_PIN_3);
}

void loop()
{
    bucky.jump(1000);
}
