#ifndef SENSORUTILITY_H_
#define SENSORUTILITY_H_

namespace Ultrasonic {
void setup(int voutPin, int trigPin, int echoPin);
float readDistanceCm(int trigPin, int echoPin);
} // namespace Ultrasonic

void buzz(int buzzerPin, int repeat);

#endif /* SENSORUTILITY_H_ */
