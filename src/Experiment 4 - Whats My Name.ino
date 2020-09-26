#include <Wire.h> // Include code for talking analog
#include <LiquidCrystal_I2C.h> //Include code for controlling LCD
LiquidCrystal_I2C lcd(0x3F,16,2); //Set the LCD
void setup()
{

lcd.init(); // initialize the lcd
// Print a message to the LCD.
lcd.backlight(); //Turn on Backlight
lcd.setCursor(0,0); // go to column 0 row 0
lcd.print("What is"); //Type What is on the display
lcd.setCursor(3,1); // go to column 3 row 1
lcd.print("My Name"); //Type My Name on the display
}

void loop() // We do not do anything after the setup. Just show the text
{
}