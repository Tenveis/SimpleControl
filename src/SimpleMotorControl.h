#ifndef SRC_MOTOR_DRIVER_H
#define SRC_MOTOR_DRIVER_H

// std include
#include <Arduino.h>
#include <stdint.h>

// custom include
#include "configuration.h"

enum MOTION
{
    FORWARD,
    BACKWARD,
    STOP,
    CLEAR
};

class SimpleMotorControl
{
public:
private:
    uint8_t mSignalPin1_;
    uint8_t mSignalPin2_;
    uint8_t mPwmPin_;

#if PWM
    void moveForward(int8_t pwmVal);
    void moveBackward(int8_t pwmVal);
#else
    void moveForward();
    void moveBackward();
#endif

    void stop();
    void clear();

public:
    SimpleMotorControl(uint8_t mSignalPin1, uint8_t mSignalPin2);
    SimpleMotorControl(uint8_t mSignalPin1, uint8_t mSignalPin2, uint8_t mPwmPin);

    ~SimpleMotorControl();

    void motorOutput(uint8_t motorDir, int8_t pwmVal);
};

#endif