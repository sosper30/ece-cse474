// Controller

// Include the SPI library to use SPI communication functions
#include<SPI.h>

#define LED 7   // Define pin 7 for LED
#define ipbutton 2  // Define pin 2 for input button

int buttonvalue;  // Variable to store the button's state
int x;  // Variable to store the value to send to the slave

void setup(void)
{
  // Start serial communication at a baud rate of 115200
  Serial.begin(115200);

  // Configure pin 2 as input (connected to the button)
  pinMode(ipbutton,INPUT);

  // Configure pin 7 as output (connected to the LED)
  pinMode(LED,OUTPUT);

  // Start SPI communication
  SPI.begin();

  // Set the SPI clock speed divider to 8 to get an SPI clock of 2 MHz (16MHz / 8)
  SPI.setClockDivider(SPI_CLOCK_DIV8);

  // Ensure the Slave Select (SS) line is initially set to HIGH (inactive)
  digitalWrite(SS,HIGH);
}

void loop(void)
{
  byte Mastersend, Mastereceive;

  // Read the status of the button
  buttonvalue = digitalRead(ipbutton);

  // Set x value depending on the button's status
  x = buttonvalue == HIGH ? 1 : 0;

  // Set the SS line to LOW to start communication with the Slave
  digitalWrite(SS, LOW);

  // Set the Mastersend value to x
  Mastersend = x;

  // Send the Mastersend value to the slave and also receive a value from the slave
  Mastereceive = SPI.transfer(Mastersend);

  // Turn on or off the LED depending on the received value from the slave
  digitalWrite(LED, Mastereceive == 1 ? HIGH : LOW);

  // Output a message to the serial monitor indicating the LED's state
  Serial.println(Mastereceive == 1 ? "Master LED ON" : "Master LED OFF");

  // Wait for 1 second before repeating the loop
  delay(1000);
}


//-------------------------------

//Peripheral
// Include the SPI library
#include<SPI.h>

#define LEDpin 7  // Define pin 7 for LED
#define buttonpin 2  // Define pin 2 for input button

volatile boolean received;  // Flag indicating whether a value was received from the Master
volatile byte Slavereceived, Slavesend;  // Variables to store the received value and the value to send
int buttonvalue;  // Variable to store the button's state
int x;  // Variable to store the value to send to the master

void setup()
{
  // Start serial communication at a baud rate of 115200
  Serial.begin(115200);

  // Configure pin 2 as input (connected to the button)
  pinMode(buttonpin,INPUT);

  // Configure pin 7 as output (connected to the LED)
  pinMode(LEDpin,OUTPUT);

  // Set MISO (Master In Slave Out) as output
  pinMode(MISO,OUTPUT);

  // Enable SPI in Slave mode
  SPCR |= _BV(SPE);

  // Attach the SPI interrupt
  SPI.attachInterrupt();
}

// SPI interrupt routine
ISR (SPI_STC_vect)
{
  // Store the received value from the master
  Slavereceived = SPDR;

  // Set the received flag to true
  received = true;
}

void loop()
{
  // If a value was received from the Master
  if(received)
  {
    // Turn on or off the LED depending on the received value
    digitalWrite(LEDpin, Slavereceived == 1 ? HIGH : LOW);

    // Output a message to the serial monitor indicating the LED's state
    Serial.println(Slavereceived == 1 ? "Slave LED ON" : "Slave LED OFF");

    // Read the status of the button
    buttonvalue = digitalRead(buttonpin);

    // Set x value depending on the button's status
    x = buttonvalue == HIGH ? 1 : 0;

    // Set the Slavesend value to x
    Slavesend = x;

    // Send the Slavesend value to the master
    SPDR = Slavesend;

    // Wait for 1 second before repeating the loop
    delay(1000);
  }
}
