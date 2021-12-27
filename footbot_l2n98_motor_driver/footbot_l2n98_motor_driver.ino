#include <SoftwareSerial.h>
SoftwareSerial bt(10,11); // rx,tx

#define LM1 3 // this may sometime varies after one trial run
#define LM2 4
#define LMPWM 5
#define RM1 6
#define RM2 7
#define RMPWM 9

void pinset(){
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(LMPWM,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(RMPWM,OUTPUT);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(9600);
  pinset();
}

void motor(int a, int b){
   if(a>=0){
    digitalWrite(LM1,1);
    digitalWrite(LM2,0);
    analogWrite(LMPWM,a);
    }
   else{
    digitalWrite(LM1,0);
    digitalWrite(LM2,1);
    analogWrite(LMPWM, -1 * a);
    }
   if(b>=0){
    digitalWrite(RM1,1);
    digitalWrite(RM2,0);
    analogWrite(RMPWM,b);
    }
   else{
    digitalWrite(RM1,0);
    digitalWrite(RM2,1);
    analogWrite(RMPWM,-1*b);
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
