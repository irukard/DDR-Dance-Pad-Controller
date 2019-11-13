#include <Keyboard.h>

// Pro Micro Pin asignment
// Modify according you pin assignment
#define UP_ARROW_PIN 7
#define LEFT_ARROW_PIN 6
#define RIGHT_ARROW_PIN 8
#define DOWN_ARROW_PIN 5
#define START_PIN 9
#define SELECT_PIN 4

// Keyboard Key Codes
#define KEY_UP_ARROW 0xDA
#define KEY_LEFT_ARROW 0xD8
#define KEY_RIGHT_ARROW 0xD7
#define KEY_DOWN_ARROW 0xD9
#define KEY_RETURN 0xB0
#define KEY_ESC 0xB1

bool nowU=HIGH;
bool nowL=HIGH;
bool nowR=HIGH;
bool nowD=HIGH;
bool nowSt=HIGH;
bool nowSe=HIGH;

bool prevU=HIGH;
bool prevL=HIGH;
bool prevR=HIGH;
bool prevD=HIGH;
bool prevSe=HIGH;

void setup() {

  pinMode(UP_ARROW_PIN,INPUT_PULLUP);
  pinMode(LEFT_ARROW_PIN,INPUT_PULLUP);
  pinMode(RIGHT_ARROW_PIN,INPUT_PULLUP);
  pinMode(DOWN_ARROW_PIN,INPUT_PULLUP);
  pinMode(START_PIN,INPUT_PULLUP);
  pinMode(SELECT_PIN,INPUT_PULLUP);

}

void loop() {

  nowU=digitalRead(UP_ARROW_PIN);
  nowL=digitalRead(LEFT_ARROW_PIN);
  nowR=digitalRead(RIGHT_ARROW_PIN);
  nowD=digitalRead(DOWN_ARROW_PIN);
  nowSt=digitalRead(START_PIN);
  nowSe=digitalRead(SELECT_PIN);

// UP ARROW PRESSED
 if (nowU!=prevU && nowU==LOW) {
    Keyboard.press(KEY_UP_ARROW);
    prevU=nowU;
 }
// UP ARROW RELEASED
 if (nowU!=prevU && nowU==HIGH) {
    Keyboard.release(KEY_UP_ARROW);
    prevU=nowU;
 }

// LEFT ARROW PRESSED
 if (nowL!=prevL && nowL==LOW) {
    Keyboard.press(KEY_LEFT_ARROW);
    prevL=nowL;
 }
// LEFT ARROW RELEASED
 if (nowL!=prevL && nowL==HIGH) {
    Keyboard.release(KEY_LEFT_ARROW);
    prevL=nowL;
 }

// RIGHT ARROW PRESSED
 if (nowR!=prevR && nowR==LOW) {
    Keyboard.press(KEY_RIGHT_ARROW);
    prevR=nowR;
 }
// RIGHT ARROW RELEASED
 if (nowR!=prevR && nowR==HIGH) {
    Keyboard.release(KEY_RIGHT_ARROW);
    prevR=nowR;
 }

// DOWN ARROW PRESSED
 if (nowD!=prevD && nowD==LOW) {
    Keyboard.press(KEY_DOWN_ARROW);
    prevD=nowD;
 }
// DOWN ARROW RELEASED
 if (nowD!=prevD && nowD==HIGH) {
    Keyboard.release(KEY_DOWN_ARROW);
    prevD=nowD;
 }

// START sends single enter.
 if (nowSt==LOW) {
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.release(KEY_RETURN);
    delay(250);
 }

//SELECT PRESSED
 if (nowSe!=prevSe && nowSe==LOW) {
    Keyboard.press(KEY_ESC);
    prevSe=nowSe;
 }
//SELECT RELEASED
 if (nowSe!=prevSe && nowSe==HIGH) {
    Keyboard.release(KEY_ESC);
    prevSe=nowSe;
 }

}