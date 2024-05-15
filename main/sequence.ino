void sequence() {

  plate = plateSelector();
  start = digitalRead(startButton);

  if (start == LOW) { // Check if the start button is pressed
    if (plate == 0) {
      rowNum = 6;
    }
    else {
      rowNum = 8;
    }

    int sensorValues[rowNum][3];

    for (int row = 0; row < rowNum; row++) {
      wellColor(sensorValues[row]);
      Serial.println(row + 1);
      
      // Iterate over each column (sensor value)
      for (int col = 0; col < 3; col++) {
        Serial.print("Sensor ");
        Serial.print(col + 1); // Print the sensor number
        Serial.print(": ");
        Serial.println(sensorValues[row][col]); // Print the sensor value
      }

      Serial.println(); // Print a blank line between rows for clarity

      moveMotor(plate, 0); // Move the motor once based on the plate selection
    }

    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, LOW);

    for (int i = 0; i <= rowNum - 1 ; i++) {
      moveMotor(plate, 1); // Move the motor once based on the plate selection
    }

    if (rowNum == 6) {
      displayColors6(sensorValues);
    }
    else {
      displayColors8(sensorValues);
    } 
  }
}
