void wellColor(int* sensorValues) {
  // Array to store pin values for RGB LEDs
  const int rgbPins[3] = {redPin, greenPin, bluePin};

  // Array to store values to be subtracted
  const int valuesToSubtract[3] = {996, 942, 970};

  for (int i = 0; i < 3; i++) {
    // Turn on the LED corresponding to the current iteration
    for (int j = 0; j < 3; j++) {
      digitalWrite(rgbPins[j], i == j ? HIGH : LOW);
    }
    delay(333);  // Wait for 333 milliseconds
    
    // Subtract the specified value, ensuring result is not negative
    int adjustedValue = max(valuesToSubtract[i] - analogRead(sensorPin), 0);
    
    // Map the adjusted value to the range 0-255
    sensorValues[i] = map(adjustedValue, 0, valuesToSubtract[i], 0, 255);

    // Error checking for sensor readings
    if (sensorValues[i] < 0) {
      // Handle out-of-range readings here, such as setting a default value
      sensorValues[i] = 0; // Setting to 0 for simplicity, adjust as needed
    }
  }
}
