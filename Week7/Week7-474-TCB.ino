/**
 * @file Week7-474-TCB.ino
 * @author Sep Makhsous
 * @date February 12, 2024
 * @brief This program demonstrates a simple task scheduling system to control the flashing of two LEDs
 * WokWi Link: https://wokwi.com/projects/389600034291294209 
 */


#define LED_PIN_TASK1 3 // Pin number for the first LED. Indicates the digital output connected to the first LED.
#define LED_PIN_TASK2 4 // Pin number for the second LED. Used to control the second LED.

// Task states definitions, representing the lifecycle of a task.
#define STATE_RUNNING 0 // Task is currently running. 
#define STATE_READY 1 // Task is ready to run. 
#define STATE_SLEEP 2 // Task is waiting for its sleep time to expire before it can run again.
#define STATE_DEAD 3 // Task has completed its function or has been terminated.

#define N_MAX_TASKS 5 // Maximum number of tasks that can be managed by the system.

int task_delays[] = {1000, 1000, 500, 500}; // Array defining delays for tasks in milliseconds. Adjust these values to change the blinking rate.

// Structure defining a Task Control Block (TCB), which holds information about each task.
typedef struct TCBstruct {
  int taskID; // Unique identifier for the task within the task list.
  char taskName[20]; // Descriptive name for the task. Useful for debugging and readability.
  int numCalls; // Counts how many times the task has been called. Useful for monitoring task activity.
  unsigned short int state; // Current state of the task (e.g., READY, SLEEP, DEAD).
  void (*functionptr)(); // Pointer to the function that the task needs to execute.
  unsigned int sleeptime; // Time in milliseconds the task needs to wait before next execution.
} task;

task tasklist[N_MAX_TASKS]; // Array to hold tasks. Acts as the Task Control Block (TCB) registry.
int deadlist[N_MAX_TASKS]; // Array to keep track of tasks that have been terminated.
int time_count; // Counter used to simulate time passing.
int quit_flag; // A flag indicating whether a task has requested to terminate itself.

void setup() {
  // Initializes digital pins connected to LEDs as outputs. Sets the initial state of LEDs to OFF for safety.
  pinMode(LED_PIN_TASK1, OUTPUT);
  digitalWrite(LED_PIN_TASK1, LOW);
  pinMode(LED_PIN_TASK2, OUTPUT);
  digitalWrite(LED_PIN_TASK2, LOW);

  time_count = 0; // Reset time counter.
  quit_flag = 0; // Ensure quit flag is reset at start.

  // Initialize the task list with tasks for toggling LEDs. Each task is assigned a function, initial state, and sleep time.
  // The pattern is to have one task for turning an LED on and another for turning it off, creating a blinking effect.
  initTask(0, "LED1_on", &task1_on, STATE_READY, 0);
  initTask(1, "LED1_off", &task1_off, STATE_SLEEP, 250); // LED2 blinks with a period of 500 ms (250 ms on, 250 ms off).
  initTask(2, "LED2_on", &task2_on, STATE_READY, 0);
  initTask(3, "LED2_off", &task2_off, STATE_SLEEP, 250); // LED2 blinks with a period of 500 ms (250 ms on, 250 ms off).
}

void loop() {
  // Main loop iterates over the tasklist, executing tasks based on their state and sleep time.
  for (int i = 0; tasklist[i].functionptr != NULL; i++) {
    // Check if task is ready and sleep time has elapsed.
    if (tasklist[i].state == STATE_READY && tasklist[i].sleeptime == 0) {
      tasklist[i].functionptr(); // Execute the task's function.
      tasklist[i].numCalls++; // Increment the call count for monitoring.
      tasklist[i].state = STATE_SLEEP; // Set task to sleep state.
      tasklist[i].sleeptime = task_delays[i % 4]; // Assign sleep time from the predefined delays array.
    } else if (tasklist[i].state == STATE_SLEEP) {
      // If task is sleeping, decrement its sleep time.
      tasklist[i].sleeptime--;
      if (tasklist[i].sleeptime <= 0) {
        // Once sleep time is up, set task state to ready for next execution.
        tasklist[i].state = STATE_READY;
      }
    }
    // Handle task self-termination logic.
    if (quit_flag != 0) {
      tasklist[i].state = STATE_DEAD;
      deadlist[i] = tasklist[i].taskID;
      quit_flag = 0; // Reset quit flag after handling.
    }
  }
  increment(); // Increment the simulated time counter.
}

// Increment function simulates time passing.
void increment() {
  delay(1); // Simulates a 1 ms time step.
  if (time_count < 30000) { // Simulate for a specific duration (30 seconds in this example).
    time_count++;
  } else {
    time_count = 0; // Reset time counter to loop the simulation.
  }
}

// Task functions to control LEDs.
void task1_on() { digitalWrite(LED_PIN_TASK1, HIGH); }
void task1_off() { digitalWrite(LED_PIN_TASK1, LOW); }
void task2_on() { digitalWrite(LED_PIN_TASK2, HIGH); }
void task2_off() { digitalWrite(LED_PIN_TASK2, LOW); }

// Utility function to initialize tasks. 
void initTask(int id, const char* name, void (*func)(), unsigned short int initialState, unsigned int initialSleep) {
  tasklist[id].taskID = id;
  strncpy(tasklist[id].taskName, name, sizeof(tasklist[id].taskName) - 1); // Ensure name is null-terminated.
  tasklist[id].functionptr = func;
  tasklist[id].state = initialState;
  tasklist[id].sleeptime = initialSleep;
  tasklist[id].numCalls = 0;
}

// Function to terminate a task from within itself.
void task_self_quit() {
  quit_flag = 1; // Set quit flag to indicate a task wishes to terminate.
}

// Function to restart a terminated task.
void task_start(int taskID) {
  if (deadlist[taskID] != -1) { // Check if task is in the deadlist.
    deadlist[taskID] = -1; // Remove task from deadlist.
    initTask(taskID, tasklist[taskID].taskName, tasklist[taskID].functionptr, STATE_READY, 0); // Reinitialize the task.
  }
}
