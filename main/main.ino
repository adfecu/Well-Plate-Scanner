#include <U8g2lib.h>

void displayColors();
int plateSelector();
void moveMotor();
void sequence();
void wellColor();

const int startButton = 5;
const int switchPin = 4;
const int stepPin = 3;
const int dirPin = 2;
const int enPin = 8;
const int redPin = 11;    // Pin connected to the red leg of the RGB LED
const int greenPin = 9;  // Pin connected to the green leg of the RGB LED
const int bluePin = 10;   // Pin connected to the blue leg of the RGB LED
const byte sensorPin = A3;

int start;
int plate;
int rowNum;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(startButton, INPUT_PULLUP);
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  digitalWrite(enPin, LOW);
}

void loop() {
  // Complete operation sequence
  
  sequence();
}
