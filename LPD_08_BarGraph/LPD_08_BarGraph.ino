/*
LilyPad Development Board Activity 8: LED Bar Graph
SparkFun Electronics
https://www.sparkfun.com/products/11262

Play with the row of five LEDs on the bottom of the LilyPad Development Board

Follow the tutorial at: 
https://learn.sparkfun.com/tutorials/lilypad-development-board-activity-guide/8-led-bar-graph

This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

// Create a variable for the light sensor input:

int sensorPin = A6;


// To the five LEDs on the LilyPad Development Board easier to use, we'll put those numbers into an array.
// The initial [5] defines the size of the array (five elements).
// We're filling the array with predefined values, but you could do this
// in your code as well.

int bargraphLED[5] = {5,6,A2,A4,A3};

// The array is indexed from 0 to 4; for example bargraphLED[2] = A2

void setup()
{
  int x;

  // Initialize the sensor pin as an input, but without a pullup
  // (Pullups are only used for switch inputs)

  pinMode(sensorPin, INPUT);

  // Initialize the bargraph LED pins as outputs
  // We'll use the matrix we defined above,
  // where the LEDs are indexed from 0 to 4

  for (x = 0; x <= 4; x++)
  {
    pinMode(bargraphLED[x], OUTPUT);
  }

  // Initialize the serial monitor

  Serial.begin(9600);
}

void loop()
{
  int sensorValue;

  // Read the sensor value (will be 0 to 1023):

  sensorValue = analogRead(sensorPin);

  // Print out the sensor reading:

  Serial.print("sensor value: ");
  Serial.println(sensorValue);

  // Display the sensor reading on the bar graph LEDs.
  // This is a new function that we created ourselves (see below).

  barGraph(sensorValue);
}

// Here we're making our own command called barGraph:
// The first "void" means we don't return anything from this command
// The "int value" is what we'll pass to the command (it must be an integer,
// and it will be called "value" in the command.

void barGraph(int value)
{
  // Create a LED bargraph using value as an input.
  // Value should be in the range 0 to 1023.

  int x;

  // Step through the bargraph LEDs,
  // Turn them on or off depending on value.

  // Value will be in the range 0 to 1023.
  // There are 6 LEDs in the bargraph.
  // 1023 divided by 5 is 204, so 204 will be our threshold
  // between each LED

  for (x=0; x <= 4; x++)
  {
    if (value > (x*204) )
    {
      digitalWrite(bargraphLED[x], HIGH);
    }
    else
    {
      digitalWrite(bargraphLED[x], LOW);
    }    
  }
}

