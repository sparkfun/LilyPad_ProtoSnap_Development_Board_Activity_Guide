/*
LilyPad Development Board Activity 1: Blink an LED
SparkFun Electronics
https://www.sparkfun.com/products/11262

Blink the white LED attached to sew tab 5 on the LilyPad Arduino Simple

Follow the tutorial at:        
https://learn.sparkfun.com/tutorials/lilypad-development-board-activity-guide/1-blink-an-led

This example is based on: Blink by Scott Fitzgerald
https://www.arduino.cc/en/Tutorial/Blink

This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

// The setup function runs once when the microcontroller starts up or resets:

void setup()
{
  // Before you use a sew tab (pin), you must set it to be either an input or output:

  pinMode(10, OUTPUT); // Set pin 5 to be an output
}

// After the setup function runs, the loop function runs over and over forever:

void loop()
{
  digitalWrite(10, HIGH); // Give pin 5 a HIGH voltage level (on), which lights up the LED
  delay(1000);           // Pause for 1000 milliseconds (one second), the LED stays on
  digitalWrite(10, LOW);  // Give pin 5 a LOW voltage level (off), which turns off the LED
  delay(1000);           // Pause for 1000 milliseconds (one second), the LED stays off
}

