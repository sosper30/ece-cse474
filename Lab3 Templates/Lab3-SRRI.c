/**
 * @file Lab3_SRRI.ino
 * @brief ECE Lab 3 Assignment
 * @detail University of Washington ECE 474
 */

// Define necessary variables and constants

/**
 * Set up pins and timers for speaker and LED
 * Initialize the task structure for the ISR
 */
void setup() {
  // Set up pins as outputs for the speaker and LED

  // Set up timers and their configurations for speaker

  // Initialize the task structure for the ISR
}

/**
 * Loop function that controls the tasks running based on their states
 */
void loop() {
  // Enter the loop when a task is present in the taskScheduler
  while (taskScheduler[currentTask] != NULL) {
    // Run the task if it is not in the SLEEPING state

    // Change the task state to RUNNING

    // Increment the currentTask and timerCounter
  }

  // Reset the currentTask to 0
}

/**
 * Function for flashing the external LED
 */
void flashExternalLED() {
  // Implement the logic for flashing the LED based on the timerCounterLED

  // Increment the timerCounterLED
}

/**
 * Function for playing the theme song on the speaker
 */
void playSpeaker() {
  // Implement the logic for playing the notes of the song based on the timerCounterSong

  // Increment the timerCounterSong
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

/**
 * Function that controls the sleep time of a task
 * @param t The sleep time in milliseconds
 */
void sleep_474(int t) {
  // Set the sleep time of the current task

  // Change the task state to SLEEPING
}

/**
 * Function that synchronizes the schedule and tasks while in the PENDING state
 */
void schedule_sync() {
  // Enter an infinite loop when sFlag is PENDING

  // Update the sleep time of the task

  // Wake up any sleeping task if the sleep time is negative

  // Reset the sFlag to PENDING
}

/**
 * Interrupt Service Routine for TIMER0_COMPA_vect
 * Sets the flag to DONE
 */
ISR(TIMER0_COMPA_vect) {
  // Set the sFlag to DONE
}
