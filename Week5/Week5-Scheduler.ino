/*
 * Scheduler Example with Function Pointers and Sleep
 * Author: Sep Makhsous
 * Date: January 30, 2024
 *
 * This code demonstrates a simple task scheduler for microcontrollers.
 * It uses function pointers for task management and implements a sleep mechanism
 * to control task execution frequency. The main concepts include task scheduling,
 * pointers, global and static variables, and timing control.
 */

// Define constants for LED control and the number of tasks.
#define LED_INTERNAL 13    // Pin number for the internal LED.
#define LED_EXTERNAL 10    // Pin number for an external LED.
#define LEDPORT      PORTB // Port register for controlling LED state.
#define LEDDDR       DDRB  // Data Direction Register for setting LED pins as output.
#define L_I_BIT      1<<7  // Bit mask for the internal LED (bit 7).
#define L_E_BIT      1<<4  // Bit mask for the external LED (bit 4).
#define NTASKS       3     // Number of tasks in the scheduler.

// Global Variables and Function Pointer Array
void (*tasks [NTASKS])();     // Array of function pointers for tasks.
int delays[NTASKS] = {0};     // Array to track delay time for each task.
int task_active = 0;          // Index of the currently active task.
// Note: Global variables are accessible throughout the entire file. They retain their value 
// between function calls and are initialized only once at the start of the program.

// Function to simulate sleep behavior for a task.
void sleep(int sleeptime){
  delays[task_active] = sleeptime; // Set the delay for the current task.
  // Note: Using a global variable here allows us to track the state across multiple function calls.
}

// setup() runs once upon a reset or power-on.
void setup(){
  // Set up LED pins as outputs.
  LEDDDR |= ( L_I_BIT | L_E_BIT ); // Configure LED pins as output.

  // Initialize the task array with task functions.
  tasks[0] = taskA; // Assign taskA to the first slot.
  tasks[1] = NULL;  // No task assigned to the second slot.
  tasks[2] = taskB; // Assign taskB to the third slot.
}
 
// loop() runs continuously after setup() completes.
void loop(){
  // Iterate through tasks and execute if they are ready.
  for(task_active = 0; task_active < NTASKS; task_active++) {
    if((tasks[task_active] != NULL) && (delays[task_active] <= 0)){
      (*tasks[task_active])(); // Execute the task if it's not NULL and delay is expired.
    } else if(tasks[task_active] != NULL){
      delays[task_active]--; // Decrement delay if the task is not ready yet.
    }
  }
  delay(1); // Synchronize by delaying 1 ms at the end of each loop iteration.
}

// TaskA: Flash the onboard LED 10 times per second.
void taskA(){
  static int flag = 0; // Static variable to toggle LED state.
  // Note: A static variable inside a function retains its value between calls to that function.
  // It's initialized only once and is a local but persistent variable.
  flag ^= 1;           // Toggle flag state.
  sleep(1000);         // Set taskA to sleep for 1000 ms.

  // Toggle the internal LED based on flag state.
  if(flag) {
    LEDPORT |= L_I_BIT;  // Turn on internal LED.
  } else {
    LEDPORT &= ~L_I_BIT; // Turn off internal LED.
  }
}

// TaskB: Flash the offboard LED once per second.
void taskB(){
  static int time = 0; // Static counter to track time.
  // Note: Similar to 'flag' in taskA, 'time' here retains its value across multiple calls.
  time++;              // Increment time each call.

  // Toggle external LED based on time.
  if(time == 500) {
    LEDPORT |= L_E_BIT;  // Turn on external LED at half-second.
  }
  if(time == 1000) {
    LEDPORT &= ~L_E_BIT; // Turn off external LED at one second.
    time = 0;            // Reset time counter.
  }
}
