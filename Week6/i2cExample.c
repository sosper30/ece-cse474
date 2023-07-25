#include "Wire.h"  // Include Arduino Wire library for I2C communication

// MPU-6050 sensor I2C address
const int MPU_ADDR = 0x68;

// Variables for accelerometer data (unused in this code)
int16_t accel_x, accel_y, accel_z;

// Variables for gyroscope data (unused in this code)
int16_t gyro_x, gyro_y, gyro_z;

// Variables for temperature data
int16_t temperature; 
uint8_t temp_H, temp_L;

void setup() {
  Serial.begin(9600);  // Start the serial communication with the baud rate of 9600
  
  Wire.begin();  // Initialize the I2C bus

  // Start communication with MPU6050
  Wire.beginTransmission(MPU_ADDR); 

  // Access the Power Management register and set the device to active mode
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // Set to zero (wakes up the MPU-6050)

  Wire.endTransmission(true); // End the transmission
}

void loop() {
  // Request temperature data from the MPU-6050
  Wire.beginTransmission(MPU_ADDR); // Start communication with MPU6050 
  Wire.write(0x41); // Access the temperature register
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 2, true); // Request 2 bytes of data

  // Read temperature data
  temp_H = Wire.read(); // High byte
  temp_L = Wire.read(); // Low byte

  // Combine high and low bytes to a single value
  temperature = (temp_H << 8 | temp_L); 

  // Print raw temperature data values
  Serial.print("Temp H: ");
  Serial.println(temp_H, BIN); // Print the high byte
  Serial.print("Temp L: ");
  Serial.println(temp_L, BIN); // Print the low byte
  Serial.print("Temp all: ");
  Serial.println(temperature, BIN); // Print the combined value

  // Calculate and print actual temperature
  Serial.print("Temp = ");
  Serial.println(temperature/340.00+36.53); // Temperature formula from the sensor's datasheet

  // Wait for 1 second before repeating the loop
  delay(1000);
}
