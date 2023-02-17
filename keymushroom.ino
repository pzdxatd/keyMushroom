#include <Keyboard.h>
#include <ButtonDebounce.h>

ButtonDebounce button(2, 5);
bool pressedState = false;
bool sendState = true;
char key = ('n');

void setup() {
  
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
  pinMode(3, OUTPUT);
}

void loop() {
  button.update();
  if (button.state() == LOW){
    digitalWrite(3, LOW);
    pressedState = true;
    
  }else if (button.state() ==HIGH){
    digitalWrite(3, HIGH);
    sendState = false;
    pressedState = false;
  }

  if(sendState == false && pressedState == true){
    Keyboard.write(key);
    sendState = true;
  }
  
 
  
}
