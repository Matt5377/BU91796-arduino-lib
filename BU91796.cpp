#include "Arduino.h"
#include "BU91796.h"

#include <Wire.h>

BU91796::BU91796()
{
    _blinkMode = 0;
    _allSeg = 0;
    _driveWaveform = 0;
    _dispOnOff = 1;
    _PwrSaveSR = 0x2;
    _PwrSaveFR = 0x0;
}

void BU91796::begin(bool clkSrc)
{
    Wire.beginTransmission(I2C_Addr);
    Wire.write(0b11101010);  //Reset
	Wire.endTransmission();
	
	Wire.beginTransmission(I2C_Addr);
	Wire.write(0b11101000 | clkSrc); 			    //ICSET
    Wire.write(0b01000000 | (_dispOnOff << 3)); 	//MODESET
    for (int i = 0; i < 10; i++)					//Clear DDRAM
    {
        Wire.write(0x0);
    }
    Wire.endTransmission();
}

void BU91796::blink(uint8_t blinkMode)
{
    _blinkMode = blinkMode & 0x3;
    Wire.beginTransmission(I2C_Addr);
    Wire.write(0b11110000 | _blinkMode);			//BLKCTL
    Wire.endTransmission();
}

void BU91796::displayActive(bool dispOnOff)
{
    _dispOnOff = dispOnOff;
    Wire.beginTransmission(I2C_Addr);
    Wire.write(0b11000000 | (_dispOnOff << 3));
    Wire.endTransmission();
}

void BU91796::setAllSegmens(uint8_t allSeg)
{
    _allSeg = allSeg & 0x3;
    Wire.beginTransmission(I2C_Addr);
    Wire.write(0b11111100 | _allSeg);				//APCTL
    Wire.endTransmission();
}


void BU91796::setDriveWaveform(bool driveWaveform)
{
    _driveWaveform = driveWaveform;
    Wire.beginTransmission(I2C_Addr);
    Wire.write(0b10100000 | (_PwrSaveFR << 3) | (_driveWaveform << 2) | _PwrSaveSR);
    Wire.endTransmission();
}

void BU91796::setPowerSaveFRMode(uint8_t PwrSaveFR)
{
    _PwrSaveFR = PwrSaveFR & 0x3;
    Wire.beginTransmission(I2C_Addr);
    Wire.write(0b10100000 | (_PwrSaveFR << 3) | (_driveWaveform << 2) | _PwrSaveSR);
    Wire.endTransmission();
}

void BU91796::setPowerSaveSRMode(uint8_t PwrSaveSR)
{
    _PwrSaveSR = PwrSaveSR & 0x3;
    Wire.beginTransmission(I2C_Addr);
    Wire.write(0b10100000 | (_PwrSaveFR << 3) | (_driveWaveform << 2) | _PwrSaveSR);
    Wire.endTransmission();
}

void BU91796::write(uint8_t data, uint8_t address)
{
    Wire.beginTransmission(I2C_Addr);
    Wire.write(address & 0x1F);						//ADSET
    Wire.write(data);
    Wire.endTransmission();
}