#include <Servo.h>

int IN1 = 3;
int IN2 = 5;
int IN3 = 6;
int IN4 = 9;
int trig = 2;
int echo = 4;
float time;
float distance;
float distance_left;
float distance_right;
Servo motor;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  motor.attach(10);
  Serial.begin(9600);
}

void forward() {
  analogWrite(IN1, 100);
  analogWrite(IN2, 0);
  analogWrite(IN3, 100);
  analogWrite(IN4, 0);
}

void backward() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 100);
  analogWrite(IN3, 0);
  analogWrite(IN4, 100);
}

void turn_right() {
  analogWrite(IN1, 90);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 90);
}

void turn_left() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 90);
  analogWrite(IN3, 90);
  analogWrite(IN4, 0);
}

void stop() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
  delay(500);
}

float USS() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  time = pulseIn(echo, HIGH, 30000);
  if (time == 0) {
    return 400;
  }

  distance = time * 0.034 / 2;
  return distance;
}

void loop() {
  motor.write(90);
  float current_distance = USS();

  if (current_distance > 20) {
    forward();
  } else {
    stop();
    delay(1000);

    // قياس المسافة إلى اليسار
    motor.write(0);
    delay(1000);
    distance_left = USS();

    // قياس المسافة إلى اليمين
    motor.write(180);
    delay(1000);
    distance_right = USS();

    Serial.print("Distance Left: ");
    Serial.println(distance_left);
    Serial.print("Distance Right: ");
    Serial.println(distance_right);

    if (distance_left > 20 && distance_right > 20) {
      if (distance_left > distance_right) {
        turn_left();
        delay(700);
      } else {
        turn_right();
        delay(700);
      }
    } else if (distance_left > 20) {
      turn_left();
      delay(700);
    } else if (distance_right > 20) {
      turn_right();
      delay(700);
    } else {
      // إذا كان هناك عائق في كل الاتجاهات، قم بالتراجع مع الدوران
      backward();
      delay(1500);

      stop();
      delay(500);

      // اختيار اتجاه عشوائي للدوران بعد التراجع
      if (random(2) == 0) {
        turn_left();
      } else {
        turn_right();
      }
      delay(1200); // وقت أطول للدوران حتى يغير مساره

      stop();
      delay(500);
    }

    forward();
  }
}
