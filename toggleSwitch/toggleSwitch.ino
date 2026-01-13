void setup() {
  // put your setup code here, to run once:
  pinMode(BCM0, INPUT);
  pinMode(BCM1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(BCM0)) //ตรวจสอบกดยัง
  {
    digitalWrite(BCM1,!digitalRead(BCM1));
    delay(200);
  }
}
