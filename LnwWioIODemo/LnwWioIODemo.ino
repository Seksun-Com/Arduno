#include "TFT_eSPI.h"
TFT_eSPI tft;

int begin_x = 17;

void setup() {
  // put your setup code here, to run once:
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_YELLOW);
  tft.fillRect(0, 0, 320, 60, TFT_BLUE);
  tft.fillRect(0, 180, 320, 60, TFT_BLUE);
  tft.setTextColor(TFT_CYAN);
  tft.setTextSize(2);
  tft.drawString("Lnw WioIOdemo V.1.0", 50, 25);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.drawString("By Seksun Charoenkitmongk", 13, 205);

  pinMode(WIO_5S_LEFT, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);

  tft.fillRect(begin_x, 80, 20, 85, TFT_BLACK);

  pinMode(BCM0, OUTPUT);
  pinMode(BCM1, OUTPUT);
  pinMode(BCM2, OUTPUT);
  pinMode(BCM3, OUTPUT);
  pinMode(BCM4, OUTPUT);
  pinMode(BCM5, OUTPUT);
  pinMode(BCM6, OUTPUT);
  pinMode(BCM7, OUTPUT);
  pinMode(BCM8, OUTPUT);
  pinMode(BCM9, OUTPUT);
}

uint32_t BCM[10] = {BCM0, BCM1, BCM2, BCM3, BCM4, BCM5, BCM6, BCM7, BCM8, BCM9};
int i = 0;

void loop() {
  if (digitalRead(WIO_5S_RIGHT) == LOW) {
    if (begin_x < 278) {
      i++;
      begin_x = 17+22*i;
      tft.fillRect(begin_x, 80, 20, 85, TFT_BLACK);
      digitalWrite(BCM[i], 1);
      delay(500);
    }
  }

  if (digitalRead(WIO_5S_LEFT) == LOW) {
    if (begin_x > 0) {
      digitalWrite(BCM[i], 0);
      tft.fillRect(begin_x, 80, 20, 85, TFT_YELLOW);
      i--;
      begin_x = 17+22*i;
      delay(500);
    }
  }
}
