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
	Serial.print("distance:");
	Serial.println(distance);
	getDistance();
	myservo.write(78);
	if (distance <= 10)
	{
		myservo.write(180);
		delay(10);
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
