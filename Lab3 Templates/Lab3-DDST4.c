/**
 * @file Lab3_DDS.ino
 * @date __date__
 * @brief ECE Lab 3 Assignment
 * @detail University of Washington ECE 474
 * 
 * 
 */

// Here we will define our states for TCB, timers, and periods based on the specifications given in the assignment

struct TCB {
  // Variables according to your requirement will be defined here.
} TCB_struct; // Name given to the TCB struct

// An array of TCB structures will be created here to control the processes

void setup() {
  // Here we will initialize the required pins as output, set the required mode and prescalar value, set the bits of COMnC1, COMnB1, COMnA1 to 0, and COMnC0, COMnC0, COMnC0 to 1
  // We will also initialize the characteristics of tasks in our processList array
}

void loop() {
  // Implement the scheduler and task control logic in this function.
}

void flashExternalLED() {
  // Here we will implement the logic to flash an external LED for a certain amount of time, then turn it off for another amount of time
}

void playSpeaker() {
  // Here we will implement the logic to play a theme from a song for a certain amount of time, then sleep for a certain amount of time, then play the theme again
}

void function_ptr(void* function()) {
  // This function will invoke the function that is passed as a parameter
}

void task_self_quit() {
  // Here we will implement the logic for a task to terminate itself by manipulating its TCB
}

void task_start(TCB* task) {
  // Here we will implement the logic for a task to start another task
}

void scheduler(){
  // Here we will implement the logic for tasks to be processed and executed
}

byte bit_set(uint8_t bitValue, uint8_t port) {
  // Here we will implement the logic to set the value 1 to the designated port via bitshifting
  // In other words, we'll be setting the designated PIN (port) to high
  // This function will return a byte that equals 1
}

byte bit_clear(uint8_t bitValue, uint8_t port) {
  // Here we will implement the logic to set the value 0 to the designated port via bitshifting
  // In other words, we'll be setting the designated PIN (port) to low
  // This function will return a byte that equals 0
}
