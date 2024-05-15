#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ A5, /* data=*/ A4, /* reset=*/ -1);   // All Boards without Reset of the Display

void displayColors6(int sensorValues[][3]) {
  u8g2.begin();

  static int progressBarValue = 0;
  static bool barsDrawn = false;

  if (!barsDrawn) {
    u8g2.clearBuffer();
    u8g2.setFontMode(1);
    u8g2.setBitmapMode(1);
    u8g2.setFont(u8g2_font_timR14_tr);
    u8g2.drawStr(3, 16, "1");
    u8g2.drawStr(3, 31, "2");
    u8g2.drawStr(3, 46, "3");
    u8g2.drawStr(3, 61, "4");
    u8g2.drawStr(62, 16, "5");
    u8g2.drawStr(62, 31, "6");
    u8g2.drawFrame(16, 3, 38, 13);
    u8g2.drawFrame(16, 18, 38, 13);
    u8g2.drawFrame(75, 3, 38, 13);
    u8g2.drawFrame(16, 33, 38, 13);
    u8g2.drawFrame(75, 18, 38, 13);
    u8g2.drawFrame(16, 48, 38, 13);

    const int barCoordinates[8][4] = {
      {18, 5, 34, 9},
      {18, 20, 34, 9},
      {18, 35, 34, 9},
      {18, 50, 34, 9},
      {77, 5, 34, 9},
      {77, 20, 34, 9},
    };

    for (int i = 0; i < 6; ++i) {
      while (progressBarValue <= 33) {
        u8g2.drawBox(barCoordinates[i][0], barCoordinates[i][1], progressBarValue, 9);
        progressBarValue += 100;
        u8g2.sendBuffer();
      }
      u8g2.drawBox(barCoordinates[i][0], barCoordinates[i][1], 34, 9);
      u8g2.sendBuffer();
      progressBarValue = 0;
    }

    barsDrawn = true;

    u8g2.clearDisplay();
  }

  if (barsDrawn) {
    u8g2.setFont(u8g2_font_5x7_tr);
    const int positionCoordinates[8][2] = {
      {10, 15},
      {10, 30},
      {10, 45},
      {10, 60},
      {70, 15},
      {70, 30},
    };

    for (int i = 0; i < 8; ++i) {
      u8g2.setCursor(positionCoordinates[i][0], positionCoordinates[i][1]);
      u8g2.print(sensorValues[i][0]); // Print the first value at the current position
      u8g2.print(",");
      u8g2.print(sensorValues[i][1]); // Print the second value at the current position
      u8g2.print(",");
      u8g2.print(sensorValues[i][2]); // Print the third value at the current position
    }
    u8g2.sendBuffer();
  }
}

void displayColors8(int sensorValues[][3]) {
  u8g2.begin();

  static int progressBarValue = 0;
  static bool barsDrawn = false;

  if (!barsDrawn) {
    u8g2.clearBuffer();
    u8g2.setFontMode(1);
    u8g2.setBitmapMode(1);
    u8g2.setFont(u8g2_font_timR14_tr);
    u8g2.drawStr(3, 16, "1");
    u8g2.drawStr(3, 31, "2");
    u8g2.drawStr(3, 46, "3");
    u8g2.drawStr(3, 61, "4");
    u8g2.drawStr(62, 16, "5");
    u8g2.drawStr(62, 31, "6");
    u8g2.drawStr(62, 46, "7");
    u8g2.drawStr(62, 61, "8");
    u8g2.drawFrame(16, 3, 38, 13);
    u8g2.drawFrame(16, 18, 38, 13);
    u8g2.drawFrame(75, 3, 38, 13);
    u8g2.drawFrame(16, 33, 38, 13);
    u8g2.drawFrame(75, 18, 38, 13);
    u8g2.drawFrame(16, 48, 38, 13);
    u8g2.drawFrame(75, 33, 38, 13);
    u8g2.drawFrame(75, 48, 38, 13);

    const int barCoordinates[8][4] = {
      {18, 5, 34, 9},
      {18, 20, 34, 9},
      {18, 35, 34, 9},
      {18, 50, 34, 9},
      {77, 5, 34, 9},
      {77, 20, 34, 9},
      {77, 35, 34, 9},
      {77, 50, 34, 9},
    };

    for (int i = 0; i < 8; ++i) {
      while (progressBarValue <= 33) {
        u8g2.drawBox(barCoordinates[i][0], barCoordinates[i][1], progressBarValue, 9);
        progressBarValue += 100;
        u8g2.sendBuffer();
      }
      u8g2.drawBox(barCoordinates[i][0], barCoordinates[i][1], 34, 9);
      u8g2.sendBuffer();
      progressBarValue = 0;
    }

    barsDrawn = true;

    u8g2.clearDisplay();
  }

  if (barsDrawn) {
    u8g2.setFont(u8g2_font_5x7_tr);
    const int positionCoordinates[8][2] = {
      {10, 15},
      {10, 30},
      {10, 45},
      {10, 60},
      {70, 15},
      {70, 30},
      {70, 45},
      {70, 60},
    };
    for (int i = 0; i < 8; ++i) {
      u8g2.setCursor(positionCoordinates[i][0], positionCoordinates[i][1]);
      u8g2.print(sensorValues[i][0]); // Print the first value at the current position
      u8g2.print(",");
      u8g2.print(sensorValues[i][1]); // Print the second value at the current position
      u8g2.print(",");
      u8g2.print(sensorValues[i][2]); // Print the third value at the current position
    }
    u8g2.sendBuffer();
  }
}

void startup(){
  u8g2.begin();

  

  u8g2.sendBuffer();
  }
