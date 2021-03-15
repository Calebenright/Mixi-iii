boolean buts0[] = {0, 0, 0, 0, 0, 0, 0, 0};
int myPots0[] = {0, 0, 0, 0};

void mode0() {
  setMode0Color();
  switch0();
  beats0();
}

void setMode0Color() {
  strip.clear();
  strip.setPixelColor(0, 0, 255, 0);
  strip.setPixelColor(4, 0, 0, 255);
  strip.setPixelColor(1, 255, 0, 0);
  strip.setPixelColor(2, 255, 0, 0);
  strip.setPixelColor(3, 255, 0, 0);
  strip.setPixelColor(5, 255, 0, 0);
  strip.setPixelColor(6, 255, 0, 0);
  strip.setPixelColor(7, 255, 0, 0);
  strip.show();
}

void switch0() {
  for (int i = 0; i < 8; i++) {
    if (buttonStates[i] == 1 && i == 4) {
      colorWipe(0, 0, 255);
      switchVal = 2;
    }
    else if (buttonStates[i] == 1 && i == 0) {
      colorWipe(0, 255, 0);
      switchVal = 3;
    }
  }
     if (digitalRead(buttonPins[3]) && digitalRead(buttonPins[7])) {
      colorWipe(255, 255, 255);
      switchVal = 4;
    }
}

void beats0() {
  for (int i = 0; i < 8; i++) {
    if (buttonStates[i] == 1 && i != 0 && i != 4) {
      buts0[i] = !buts0[i];
      if (buts0[i] == 1) {
        usbMIDI.sendControlChange(i, 127, 1);
        strip.setPixelColor(i, 0, 0, 0);
        strip.show();
      } else {
        usbMIDI.sendControlChange(i, 0, 1);
        strip.setPixelColor(i, 255, 0, 0);
        strip.show();
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    int myPot = potStates[i];
    if (abs(myPot - myPots0[i]) > potTol) {
//      Serial.print(myPot); Serial.print("\t"); Serial.println(myPots0[i]);
      usbMIDI.sendControlChange(i + 100, myPot, 1);
      myPots0[i] = myPot;
    } 
  }
}
