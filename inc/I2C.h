#ifndef _I2C_H
#define _I2C_H

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef enum {
	freq_100K,
    freq_250K,
    freq_400K
} freq_mode;

#define SUCCESS 0
#define I2C_READ_FLAG 1
#define I2C_WRITE_FLAG 0


// These functions will be used to write the below 3 funcrions

uint8_t i2c_start(void); /* Send START condition */
uint8_t i2c_stop(void);  /* Send STOP condition */
uint8_t i2c_write_sla(uint8_t addr); /* Transmit slave address with read/write flag */
uint8_t i2c_write(uint8_t addr); /* Transmit 1 byte*/
uint8_t i2c_read(bool read_ack); /* Reads 1 byte */


// These are the main apis of the i2c library
uint8_t i2c_init(freq_mode freq);  
/*
Sets up the i2c peripheral
i.e. Sets up the SCL(clock) speed and configures the default SDA and SCL pins    
*/

uint8_t i2c_master_transmit(uint8_t slave_addr, uint8_t* p_data, uint8_t len); 
/*
Transmits the data of specified length (len) from the data buffer(*pdata) to the slave with address (slave_addr)
*/

uint8_t i2c_master_receive(uint8_t slave_addr, uint8_t* p_data, uint8_t len);
/*
Recieves the data of specified length (len) into the data buffer(*pdata) to the slave with address (slave_addr)
*/

#endif