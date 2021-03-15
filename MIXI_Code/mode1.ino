boolean buts1[] = {0, 0, 0, 0, 0, 0, 0, 0};
int myPots1[] = {0, 0, 0, 0};

void mode1() {
  setMode1Color();
  switch1();
  beats1();
}

void setMode1Color() {
  strip.clear();
  strip.setPixelColor(0, 255, 0, 0);
  strip.setPixelColor(4, 0, 255, 0);
  strip.setPixelColor(1, 0, 0, 255);
  strip.setPixelColor(2, 0, 0, 255);
  strip.setPixelColor(3, 0, 0, 255);
  strip.setPixelColor(5, 0, 0, 255);
  strip.setPixelColor(6, 0, 0, 255);
  strip.setPixelColor(7, 0, 0, 255);
  strip.show();
}

void switch1() {
  for (int i = 0; i < 8; i++) {
    if (buttonStates[3] == 1 && buttonStates[7] == 1) {
      colorWipe(0, 0, 0);
      switchVal = 4;
    }
    else if (buttonStates[i] == 1 && i == 4) {
      colorWipe(0, 255, 0);
      switchVal = 3;
    }
    else if (buttonStates[i] == 1 && i == 0) {
      colorWipe(255, 0, 0);
      switchVal = 1;
    }
  }
}

void beats1() {
  for (int i = 0; i < 8; i++) {
    if (buttonStates[i] == 1 && i != 0 && i != 4) {
      buts1[i] = !buts1[i];
      if (buts1[i] == 1) {
        usbMIDI.sendControlChange(i + 50, 127, 1);
      } else {
        usbMIDI.sendControlChange(i + 50, 0, 1);
      }
    }

  }

  for (int i = 0; i < 4; i++) {
    int myPot1 = potStates[i];
    if (abs(myPot1 - myPots1[i]) > potTol) {
      usbMIDI.sendControlChange(i + 120, myPot1, 1);
      myPots1[i] = myPot1;
    } 
  }
}
