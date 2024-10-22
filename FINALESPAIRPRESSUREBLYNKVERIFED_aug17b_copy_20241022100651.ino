// Blynk credentials
#define BLYNK_TEMPLATE_ID "TMPL32dotQj8l"  // Replace with your template ID
#define BLYNK_TEMPLATE_NAME "Air Pressure  with ESP8266"        // Replace with your template name

// Define your SCK and DOUT pins
#define SCK_PIN 14  // D5 on the ESP8266
#define DOUT_PIN 12 // D6 on the ESP8266

#include <HX710B.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

// Sensor Offset
const float SensorOffset = 102315.0;

char auth[] = "W9ogYigLytH9wuh6NLmDS_9G1ZaTT0UK";

// WiFi credentials
char ssid[] = "Vijai";       // Replace with your WiFi SSID
char pass[] = "123456789";   // Replace with your WiFi Password

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  // Blynk run routine
  Blynk.run();

  // Apply calibration and convert to kPa
  float sensorValue = (analogRead(A0) - SensorOffset) / 100.0; // Do math for calibration

  // Print the air pressure value to the Serial Monitor
  Serial.print("Air Pressure: ");
  Serial.print(sensorValue, 2);
  Serial.println(" kPa");

  // Send air pressure to Blynk virtual pin V3
  Blynk.virtualWrite(V2, sensorValue);
  Blynk.virtualWrite(V4, sensorValue);
  delay(5000);  // Delay for stability
}
