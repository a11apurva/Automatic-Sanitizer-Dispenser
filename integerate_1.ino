#include <Servo.h>

Servo myservo;

const int trigPin = 8;
const int echoPin = 9;
const int servoPin = 10;
const int threshold = 18;

int pos = 0;  // position variable
int pos0=160; // initial position
int pos1=130; // target position

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin); 
  myservo.write(pos0);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance < threshold)
  {
    for (pos = pos0; pos >= pos1; pos -= 1) 
    { 
      myservo.write(pos);
      delay(15);       
    }
    for (pos = pos1; pos <= pos0; pos += 1) 
    { 
      myservo.write(pos); 
      delay(15);  
    }
  }
    
  delay(1000);
}
