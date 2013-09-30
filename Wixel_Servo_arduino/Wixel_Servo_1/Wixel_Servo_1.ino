#include <Servo.h>

HardwareSerial Uart = HardwareSerial();

Servo myServo1;
Servo myServo2;

int sdata;
int idata;
int pos1;
int idata1;
int pos2;

void setup(){
  //Serial.begin(115200);
  Uart.begin(115200);
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  myServo1.attach(15);
  myServo2.attach(12);
}

void loop(){
  //if(Serial.available()){
  if(Uart.available()){
    digitalWrite(21, HIGH);
    //sdata = Serial.read();
    sdata = Uart.read();
    
    if(sdata == 'A'){
      digitalWrite(20, HIGH);
      
      //while(Serial.available()){
      //idata = Serial.read();
      idata = Uart.read();
      pos1 = constrain(idata,0,180);
      myServo1.write(pos1);
      //delay(300);
      //}
      //idata1 = Serial.read();
      idata1 = Uart.read();
      pos2 = constrain(idata1,0,180);
      myServo2.write(pos2);
      
      delay(20); 
    }
    else{
      digitalWrite(19, HIGH);
      delay(20);
    }
  }
  //digitalWrite(21,LOW);
  digitalWrite(21,LOW);
  digitalWrite(20,LOW);
  digitalWrite(19,LOW);
  delay(20);
}
    
