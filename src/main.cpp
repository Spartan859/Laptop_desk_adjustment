#include <Arduino.h>

int trigPin = 36;    //Trig
int echoPin = 35;    //Echo
int pwmA=4,Ain1=6,Ain2=5;
int stby=7;
long duration, cm, inches;

 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  Serial.println("Started!!!!!!!");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Ain1,OUTPUT);
  pinMode(Ain2,OUTPUT);
  pinMode(stby,OUTPUT);
  digitalWrite(stby,HIGH);
  /*
  digitalWrite(Ain1,LOW);
  digitalWrite(Ain2,HIGH);
  analogWrite(pwmA,250);*/
}

void set_move_mode(int tp){
    analogWrite(pwmA,200);
    if(tp==0){
        digitalWrite(Ain1,LOW);
        digitalWrite(Ain2,LOW);
    }else if(tp==1){
        digitalWrite(Ain1,LOW);
        digitalWrite(Ain2,HIGH);
    }else if(tp==2){
        digitalWrite(Ain1,HIGH);
        digitalWrite(Ain2,LOW);
    }
}
 
void loop()
{
  
  
  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if(cm<=5){
    set_move_mode(2);
  }else if(cm>=7&&cm<=20){
    set_move_mode(1);
  }else set_move_mode(0);
  delay(200);
}