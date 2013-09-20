#include <Servo.h>

Servo myServo1;
Servo myServo2;

int sdata;
int idata;
int pos1;
int idata1;
int pos2;

void setup(){
  Serial.begin(115200);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  myServo1.attach(9);
  myServo2.attach(6);
}

void loop(){
  if(Serial.available()){
    digitalWrite(13, HIGH);
    sdata = Serial.read();
    
    if(sdata == 'A'){
      digitalWrite(12, HIGH);
      
      //while(Serial.available()){
      idata = Serial.read();
      pos1 = constrain(idata,0,180);
      myServo1.write(pos1);
      //delay(300);
      //}
      idata1 = Serial.read();
      pos2 = constrain(idata1,0,180);
      myServo2.write(pos2);
      
      delay(20); 
    }
    else{
      digitalWrite(11, HIGH);
      delay(20);
    }
  }
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  delay(20);
}
    
