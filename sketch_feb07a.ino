#include<Servo.h>
Servo servo;
int trigpin=2;
int echopin=3;
long distance;
long duration;
int m1A=9;
int m1B=10;
int m2A=11;
int m2B=12 ;
long dr,dl;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(m1A,OUTPUT);
  pinMode(m1B,OUTPUT);
  pinMode(m2A,OUTPUT);
  pinMode(m2B,OUTPUT);
  pinMode(5,OUTPUT);
  servo.attach(5);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echopin,HIGH); //pulseIn : Gives the time duration. 
  distance=duration*0.01715;
  Serial.print("Distance : ");
  Serial.println(distance);
  delay(500);
  servo.write(90);

    digitalWrite(m1A,HIGH);    //FORWARD
    digitalWrite(m1B,LOW);
    digitalWrite(m2A,HIGH);
    digitalWrite(m2B,LOW);

  if(distance<20)
  {
    digitalWrite(m1A,LOW);    //STOP
    digitalWrite(m1B,LOW);
    digitalWrite(m2A,LOW);
    digitalWrite(m2B,LOW);
    delay(500);

  servo.write(180);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echopin,HIGH);  
  dr=duration*0.01715;
  delay(500);

  servo.write(0);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echopin,HIGH); 
  dl=duration*0.01715;
  delay(500);

  servo.write(90);

  if(dr>dl && dr>distance)
  {
    digitalWrite(m1A,HIGH);    //RIGHT
    digitalWrite(m1B,LOW);
    digitalWrite(m2A,LOW);
    digitalWrite(m2B,HIGH); 
    delay(600);
    
    digitalWrite(m1A,HIGH);    //FORWARD
    digitalWrite(m1B,LOW);
    digitalWrite(m2A,HIGH);
    digitalWrite(m2B,LOW); 
  }
    if(dl>dr && dl>distance)
  {
    digitalWrite(m1A,LOW);    //LEFT
    digitalWrite(m1B,HIGH);
    digitalWrite(m2A,HIGH);
    digitalWrite(m2B,LOW); 
    delay(600);
    
    digitalWrite(m1A,HIGH);    //FORWARD
    digitalWrite(m1B,LOW);
    digitalWrite(m2A,HIGH);
    digitalWrite(m2B,LOW); 
  }
    if(dl<distance && dr<distance)
    {
    digitalWrite(m1A,LOW);    //LEFT
    digitalWrite(m1B,HIGH);
    digitalWrite(m2A,HIGH);
    digitalWrite(m2B,LOW); 
    delay(1000);
    
    digitalWrite(m1A,HIGH);    //FORWARD
    digitalWrite(m1B,LOW);
    digitalWrite(m2A,HIGH);
    digitalWrite(m2B,LOW);
    }
  }
  }
