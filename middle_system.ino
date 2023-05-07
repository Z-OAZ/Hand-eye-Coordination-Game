#include <SoftwareSerial.h>

#define rxPin 8
#define txPin 10

int LED = 13;
int LED2 = 12;
char str[10];
char str2[10];

SoftwareSerial mySerial(rxPin, txPin);
void setup () {

  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  
}

void loop () {
String mystr = String(str);
String mystr2 = String(str2);
  if(mySerial.available()){
    mySerial.readBytes(str2, 7);
    Serial.println(str2);
    if(mystr2 == "Player2"){
      digitalWrite(LED2, HIGH);
    }
  }
  if(Serial.available()){
    Serial.readBytes(str, 7);
    Serial.println(str);
    if(mystr == "Player1"){
      digitalWrite(LED, HIGH);
    }
  }
  delay(1000);
  
}
