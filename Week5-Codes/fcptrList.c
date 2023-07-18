#define NUMBER_OF_FUNCTIONS 10
#define NTASKS 4

// Define the pin numbers for the LEDs
const int ledPin1 = 13;  // Pin number for LED 1
const int ledPin2 = 12;  // Pin number for LED 2

// Define a list of all the tasks which are currently running
void (*runningTasks[NUMBER_OF_FUNCTIONS])(void *p) = {0};

// Function prototypes for LED blinking
void taskA(void *p);  // Declaration of function for blinking LED 1
void taskB(void *p);  // Declaration of function for blinking LED 2

// Function prototype for scheduler
void scheduler();

// List of ready tasks
void (*readytasks[NTASKS]) (void *p) = {0};  // Initialize all pointers with NULL

void setup() {
  pinMode(ledPin1, OUTPUT);  // Set the mode of ledPin1 as OUTPUT
  pinMode(ledPin2, OUTPUT);  // Set the mode of ledPin2 as OUTPUT
  
  // Initialize array of pointers to tasks
  readytasks[0] = taskA;
  readytasks[1] = taskB;
  // NULL signals the last task
  readytasks[2] = NULL;
}

void loop() {
  // Call scheduler
  scheduler();
  // 1 ms timer
  delay(1);  
}

void taskA(void *p) {
  digitalWrite(ledPin1, HIGH);  // Turn on LED 1
  delay(500);  // Wait for 0.5 second
  digitalWrite(ledPin1, LOW);  // Turn off LED 1
  delay(500);  // Wait for 0.5 second, total cycle time = 1 second
}

void taskB(void *p) {
  digitalWrite(ledPin2, HIGH);  // Turn on LED 2
  delay(250);  // Wait for 0.25 second
  digitalWrite(ledPin2, LOW);  // Turn off LED 2
  delay(250);  // Wait for 0.25 second, total cycle time = 0.5 second
}

void scheduler() {
  for(int i=0; i<NTASKS; i++){
    if(readytasks[i] != NULL){
      readytasks[i](NULL);
    } else {
      break;  // Stop the loop when reaching the NULL task
    }
  }
}
