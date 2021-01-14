#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8,9}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
    keypad.addEventListener(keypadEvent); 
}

void loop(){
    char key = keypad.getKey();
}


void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
        if (key == 'A') {
          digitalWrite(11,HIGH);
        }
        break;

    case RELEASED:
        if (key == '*') {

         digitalWrite(11,LOW);
         digitalWrite(12,LOW);
      
        }
        break;

    case HOLD:
        if (key == '3') {
          digitalWrite(12,HIGH);  
        }
        break;
    }
}
