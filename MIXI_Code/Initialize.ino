void initLEDs(){
  for (int i = 0; i < 8; i++){
    strip.setPixelColor(i, 0, 0, 0);
    strip.setBrightness(0);
    strip.show();
    delay(50);
  }
}

void initializeButtons(){
  for (int i = 0; i < 8; i++){
    buttons[i].attach(buttonPins[i] , INPUT_PULLUP  );
    buttons[i].interval(25);  
  }
}

void updateButtons(){
  for (int i = 0; i < 8; i++){
    buttons[i].update();
    if(buttons[i].rose()){buttonStates[i] = 1;}
    else{buttonStates[i] = 0;}
  }
}

void printButtons(){
  for (int i = 0; i < 8; i++){
    int thisButton = buttonStates[i];
    Serial.print(thisButton);
    Serial.print("\t");
  }  
  //Serial.println();
}

void updatePots(){
  for (int i = 0; i < 4; i++){
    int thisPot = analogRead(potPins[i]);
    int mapPot = map(thisPot, 0, 1023, 0, 127);
    potStates[i] = mapPot;
  }
}

void printPots(){
  for (int i = 0; i < 4; i++){
    int thisPot = potStates[i];
    Serial.print(thisPot);
    Serial.print("\t");
  }  
  Serial.println();
}

void BootUp(){
 for(uint16_t c=0; c<256; c++) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((c) & 255));
    }
    strip.setBrightness(bright);
    if(bright<254){
      bright+=2;
    }
    strip.show();
    delay(10);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void colorWipe(int r, int g, int b) {
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, r, g, b);         
    strip.show();                          
    delay(30);                           
  }
}
