/*
    QuatroPortA100.h - library to control motors with QuatroPortA100 shield
    Created by Igor Tsiva 2021
    Released into the public domain.
*/

#ifndef QuatroPortA100_h
#define QuatroPortA100_h

#include "Arduino.h"

class QuatroPortA100 {
    public:
        QuatroPortA100(
            short m1In,
            short m1Dir,
            short m2In,
            short m2Dir,
            bool invertPower,
            bool invertDir
        );
        void moveForward(int m1Power, int m2Power);
        void moveBackward(int m1Power, int m2Power);
        void hold();
        void test();
    private:
        short _m1In;
        short _m1Dir;
        short _m2In;
        short _m2Dir;
        bool _invertPower;
        bool _invertDir;
};

#endif
