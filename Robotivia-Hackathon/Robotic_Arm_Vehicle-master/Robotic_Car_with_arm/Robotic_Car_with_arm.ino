#include <Servo.h>

// تعريف السيرفوهات
Servo motor_1, motor_2, motor_3, motor_4, motor_5, motor_6;

// تعريف المحركات
#define IN1 3  
#define IN2 5  
#define IN3 6  
#define IN4 9  

// زوايا البداية لكل سيرفو
int servo1 = 70;   
int servo2 = 180;
int servo3 = 40;  // Elbow position
int servo4 = 100;
int servo5 = 60;
int servo6 = 0;  // مغلق بالكامل عند البدء

// متغير استقبال بيانات البلوتوث
int data;
int Speed = 130;

void setup() {
  Serial.begin(9600);

  // ربط السيرفوهات بالأطراف
  motor_1.attach(2);
  motor_2.attach(4);
  motor_3.attach(7);  // Elbow servo
  motor_4.attach(8);
  motor_5.attach(10);
  motor_6.attach(11);  // القماشة متوصلة على البن 11

  // ضبط مواضع البداية
  motor_1.write(servo1);
  motor_2.write(servo2);
  motor_3.write(servo3);  // Set initial position for Elbow
  motor_4.write(servo4);
  motor_5.write(servo5);
  motor_6.write(servo6);

  // تعريف أطراف المحركات
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  delay(1000);
}

void loop() {
  // التحكم بالسيرفوهات
  if (data == 8 && servo1 < 180) { servo1++; motor_1.write(servo1); }
  else if (data == 9 && servo1 > 0) { servo1--; motor_1.write(servo1); }
  else if (data == 10 && servo2 > 0) { servo2--; motor_2.write(servo2); }
  else if (data == 11 && servo2 < 180) { servo2++; motor_2.write(servo2); }
  else if (data == 12 && servo3 > 0) { servo3--; motor_3.write(servo3); }  // Elbow control
  else if (data == 13 && servo3 < 180) { servo3++; motor_3.write(servo3); }  // Elbow control
  else if (data == 14 && servo4 < 180) { servo4++; motor_4.write(servo4); }
  else if (data == 15 && servo4 > 0) { servo4--; motor_4.write(servo4); }
  else if (data == 16 && servo5 > 90) { servo5--; motor_5.write(servo5); }
  else if (data == 17 && servo5 < 150) { servo5++; motor_5.write(servo5); }

  delay(30);

  if (Serial.available()) {
    data = Serial.read();
    Serial.println(data);
  }
  if (data == 1) {
    analogWrite(IN1, 255);
    analogWrite(IN2, 0);
    analogWrite(IN3, 255);
    analogWrite(IN4, 0);
  }

  else if (data == 2) {
    analogWrite(IN1, 0);
    analogWrite(IN2, 255);
    analogWrite(IN3, 0);
    analogWrite(IN4, 255);
  }
    else if (data == 4) {
    analogWrite(IN1, 255);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
  }
    else if (data == 3) {
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, 255);
    analogWrite(IN4, 0);
  }

   else if(data == 5) {
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
    }

}
