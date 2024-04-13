/*
 * its a simple mouse jiggler with a switch as input on pin A6 for Arduino Micro
 */


#include <Mouse.h>

#define LOOPDELAY 100
#define MOVINGPIXEL 30


void setup() {

  Mouse.begin();
  
  pinMode(A6, INPUT);

  delay(100);
  
}

unsigned long loopCount = 123123; // some random for first sec

void loop() {

  const byte btn = digitalRead(A6);

  if(millis()/LOOPDELAY != loopCount){
    
    loopCount = millis()/LOOPDELAY;
    
    if(btn) Mouse.move(random(0,MOVINGPIXEL)-MOVINGPIXEL/2,random(0,MOVINGPIXEL)-MOVINGPIXEL/2,0);
    
  }

}
