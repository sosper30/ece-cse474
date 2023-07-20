/**
 * @file Lab3_DDS.ino
 * @date __date__
 * @brief ECE Lab 3 Assignment
 * @detail University of Washington ECE 474
 * 
 * 
 */

// Define states for TCB, timers, and periods
// FILL THESE VALUES ACCORDING TO THE SPECIFICATION GIVEN IN YOUR ASSIGNMENT

/**
  * A struct that defines the template of characteristics for one task
  * @return a struct that contains the characteristics declared within
  */
struct TCB {
  // Define variables according to your requirement
} TCB_struct; // name given to the TCB struct

// Create an array of TCB structures to control the processes

/**
  * Function initializes pins to output. Also initializes tasks
  */
void setup() {
  // Initialize the required pins as output
  // Set the required mode and prescalar value
  // Set the bits of COMnC1, COMnB1, COMnA1 to 0
  // Set the bits of COMnC0, COMnC0, COMnC0 to 1
  // Initialize characteristics of tasks in your processList array
}

/**
  * Function controls the tasks running dependent on the processList and scheduler
  * runs flashExternalLED and playSpeaker
  */
void loop() {
  // Implement the scheduler here
}

/**
  * Flashes an external LED for a given amount of time, then turns off for another amount of time
  */
void flashExternalLED() {
  // Implement the LED flashing logic here
}


/**
  * Function that plays a theme from a song
  * and then sleeps for a certain amount of time, then plays the theme again
  */
void playSpeaker() {
  // Implement the song playing logic here
}

/**
  * This function serves as a function pointer to any given task to execute
  * @param[function()] function that needs a pointer
  */   
void function_ptr(void* function()) {
  // Invoke the function passed as parameter here
}

/**
  * This function allows a task to terminate itself by manipulating its TCB
  */  
void task_self_quit() {
  // Implement the termination logic here
}

/**
  * This function allows a task to start up another task
  * @param[task] pointer to task control block struct
  */  
void task_start(TCB* task) {
  // Implement the task startup logic here
}

/**
  * This function allows for tasks to be processed and executed
  */ 
void scheduler(){
  // Implement the task scheduling logic here
}

/**
  * This function sets the value 1 to the designated port via bitshifting, overall,
  * setting designated PIN (port) to high
  * @param[bitValue] 8 bit unsigned integer value that is used for left bit shifting
  * @param[port] 8 bit unsigned integer value that represents the direct register address
  * @return byte that equals to 1
  */ 
byte bit_set(uint8_t bitValue, uint8_t port) {
  // Implement the bit setting logic here
}

/**
  * This function sets the value 0 to the designated port via bitwise operations, overall,
  * setting designated PIN (port) to low
  * @param[bitValue] 8 bit unsigned integer value that is used for left bit shifting
  * @param[port] 8 bit unsigned integer value that represents the direct register address
  * @return byte that equals to 0
  */
byte bit_clear(uint8_t bitValue, uint8_t port) {
  // Implement the bit clearing logic here
}
