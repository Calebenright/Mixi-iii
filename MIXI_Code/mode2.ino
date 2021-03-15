boolean buts2[] = {0, 0, 0, 0, 0, 0, 0, 0};
int myPots2[] = {0, 0, 0, 0};

void mode2() {
  setMode2Color();
  switch2();
  beats2();
}

void setMode2Color() {
  strip.clear();
  strip.setPixelColor(0, 0, 0, 255);
  strip.setPixelColor(4, 255, 0, 0);
  strip.setPixelColor(1, 0, 255, 0);
  strip.setPixelColor(2, 0, 255, 0);
  strip.setPixelColor(3, 0, 255, 0);
  strip.setPixelColor(5, 0, 255, 0);
  strip.setPixelColor(6, 0, 255, 0);
  strip.setPixelColor(7, 0, 255, 0);
  strip.show();
}

void switch2() {
  for (int i = 0; i < 8; i++) {
    if (buttonStates[i] == 1 && i == 4) {
      colorWipe(255, 0, 0);
      switchVal = 1;
    }
    else if (buttonStates[i] == 1 && i == 0) {
      colorWipe(0, 0, 255);
      switchVal = 2;
    }
  }
    if (buttonStates[3] == 1 && buttonStates[7] == 1) {
        colorWipe(0, 0, 0);
        switchVal = 4;
    }
}

void beats2() {
  for (int i = 0; i < 8; i++) {
    if (buttonStates[i] == 1 && i != 0 && i != 4) {
      buts2[i] = !buts2[i];
      if (buts2[i] == 1) {
        usbMIDI.sendControlChange(i + 75, 127, 1);
      } else {
        usbMIDI.sendControlChange(i + 75, 0, 1);
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    int myPot2 = potStates[i];
    if (abs(myPot2 - myPots2[i]) > potTol) {
      usbMIDI.sendControlChange(i + 140, myPot2, 1);
      myPots2[i] = myPot2;
    } 
  }
}
