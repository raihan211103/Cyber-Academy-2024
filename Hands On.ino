#define BLYNK_TEMPLATE_ID "MASUKAN_TEMPLATE_ID"      //Copy Template ID
#define BLYNK_TEMPLATE_NAME "MASUKAN_TEMPLATE_NAME"  //Copy Template Name
#define BLYNK_AUTH_TOKEN "MASUKAN_TOKEN_AUTH"        //Copy token auth

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>  

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST"; 
char pass[] = "";

#define TRIG_PIN ...                                  //Berapa Pin Trig (Soal 1)
#define ECHO_PIN ...                                  //Berapa Pin Echo (Soal 2)
#define SERVO_PIN ...                                 //Berapa Pin Servo (Soal 3)

Servo myServo;          
BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, .... , pass);                     //(Soal 4)

  pinMode(TRIG_PIN, ... );                            //(Soal 5)
  pinMode(... , INPUT);                               //(Soal 6)

  myServo.attach(SERVO_PIN);  
  myServo.write(0);           

  timer.setInterval(1000L, sendDataToBlynk);
}

void .... () {                                        //(Soal 7)
  Blynk.run();
  timer.run();
}

void sendDataToBlynk() {
  long duration, distance;
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(.... , HIGH);                         //(Soal 8)
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, .... );                     //(Soal 9)

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  int servoAngle = (distance < 20) ? 90 : 0;
  myServo.write(.....);                             //(Soal 10)

  Blynk.virtualWrite(V1, servoAngle);
  Blynk.virtualWrite(V0, distance);
}
