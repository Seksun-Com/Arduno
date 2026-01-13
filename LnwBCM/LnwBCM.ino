#include "TFT_eSPI.h"
TFT_eSPI tft;

int begin_x = 5;
int begin_y = 80;
int sizeBox_x = 30;
int sizeBox_y = 85;

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

  tft.fillRect(begin_x, begin_y, sizeBox_x, sizeBox_y, TFT_BLACK);

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
int indexLight = 0;
int delayLight = 0;
int isUp = 1;

void loop() {
  digitalWrite(BCM[indexLight], 1);
  delay(200-delayLight*20);
  digitalWrite(BCM[indexLight], 0);
  delay(200-delayLight*20);
  if(indexLight == 9){
    isUp = 0;
  }else if(indexLight == 0){
    isUp = 1;
  }
  if(isUp == 1){
    indexLight++;
  }else{
    indexLight--;
  }

  if (digitalRead(WIO_5S_RIGHT) == LOW) {
    if (delayLight < 9) {
      delayLight++;
      begin_x += 31;
      tft.fillRect(begin_x, begin_y, sizeBox_x, sizeBox_y, TFT_BLACK);
      delay(200);
    }
  }

  if (digitalRead(WIO_5S_LEFT) == LOW) {
    if (delayLight > 0) {
      delayLight--;
      tft.fillRect(begin_x, begin_y, sizeBox_x, sizeBox_y, TFT_YELLOW);
      begin_x -= 31;
      delay(200);
    }
  }
}
