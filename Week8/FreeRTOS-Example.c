#include <Arduino_FreeRTOS.h>

// Define task priorities
#define TASK1_PRIORITY (1)
#define TASK2_PRIORITY (2)
#define TASK3_PRIORITY (3)

// Declare a queue
QueueHandle_t sensorQueue;

// Setup function
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT); // LED on pin 13

  // Create the queue capable of holding 10 integers
  sensorQueue = xQueueCreate(10, sizeof(int));

  if (sensorQueue != NULL) {
    /* Task Creation */
    // Task 1
    xTaskCreate(
      readSensor,          // Task function
      "ReadSensor",        // A name just for humans
      128,                 // Stack size (in words, not bytes!)
      NULL,                // Task input parameters
      TASK1_PRIORITY,      // Priority
      NULL                 // Task handle (not used, so set to NULL)
    );

    // Task 2
    xTaskCreate(flashLED, "FlashLED", 128, NULL, TASK2_PRIORITY, NULL);

    // Task 3
    xTaskCreate(displayValue, "Display", 128, NULL, TASK3_PRIORITY, NULL);

    // Start scheduler
    vTaskStartScheduler();
  } else {
    Serial.println("Failed to create queue");
  }
}

// Task 1 - Read data from a sensor
void readSensor(void *pvParameters) {
  int sensorValue;
  for (;;) {
    sensorValue = analogRead(A0); // Read from potentiometer on pin A0
    xQueueSend(sensorQueue, &sensorValue, portMAX_DELAY); // Send data to the queue
    vTaskDelay(10); // Delay for 10ms
  }
}

// Task 2 - Flash an LED based on data
void flashLED(void *pvParameters) {
  int receivedValue;
  for (;;) {
    if (xQueueReceive(sensorQueue, &receivedValue, portMAX_DELAY) == pdTRUE) {
      if (receivedValue > 512) { // If value > half of the max ADC value
        digitalWrite(13, HIGH); // Turn LED ON
        vTaskDelay(200); // Keep it ON for 200ms
        digitalWrite(13, LOW); // Turn LED OFF
      }
      vTaskDelay(10); // Delay for 10ms
    }
  }
}

// Task 3 - Display the sensor value, suspends itself, and then resumes
void displayValue(void *pvParameters) {
  int receivedValue;
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 5000; // Suspend time of 5 seconds

  for (;;) {
    if (xQueuePeek(sensorQueue, &receivedValue, portMAX_DELAY) == pdTRUE) { // Just peek, don't remove item
      Serial.println(receivedValue);
    }

    // Suspend the task for 5 seconds
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
  }
}

// Required function, but it's empty because the scheduler handles the loop
void loop() {}
