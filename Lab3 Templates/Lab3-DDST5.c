/**
 * @file Lab3_DDST5.ino
 * @date __date__
 * @brief ECE Lab 3 Assignment
 * @detail University of Washington ECE 474
 * 
 * 
 */


// Define necessary constants and variables

// Define state constants for TCB, timers, and periods

// Define necessary arrays or variables for storing data

// Define necessary struct for TCB

// Define necessary functions and their prototypes

/**
 * Initialize pins and tasks
 */
void setup() {
  // Set up pins as outputs

  // Initialize seven-segment display

  // Set up timers and their configurations

  // Initialize characteristics of tasks in the processList
}

/**
 * Control the execution of tasks based on the scheduler and processList
 */
void loop() {
  while (1) {
    // Call the scheduler function

    // Delay for a short period of time
  }
}

/**
 * Function pointer for executing a task
 * @param function Pointer to the task function
 */
void function_ptr(void* function()) {
  // Execute the given task function
}

/**
 * Terminate the current task by changing its state
 */
void task_self_quit() {
  // Change the state of the current task to DEAD
}

/**
 * Start another task by changing its state to READY
 * @param task Pointer to the task control block struct
 */
void task_start(TCB* task) {
  // Change the state of the given task to READY
}

/**
 * Scheduler function for executing tasks
 */
void scheduler() {
  // Check if the current task needs to be reset to the beginning of the processList

  // Set the newTask variable to the currentTask

  // Check if the state of the newTask is READY

  // Call the function_ptr with the function of the newTask

  // Increment the currentTask to traverse the processList
}

/**
 * Task function that plays a specific song and sleeps for a certain duration
 * @param counter Timing variable to keep track of note length
 */
void playSpeakerV2(int counter) {
  // Play the notes of the song one by one at the specified timing

  // Reset the counter when it reaches a certain value
}

/**
 * Task function that displays a countdown value on the seven-segment display
 * @param count Counter variable to control time
 */
void countdown(int count) {
  // Turn off the seven-segment display

  // Convert the count value to the desired format

  // Display the frequency value on the seven-segment display

  // Reset the countdownCounter when it reaches a certain value
}

/**
 * Task function that flashes an external LED at a specific interval
 * @param counter Counter variable to keep track of time
 */
void flashExternalLEDV2(int counter) {
  // Turn on or off the external LED based on the counter value
}

/**
 * Task function that displays a smiley face on the seven-segment display
 * @param counter Counter variable to keep track of time
 */
void smileyFace(int counter) {
  // Turn off the seven-segment display

  // Display each segment of the smiley face sequentially based on the counter value

  // Increment the smileyFaceCounter
}

/**
 * Task function that combines all the required functionality
 */
void task5() {
  // Implement the logic for task 5 by calling the necessary functions and controlling the timing
}

/**
 * Helper function to set a bit in a register
 * @param bitValue The bit value to be set
 * @param port The port register to modify
 * @return The modified port value
 */
byte bit_set(uint8_t bitValue, uint8_t port) {
  // Set the specified bit in the given port register

  // Return the modified port value
}

/**
 * Helper function to clear a bit in a register
 * @param bitValue The bit value to be cleared
 * @param port The port register to modify
 * @return The modified port value
 */
byte bit_clear(uint8_t bitValue, uint8_t port) {
  // Clear the specified bit in the given port register

  // Return the modified port value
}
