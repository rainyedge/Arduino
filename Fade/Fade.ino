/*
 Fade
 あああ
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */

int led = 2;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup()  { 
  Serial.begin(9600);

  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(A0, INPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // set the brightness of pin 9:
  analogWrite(led, brightness);    
  int v1 = analogRead(A0);
  
  //Serial.println("AT+GMR");
  Serial.print("*");
  //Serial.println(String(v1));
  
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  //digitalWrite(2,255);
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);                            
}

