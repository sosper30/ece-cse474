/**
 * @file Lab3_RR.ino
 * @brief ECE Lab 3 Assignment
 * @detail University of Washington ECE 474
 */

// Define necessary variables and constants

/**
 * Set up pins and timers for speaker and LED
 */
void setup() {
  // Set up pins as outputs for the speaker and LED

  // Set up timers and their configurations for speaker
}

/**
 * Loop function that controls the Round-Robin schedule
 */
void loop() {
  while (1) {
    // Call the flashExternalLED function

    // Call the playSpeaker function

    // Increment the timerCounter

    // Delay for a short period of time
  }
}

/**
 * Function for flashing the external LED
 */
void flashExternalLED() {
  // Implement the logic for flashing the LED based on the timerCounter

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
