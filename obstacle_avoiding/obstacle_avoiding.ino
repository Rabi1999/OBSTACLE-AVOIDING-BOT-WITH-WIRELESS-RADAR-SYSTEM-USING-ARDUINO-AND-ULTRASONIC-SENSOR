#include <Servo.h>.
#define MAX_DISTANCE 255
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90,s = 0; 
 const int trigPin = 12;
const int echoPin = 8;
const int in1 = 4;
const int in2 = 6;
const int in3 = 3;
const int in4 = 5;
 int in5 =7 ;// variable to store the servo position
long duration,distance ,distance1 ,distance2;
int naba();
byte val;
void setup() {
  myservo.attach(9); 
  myservo.write(90);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(in5,OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  Serial.begin(9600);
  delay(3000);
 distance=naba();
 val=distance;
  Serial.write(val);
// attaches the servo on pin 9 to the servo object
}
void loop() {
      
   if(distance<27)
    {
      digitalWrite(in1, LOW); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, LOW);
      digitalWrite(in5,HIGH);
      Serial.write(val);
      delay(400);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      digitalWrite(in5,HIGH);
      delay(150);
      digitalWrite(in1, LOW); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, LOW);
      digitalWrite(in5,LOW);
      Serial.write(val);
      delay(200);
     
  for(pos=90;pos>0;pos-=5)
  {
        myservo.write(pos);
        delay(5);
  }
      delay(400);
      distance2=naba();
      val=distance2;
      Serial.write(val);
      delay(500);
   for(pos=0;pos<180;pos+=5)
   { myservo.write(pos);
   delay(5);
   }
   delay(400);
       distance1=naba();
       val=distance1;
       Serial.write(val);
       delay(500);
   for(pos=180;pos>90;pos-=5) 
   {myservo.write(pos);
   delay(5);
   } 

 if(distance1>distance2)
 {
   digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      digitalWrite(in5,HIGH);
      delay(200);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      digitalWrite(in5,HIGH);
      delay(200);
      
 }
 else if(distance2>distance1)
 {
   
     digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      digitalWrite(in5,HIGH);
      delay(200);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      digitalWrite(in5,HIGH);
      delay(200);
}

    }
    else
    {
       Serial.write(val);
    digitalWrite(in1, HIGH); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW);
      digitalWrite(in5,LOW);
      delay(100);    
}
distance= naba();
val=distance;
}
int naba()
{
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  if(distance>MAX_DISTANCE)
  distance=MAX_DISTANCE;
  delay(100);
  return(distance);
   
}
