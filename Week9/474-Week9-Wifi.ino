/*This example assumes the use of an ESP8266 or ESP32 Wi-Fi module connected to the Arduino Mega. 
The code is structured around FreeRTOS tasks to manage the Wi-Fi connection and sensor data transmission efficiently.*/


#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

// Wi-Fi library compatible with Arduino and ESP8266/ESP32 (arbitrary)
#include <WiFi.h>

// Wi-Fi credentials (replace with your actual SSID and password)
const char* ssid     = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// Server details
const char* serverUrl = "http://example.com/data";
const int httpPort = 80;

// Function prototypes
void connectToWiFi();
void sendDataToServer(const String& data);
void vSensorDataTask(void *pvParameters);

void setup() {
  Serial.begin(9600);

  // Initialize Wi-Fi
  connectToWiFi();

  // Create a task for reading sensor data and sending it to the server
  xTaskCreate(
    vSensorDataTask,      // Task function
    "Sensor Data",        // Name of the task
    2048,                 // Stack size in words
    NULL,                 // Task input parameter
    1,                    // Priority of the task
    NULL                  // Task handle
  );

  // Start the scheduler
  vTaskStartScheduler();
}

void loop() {
  // Empty. Tasks are managed by FreeRTOS.
}

/**
 * connectToWiFi function initializes the Wi-Fi connection using the provided SSID and password.
 * It attempts to connect to the Wi-Fi network and prints dots on the Serial monitor until the connection is established.
 */
void connectToWiFi() {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    vTaskDelay(500 / portTICK_PERIOD_MS); // Wait for the Wi-Fi to connect
    Serial.print(".");
  }

  Serial.println("Connected to WiFi!");
}

/**
 * sendDataToServer function checks if the Wi-Fi connection is active before attempting to send data to the server.
 * It opens a TCP connection to the specified server and sends a POST request with the sensor data.
 * If the connection to the server fails or if the Wi-Fi connection is lost, it attempts to reconnect.
 */
void sendDataToServer(const String& data) {
  // Check Wi-Fi connection
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    if (client.connect(serverUrl, httpPort)) {
      // Create HTTP request
      client.println("POST /data HTTP/1.1");
      client.println("Host: example.com");
      client.println("Content-Type: application/x-www-form-urlencoded");
      client.print("Content-Length: ");
      client.println(data.length());
      client.println();
      client.print(data);

      // Close the connection
      client.stop();
    } else {
      Serial.println("Connection to server failed.");
    }
  } else {
    Serial.println("WiFi not connected!");
    connectToWiFi();
  }
}

/**
 * vSensorDataTask function simulates reading sensor data (for example, temperature and humidity)
 * and calls sendDataToServer to send this data to a server every 10 seconds.
 * This task demonstrates how to periodically perform an action (like reading sensors and sending data) in a FreeRTOS task.
 */
void vSensorDataTask(void *pvParameters) {
  for (;;) {
    // Simulate reading sensor data
    String sensorData = "temperature=24.5&humidity=60";

    // Send data to server
    sendDataToServer(sensorData);

    // Sleep for 10 seconds before next read
    vTaskDelay(10000 / portTICK_PERIOD_MS);
  }
}
