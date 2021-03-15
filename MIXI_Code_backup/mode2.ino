boolean buts2[] = {0, 0, 0, 0, 0, 0, 0, 0};
int myPots2[] = {0, 0, 0, 0};

void mode2() {
  setMode2Color();
  switch2();
  beats2();
}

void setMode2Color() {
  strip.setPixelColor(0, 0, 0, 255);
  strip.setPixelColor(4, 255, 0, 0);
  if(startColor2 == true){
  strip.setPixelColor(1, 0, 255, 0);
  strip.setPixelColor(2, 0, 255, 0);
  strip.setPixelColor(3, 0, 255, 0);
  strip.setPixelColor(5, 0, 255, 0);
  strip.setPixelColor(6, 0, 255, 0);
  strip.setPixelColor(7, 0, 255, 0);
  startColor2 = false;
  }
  strip.show();
}

void switch2() {
  for (int i = 0; i < 8; i++) {
    if (buttonStates[i] == 1 && i == 4) {
      colorWipe(255, 0, 0);
      startColor0 = true;
      startColor1 = true;
      startColor2 = true;
      switchVal = 1;
    }
    else if (buttonStates[i] == 1 && i == 0) {
      colorWipe(0, 0, 255);
      startColor0 = true;
      startColor1 = true;
      startColor2 = true;
      switchVal = 2;

    }
  }
}

void beats2() {
  for (int i = 0; i < 8; i++) {
    if (buttonStates[i] == 1 && i != 0 && i != 4) {
      buts2[i] = !buts2[i];
      if (buts2[i] == 1) {
        usbMIDI.sendControlChange(i + 75, 127, 1);
        strip.setPixelColor(i, 0, 255, 0);
        strip.show();
      } else {
        usbMIDI.sendControlChange(i + 75, 0, 1);
        strip.setPixelColor(i, 0, 0, 0);
        strip.show();
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
