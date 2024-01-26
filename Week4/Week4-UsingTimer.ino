/**
 * @file main.c
 * @author Ethan Widger
 * @date January 25, 2024
 * @brief This file contains the setup and loop functions for a simple LED blink program
 *        on Arduino Mega using direct register manipulation for AVR microcontrollers.
 *
 * Detailed comments and explanations provided by Sep Makhsous.
 */

// Set up function, runs once at startup.
void setup() {
  // Configure PB7 (which is also digital pin 13 on Arduino Mega) as an output pin.
  // DDRB stands for Data Direction Register for Port B.
  // |= is a bitwise OR assignment operator, which sets the particular bit without affecting others.
  // (1 << PB7) shifts a binary 1 to the left by the value of PB7 (which is 7), resulting in 10000000 in binary.
  DDRB |= (1 << PB7); // This operation sets the 8th bit of Port B (PB7) to 1, making it an output.

  // Initialize Timer 4 control registers A and B to 0.
  // This ensures that all timer settings are at default before setting up specific bits.
  TCCR4A = 0; // Timer/Counter Control Register A for Timer 4
  TCCR4B = 0; // Timer/Counter Control Register B for Timer 4

  // Configure Timer 4 for CTC (Clear Timer on Compare Match) mode and set prescaler.
  // WGM42 bit is set to 1 for CTC mode. In this mode, the counter is cleared to 0 when the timer matches the OCR4A.
  // CS42 bit is set to 1 to select the clock prescaler of 256.
  // |= is used to set specific bits without affecting other bits in the register.
  TCCR4B |= (1 << WGM42) | (1 << CS42); // Set WGM42 bit and prescaler with a single statement.

  // Set the Output Compare Register A for Timer 4.
  // OCR4A is used in CTC mode as the top value for the counter.
  // The value set here determines the timer's count top and thus the timing for the compare match.
  // 31250 is the calculated value to achieve a specific time delay with the given clock frequency and prescaler.
  OCR4A = 31250; // Timer 4 will count from 0 to this value before resetting to 0 and triggering an OCF4A.
}

// Loop function runs continuously after setup finishes.
void loop() {
  // Check if the Output Compare Flag A for Timer 4 (OCF4A) is set.
  // This flag is set to 1 when Timer 4 matches the value in OCR4A.
  // TIFR4 is the Timer/Counter Interrupt Flag Register, which stores various flags for Timer 4.
  // & is the bitwise AND operator. It will only result in 1 if both bits being compared are 1.
  if (TIFR4 & (1 << OCF4A)) { // Check if the compare match flag for Timer 4's channel A is set.
    // Clear the OCF4A flag by writing a logic 1 to its bit location.
    // &= is a bitwise AND assignment operator.
    // ~(1 << OCF4A) creates a bitmask with all 1s except for the OCF4A bit.
    // ANDing with this bitmask clears the OCF4A bit and leaves others unchanged.
    TIFR4 &= ~(1 << OCF4A); // This is required to reset the flag for the next timer cycle.

    // Toggle the LED connected to PB7 (digital pin 13 on Arduino Mega).
    // PORTB is the register for reading and writing data to Port B.
    // ^= is a bitwise XOR assignment operator, which toggles the specified bit.
    // (1 << PB7) creates a bitmask that has a 1 only at the PB7 bit location.
    PORTB ^= (1 << PB7); // This toggles the LED's state from off to on, or on to off.
  }
}
