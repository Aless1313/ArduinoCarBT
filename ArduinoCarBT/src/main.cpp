#include <Arduino.h>
#define motor1Pin1 2 // Pin 2 para controlar motor1
#define motor1Pin2 3 // Pin 3 para controlar motor1
#define motor2Pin1 4 // Pin 4 para controlar motor2
#define motor2Pin2 5 // Pin 5 para controlar motor2

#define forward 'F'
#define backward 'B'
#define left 'L'
#define right 'R'
#define stop 'S'

char command; // Variable para almacenar el comando Bluetooth recibido

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  Serial.begin(9600); // Inicia la comunicación serial
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    executeCommand(command);
  }
}

void executeCommand(char command) {
  switch (command) {
    case forward:
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      break;
    case backward:
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      break;
    case left:
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      break;
    case right:
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      break;
    case stop:
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      break;
    default:
      break;
  }
}
