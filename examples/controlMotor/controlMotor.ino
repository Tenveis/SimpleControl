#include "SimpleMotorControl.h"

/**
   Refer the "configuration.h" file to make changes according to the system requirements.
*/

/**
   @brief: create an object of SimpleMotorControl
*/

SimpleMotorControl m1(8, 9, 10);

void setup()
{
  m1.motorOutput(MOTION::FORWARD, 190);
  delay(3000);
  m1.motorOutput(MOTION::STOP, 0);
  delay(1000);
  m1.motorOutput(MOTION::BACKWARD, 170);
  delay(3000);
  m1.motorOutput(MOTION::CLEAR, 0);

  // --------------------------------------------------------

  {
    SimpleMotorControl m2(6, 7);

    m2.motorOutput(MOTION::FORWARD, 0);
    delay(3000);
    m2.motorOutput(MOTION::STOP, 0);
    delay(1000);
    m2.motorOutput(MOTION::BACKWARD, 0);
    delay(3000);
    m2.motorOutput(MOTION::CLEAR, 0);
  }
}

void loop()
{

}
