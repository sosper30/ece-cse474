// Define the pin numbers for the LEDs
const int ledPin1 = 13;  // Pin number for LED 1
const int ledPin2 = 12;  // Pin number for LED 2

// Function prototypes for LED blinking
void blinkLED1();  // Declaration of function for blinking LED 1
void blinkLED2();  // Declaration of function for blinking LED 2

// Function pointer types
typedef void (*funcPtr)();  // Define a type for function pointers with void return type and no arguments

// Function pointers
funcPtr funcPtr1 = blinkLED1;  // Initialize funcPtr1 to point to blinkLED1 function
funcPtr funcPtr2 = blinkLED2;  // Initialize funcPtr2 to point to blinkLED2 function

// Function to start a function
void start_function(funcPtr functionPTR) {  // Function that takes a function pointer as an argument
  functionPTR();  // Executes the function that functionPTR points to
}

void setup() {
  pinMode(ledPin1, OUTPUT);  // Set the mode of ledPin1 as OUTPUT
  pinMode(ledPin2, OUTPUT);  // Set the mode of ledPin2 as OUTPUT
}

void loop() {
  start_function(funcPtr1);  // Start blinkLED1 function using start_function
  start_function(funcPtr2);  // Start blinkLED2 function using start_function
}

// Function to blink LED 1
void blinkLED1() {
  digitalWrite(ledPin1, HIGH);  // Turn on LED 1
  delay(500);  // Wait for 0.5 second
  digitalWrite(ledPin1, LOW);  // Turn off LED 1
  delay(500);  // Wait for 0.5 second, total cycle time = 1 second
}

// Function to blink LED 2
void blinkLED2() {
  digitalWrite(ledPin2, HIGH);  // Turn on LED 2
  delay(250);  // Wait for 0.25 second
  digitalWrite(ledPin2, LOW);  // Turn off LED 2
  delay(250);  // Wait for 0.25 second, total cycle time = 0.5 second
}
