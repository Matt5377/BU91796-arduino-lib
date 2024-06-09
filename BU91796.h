#ifndef BU91796_h
#define BU91796_h

#include "Arduino.h"

#define I2C_Addr 0x3E

class BU91796
{
public:
    BU91796();
	
	#define INTERNAL_OSC 			 0
	#define EXTERNAL_OSC 			 1
	#define BLINK_DISABLE 			 0
	#define BLINK_0_5HZ 			 1
	#define BLINK_1HZ				 2
	#define BLINK_2HZ 				 3
	#define NORMAL 					 0
	#define ALL_OFF 				 1
	#define ALL_ON 					 2
	#define LINE_INV 				 0
	#define FRAME_INV 				 1
	#define POWER_SAVE_SR_1			 0
	#define POWER_SAVE_SR_2			 1
	#define POWER_SAVE_SR_NORMAL	 2
	#define POWER_SAVE_SR_HIGH POWER 3
	#define POWER_SAVE_FR_NORMAL 	 0
	#define POWER_SAVE_FR_1			 1
	#define POWER_SAVE_FR_2 		 2
	#define POWER_SAVE_FR_3 		 3
	
	/**************************************************
	begin
	
	Description:
	Performs a software reset and clears all DDRAM.
	
	Parameters:
	bool clkSrc 
		0 = Internal oscillator
		1 = External oscillator
	***************************************************/
    void begin(bool clkSrc);
	
	/**************************************************
	blink
	
	Description:
	Sets the blink mode
	
	Parameters:
	uint8_t blinkMode 
		0 = Blinking disabled
		1 = Blinking 0.5 Hz
		2 = Blinking 1 Hz
		3 = Blinking 2 Hz
	***************************************************/
    void blink(uint8_t  blinkMode);
	
	/**************************************************
	displayActive
	
	Description:
	Enables / disables the display driver.
	
	Parameters:
	bool dispOnOff 
		0 = Display disabled
		1 = Display enabled
	***************************************************/
    void displayActive(bool dispOnOff);
	
	/**************************************************
	setAllSegmens
	
	Description:
	Sets all segments on or off.
	
	Parameters:
	uint8_t allSeg
		0 = Normal mode (segments controlled by DDRAM)
		1 = All segments off
		2 = All segments on
	***************************************************/
    void setAllSegmens(uint8_t allSeg);
	
	/**************************************************
	setDriveWaveform
	
	Description:
	Sets the drive waveform.
	
	Parameters:
	bool driveWaveform
		0 = Line inversion
		1 = Frame inversion
	***************************************************/
    void setDriveWaveform(bool driveWaveform);
	
	/**************************************************
	setPowerSaveSRMode
	
	Description:
	Sets the power save SR mode.
	
	Parameters:
	uint8_t PwrSaveSR
		0 = Power save mode 1
		1 = Power save mode 2
		2 = Normal mode
		3 = High power mode
	***************************************************/
    void setPowerSaveSRMode(uint8_t PwrSaveSR);
	
	/**************************************************
	setPowerSaveFRMode
	
	Description:
	Sets the power save FR mode.
	
	Parameters:
	uint8_t PwrSaveFR
		0 = Normal mode (80Hz)
		1 = Power save mode 1 (71Hz)
		2 = Power save mode 2 (64Hz)
		3 = Power save mode 3 (53Hz)
	***************************************************/
    void setPowerSaveFRMode(uint8_t PwrSaveFR);
	
	/**************************************************
	write
	
	Description:
	Writes 1 byte to the DDRAM
	
	Parameters:
	uint8_t data		The data to be written
	uint8_t address		The adress to write (0-19)
	***************************************************/
    void write(uint8_t  data, uint8_t address);
	
	
private:
    uint8_t DDRAM[10];
    uint8_t _blinkMode;
    uint8_t _allSeg;
    bool _driveWaveform;
    bool _dispOnOff;
    uint8_t _PwrSaveSR;
    uint8_t _PwrSaveFR;
};

#endif