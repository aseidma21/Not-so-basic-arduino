//Note: This code is to print distance every time a button is pressed
#include <NewPing.h>
 
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 1000
 
NewPing myHC_SR04(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
 Serial.begin(9600);
 pinMode(ECHO_PIN, INPUT);
 pinMode(TRIGGER_PIN, OUTPUT);
 pinMode(2, OUTPUT);


}
 
void loop() {
     if(digitalRead(2) == 1) {
     	Serial.println(myHC_SR04.ping_cm());
     	delay(500);
     }

}   


