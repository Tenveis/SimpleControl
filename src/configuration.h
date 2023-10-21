#ifndef SRC_CONFIGURATION_H
#define SRC_CONFIGURATION_H


/*
add configuration parameters such as :
    turn on/off PWM
    number of motors
    availaibility of encoder
    debug parameter
    ...many more
*/

#define SET                 (1)
#define RESET               (0)
#define NEGATE              (-1)

/* un-comment the following to start debugging.*/
// #define DEBUG


/* change value to "RESET" the following to turn off pwm.*/
#define PWM         (SET)

/* comment the following to reverse the direction of forward motion.*/
#define REVERSE_FORWARD_DIRECTION







#endif