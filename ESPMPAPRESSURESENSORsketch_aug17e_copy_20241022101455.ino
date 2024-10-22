#define BLYNK_TEMPLATE_ID "TMPL32dotQj8l"  // Replace with your template ID
#define BLYNK_TEMPLATE_NAME "Air Pressure with ESP8266"  
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

char auth[] = "W9ogYigLytH9wuh6NLmDS_9G1ZaTT0UK"; // Replace with your Blynk authentication token
char ssid[] = "Vijai";       // Replace with your WiFi SSID
char pass[] = "123456789";   // Replace with your WiFi Password

// Pressure sensor variables
const int pressureInput = A0; // Select the analog input pin for the pressure transducer
const float pressureZero = 102.4; // Analog reading of pressure transducer at 0 PSI
const float pressureMax = 921.6;  // Analog reading of pressure transducer at 100 PSI
const int pressureTransducerMaxPSI = 100; // PSI value of transducer being used

float pressureValue = 0; // Variable to store the value coming from the pressure transducer

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  // Run Blynk
  Blynk.run();
  
  // Read value from input pin and assign it to the variable
  pressureValue = analogRead(pressureInput);
  
  // Conversion equation to convert analog reading to PSI
  pressureValue = ((pressureValue - pressureZero) * pressureTransducerMaxPSI) / (pressureMax - pressureZero);
  
  // Print the pressure value to the Serial Monitor
  Serial.print(pressureValue, 1);
  Serial.println(" PSI");

  // Send the pressure value to Blynk (e.g., to Virtual Pin V1)
  Blynk.virtualWrite(V0, pressureValue);
  
  // Delay between sensor reads
  delay(250);
}
