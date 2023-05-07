char mystr[7] = "Player1"; //String data


#include "LedControl.h" 

int UD = 0;
int LR = 0; 
boolean getTheRandomNum;
const int buttonPin = 7;
int buttonState = 0;
int counter = 0;

LedControl lc=LedControl(8,10,9,1); //10 -> CLOCK, 9 -> CS, 8 -> DIN

void setup() {
  Serial.begin(9600);

  lc.shutdown(0,false);// turn off power saving, enables display
  lc.setIntensity(0,8);// sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
  pinMode(buttonPin, INPUT_PULLUP);
  getTheRandomNum = true;
  
}

int getRandom() {
  return rand() % ((7 - 0) + 1) + 0;
}

void loop() {
  if(counter == 5) {
   Serial.write(mystr,7);
  }
  
  
  buttonState = digitalRead(buttonPin);

  int randomx;
  int randomy;
  UD = analogRead(A0);
  LR = analogRead(A1);
  char x_translate = map(LR, 1024, 0, 7, -1); 
  char y_translate = map(UD, 1024, 0, 0, 8);

  if(getTheRandomNum == true) {
    randomx = getRandom();
    randomy = getRandom();
    getTheRandomNum = false;
  }

  
  lc.clearDisplay(0);
  lc.setLed(0,x_translate,y_translate,true);  
  lc.setLed(0,randomx,randomy,true);
  
  if (buttonState == HIGH) {
    if(x_translate == randomx && y_translate == randomy){
      getTheRandomNum = true; 
      counter++; 
    }
  }
  delay(250); 
}
