# IITISoC-23-ELEC4-Device-Driver-Design

# Description:
This is a device driver for Spakfun Qwicc Joystick for an stm/avr microcontroller.
Links to the product page and hardware details:
1. [Sparkfun Qwicc Joystick Product Page](https://www.sparkfun.com/products/15168?_ga=2.249157377.785339789.1685806289-1287641380.1685806289)
2. [Schematic File](https://cdn.sparkfun.com/assets/7/4/a/6/8/Qwiic_Joystick.pdf)
3. [Hookup guide](https://learn.sparkfun.com/tutorials/qwiic-joystick-hookup-guide?_ga=2.64988079.1024945227.1687890671-1287641380.1685806289)
4. [ATtiny 85 Firmware repo](https://github.com/sparkfun/Qwiic_Joystick/tree/master/Firmware/ATtiny85%20Firmware)

# File Structure: 
1. Include Folder (inc) : Has the necessary header files : joystick.h and I2C.h
2. Source Folder (src)  : Has the corresponding src files: joystick.cpp
3. Readme.md            : Description about project

# APIs provided:
1. Joystick class
2. .init() : method to initialise the joystick object and check if a joystick board is available on the specified address on the bus.
3. .readX(): reads the current X position of the joystick. Returns a value between 0 to 1023.
4. .readY(): reads the current Y position of the joystick. Returns a value between 0 and 1023.
5. .buttonstate(): reads the current button state.

Note:
The I2C driver is still under development. The I2C functions have been declared but have to be implemented.