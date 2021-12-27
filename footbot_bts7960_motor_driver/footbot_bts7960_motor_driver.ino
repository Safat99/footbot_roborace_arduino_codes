#include <SoftwareSerial.h>
SoftwareSerial bt(10,11); // rx,tx

////////////////////////////// all this pins are needed to be pwm pins of arduino ////////////////////////////////

#define LM1 3 // this may sometime varies after one trial run
#define LM2 6 
#define RM1 6
#define RM2 9


void pinset(){
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(9600);
  pinset();
}

void motor(int a, int b){
   if(a>=0){
      analogWrite(LM1,a);
      analogWrite(LM2,0);
    }
   else{
      analogWrite(LM2,-1*a);
      analogWrite(LM1,0);
    }
   if(b>=0){
      analogWrite(RM1,a);
      analogWrite(RM2,0);
    }
   else{
      analogWrite(RM2,-1*a);
      analogWrite(RM1,0);
    }
  }

char serialRead(){
  return bt.read();
}

int speeds;
char value;

void loop() {
  // put your main code here, to run repeatedly:
  if (bt.available()){
    value = bt.read();
    Serial.println(value);
    }

  switch(value){
    case '0': speeds=255*0.1;break; 
    case '1': speeds=255*0.2;break;
    case '2': speeds=255*0.3;break;
    case '3': speeds=255*0.4;break;
    case '4': speeds=255*0.5;break;
    case '5': speeds=255*0.6;break;
    case '6': speeds=255*0.7;break;
    case '7': speeds=255*0.8;break;
    case '8': speeds=255*0.9;break;
    case '9': speeds=255;break;
    case 'F': 
        Serial.println('Forward');
        motor(speeds,speeds);
        break;
    case  'B':
        Serial.println('Backward');
        motor(-speeds,-speeds);
        break;
    case  'L':
        Serial.println('Left');
        motor(-speeds,-speeds);
        break;
    case  'R':
        Serial.println('Right');
        motor(-speeds,-speeds);
        break;  
    case  'H':
        Serial.println('Forward-Right');
        motor(speeds,0);
        break;
    case  'G':
        Serial.println('Forward-Left');
        motor(0,speeds);
        break;
    case  'I':
        Serial.println('Backward-Right');
        motor(-speeds,0);
        break;
    case  'J':
        Serial.println('Backward-Left');
        motor(0,-speeds);
        break;
  }
}
