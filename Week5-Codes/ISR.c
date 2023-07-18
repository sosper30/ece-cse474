// Define a volatile variable for count. Volatile is used for variables that can change 
// in the background during normal program flow (like in an ISR)
volatile unsigned int count = 0;

// ISR for Timer1 overflow. This function will be called every time Timer1 overflows. 
ISR(TIMER1_OVF_vect) {
    count++;  // Increment the counter
} 

void setup() {
    // Initialize digital pin 13 as an output
    pinMode(13, OUTPUT);

    // Initialize Timer1 
    noInterrupts();          // Disable all interrupts
    TCCR1A = 0;              // Set entire TCCR1A register to 0
    TCCR1B = 0;              // Set entire TCCR1B register to 0

    // Set compare match register to desired timer count
    TCNT1 = 0;               // Initialize counter value to 0
    TCCR1B |= (1 << CS10);   // Turn on CTC mode with no prescaling

    // Enable timer overflow interrupt
    TIMSK1 |= (1 << TOIE1);

    interrupts();            // Enable all interrupts
}

void loop() {
    noInterrupts();  // Begin critical section

    // Check if count is greater than 20
    if (count > 20) {
        digitalWrite(13, HIGH);  // Turn on the LED on pin 13
    }

    interrupts();  // End critical section
}
