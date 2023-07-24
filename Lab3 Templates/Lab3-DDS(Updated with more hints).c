{\rtf1\ansi\ansicpg1252\cocoartf2709
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 /**\
 * @file Lab3_DDS.ino\
 * @date __date__\
 * @brief ECE Lab 3 Assignment\
 * @detail University of Washington ECE 474\
 * \
 * \
 */\
\
// Define states for TCB\
typedef enum \{\
    READY,   // The task is ready to be run\
    RUNNING, // The task is currently running\
    DEAD     // The task has terminated and is not ready to be run\
\} TaskStatus;\
\
/**\
  * A struct that defines the template of characteristics for one task\
  * @return a struct that contains the characteristics declared within\
  */\
typedef struct TCB \{\
    int uniqueID;           // Unique ID for the task\
    char taskName[21];      // Task name, up to 20 characters\
    int timesRestarted;     // Total number of times the task has been started/restarted\
    TaskStatus status;      // Current status of the task\
\} TCB;\
\
// Create an array of TCB structures to control the processes\
TCB tcbList[MAX_TASKS];     // This list will contain all tasks that are READY or RUNNING\
TCB deadTaskList[MAX_TASKS]; // A separate list for DEAD tasks\
\
// Keep track of the currently running task\
int currentTaskIndex; // The index of the currently running task in tcbList\
\
/**\
  * Function initializes pins to output. Also initializes tasks\
  * You'll need to set up the initial state of your tasks here\
  */\
void setup() \{\
  // Initialize the required pins as output\
  // Set the required mode and prescalar value\
  // Set the bits of COMnC1, COMnB1, COMnA1 to 0\
  // Set the bits of COMnC0, COMnC0, COMnC0 to 1\
  // Initialize characteristics of tasks in your tcbList array\
  // For example, set their initial status, set their unique IDs and names, etc.\
\}\
\
/**\
  * Function controls the tasks running dependent on the tcbList and scheduler\
  * This is where the scheduling happens. In each iteration of the loop, the scheduler\
  * decides which task to run next based on their status and possibly other factors.\
  */\
void loop() \{\
  // Implement the scheduler here\
  // In each loop iteration, decide which task to run next, then run it\
\}\
\
/**\
  * Flashes an external LED for a given amount of time, then turns off for another amount of time\
  * This could be one of the tasks you run. The specifics will depend on your hardware setup.\
  */\
void flashExternalLED() \{\
  // Implement the LED flashing logic here\
\}\
\
/**\
  * Function that plays a theme from a song\
  * and then sleeps for a certain amount of time, then plays the theme again\
  * This could be another one of the tasks you run. The specifics will depend on your hardware setup.\
  */\
void playSpeaker() \{\
  // Implement the song playing logic here\
\}\
\
/**\
  * This function serves as a function pointer to any given task to execute\
  * It's unclear from your description what exactly this function should do, but it seems like\
  * it's meant to be a way to run a task by giving a pointer to its function.\
  */   \
void function_ptr(void* function()) \{\
  // Invoke the function passed as parameter here\
  // You'll probably need to cast the void pointer to a function pointer type\
\}\
\
/**\
  * This function allows a task to terminate itself by manipulating its TCB\
  * A task can call this function to change its own status to DEAD and remove itself\
  * from the tcbList.\
  */  \
void task_self_quit() \{\
  tcbList[currentTaskIndex].status = DEAD;\
  // Move this task to the deadTaskList\
  // Remember to also remove it from tcbList. You'll need to write the code for this.\
\}\
\
/**\
  * This function allows a task to start up another task\
  * A task can call this function to change the status of a DEAD task to READY,\
  * effectively "reviving" the task.\
  * @param[task] pointer to task control block struct\
  */  \
void task_start(TCB* task) \{\
  task->status = READY;\
  task->timesRestarted++;\
  // Add this task to the tcbList\
  // Remember to also remove it from the deadTaskList. You'll need to write the code for this.\
\}\
\
/**\
  * This function allows for tasks to be processed and executed\
  * This function will be called in the loop() function. It should check the status of\
  * each task in the tcbList and decide which one to run next, updating currentTaskIndex\
  * accordingly.\
  */ \
void scheduler()\{\
  // Implement the task scheduling logic here\
  // Make sure to update the currentTaskIndex appropriately\
\}\
\
/**\
  * This function sets the value 1 to the designated port via bitshifting, overall,\
  * setting designated PIN (port) to high\
  * @param[bitValue] 8 bit unsigned integer value that is used for left bit shifting\
  * @param[port] 8 bit unsigned integer value that represents the direct register address\
  * @return byte that equals to 1\
  */ \
byte bit_set(uint8_t bitValue, uint8_t port) \{\
  // Implement the bit setting logic here\
  // This function will be hardware-dependent\
\}\
\
/**\
  * This function sets the value 0 to the designated port via bitwise operations, overall,\
  * setting designated PIN (port) to low\
  * @param[bitValue] 8 bit unsigned integer value that is used for left bit shifting\
  * @param[port] 8 bit unsigned integer value that represents the direct register address\
  * @return byte that equals to 0\
  */\
byte bit_clear(uint8_t bitValue, uint8_t port) \{\
  // Implement the bit clearing logic here\
  // This function will be hardware-dependent\
\}\
}