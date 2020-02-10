//Note: This code is to print distance every time a button is pressed
#include <NewPing.h> //tells sublime yo use Newping library 
 
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 1000 //Sets maximum distance sensor will read
 
NewPing myHC_SR04(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
 Serial.begin(9600);
 pinMode(ECHO_PIN, INPUT); //sensor data pin
 pinMode(TRIGGER_PIN, OUTPUT); //sensor data pin
 pinMode(2, OUTPUT); //button data pin


}
 
void loop() {
     if(digitalRead(2) == 1) { //if button is pressed...
     	Serial.println(myHC_SR04.ping_cm()); //uses newping command to print the distance from the sensor to the serial monitor
     	delay(500);
     }

}   


