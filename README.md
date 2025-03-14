The Esp32.ino file is designed to collect data from the MAX30105 sensor, which measures heart rate and oxygen saturation, and send it to the Blynk app. 
Using the ESP32 board, the code connects to a WiFi network and interfaces with the MAX30105 sensor to collect data every 2 seconds.
This data, which includes infrared (IR) and red light values, corresponds to heart rate and oxygen saturation levels, and is sent to the Blynk app via 
virtual pins for real-time monitoring.To set up the system, you need to install the necessary libraries for both the MAX30105 sensor and Blynk for ESP32. 
The auth[] value in the code must be replaced with your unique Blynk authorization token, and the ssid[] and pass[] values should be replaced with your WiFi network name and password. 
The MAX30105 sensor should be connected to the ESP32 using I2C communication, and once the hardware is set up, the code can be uploaded to the ESP32 using the Arduino IDE.
Once the system is running, the ESP32 will read the IR and red light values from the MAX30105 sensor every 2 seconds. If the signal is weak (indicating no finger detected),
a message will be printed to the serial monitor. If the sensor detects a valid signal, the IR value (heart rate) is sent to virtual pin V1 and the red value (oxygen saturation)
is sent to virtual pin V2 on Blynk. This allows you to monitor both heart rate and oxygen saturation in real-time through the Blynk app.
The system provides a convenient way to monitor health metrics like heart rate and oxygen saturation remotely via the Blynk app. 
By integrating the MAX30105 sensor with the ESP32 board and the Blynk platform, the Esp32.ino file makes it easy to collect and visualize important health data from your device.



