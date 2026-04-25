#ifndef PCA9685_H
#define PCA9685_H

#ifdef  __cplusplus
extern "C" {
#endif
 

/*********** R E G I S T E R   A D D R E S S E S ******************************/
#define PCA9685_MODE1           0x00    // Mode 1 Register
#define PCA9685_MODE2           0x01    // Mode 2 Register 
#define PCA9685_SUBADR1         0x02    // I2C-bus subaddress 1 
#define PCA9685_SUBADR2         0x03    // I2C-bus subaddress 2 
#define PCA9685_SUBADR3         0x04    // I2C-bus subaddress 3 
#define PCA9685_ALLCALLADR      0x05    // LED All Call I2C-bus address 
#define PCA9685_LED0_ON_L       0x06    // LED0 on tick, low byte
#define PCA9685_LED0_ON_H       0x07    // LED0 on tick, high byte
#define PCA9685_LED0_OFF_L      0x08    // LED0 off tick, low byte 
#define PCA9685_LED0_OFF_H      0x09    // LED0 off tick, high byte 
                                        // etc all 16:  LED15_OFF_H 0x45
#define PCA9685_ALLLED_ON_L     0xFA    // load all the LEDn_ON registers, low 
#define PCA9685_ALLLED_ON_H     0xFB    // load all the LEDn_ON registers, high 
#define PCA9685_ALLLED_OFF_L    0xFC    // load all the LEDn_OFF registers, low 
#define PCA9685_ALLLED_OFF_H    0xFD    // load all the LEDn_OFF registers,high 
#define PCA9685_PRESCALE        0xFE    // Prescaler for PWM output frequency
#define PCA9685_TESTMODE        0xFF    // defines the test mode to be entered 

/*********** M O D E 1   B I T S   D E F I N E S ******************************/
#define MODE1_ALLCAL    0x01    // respond to LED All Call I2C-bus address 
#define MODE1_SUB3      0x02    // respond to I2C-bus subaddress 3
#define MODE1_SUB2      0x04    // respond to I2C-bus subaddress 2
#define MODE1_SUB1      0x08    // respond to I2C-bus subaddress 1
#define MODE1_SLEEP     0x10    // Low power mode. Oscillator off 
#define MODE1_AI        0x20    // Auto-Increment enabled 
#define MODE1_EXTCLK    0x40    // Use EXTCLK pin clock
#define MODE1_RESTART   0x80    // Restart enabled

/*********** M O D E 2   B I T S   D E F I N E S ******************************/
#define MODE2_OUTNE_0   0x01    // Active LOW output enable input 
#define MODE2_OUTNE_1   0x02    // Active LOW output enable input - high impedience 
#define MODE2_OUTDRV    0x04    // totem pole structure vs open-drain
#define MODE2_OCH       0x08    // Outputs change on ACK vs STOP
#define MODE2_INVRT     0x10    // Output logic state inverted 

/*********** G E N E R A L   D E F I N E S ************************************/
#define PCA9685_I2C_WRITE_ADDRESS   0x80      // Default PCA9685 I2C Write Slave Address
#define PCA9685_I2C_READ_ADDRESS    PCA9685_I2C_WRITE_ADDRESS + 1   // Read Slave Address
#define FREQUENCY_OSCILLATOR        25000000  // Int. osc. frequency in datasheet 

#define PCA9685_PRESCALE_MIN    3   //minimum prescale value
#define PCA9685_PRESCALE_MAX    255 // maximum prescale value

/*********** P R O T O T Y P E S **********************************************/
void PCA9685_Init(void);
void PCA9685_SetPWM(unsigned char CHANNEL, unsigned int DATA_ON, unsigned int DATA_OFF);
void PCA9685_WriteByte(unsigned char ADDR, unsigned char DATA);
unsigned char PCA9685_ReadByte(unsigned char ADDR);
void PCA9685_SetPWMFreq(float freq);
void PCA9685_SetOscillatorFrequency(float freq);

#ifdef  __cplusplus
}
#endif

#endif  /* PCA9685_H */

