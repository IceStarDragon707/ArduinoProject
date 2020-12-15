 
/*
 This is a sample sketch to show how to use the OneButtonLibrary
 to detect click events on 2 buttons in parallel. 
 The library internals are explained at
 http://www.mathertel.de/Arduino/OneButtonLibrary.aspx
 
 Setup a test circuit:
 * Connect a pushbutton to pin A1 (ButtonPin) and ground.
 * Connect a pushbutton to pin A2 (ButtonPin) and ground.
 * The Serial interface is used for output the detected button events.
 
 The Sketch shows how to setup the library and bind 2 buttons to their functions.
 In the loop function the button1.tick and button2.tick functions have to be called as often as you like.
 */

// 01.03.2014 created by Matthias Hertel
// ... and working.

/* Sample output:
Starting TwoButtons...
Button 1 click.
Button 2 click.
Button 1 doubleclick.
Button 2 doubleclick.
Button 1 longPress start
Button 1 longPress...
Button 1 longPress...
Button 1 longPress...
Button 1 longPress stop
Button 2 longPress start
Button 2 longPress...
Button 2 longPress...
Button 2 longPress stop
*/

#include "OneButton.h"

// Setup a new OneButton on pin A1.  
OneButton button1(11, true);
int LED_r=2, LED_g=5, LED_y=3;


// setup code here, to run once:
void setup() {
  // Setup the Serial port. see http://arduino.cc/en/Serial/IfSerial
  Serial.begin(9600);
  while (!Serial) {
    // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("Get Started...");

  // link the button 1 functions.
  button1.attachClick(click_);
  button1.attachDoubleClick(doubleclick_);
  button1.attachLongPressStart(longPressStart_);
  button1.attachLongPressStop(longPressStop_);
  button1.attachDuringLongPress(longPress_);

  pinMode(LED_r, HIGH);
  pinMode(LED_g, HIGH);
  pinMode(LED_y, HIGH);
} // setup


// main code here, to run repeatedly: 
void loop() {
  // keep watching the push buttons:
  button1.tick();

  // You can implement other code in here or just wait a while 
  delay(10);
} // loop


// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time (and no 2. button press followed).
void click_() {
  Serial.println("Button mono-click.");
  digitalWrite(LED_g, HIGH);
  delay(1000);
  digitalWrite(LED_g, LOW);
} // click1


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick_() {
  Serial.println("Button doubleclick.");
  digitalWrite(LED_r, HIGH);
  delay(1000);
  digitalWrite(LED_r, LOW);
  delay(1000);
  digitalWrite(LED_r, HIGH);
  delay(1000);
  digitalWrite(LED_r, LOW);
} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
void longPressStart_() {
  Serial.println("Button onlongPress begining");
  digitalWrite(LED_r, HIGH);
  digitalWrite(LED_y, HIGH);
  digitalWrite(LED_g, HIGH);
  delay(100);
  digitalWrite(LED_r, LOW);
  digitalWrite(LED_g, LOW);
  digitalWrite(LED_y, LOW);
} // longPressStart1


// This function will be called often, while the button1 is pressed for a long time.
void longPress_() {
  Serial.println("Button onlongPress during");
  digitalWrite(LED_y, HIGH);
} // longPress1


// This function will be called once, when the button1 is released after beeing pressed for a long time.
void longPressStop_() {
  Serial.println("Button onlongPress ending");
  digitalWrite(LED_y, LOW);
  delay(10);
  digitalWrite(LED_r, HIGH);
  digitalWrite(LED_y, HIGH);
  digitalWrite(LED_g, HIGH);
  delay(100);
  digitalWrite(LED_r, LOW);
  digitalWrite(LED_g, LOW);
  digitalWrite(LED_y, LOW);
  delay(100);
  digitalWrite(LED_r, HIGH);
  digitalWrite(LED_y, HIGH);
  digitalWrite(LED_g, HIGH);
  delay(100);
  digitalWrite(LED_r, LOW);
  digitalWrite(LED_g, LOW);
  digitalWrite(LED_y, LOW);
} // longPressStop1
