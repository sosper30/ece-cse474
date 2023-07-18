// Constants for different states of tasks
#define N_MAX_TASKS 10
#define STATE_RUNNING 0
#define STATE_READY 1
#define STATE_WAITING 2
#define STATE_INACTIVE 3

// Define the pin numbers for the LEDs
const int ledPin1 = 13;  // Pin number for LED 1
const int ledPin2 = 12;  // Pin number for LED 2

// Define a Task Control Block (TCB) structure which contains
// a function pointer to the task function, the task state, and a delay value
typedef struct TCBStruct {
  void (*fptr)(void); // Function pointer to task
  unsigned short int state; // State of the task
  unsigned int delay; // Delay value for the task (not used in this code)
} TCBStruct;

// Array to store all Task Control Blocks
TCBStruct TaskList[N_MAX_TASKS];

// Function prototypes for task A and task B
void task_A();
void task_B();

void setup() {
  // Set the mode of the LED pins as OUTPUT
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // Initialize task list
  int j=0;
  
  // Add task_A to the task list, set its state to READY, and set delay to 0
  TaskList[j].fptr = task_A;
  TaskList[j].state = STATE_READY;
  TaskList[j].delay = 0;
  j++;

  // Add task_B to the task list, set its state to READY, and set delay to 0
  TaskList[j].fptr = task_B;
  TaskList[j].state = STATE_READY;
  TaskList[j].delay = 0;
  j++;

  // Mark the end of the task list with a NULL function pointer
  TaskList[j].fptr = NULL; 
}

void loop() {
  // Execute all ready tasks in the task list
  for(int i=0; i<N_MAX_TASKS; i++) {
    // Check if the task is not NULL and its state is READY
    if(TaskList[i].fptr != NULL && TaskList[i].state == STATE_READY) {
      TaskList[i].fptr(); // Execute the task
    } else {
      // Stop the loop when reaching a NULL task or a task that is not ready
      break; 
    }
    // Delay for 1 ms
    delay(1); 
  }
}

// Task A: Flash the LED connected to ledPin1 at 1Hz (0.5s ON, 0.5s OFF)
void task_A() {
  static int time;  // Static variable to keep track of time
  time++;
  // At 500 ms, turn on the LED
  if(time==500) {
    digitalWrite(ledPin1, HIGH); 
  }
  // At 1000 ms (1 s), turn off the LED and reset time
  if(time==1000) {
    digitalWrite(ledPin1, LOW);  
    time = 0; 
  }
}

// Task B: Flash the LED connected to ledPin2 at 2Hz (0.25s ON, 0.25s OFF)
void task_B() {
  static int time;  // Static variable to keep track of time
  time++;
  // At 250 ms, turn on the LED
  if(time==250) {
    digitalWrite(ledPin2, HIGH); 
  }
  // At 500 ms, turn off the LED and reset time
  if(time==500) {
    digitalWrite(ledPin2, LOW);  
    time = 0;  
  }
}
