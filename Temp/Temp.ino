#include <TFT_eSPI.h>
#include "DHT.h"
#define DHTPIN BCM27
#define DHTTYPE DHT11
TFT_eSPI tft;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  dht.begin();
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_PINK);
  tft.setTextColor(TFT_BLACK,TFT_PINK);
  tft.setTextSize(2);
  tft.drawString("DHT11 Test", 80, 20);
  tft.setTextColor(TFT_BLUE,TFT_PINK);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = dht.readTemperature(); // อ่านค่าอุณหภูมิในอากาศมาเก็บไว้ที่ตัวแปร temp
  float humi = dht.readHumidity();   // อ่านค่าความขึ้นสัมพัทธ์ในอากาศมาเก็บไว้ที่ตัวแปร humi
  tft.drawString("Temp: "+String(temp)+String(" C "),80,100); // แสดงค่าอุณหภูมิที่หน้าจอแสดงผล
  tft.drawString("Humi: "+String(humi)+String(" %RH "), 80, 120); // แสดงค่าความขึ้นสัมพัทธ์ในอากาศที่หน้าจอแสดงผล
  delay(1000);
  // หน่วงเวลา 1 วินาที
}
