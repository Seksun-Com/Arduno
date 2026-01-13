void setup() {
  // put your setup code here, to run once:
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
int isUp = 1; 
void loop() {
  digitalWrite(BCM[i], 1);
  delay(200);
  digitalWrite(BCM[i], 0);
  delay(200);
  if(i == 9){
    isUp = 0;
  }else if(i == 0){
    isUp = 1;
  }
  if(isUp == 1){
     i++;
  }else{
    i--;
  }  
}
