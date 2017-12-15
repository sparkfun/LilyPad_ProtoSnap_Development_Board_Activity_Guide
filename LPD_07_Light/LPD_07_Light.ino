/*
LilyPad Development Board Activity 7: Sensing Light
SparkFun Electronics
https://www.sparkfun.com/products/11262

Explore analog input from the light sensor

Follow the tutorial at: 
https://learn.sparkfun.com/tutorials/lilypad-development-board-activity-guide/7-sensing-light

This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

// Create variables for the pins we'll use:

int sensorPin = A6;

int LED1 = 5;
int LED2 = 6;

void setup()
{
  // Initialize the sensor pin as an input, but without a pullup
  // (Pullups are only used for switch inputs)

  pinMode(sensorPin, INPUT);

  // Initialize the output pins:

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  // Initialize the serial monitor:

  Serial.begin(9600);
}

void loop()
{
  int sensorValue;

  // Read the sensor value (will be 0 to 1023):

  sensorValue = analogRead(sensorPin);

  // Print out the sensor reading to the serial monitor:

  Serial.print("sensor value: ");
  Serial.println(sensorValue);

  // Since the sensor value is 0 to 1023,
  // and analogWrite needs a value from 0 to 255,
  // we'll divide the sensor value by four to scale it down:

  analogWrite(LED1,sensorValue / 4);
  analogWrite(LED2,sensorValue / 4);
}

