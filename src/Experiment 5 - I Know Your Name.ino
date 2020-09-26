#include <Wire.h> // Include code for talking analog
#include <LiquidCrystal_I2C.h> //Include code for controlling LCD

int state = HIGH;      // the current state of the output pin
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers
LiquidCrystal_I2C lcd(0x3F,16,2); //Set the LCD

void setup()
{
  pinMode(8, INPUT); //Set pin 8 to look for a button press
  
  lcd.init(); // initialize the lcd

  lcd.backlight(); //Turn on Backlight

  lcd.setCursor(0,0); // go to column 0 row 0
  lcd.print("What is"); //Type What is on the display
  lcd.setCursor(3,1); // go to column 3 row 1
  lcd.print("My Name"); //Type My Name on the display
  state = LOW;
}

void loop() // We just keep looping waiting for someone to push the button.
{

  reading = digitalRead(8);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH){
      state = LOW;
      lcd.clear();
      lcd.setCursor(0,0); // go to column 0 row 0
      lcd.print("What is"); //Type What is on the display
      lcd.setCursor(3,1); // go to column 3 row 1
      lcd.print("My Name"); //Type My Name on the display
      digitalWrite(8,LOW);    
       }
    else {
      state = HIGH;
      lcd.clear();
      lcd.print("You know my"); //Type What is on the display
      lcd.setCursor(3,1); // go to column 3 row 1
      lcd.print("Name"); //Type My Name on the display
      digitalWrite(8,HIGH);      
    }
    time = millis();    
  }
 previous = reading;

}