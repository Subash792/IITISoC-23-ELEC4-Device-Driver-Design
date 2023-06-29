#include "joystick.h"

// Constructor
Joystick::Joystick(){

}

// initializes the joystick object and checks if the device is available on the bus or not.
bool Joystick::init(uint8_t addr){
    devaddr = addr;
    i2c_init(freq_250K);

    uint8_t error_code = i2c_start();
    if(error_code != SUCCESS)
        return false;

    error_code = i2c_write_sla((addr<<1)| I2C_WRITE_FLAG);
    i2c_stop();
    if(error_code != SUCCESS)
        return false;
    
    return true; // all setup;
};

// reads an 8 bit register on the slave device using i2c
uint8_t Joystick::readRegister(uint8_t addr){
    uint8_t value;
    uint8_t address = addr;
    uint8_t error_code = i2c_master_transmit(devaddr, &address, (uint8_t)1);
    if(error_code!= SUCCESS)
        return 0;
    
    error_code = i2c_master_receive(devaddr,&value, (uint8_t)1);
    if(error_code!= SUCCESS)
        return 0;
    else return value;
}

// returns the current x position of the joystick
// it is a number between 0 and 1023
uint16_t Joystick::readX()
{
  uint16_t X_MSB = readRegister(JOYSTICK_X_MSB);
  uint16_t X_LSB = readRegister(JOYSTICK_X_LSB);
  return ((X_MSB<<8) | X_LSB)>>6;
}

// returns the current y position of the joystick
// it is a number between 0 and 1023
uint16_t Joystick::readY()
{
  uint16_t Y_MSB = readRegister(JOYSTICK_X_MSB);
  uint16_t Y_LSB = readRegister(JOYSTICK_X_LSB);
  return ((Y_MSB<<8) | Y_LSB)>>6;
}

// returns the current state of button
// i.e. 0 if it is being pressed and 1 otherwise
uint8_t Joystick::buttonstate()
{
   uint8_t button = readRegister(JOYSTICK_BUTTON);
   return(button);
}

