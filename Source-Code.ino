//Setup for Ultrasonic sensor
#include <HCSR04.h>

HCSR04 hc(13, 12); //initialisation class HCSR04 (trig pin , echo pin)

//Setup for Servo Motor
#include <Servo.h>

Servo myservo;

int leftDis = 0;
int rightDis = 0;
int forwardDis = 0;

//Setup for Wheel Motors
#define enA 6
#define in1 7
#define in2 5
#define enB 3
#define in3 4
#define in4 2

void go() {   //Forward Movement
  analogWrite(enA, 175);
  analogWrite(enB, 175);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void back() {   //Reverse Movement
  analogWrite(enA, 175);
  analogWrite(enB, 175);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {   //Turning Left
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void right() {    //Turning Right
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stopp() {    //Stops robot
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
}

void setup() {
  Serial.begin(9600);
  myservo.attach(11);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
}

void loop() {
  
  myservo.write(80);
  delay(500);
  
  forwardDis = hc.dist();
  Serial.println(forwardDis);

  if (forwardDis < 30 && forwardDis > 0) { //Object is in front of robot
    stopp();   //Stops robot movement
    delay(250);
    back();   //backs away from object slightly
    delay(500);
    stopp();
    delay(1000);

    myservo.write(0);   //Moves US Sensor to the right
    delay(1000);
    rightDis = hc.dist();   //Measures Distance
    Serial.println(leftDis);    //Optional print to Serial Monitor
    delay(1000);
  
    myservo.write(180);   //Moves US Sensor to the left
    delay(1000);
    leftDis = hc.dist();    //Measures Distance
    Serial.println(rightDis);   //Optional print to Serial Monitor
    delay(1000);

    if(rightDis > leftDis){   //Path is clearest to the right
        right();    //turns robot to the right 90ish degrees
        delay(15);
    }
    else if(rightDis < leftDis) {   //Path clearest to the left
        left();   //turns robot to the left 90ish degrees
        delay(15);
    }
    
    myservo.write(80);    //Moves US Sensor back to the forward position
    delay(250);
  }

  else{   //While there is not objects in the way
    go();   //Moves robot forward
  }
}
