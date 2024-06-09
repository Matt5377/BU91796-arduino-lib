/*
	Simple demo program for the BU91796 arduino library.
	
	Displays "12345" on a 7 segment LCD panel and activates blink mode at 1Hz.
*/

#include <Wire.h>
#include <BU91796.h>

BU91796 lcd;

const uint8_t lcd_digits[10] = {0xFA, 0x0A, 0xBC, 0x9E, 0x4E, 0xD6, 0xF6, 0x8A, 0xFE, 0xDE};

void setup() {
  Wire.begin();
  lcd.begin(INTERNAL_OSC);
  lcd.write(lcd_digits[1], 0);
  lcd.write(lcd_digits[2], 2);
  lcd.write(lcd_digits[3], 4);
  lcd.write(lcd_digits[4], 6);
  lcd.write(lcd_digits[5], 8);
  lcd.blink(BLINK_1HZ);
}

void loop(){

}