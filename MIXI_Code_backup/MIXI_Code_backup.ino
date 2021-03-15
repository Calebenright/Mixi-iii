#include <Bounce2.h>
int buttonPins[] = {5, 6, 7, 8, 9, 10, 11, 12};
int buttonStates[] = {0, 0, 0, 0, 0, 0, 0, 0};
Bounce * buttons = new Bounce[8];

int potPins[] = {A0, A1, A2, A3};
int potStates[] = {0, 0, 0, 0};
int switchVal = 0;
int bright=0;
int potTol = 10;
boolean startColor0 = true;
boolean startColor1 = true;
boolean startColor2 = true;

#define NUM_LEDS 8
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(NUM_LEDS, 4, NEO_RGB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  initializeButtons();
  initLEDs();
  //  Keeping this to start the LED's off and at brightness 0 to fade in
  Serial.println("My Time Has Come!");
}

void loop() {
  updatePots();
  updateButtons();
//  printButtons();
//  printPots();
  
    switch (switchVal) {
      case 0: BootUp(); switchVal++; break; // Boot Up Animation
      case 1: mode0();    break; // Mode 0
      case 2: mode1();    break; // Mode 1
      case 3: mode2();    break; // Mode 2
      case 4: secretMode3();    break; // Mode 3
    }
  
//  Zane Starter Code
//  updateButtons();
//  printButtons();
//  updatePots();
//  printPots();
}


// Old Switcher

//void switchy(){
//   for (int i = 0; i < 8; i++){
//      buttons[i].update();
//      if(buttons[i].rose()){
//       switchVal=(switchVal+1)%4;
//    }
//   }
//}
