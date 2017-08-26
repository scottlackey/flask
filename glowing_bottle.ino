// Glowing madscientist flask created by Scott Lackey 8/27/2017
//https://github.com/scottlackey/
// made for gemma M0 but will work with flora or trinket, just change the PIN to the one you're using for data out
 
#include <Adafruit_NeoPixel.h>

#define PIN 0
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(18, PIN);
 
uint8_t  mode   = 0; // Current animation effect
uint32_t prevTime;
uint8_t wait = 400; //speed of pulsing
int modetime = 12000; //time between effects

void setup() {
  pixels.begin();
  prevTime = millis();
}
 
void loop() {
  uint8_t  i;
  uint32_t t;

  switch(mode) {
 
   case 0: //simmering effect!
    simmer();
    break;
 
   case 1: // pulse green
    glow();
    break;

   case 2: //hold green color
     hold();
     break;

   case 3: // pulse green
     glow();
     break;

   case 4: //simmer
     simmer();
     break;

   case 5: // glow red!
     redglow();
     break;
   
   case 6: // pulse green again
     glow();
     break;
  
  }
  
  t = millis();
  if((t - prevTime) > modetime) {      // time between modes
    mode++;                       
    if(mode > 6) {                 // all modes completed?
      mode = 0;                    // reset to mode 0
    }
    for(i=0; i<24; i++) pixels.setPixelColor(i, 0); //clear all pixels
    prevTime = t;
  }
  
}

void hold(){
  uint8_t i;
  pixels.setBrightness(30);
  for(i=0; i<24; i++){
    pixels.setPixelColor(i, 0, 255, 0);
    pixels.show(); 
  }
}

void simmer(){ //sets a few pixels to green and then bubbles the rest
  uint8_t  i;
  i= random(20);
  pixels.setBrightness(60);
  pixels.setPixelColor(16, 0, 255, 0);
  pixels.setPixelColor(15, 0, 255, 0);
  pixels.setPixelColor(1, 0, 255, 0);
  pixels.setPixelColor(2, 0, 255, 0);
  pixels.setPixelColor(3, 0, 255, 0);
  pixels.setPixelColor(i, 0, 255, 0); //bubble pixel
  pixels.show();
  delay(10);
  if( i != 1 && i != 2 && i != 0 && i != 3){
    pixels.setPixelColor(i, 0);
  }
}

void glow(){
  uint8_t i;
  for(i=0; i<24; i++){
    pixels.setPixelColor(i, 0, 255, 0);
    pixels.show(); 
  }
  for(i=10; i<90; i+=10){
     pixels.setBrightness(i);
     pixels.show();
     delay(wait);
  }
    for(i=90; i>0; i-=10){
     pixels.setBrightness(i);
     pixels.show();
     delay(wait);
  }
   
  
}

void redglow(){
  uint8_t i;
  for(i=0; i<24; i++){
    pixels.setPixelColor(i, 255, 0, 0);
    pixels.show(); 
  }
    
    for(i=10; i<90; i+=10){
     pixels.setBrightness(i);
     pixels.show();
     delay(wait);
  }
    for(i=90; i>0; i-=10){
     pixels.setBrightness(i);
     pixels.show();
     delay(wait);
  }
    for(i=0; i<24; i++){
    pixels.setPixelColor(i, 200, 100, 0);
    pixels.show(); 
  }
    for(i=10; i<90; i+=10){
     pixels.setBrightness(i);
     pixels.show();
     delay(wait);
  }
    for(i=90; i>0; i-=10){
     pixels.setBrightness(i);
     pixels.show();
     delay(wait);
  }
}
