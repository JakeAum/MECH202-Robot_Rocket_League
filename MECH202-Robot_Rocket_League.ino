// Jacob Auman
// MECH202 
// Arduino Code For the Controller

// Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

///////////////////////////////////////
// Variables
///////////////////////////////////////

// GPIO Pin Assignments
const int potPinLeft = A5; // OTB
const int potPinRight = A4; // OTB

// Global Variables
int potValueLeft = 0;
int potValueRight = 0;

// RF Comms - MASTER 
const int radioChannel = 1;
const int radioAddress = 0xA1A1A1A1A1LL;

RF24 radio(9, 8);  // CE, CSN  - VERRIFIED

struct DataPacket {
  int potValueLeft;
  int potValueRight;
};
DataPacket data;


///////////////////////////////////////
// Functions
///////////////////////////////////////

void readPotValues() {
  // Read Linear Potentiometer Values
  potValueLeft = analogRead(potPinLeft);
  potValueRight = analogRead(potPinRight);
}

///////////////////////////////////////
// Main
///////////////////////////////////////

void setup() {
  // Potentiometer Init
  pinMode(potPinLeft, INPUT);
  pinMode(potPinRight, INPUT);
  
  //Radio Init - MASTER TRANSMITTER
  radio.begin();
  radio.setChannel(1);
  radio.openWritingPipe(0xA1A1A1A1A1LL);
  radio.stopListening();

  // Serial Monitor
  Serial.begin(9600);
}


void loop() {
  readPotValues(); // Read the potentiometer value
  
  // Write the potentiometer values to data
  data.potValueLeft = potValueLeft;
  data.potValueRight = potValueRight;

  // Send data over RF
  radio.write(&data, sizeof(data));
  Serial.println("Sent Data");

  // Print the potentiometer value
  Serial.print(potValueLeft);
  Serial.print(potValueRight);
  delay(100);
}
