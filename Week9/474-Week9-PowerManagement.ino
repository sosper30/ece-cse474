#include <avr/sleep.h>
#include <avr/wdt.h>
#include <FreeRTOS.h>
#include <task.h>

/*The code simulates a sensor reading task that wakes up every 10 seconds to "read" sensor data, 
then goes back to sleep, showcasing task scheduling, power-saving modes, and peripheral management.*/

// Forward declaration of the task function
void vSensorReadTask(void *pvParameters);

// Idle hook function declaration
void vApplicationIdleHook(void);

void setup() {
  // Initialize serial communication for debugging purposes
  Serial.begin(9600);
  while (!Serial) continue; // Wait for Serial to be ready

  // Create a task that simulates sensor reading
  xTaskCreate(
    vSensorReadTask,    // Task function
    "SensorRead",       // Name of the task
    128,                // Stack size (can be adjusted based on requirement)
    NULL,               // Task input parameter
    1,                  // Priority of the task
    NULL                // Task handle
  );

  // Start the scheduler, this function will not return and will begin scheduling the tasks.
  vTaskStartScheduler();
}

void loop() {
  // Empty. Everything is managed by FreeRTOS tasks and the scheduler.
}

// Task function that simulates reading sensor data
void vSensorReadTask(void *pvParameters) {
  (void) pvParameters; // Just to avoid compiler warnings about unused parameter

  for (;;) {
    // Simulate sensor reading by printing to the Serial (this is where you'd add your sensor reading logic)
    Serial.println("Reading sensor data...");

    // Sleep for 10 seconds before next read. In a real application, adjust the delay as needed.
    vTaskDelay(pdMS_TO_TICKS(10000));
  }
}

// Idle hook function definition. This is called by FreeRTOS when there are no tasks to run.
void vApplicationIdleHook(void) {
  // Set the sleep mode to power down. In actual applications, choose the mode that best suits your needs.
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);

  // Disable interrupts to ensure the sleep mode is entered safely.
  cli();

  // Check if it is still safe to enter the sleep mode.
  if (eTaskConfirmSleepModeStatus() == eAbortSleep) {
    // Abort entering sleep mode if not safe.
    sei();
  } else {
    // Safe to enter sleep mode, enable sleep and go to sleep.
    sleep_enable();
    sei(); // Ensure interrupts are enabled so we can wake up again
    sleep_cpu();

    // CPU will stop executing here and resume from this point when it is woken up

    // Disable sleep on wake up to prevent accidental sleep.
    sleep_disable();
  }
}

// This example requires configuring FreeRTOSConfig.h for support of idle hook and tickless idle
// Ensure the following is defined in FreeRTOSConfig.h:
// #define configUSE_IDLE_HOOK            1
// #define configUSE_TICKLESS_IDLE        1


//--------------------------------------------------------------------------------------