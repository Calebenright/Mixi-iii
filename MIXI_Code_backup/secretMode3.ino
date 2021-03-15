boolean buts3[] = {0, 0, 0, 0, 0, 0, 0, 0};
int myPots3[] = {0, 0, 0, 0};

void secretMode3() {
  setMode3Color();
  switch3();
  beats3();
}

void setMode3Color() {
  strip.clear();
  strip.setPixelColor(0, 0, 255, 0);
  strip.setPixelColor(4, 0, 0, 255);
  strip.setPixelColor(1, 255, 255, 255);
  strip.setPixelColor(2, 255, 255, 255);
  strip.setPixelColor(3, 255, 255, 255);
  strip.setPixelColor(5, 255, 255, 255);
  strip.setPixelColor(6, 255, 255, 255);
  strip.setPixelColor(7, 255, 255, 255);
  strip.show();
}

void switch3() {
  for (int i = 0; i < 8; i++) {
    if (buttonStates[i] == 1 && i == 4){
      colorWipe(0,0,255);
      switchVal = 2;
    }
    else if (buttonStates[i] == 1 && i == 0) {
      colorWipe(0,255,0);
      switchVal = 3;
    }
  }
}

void beats3() {
  for (int i = 0; i < 8; i++) {
    if (buttonStates[i] == 1 && i != 0 && i != 4) {
      buts3[i] = !buts3[i];
      if (buts3[i] == 1) {
        usbMIDI.sendControlChange(i + 200, 127, 1);
      } else {
        usbMIDI.sendControlChange(i + 200, 0, 1);
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    int myPot3 = potStates[i];
    if (abs(myPot3 - myPots3[i]) > potTol) {
      usbMIDI.sendControlChange(i + 220, myPot3, 1);
      myPots3[i] = myPot3;
    } 
  }
}
