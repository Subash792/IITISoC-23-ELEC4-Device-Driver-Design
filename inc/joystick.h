#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include "I2C.h"

// To do:
// create a class to instatiate a joystick in code
// what are the methods associated with an object of this type?
// 1. A method to setup the i2c communication with device
// 2. Methods to get x and y coordinates of the joystick
// 3. Methods to recognize gestures
// 4. I2C driver for the microcontroller chosen

#define JOYSTICK_DEFAULT_ADDR 0x20

// 
enum joystickRegisters {
  JOYSTICK_X_MSB = 0X03, // 0x03
  JOYSTICK_X_LSB,       // 0x04
  JOYSTICK_Y_MSB,       // 0x05
  JOYSTICK_Y_LSB,       // 0x06
  JOYSTICK_BUTTON,      // 0x07
};

class Joystick{
    public:
    Joystick();
    bool init(uint8_t addr = JOYSTICK_DEFAULT_ADDR); // sets and checks if a slave is present on the given address

    uint16_t readX(); // gets the x co-ordinate of the joystick
    uint16_t readY(); // gets the y co-ordinate of the joystick
    uint8_t buttonstate(); // gets the state of the button on the joystick (pressed or not pressed)

    private:
    uint8_t devaddr; // joystick slave address
    uint8_t readRegister(uint8_t addr);
};

#endif