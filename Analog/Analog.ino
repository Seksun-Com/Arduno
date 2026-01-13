#include <TFT_eSPI.h>  // ผนวกไลบรารีควบคุมการแสดงผล LCD
TFT_eSPI tft;          // สร้างออบเจ็กต์ชื่อ #t จากคลาส TFT_eSPI สำหรับควบคุมการแสดงผล LCD
void setup() {
  pinMode(A0, INPUT);  // กำหนดให้พอร์ต A0 ทำงานเป็นอินพุต
  tft.begin();   // เริ่มต้นการทำงานของ LCD
  tft.setRotation(3);   // กำหนดทิศทางการแสดงผลของหน้าจอ LCD
  tft.setTextSize(3);   // กำหนดขนาดฟอนต์เป็น 3
  tft.fillScreen(TFT_ORANGE);   // กำหนดพื้นหลังของจอแสดงผลเป็นสีดำ
  tft.setTextColor(TFT_BLACK, TFT_ORANGE);   //กำหนดสีตัวอักษรเป็นสีขาวพื้นหลังสีดำ
  tft.drawString("ADC GPIO27", 60, 60);   // แสดงข้อความหัวข้อการทดสอบ
}
void loop() {
  int adc = analogRead(A0);  // อ่านค่าสัญญาณแอนะล็อกจากขาพอร์ต A0 มาเก็บไว้ที่ตัวแปร adc
  tft.drawString("ADCO: " + String(adc) + String("   "), 60, 120);
  // แสดงค่าของการแปลงสัญญาณแอนะล็อกเป็นดิจิทัลที่อ่านได้จากขาพอร์ต A0 (มีค่าในช่วง 0 ถึง 1023)
  delay(100);  // หน่วงเวลาเล็กน้อย
}