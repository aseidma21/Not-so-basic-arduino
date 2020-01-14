#include <NewPing.h>

#include <Servo.h>
const int trigPin = 10;
const int echoPin = 9;
int duration;
int distance;
int button = 2;
void setup()
{
	pinMode(echoPin, INPUT);
	pinMode(trigPin, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	getDistance();
	if (digitalRead(button) == HIGH)
	{
		Serial.print("distance:");
		Serial.println(distance);
	}
}

int getDistance()
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
