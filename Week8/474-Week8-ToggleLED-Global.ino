//WokWi Link: https://wokwi.com/projects/390293607010940929

#include <Arduino_FreeRTOS.h>

// Function prototypes for the tasks
void TaskBlink(void *pvParameters);
void TaskSerialRead(void *pvParameters);

// Global variable to store the input value for the blink delay
// This variable is volatile because it is modified by one task and read by another task.
volatile int inputValue = 500;

// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  
  // Wait for serial port to connect. This is necessary for boards that use native USB
  while (!Serial) {
    ; // Wait for serial port to connect. Necessary for some boards like Leonardo, Micro, Yun, etc.
  } 

  // Create two tasks to run independently.
  xTaskCreate(
    TaskBlink,          // Function that implements the task.
    "Blink",            // Text name for the task. This is to facilitate debugging.
    128,                // Stack size in words, not bytes.
    NULL,               // Parameter passed into the task.
    1,                  // Priority at which the task is created.
    NULL);              // Used to pass back a handle by which the created task can be referenced.

  xTaskCreate(
    TaskSerialRead,     // Function that implements the task.
    "AnalogRead",       // Text name for the task.
    128,                // Stack size in words.
    NULL,               // Parameter passed into the task.
    2,                  // Priority of the task.
    NULL);              // Task handle.

  // The task scheduler, which manages the task execution, is automatically started.
}

// The loop function does nothing in this sketch. All functionality is in the tasks.
void loop() {
  // Empty. All work is done in FreeRTOS tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

// Task to blink an LED
void TaskBlink(void *pvParameters) {
  pinMode(LED_BUILTIN, OUTPUT); // Initialize digital pin LED_BUILTIN as an output.

  for (;;) { // Infinite loop for the task
    digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED on
    vTaskDelay(inputValue / portTICK_PERIOD_MS); // Delay for inputValue milliseconds
    digitalWrite(LED_BUILTIN, LOW);    // Turn the LED off
    vTaskDelay(inputValue / portTICK_PERIOD_MS); // Delay for inputValue milliseconds
  }
}

// Task to read from the serial port
void TaskSerialRead(void *pvParameters) {
  Serial.println("Enter the number of ms delay");

  for (;;) { // Infinite loop for the task
    if (Serial.available() > 0) { // Check if data is available to read
      int readValue = Serial.parseInt(); // Read the incoming integer

      // Only update global if a non-zero value is read
      if (readValue > 0) {
        inputValue = readValue; // Update the global variable

        // Echo back the received value for confirmation
        Serial.print("Received value: ");
        Serial.println(inputValue);
      } else {
        // Inform the user no valid input was detected if 0 is received
        Serial.println("No new input detected.");
      }
    }
    // Delay for a bit to avoid flooding
    vTaskDelay(500 / portTICK_PERIOD_MS);  // Half a second delay between reads for stability
  }
}

