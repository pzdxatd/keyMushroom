#include <Keyboard.h>
#include <ButtonDebounce.h>

struct ButtonInfo {
    ButtonDebounce button;
    uint8_t ledPin;
    char key;
    uint8_t buttonPin; 
};

ButtonInfo buttons[] = {
    {ButtonDebounce(22, 5), 18, 'y', 22},
    {ButtonDebounce(4, 5), 7, 'n', 4}
};

const int numButtons = sizeof(buttons) / sizeof(buttons[0]); 

void setup() {
    Keyboard.begin();
    for (int i = 0; i < numButtons; i++) {
        pinMode(buttons[i].buttonPin, INPUT_PULLUP); 
        pinMode(buttons[i].ledPin, OUTPUT);
        digitalWrite(buttons[i].ledPin, HIGH); 
    }
}

void loop() {
    for (int i = 0; i < numButtons; i++) {
        buttons[i].button.update(); 
        if (buttons[i].button.state() == LOW) {
            digitalWrite(buttons[i].ledPin, LOW); 
            Keyboard.press(buttons[i].key); 
        } else {
            digitalWrite(buttons[i].ledPin, HIGH); 
            Keyboard.release(buttons[i].key); 
        }
    }
}
