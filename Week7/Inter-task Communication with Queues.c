#define QUEUE_SIZE 5 // This defines the maximum number of items that can be in the queue at once.

// Define the Queue Handle. A Queue handle is like a pointer to the queue, and we use it to
// reference the queue in various function calls.
QueueHandle_t xQueue;

// Producer Task
void vTaskProducer(void *pvParameters) {
  int i = 0;
  // This is an infinite loop that causes the task to run indefinitely.
  for (;;) {
    // Check if the queue has been created.
    if (xQueue != NULL) {
      // Send an item to the back of the queue
      if (xQueueSendToBack(xQueue, (void *)&i, (TickType_t)10) == pdPASS) {
        // If the item was successfully added to the queue, print a success message.
        Serial.println("Added to queue: " + String(i));
      } else {
        // If the item couldn't be added to the queue (because the queue is full), 
        // print a failure message.
        Serial.println("Failed to post the message, even after 10 ticks.");
      }
    }
    i++; // Increment the integer that will be added to the queue.
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for a second
  }
}

// Consumer Task
void vTaskConsumer(void *pvParameters) {
  int rxInt; // This variable will hold the integers received from the queue.
  // Another infinite loop for this task.
  for (;;) {
    // Check if the queue has been created.
    if (xQueue != NULL) {
      // Receive an item from the queue.
      if (xQueueReceive(xQueue, &(rxInt), (TickType_t)10) == pdPASS) {
        // If an item was successfully received from the queue, print it.
        Serial.println("Received: " + String(rxInt));
      }
    }
    vTaskDelay(500 / portTICK_PERIOD_MS); // Delay for half a second.
  }
}

void setup() {
  Serial.begin(9600);
  
  // Create a queue capable of containing 5 integers. 
  // This queue will be used to communicate between the producer and consumer tasks.
  xQueue = xQueueCreate(QUEUE_SIZE, sizeof(int));

  // Create the tasks.
  xTaskCreate(vTaskProducer, "Producer", 1000, NULL, 1, NULL);
  xTaskCreate(vTaskConsumer, "Consumer", 1000, NULL, 1, NULL);
}

void loop() {
  // Do nothing here. Let the FreeRTOS scheduler manage the tasks.
}
