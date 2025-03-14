#define BLYNK_PRINT Serial
#include <Wire.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "MAX30105.h"

MAX30105 particleSensor;

// Replace with your Blynk credentials
char auth[] = "3----------6eab--------86L----MF";
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

BlynkTimer timer;

// Function to read data from MAX30102
void sendSensorData() {
    long irValue = particleSensor.getIR();
    long redValue = particleSensor.getRed();
    
    if (irValue < 50000) { // Weak signal check
        Serial.println("No finger detected!");
        return;
    }

    Serial.print("IR: "); Serial.print(irValue);
    Serial.print(" Red: "); Serial.println(redValue);

    Blynk.virtualWrite(V1, irValue);  // Send IR value to Blynk
    Blynk.virtualWrite(V2, redValue); // Send Red value to Blynk
}

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, pass);
    Blynk.begin(auth, ssid, pass);

    if (!particleSensor.begin(Wire, I2C_SPEED_STANDARD)) {
        Serial.println("MAX30102 not found. Check connections.");
        while (1);
    }

    Serial.println("MAX30102 initialized!");

    // Set data reading every 2 seconds
    timer.setInterval(2000L, sendSensorData);
}

void loop() {
    Blynk.run();
    timer.run();
}
 ⁠
