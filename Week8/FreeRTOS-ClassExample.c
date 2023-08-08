#include <Arduino_FreeRTOS.h>

#define TASK1_PRIORITY (1)
#define TASK2_PRIORITY (2)
#define TASK3_PRIORITY (3)

//Declare a queue variable to hold our data
QueueHandle_t sensorQueue;

//We need to initialize our setup

void setup() {

    pinMode(13, OUTPUT);
    Serial.begin(9600);

    //create a queue capable of holding 10 int values.
    sensorQueue xQueueCreate(10, sizeof(int));

    if (sensorQueue != NULL){
        
        xTaskCreate(readSensor, "ReadSensor", 128, NULL, TASK1_PRIORITY, NULL);

        xTaskCreate(
            flashLED,       //Task Function
            "FlashLED"      //A name for humans
            128,            //Stack size (in words not bytes, each word is 2 bytes)
            NULL,           //Task input prameters
            TASK2_PRIORITY, //Priority
            NULL            //Task handle (not used)
        );

        xTaskCreate(displayValue, "Display", 128, NULL, TASK3_PRIORITY, NULL);

        vTaskStartScheduler();
    }
    else{
        //if the queue wasnt created properly, print an error message
        Serial.println("Failed to create queue, try again");
    }
}

// void loop is not needed since we are using FreeRTOS scheduler
void loop(){}

//Task 1 (read data from a POT and share that with Task 2 and 3)
void readSensor(void *pvParameters){
    int sensorValue;
    for (;;){
        //reading the value and saving it in our sensorValue int
        sensorValue = analogRead(A0);

        //sensd the value and we just read to the queue
        xQueueSend(sensorQueue, &sensorValue, portMAX_DELAY);

        //Wait for 10ms before you read the value again
        vTaskDelay(10);
    }
}

//Task 2 (to use the data from Task 1 to adjust the flashing of an LED)
void flashLED(void *pvParameters){
    int receivedValue;
    for (;;) {
        if (xQueueReceive(sensorQueue, &receivedValue, portMAX_DELAY)=pdTRUE){
            // If the value is greater than half the max ADC (1023/2 = 512)
            if (receivedValue>512){
                digitalWrite(13, HIGH);
                vTaskDelay(200);
                digitalWrite(13, LOW);
            }
            vTaskDelay(10);
        }
        /* this is not the proper way to set up your error system
        else{
            //if the queue wasnt created properly, print an error message
            Serial.println("Failed to recieve data from queue, try again");
        }*/
        //  For your Bonus, define a new behavior for your LED to flash at a different rate based on the sensorValue
    }
}

//Task 3 (to display the sensorValue)
void displayValue(void *pvParameters){
    int receivedValue;
    
    //In your bonus, include a brief comment explaining what is happening in the next two lines. you need to look up the API ref.
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 5000;
    //end of bonus question

    for (;;) {
        if (xQueuereceive(sensorQueue, &receivedValue, portMAX_DELAY)=pdTRUE){
            Serial.println(receivedValue);
        }
        /* this is not the proper way to set up your error system
        else{
            //if the queue wasnt created properly, print an error message
            Serial.println("Failed to recieve data from queue, try again");
        }*/
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}
