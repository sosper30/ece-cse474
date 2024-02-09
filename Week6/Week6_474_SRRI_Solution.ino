/**
 * Solution for Synchronized Round Robin with Interrupt Service Routine (SRRI) Scheduler
 * This code has only been tested on WokWi and has not been tested on the physical Mega board
 * WokWi Link: https://wokwi.com/projects/389231092272398337
 */


#define CLK_FREQ 16000000 // Define the clock frequency for timer calculations, 16 MHz for Arduino Mega.
#define CLK_SCALE 1024    // Prescaler value for Timer 0, used to scale down the clock frequency.

#define LED_PIN_TASK1 3 // Digital pin number for the first LED, indicating which pin controls the LED for Task 1.
#define LED_PIN_TASK2 4 // Digital pin number for the second LED, for controlling the LED in Task 2.

// Define task and system states.
#define PENDING 0  // Status flag indicating that an ISR (Interrupt Service Routine) cycle is pending.
#define DONE 1     // Status flag indicating that an ISR cycle is complete.
#define RUNNING 0  // Task state indicating it is currently being executed.
#define READY 1    // Task state indicating it is ready to be executed.
#define SLEEP 2    // Task state indicating it is currently sleeping (not executing).
#define N_MAX_TASKS 6 // Maximum number of tasks that can be scheduled in the taskArray.

// Declaration of global arrays and variables for task management.
void (*taskArray[N_MAX_TASKS])(); // Array of function pointers to tasks.
int current_sleeptime[N_MAX_TASKS]; // Array holding the sleep time for each task.
int current_state[N_MAX_TASKS]; // Array indicating the current state of each task.

volatile int sFlag; // Volatile flag used by ISR to signal the main loop about ISR cycle completion.
int task_index; // Index of the current task being processed in the loop.

void setup() {
  // Initialize digital pins connected to LEDs as outputs.
  pinMode(LED_PIN_TASK1, OUTPUT);
  pinMode(LED_PIN_TASK2, OUTPUT);

  // Timer 0 configuration for system timing/interrupts.
  OCR0A = CLK_FREQ / (500 * 2 * CLK_SCALE) - 1; // Calculate compare match value for a 2ms period.
  TCCR0B = (1<<WGM02) | (1<<CS00) | (1<<CS02); // Set Timer 0 to CTC mode with a prescaler of 1024.
  TIMSK0 |= (1<<OCIE0A); // Enable Timer 0 Compare Match A Interrupt.
  
  sei(); // Enable global interrupts for ISR handling.

  // Initialize task management variables and setup initial task states and sleep times.
  task_index = 0; // Start processing tasks from the beginning of the taskArray.
  sFlag = PENDING; // Initial ISR cycle status set to pending.

  // Setup taskArray with specific tasks, their initial sleep times, and states.
  int j = 0; // Task array index for initialization.
  // task1_on and task2_on are initially set to READY to start execution without delay.
  taskArray[j] = &task1_on; current_sleeptime[j] = 0; current_state[j] = READY; j++;
  // Initial sleep time of 250ms for task1_off and task2_off is set to ensure that they start with a delay,
  // allowing their corresponding "on" tasks to execute first and establish an initial LED state.
  taskArray[j] = &task1_off; current_sleeptime[j] = 250; current_state[j] = SLEEP; j++;
  taskArray[j] = &task2_on; current_sleeptime[j] = 0; current_state[j] = READY; j++;
  taskArray[j] = &task2_off; current_sleeptime[j] = 250; current_state[j] = SLEEP; j++;
  // schedule_sync is always READY to adjust task states and sleep times based on the ISR signal.
  taskArray[j] = &schedule_sync; current_sleeptime[j] = 0; current_state[j] = READY; j++;
  taskArray[j] = NULL; // Mark the end of task initialization with a NULL pointer.
}

// ISR for Timer 0 Compare Match A, triggered every 2ms based on timer setup.
ISR(TIMER0_COMPA_vect) {
  sFlag = DONE; // Signal that the ISR cycle is complete, allowing schedule_sync to update tasks.
}

void loop() {
  // Main loop cycles through tasks, checking their state and executing READY tasks.
  if (current_state[task_index] == READY) {
    current_state[task_index] = RUNNING;
    (*taskArray[task_index])(); // Execute the current READY task.
  }
  task_index++; // Move to the next task in the array.
  // Reset task_index to cycle through tasks continuously.
  if (task_index >= N_MAX_TASKS || taskArray[task_index] == NULL) task_index = 0;
}

void schedule_sync() {
  // Wait for ISR to signal that the current cycle is done.
  while (sFlag != DONE) {}
  for (int i = 0; taskArray[i] != NULL; i++) {
    // Decrement sleeptime for SLEEPING tasks and update their state to READY if sleeptime has elapsed.
    current_sleeptime[i] -= 2; // Each cycle represents a 2ms decrement.
    if (current_sleeptime[i] <= 0) {
      current_sleeptime[i] = 0;
      current_state[i] = READY; // Task is now READY for execution.
    }
  }
  task_index = -1; // Reset task_index for the next round, ensuring the first task is processed next.
  sFlag = PENDING; // Reset sFlag for the next ISR cycle.
}

void sleep_474(int t) {
  // Set the current task's state to SLEEP and assign a sleeptime.
  current_state[task_index] = SLEEP;
  current_sleeptime[task_index] = t;
}

void task1_on() {
  digitalWrite(LED_PIN_TASK1, HIGH);
  sleep_474(1000); // On for 1000ms
}

void task1_off() {
  digitalWrite(LED_PIN_TASK1, LOW);
  sleep_474(1000); // Off for 1000ms
}

void task2_on() {
  digitalWrite(LED_PIN_TASK2, HIGH);
  sleep_474(500); // On for 500ms
}

void task2_off() {
  digitalWrite(LED_PIN_TASK2, LOW);
  sleep_474(500); // Off for 500ms
}
