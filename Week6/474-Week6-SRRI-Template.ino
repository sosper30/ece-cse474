/**
 * Template for Synchronized Round Robin with Interrupt Service Routine (SRRI) Scheduler
 * 
 * This template provides a framework for implementing a SRRI scheduler on an Arduino
 * microcontroller. The scheduler is designed to manage two tasks, specifically flashing LEDs
 * at different rates. 
 * Look for "TODO" and follow the instructions
 */

// Clock frequency in Hz for the microcontroller (16 MHz for Arduino)
#define CLK_FREQ 16000000
// Clock scale for the timer, adjust based on the timer configuration
#define CLK_SCALE 1024

// Define LED pins for your tasks
#define LED_PIN_TASK1 /* TODO: Assign a digital pin number for the first LED */
#define LED_PIN_TASK2 /* TODO: Assign a digital pin number for the second LED */

// Task states for the scheduler
#define READY 0
#define RUNNING 1
#define SLEEPING 2

// Maximum number of tasks the scheduler can handle
#define N_MAX_TASKS 4

// Scheduler and ISR flag definitions
volatile int sFlag; // Flag used by the ISR
int task_index; // Current task being executed

// Arrays for task management
void (*taskArray[N_MAX_TASKS])(); // Array of function pointers to tasks
int current_sleeptime[N_MAX_TASKS]; // Sleep time for each task
int current_state[N_MAX_TASKS]; // State of each task

void setup() {
  // TODO: Initialize digital pins for LED output using pinMode()

  // Initialize Timer 0 for interrupts with a 2ms period
  // TODO: Configure Timer 0 (CTC mode, prescaler) and enable its interrupt
  
  sei(); // Enable global interrupts

  // Initialize taskArray with tasks and their initial states
  int i = 0;
  taskArray[i] = &task1; // Task 1
  current_sleeptime[i] = 0;
  current_state[i] = READY;
  i++;
  taskArray[i] = &task2; // Task 2
  current_sleeptime[i] = 0;
  current_state[i] = READY;
  i++;
  taskArray[i] = &schedule_sync; // Synchronization task
  current_sleeptime[i] = 0;
  current_state[i] = READY;
  i++;
  taskArray[i] = NULL; // End of tasks

  sFlag = READY; // Initialize the scheduler flag
  task_index = 0; // Start from the first task
}

/**
 * ISR for Timer 0 Compare Match
 * Triggered every 2 milliseconds, it should update the sFlag.
 */
ISR(TIMER0_COMPA_vect) {
  // TODO: Set sFlag to indicate the interrupt cycle is complete
}

/**
 * Task 1: Flashes an LED at a base rate
 * This task toggles an LED on and off.
 */
void task1() {
  static bool ledState = false;
  // TODO: Toggle the LED state for Task 1 and call sleep_474 with appropriate duration
}

/**
 * Task 2: Flashes an LED at double the rate of Task 1
 * This task toggles another LED on and off at double the speed.
 */
void task2() {
  static bool ledState = false;
  // TODO: Toggle the LED state for Task 2 and call sleep_474 with half the duration of Task 1
}

/**
 * Schedule Sync Task
 * Manages the sleep times of tasks and updates their states.
 */
void schedule_sync() {
  // TODO: Implement the logic to wait for sFlag, then update sleeping tasks and reset sFlag
}

/**
 * Sleep Function
 * Sets the current task to SLEEPING state for a specified amount of time.
 */
void sleep_474(int t) {
  // TODO: Update the current task's state to SLEEPING and set its sleep time
}

/**
 * Main Scheduler Loop
 * Cycles through tasks, executing those in the READY state.
 */
void loop() {
  // TODO: Implement the scheduler logic to cycle through tasks and execute them based on their state
}
