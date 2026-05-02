#include <Arduino.h>

namespace Ultrasonic {

const float SOUND_SPEED_CM_PER_US = 0.0343f;
const int TRIG_LOW_DELAY_US = 2;
const int TRIG_HIGH_PULSE_US = 10;

void setup(int voutPin, int trigPin, int echoPin)
{
	pinMode(voutPin, OUTPUT);
	digitalWrite(voutPin, HIGH);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

float readDistanceCm(int trigPin, int echoPin)
{
	digitalWrite(trigPin, LOW);
	delayMicroseconds(TRIG_LOW_DELAY_US);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(TRIG_HIGH_PULSE_US);
	digitalWrite(trigPin, LOW);
	long duration = pulseIn(echoPin, HIGH);
	return duration * SOUND_SPEED_CM_PER_US / 2;
}

} // namespace Ultrasonic

const int BUZZ_DURATION_MS = 150;

void buzz(int buzzerPin, int repeat)
{
	for (int i = 0; i < repeat; i++) {
		digitalWrite(buzzerPin, HIGH);
		delay(BUZZ_DURATION_MS);
		digitalWrite(buzzerPin, LOW);
		delay(BUZZ_DURATION_MS);
	}
}
