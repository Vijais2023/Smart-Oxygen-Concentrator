#include <LiquidCrystal.h>
#include <Wire.h>

const float SensorOffset = -10232.0;

// Initialize the LiquidCrystal library with the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Print a static message to the LCD
  lcd.print("Air Pressure:");

  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // Read the input on analog pin 0:
  float sensorValue = (analogRead(A0) - SensorOffset) / 100.0; // Calibration

  // Print out the value to the Serial Monitor:
  Serial.print("Air Pressure: ");  
  Serial.print(sensorValue, 2);
  Serial.println(" kPa");
  
  // Set the cursor to the second row and first column
  lcd.setCursor(0, 1);
  
  // Print the sensor value on the LCD
  lcd.print(sensorValue, 2);
  lcd.print(" kPa    "); // Padding with spaces to clear previous characters
  
  delay(5000);  // Delay in between reads for stability
}
