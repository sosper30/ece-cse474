//WokWi Link: https://wokwi.com/projects/390406931835597825 

#include <Arduino_FreeRTOS.h>
#include <queue.h> //wokwi does not recognize Queue under FreeRTOS

// Function prototypes for the tasks
void TaskBlink(void *pvParameters);
void TaskSerialRead(void *pvParameters);

// Declare a handle for the queue. This queue will be used for communication between tasks.
QueueHandle_t blinkDelayQueue;

// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  
  // Wait for serial port to connect. This is necessary for boards that use native USB
  while (!Serial) {
    ; // Wait for serial port to connect. Necessary for Leonardo, Micro, Yun, etc.
  } 

  // Create a queue to hold int values. Queue length is 1, and each item size is the size of int.
  // This queue will store the blink delay value.
  blinkDelayQueue = xQueueCreate(1, sizeof(int));
  
  // Check if the queue was created successfully
  if (blinkDelayQueue == NULL) {
    Serial.println("Queue creation failed");
    return; // Queue was not created and no memory was available
  }

  // Send an initial value to the queue to ensure that the blinking starts with a default value.
  int initialValue = 500; // Default delay value
  xQueueSend(blinkDelayQueue, &initialValue, 0);

  // Create two tasks to run independently.
  xTaskCreate(
    TaskBlink,          // Function that implements the task.
    "Blink",            // Text name for the task. This is to facilitate debugging.
    128,                // Stack size in words, not bytes.
    NULL,               // Parameter passed into the task.
    1,                  // Priority at which the task is created.
    NULL);              // Task handle not used.

  xTaskCreate(
    TaskSerialRead,     // Function that implements the task.
    "SerialRead",       // Text name for the task.
    128,                // Stack size in words.
    NULL,               // Parameter passed into the task.
    2,                  // Priority of the task.
    NULL);              // Task handle not used.

  // The task scheduler, which manages the task execution, is automatically started.
}

void loop() {
  // Empty. All work is done in FreeRTOS tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

// Task to blink an LED
void TaskBlink(void *pvParameters) {
  int delayValue; // Variable to store the delay value
  pinMode(LED_BUILTIN, OUTPUT); // Initialize the built-in LED pin as an output

  for (;;) {
    // Attempt to receive a new delay value from the queue. Do not wait if the queue is empty.
    if (xQueueReceive(blinkDelayQueue, &delayValue, 0) == pdPASS) {
      // New delay value received, delayValue is updated.
    } // If no new value is received, the task will use the last known delayValue.

    // Blink the LED on
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(delayValue / portTICK_PERIOD_MS); // Wait for the specified delay period
    // Blink the LED off
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(delayValue / portTICK_PERIOD_MS); // Wait for the specified delay period
  }
}

// Task to read from the serial port
void TaskSerialRead(void *pvParameters) {
  Serial.println("Enter the number of ms delay");

  for (;;) {
    // Check if data is available to read from the serial port
    if (Serial.available() > 0) {
      int readValue = Serial.parseInt(); // Parse the incoming integer

      // Validate the parsed integer
      if (readValue > 0) {
        // If valid, send the read value to the queue
        if (xQueueSend(blinkDelayQueue, &readValue, portMAX_DELAY) == pdPASS) {
          // Confirm the received value via serial output
          Serial.print("Received value: ");
          Serial.println(readValue);
        }
      } else {
        // If no valid input is detected, notify the user
        Serial.println("No new input detected.");
      }
    }
    // Delay a bit before the next read to avoid overwhelming the serial input
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}
