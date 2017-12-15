/*
LilyPad Development Board Activity 2: Basic Color Mixing
SparkFun Electronics
https://www.sparkfun.com/products/11262

Create primary and secondary colors on the tri-color (Red/Green/Blue)
LED connected to sew tabs 9, 11, and 10 on the LilyPad Arduino Simple.

Follow the tutorial at:
https://learn.sparkfun.com/tutorials/lilypad-development-board-activity-guide/2-basic-color-mixing

This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

// The LilyPad Development Board has a tri-color, also known as an RGB 
// (Red / Green / Blue) LED.
// In this activity we'll use digitalWrite to tun the three LEDs on and off
// in various combinations to create eight primary and secondary colors.

// Create integer variables for our LED pins:

// The built-in LED:

int RGB_red = 9;
int RGB_green = 11;
int RGB_blue = 10;


void setup()
{
  // Make all of our LED pins outputs:

  pinMode(RGB_red, OUTPUT);
  pinMode(RGB_green, OUTPUT);
  pinMode(RGB_blue, OUTPUT);

}

void loop()
{

  // This code will step through the six primary and secondary colors, plus white and black.
  // Note: for this particular LED, the wiring shares a common anode (+), which means to
  // turn on the LEDs you will set them LOW instead of HIGH. 
  // Keep this in mind as you prototype with the LED and mix your colors.

  // For each of these colors, we'll turn the necessary RGB LEDs on or off.


  // Black (all LEDs off)

  // RGB LEDs:

  digitalWrite(RGB_red, HIGH);
  digitalWrite(RGB_green, HIGH);
  digitalWrite(RGB_blue, HIGH);
  delay(1000);

  // Red (red LED on)

  digitalWrite(RGB_red, LOW);
  digitalWrite(RGB_green, HIGH);
  digitalWrite(RGB_blue, HIGH);
  delay(1000);

  // Yellow (red and green LEDs on)

  digitalWrite(RGB_red, LOW);
  digitalWrite(RGB_green, LOW);
  digitalWrite(RGB_blue, HIGH);
  delay(1000);

  // Green (green LED on)

  digitalWrite(RGB_red, HIGH);
  digitalWrite(RGB_green, LOW);
  digitalWrite(RGB_blue, HIGH);
  delay(1000);

  // Cyan (blue and green LEDs on)

  digitalWrite(RGB_red, HIGH);
  digitalWrite(RGB_green, LOW);
  digitalWrite(RGB_blue, LOW);
  delay(1000);

  // Blue (blue LED on)

  digitalWrite(RGB_red, HIGH);
  digitalWrite(RGB_green, HIGH);
  digitalWrite(RGB_blue, LOW);
  delay(1000);

  // Magenta (red and blue LEDs on)

  digitalWrite(RGB_red, LOW);
  digitalWrite(RGB_green, HIGH);
  digitalWrite(RGB_blue, LOW);
  delay(1000);

  // White (all LEDs on)

  digitalWrite(RGB_red, LOW);
  digitalWrite(RGB_green, LOW);
  digitalWrite(RGB_blue, LOW);
  delay(1000);
}

