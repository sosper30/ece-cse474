// Define the LED pin numbers. These are the digital pins on your Arduino Mega 
// that you will connect your LEDs to.
#define LED_PIN_1 13
#define LED_PIN_2 12

// This is the first task that we will create. It's function will be to blink LED_PIN_1.
void vTaskBlink1(void *pvParameters) {
  // This is an infinite loop, denoted by "for (;;)". In a FreeRTOS task, we use an 
  // infinite loop because we want the task to execute indefinitely. If we don't use 
  // an infinite loop, the task will execute once and then be deleted.
  for (;;) {
    digitalWrite(LED_PIN_1, HIGH); // Turn LED_PIN_1 on
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Delay for a second
    digitalWrite(LED_PIN_1, LOW); // Turn LED_PIN_1 off
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Delay for a second
    // The vTaskDelay() function puts the task into a Blocked state for a specified 
    // number of tick periods. This is commonly used to create a periodic task. Same as our Sleep 474 function but this one is already implemented.
  }
}

// This is the second task that will blink LED_PIN_2.
void vTaskBlink2(void *pvParameters) {
  // This task also runs indefinitely because of the infinite loop.
  for (;;) {
    digitalWrite(LED_PIN_2, HIGH); // Turn LED_PIN_2 on
    vTaskDelay(500 / portTICK_PERIOD_MS);  // Delay for half a second
    digitalWrite(LED_PIN_2, LOW); // Turn LED_PIN_2 off
    vTaskDelay(500 / portTICK_PERIOD_MS);  // Delay for half a second
  }
}

void setup() {
  pinMode(LED_PIN_1, OUTPUT); // Set LED_PIN_1 as an output
  pinMode(LED_PIN_2, OUTPUT); // Set LED_PIN_2 as an output

  // Create the tasks with xTaskCreate()
  xTaskCreate(vTaskBlink1, "Blink1", 1000, NULL, 1, NULL);
  xTaskCreate(vTaskBlink2, "Blink2", 1000, NULL, 1, NULL);
  // The setup() function runs once when you press reset or power the board. 
  // Here, we're creating the tasks that will blink the LEDs.
}

void loop() {
  // Do nothing here. In FreeRTOS, the tasks are managed by the FreeRTOS scheduler,
  // so we don't need to put anything in the loop() function.
}
