#include "Arduino.h"
#include "QuatroPortA100.h"

#define FORWARD HIGH
#define BACKWARD LOW

QuatroPortA100::QuatroPortA100(
    short m1In,
    short m1Dir,
    short m2In,
    short m2Dir,
    bool invertPower,
    bool invertDir
) {
    _m1In = m1In;
    _m1Dir = m1Dir;
    _m2In = m2In;
    _m2Dir = m2Dir;
    _invertPower = invertPower;
    _invertDir = invertDir;
}

void QuatroPortA100::moveForward(int m1Power, int m2Power) {
    int m1ResultPower = _invertPower ? 255 - m1Power : m1Power;
    int m2ResultPower = _invertPower ? 255 - m2Power : m2Power;
    short m1ResultDir = _invertDir ? BACKWARD : FORWARD;
    short m2ResultDir = _invertDir ? BACKWARD : FORWARD;

    analogWrite(_m1In, m1ResultPower);
    digitalWrite(_m1Dir, m1ResultDir);
    analogWrite(_m2In, m2ResultPower);
    digitalWrite(_m2Dir, m2ResultDir);
}

void QuatroPortA100::moveBackward(int m1Power, int m2Power) {
    int m1ResultPower = _invertPower ? m1Power : 255 - m1Power;
    int m2ResultPower = _invertPower ? m2Power : 255 - m2Power;
    short m1ResultDir = _invertDir ? FORWARD : BACKWARD;
    short m2ResultDir = _invertDir ? FORWARD : BACKWARD;

    m2ResultPower = 255;
    m2ResultDir = LOW;

    analogWrite(_m1In, m1ResultPower);
    digitalWrite(_m1Dir, m1ResultDir);
    analogWrite(_m2In, m2ResultPower);
    digitalWrite(_m2Dir, m2ResultDir);
}

void QuatroPortA100::hold() {
  analogWrite(_m1In, 0);
  digitalWrite(_m1Dir, BACKWARD);
  analogWrite(_m2In, 0);
  digitalWrite(_m2Dir, BACKWARD);
}

void QuatroPortA100::test() {
    moveForward(200, 200);
    delay(5000);
    hold();
    delay(2000);
    moveBackward(200, 200);
    delay(5000);
    hold();
    delay(2000);
}
