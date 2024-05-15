const float stepsPerRevolution = 400; // Adjust according to your motor
const float pitchPerRevolution = 10; // Adjust according to your rail

float distanceInMM;
const float distanceMM24 = 18.9;
const float distanceMM48 = 13;

void moveMotor(int plateOption, int dir) {
  float stepsPerMM = stepsPerRevolution / pitchPerRevolution;

  if (plateOption == 0) {
    distanceInMM = distanceMM24;
  }
  else {
    distanceInMM = distanceMM48;
  }

  int stepsToMove = distanceInMM * stepsPerMM;

  digitalWrite(dirPin, dir); // Enables the motor to move in a particular direction
  for (int x = 0; x < stepsToMove; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  delay(100); // One second delay
}
