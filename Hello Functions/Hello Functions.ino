#include <Servo.h>
const int trigPin = 10;
const int echoPin = 9;
int duration;
int distance;
Servo myservo;
void setup()
{
	pinMode(echoPin, INPUT);
	pinMode(trigPin, OUTPUT);
	Serial.begin(9600);
	myservo.attach(2);
}

void loop()
{
	Serial.print("distance:"); //prints the word "distance" to the serial monitor
	Serial.println(distance); //prints distance value returning from sensor
	getDistance(); // gets value returning from sensor
	myservo.write(78); //moves servo to what looks like 0 with the actual servo
	if (distance <= 10) // if distance returning from sensor is less than or equal to 10..
	{
		myservo.write(180); //move servo 180 degrees
		delay(10); // and delay 10 milliseconds
	}
	
}

int getDistance() //codes for above use of getDistance function which gets data from the ultrasonic sensor
{
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distance = duration * (0.034) /2;
	return distance;
}
