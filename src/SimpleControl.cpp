#include "SimpleControl.h"

SimpleControl::SimpleControl(uint8_t mSignalPin1, uint8_t mSignalPin2)
{
#undef PWM
#define PWM (RESET)

    mSignalPin1_ = mSignalPin1;
    mSignalPin2_ = mSignalPin2;
    pinMode(mSignalPin1_, OUTPUT);
    pinMode(mSignalPin2_, OUTPUT);
}

SimpleControl::SimpleControl(uint8_t mSignalPin1, uint8_t mSignalPin2, uint8_t mPwmPin)
{
#undef PWM
#define PWM (SET)
    mSignalPin1_ = mSignalPin1;
    mSignalPin2_ = mSignalPin2;
    mPwmPin_ = mPwmPin;

    pinMode(mSignalPin1_, OUTPUT);
    pinMode(mSignalPin2_, OUTPUT);
    pinMode(mPwmPin_, OUTPUT);
}

SimpleControl::~SimpleControl()
{
    clear();
}

void SimpleControl::motorOutput(uint8_t motorDir, int8_t pwmVal)
{
    switch (motorDir)
    {
    case MOTION::FORWARD:
#if PWM
        moveForward(pwmVal);
#else
        moveForward();
#endif
        break;

    case MOTION::BACKWARD:
#if PWM
        moveBackward(pwmVal);
#else
        moveBackward();
#endif
        break;

    case MOTION::STOP:
        stop();
        break;

    case MOTION::CLEAR:
        clear();
        break;

    default:
        clear();
        break;
    }
}

#if PWM
void SimpleControl::moveForward(int8_t pwmVal)
#else
void SimpleControl::moveForward()
#endif
{
#ifdef REVERSE_FORWARD_DIRECTION
    digitalWrite(mSignalPin1_, HIGH);
    digitalWrite(mSignalPin2_, LOW);
#endif

#ifndef REVERSE_FORWARD_DIRECTION
    digitalWrite(mSignalPin1_, LOW);
    digitalWrite(mSignalPin2_, HIGH);
#endif

#if PWM
    digitalWrite(mPwmPin_, pwmVal);
#endif
}

#if PWM
void SimpleControl::moveBackward(int8_t pwmVal)
#else
void SimpleControl::moveBackward()
#endif
{
#ifdef REVERSE_FORWARD_DIRECTION
    digitalWrite(mSignalPin1_, LOW);
    digitalWrite(mSignalPin2_, HIGH);
#endif

#ifndef REVERSE_FORWARD_DIRECTION
    digitalWrite(mSignalPin1_, HIGH);
    digitalWrite(mSignalPin2_, LOW);
#endif

#ifdef PWM
    digitalWrite(mPwmPin_, pwmVal);
#endif
}

void SimpleControl::stop()
{
    digitalWrite(mSignalPin1_, HIGH);
    digitalWrite(mSignalPin2_, HIGH);
}

void SimpleControl::clear()
{
    digitalWrite(mSignalPin1_, LOW);
    digitalWrite(mSignalPin2_, LOW);
}