//latest
#include <Servo.h>
int servoPin = 10; 
Servo Servo1; 
int ledPin = 7;               // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int val = 0;                    // variable for reading the pin status
const long count=5000;
unsigned long prev=0;
unsigned long next=0;
unsigned long x=0;
unsigned long y=0;
int facein=12;
int faceout=4;
int servoswitch=0;
int smilepin=3;
int smile=0;

int redPin= 11;
int greenPin = 6;
int bluePin = 5;
int red=0;
int r=0;
int gre=85;
int g=0;
int blu=170;
int b=0;
int i=0;
int a=0;

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
   pinMode(ledPin, OUTPUT); 
  pinMode(inputPin, INPUT);     // declare sensor as input
  Servo1.attach(servoPin); 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
   pinMode(faceout, OUTPUT);
 
 Serial.begin(9600);
}
 
void loop(){
  a=0;
  //digitalWrite(faceout,LOW);
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,LOW);

  
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    servoswitch=1;
    prev=millis();
    Serial.println("Motion detected!");
     } 
     else {
    next=millis();
    if (next-prev>=count){
    digitalWrite(ledPin, LOW); // turn LED OFF
    servoswitch=0;
    next=prev;
    Serial.println("Motion ended!");
     }
   Serial.println(servoswitch);
  }
  if (servoswitch==1){
    if (digitalRead(facein)==HIGH){
      //digitalWrite(ledPin,LOW);
      Servo1.write(0); 
      smile=1;}
   else {
    Servo1.write(180); 
    smile=0;
    }} x=millis();
    while (smile==1){
      y=millis();
     if (y-x>=10000){
      smile=0;
       }
    i=0;
      if (digitalRead(smilepin)==HIGH){
        while (i<500){
          digitalWrite(ledPin,LOW);
        Serial.print("loop");
          setColor(red, gre, blu);
          //delay(30);
  Serial.println(red);
  Serial.println(gre);
   Serial.println(blu);
  if (r==0){
  red=red+1;}
  else if(r==1){
  red=red-1;}
 
   if (g==0){
  gre=gre+1;}
  else if(g==1){
  gre=gre-10;}

   if (b==0){
  blu=blu+1;}
  else if(b==1){
  blu=blu-1;}
  
  if (red==250){
    r=1;}
  else if (red==0){
    r=0;}
  
  if (gre==250){
    g=1;}
  else if (gre==0){
    g=0;}

      if (blu==250){
    b=1;}
  else if (blu==0){
    b=0;}
 i++;
 
 } 
 
  
  }  
 
    }
    Servo1.write(180);
    }
    
  
