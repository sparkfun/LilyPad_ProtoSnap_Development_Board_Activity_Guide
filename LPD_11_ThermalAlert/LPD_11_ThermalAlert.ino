/*
LilyPad Development Board Activity 11: Thermal Alert!
SparkFun Electronics
https://www.sparkfun.com/products/11262
  
This code reads the input of the temperature sensor and compares it to
a two set thresholds named 'hotAlert' and 'coldAlert'. If temperature is above 
the hotAlert threshold, the red channel of the tri-color LED will turn on and the vibe board
will shake. If the temperature falls below the coldAlert threshold, the blue channel of the
tri-color LED will turn on. If the temperature is in the middle of these two thresholds,
the green channel of the tri-color LED will turn on.

Follow the tutorial at:
https://learn.sparkfun.com/tutorials/lilypad-development-board-activity-guide/11-thermal-alert-project
  
This example is based on: Thermal alert by 
https://learn.sparkfun.com/tutorials/digital-sandbox-arduino-companion/12-thermal-alert

This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/
  
 // Set hot and cold threshold variables to check against. If the temperature reading is above
 // this number in degrees Fahrenheit, we'll turn different LEDs on
 float hotAlert = 80.0;  // 80 degrees Fahrenheit
 float coldAlert = 70.0; // 70 degrees Fahrenheit

// Temperature sensor is connected to A1
 int sensorPin = A1;  

// The LEDs in the tri-color LED
int RGB_red = 9;
int RGB_green = 11;
int RGB_blue = 10;

// The vibe board
int motor = 3;

void setup()
{
  // Set the temperature sensor pin as an INPUT:
  pinMode(sensorPin, INPUT);
    
// Make all of our LED pins outputs:

pinMode(RGB_red, OUTPUT);
pinMode(RGB_green, OUTPUT);
pinMode(RGB_blue, OUTPUT);

pinMode(motor, OUTPUT);
  
  // Initialize Serial, set the baud rate to 9600 bps.
  Serial.begin(9600);
}

void loop()
{
  // Variable to store raw temperature
  long rawTemp;
  
  // Variable to store voltage calculation
  float voltage;
  
  // Variable to store Fahrenheit value
  float fahrenheit;
  
  // Variable to store Celsius value
  float celsius;
  
  // Read the raw 0-1023 value of temperature into a variable.
  rawTemp = analogRead(sensorPin);
  
  // Calculate the voltage, based on that value.
  // Multiply by maximum voltage (4.2V for USB power) and divide by maximum ADC value (1023).
  voltage = rawTemp * (4.2 / 1023.0);
  Serial.print("Voltage: "); // Print voltage reading to serial monitor
  Serial.println(voltage);
  
  // Calculate the celsius temperature, based on that voltage..
  celsius = (voltage - 0.5) * 100;
  Serial.print("Celsius: "); // Print celcius temp to serial monitor
  Serial.println(celsius);
  
  // Use a common equation to convert celsius to Fahrenheit. F = C*9/5 + 32.
  fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
  Serial.print("Fahrenheit: "); // Print Farenheit temp to serial monitor
  Serial.println(fahrenheit); 
  // Print a blank line
  Serial.println();       

  // Check the temperature, and turn on the LEDs associated with the hot or cold thresholds
  if (fahrenheit >= hotAlert) // If the temperature rises above the hot threshold:
  {
    digitalWrite(RGB_red, LOW);    // Turn the red LED on
    digitalWrite(RGB_green, HIGH); // Turn the green LED off
    digitalWrite(RGB_blue, HIGH);  // Turn the blue LED off
    digitalWrite(motor, HIGH);     // Turn the motor on to shake as an extra alert
    delay(500);                    // Wait 1/2 second
    digitalWrite(motor, LOW);      // Then turn the motor off
  }
  else if (fahrenheit < coldAlert) // If the temperature falls below the cold threshold:
  {
    digitalWrite(RGB_red, HIGH);   // Turn the red LED off
    digitalWrite(RGB_green, HIGH); // Turn the green LED off
    digitalWrite(RGB_blue, LOW);   // Turn the blue LED on
  }
  else // For all other temperature readings (between hot and cold):
  {
    digitalWrite(RGB_red, HIGH);  // Turn the red LED off
    digitalWrite(RGB_green, LOW); // Turn the green LED on
    digitalWrite(RGB_blue, HIGH); // Turn the blue LED off
  }
  
  // Wait 1 second between readings
  delay(1000);  
}
