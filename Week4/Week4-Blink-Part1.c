// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}


// Define LED_PIN as PB7 which corresponds to digital pin 13 on the Arduino Mega. PB7 is a predefined macro 
#define LED_PIN PB7

void setup() {
  // DDRB is the Data Direction Register for Port B on the microcontroller.
  // This register determines the direction of the pins on port B.
  // A bit value of 0 in DDRB makes the corresponding pin an input, while a bit value of 1 makes it an output.
  
  // The operation '1 << LED_PIN' shifts the binary representation of 1 to the left by the number of positions
  // indicated by LED_PIN (which is 7 for PB7). This creates a binary value where the seventh bit is set to 1.
  // For instance, '1 << 7' yields '10000000' in binary, which is 128 in decimal.
  
  // The '|=' operator is a bitwise OR assignment. It sets the corresponding bit of DDRB to 1 without changing
  // the rest of the bits. This effectively configures pin 13 as an output.
  DDRB |= (1 << LED_PIN);
}

void loop() {
  // PORTB is the register for writing digital values (HIGH or LOW) to port B.
  // Writing a 1 to a bit in PORTB sets the corresponding pin to HIGH (5V), and clearing the bit to 0 sets it to LOW (0V).
  
  // The operation 'PORTB |= (1 << LED_PIN)' uses bitwise OR to set the bit corresponding to pin 13 to HIGH.
  // If the bit was already HIGH, it remains HIGH; if it was LOW, it becomes HIGH.
  PORTB |= (1 << LED_PIN);
  
  // Wait for a second (1000 milliseconds)
  delay(1000);
  
  // The operation 'PORTB &= ~(1 << LED_PIN)' first creates a binary number with all bits set to 1 except for
  // the bit corresponding to pin 13, which is set to 0 ('~(1 << LED_PIN)'). The '&=' operator is a bitwise AND assignment,
  // which clears the bit for pin 13 in PORTB to LOW. The rest of the pins are unaffected due to the '1' bits in the binary number.
  PORTB &= ~(1 << LED_PIN);
  
  // Wait for a second (1000 milliseconds)
  delay(1000);
}

