#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int x_pin = A1;
int y_pin = A0;
int x_value;
int y_value;

int deadZone = 100;  // Zone morte pour éviter des mouvements accidentels

void setup() {
  Serial.begin(9600);
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);

  // Vitesse initiale
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);

  stopAllMotors();
}

void stopAllMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  x_value = analogRead(x_pin);
  y_value = analogRead(y_pin);

  Serial.print("Valeur X : ");
  Serial.println(x_value);
  Serial.print("Valeur Y : ");
  Serial.println(y_value);

  // Zone morte : on ne fait rien si le joystick est dans la plage centrale
  if (y_value > 512 - deadZone && y_value < 512 + deadZone && x_value > 512 - deadZone && x_value < 512 + deadZone) {
    stopAllMotors();
  }
  


  // Si on incline le joystick vers l'avant (y_value faible)
  else if (y_value < 250) {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    delay(200);  // Attente de 200ms pour que le mouvement soit fluide
    stopAllMotors();
  }
  


  
  // Si on incline le joystick vers l'arrière (y_value élevé)
  else if (y_value > 750) {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    delay(200);  // Attente de 200ms pour que le mouvement soit fluide
    stopAllMotors();
  }





  // Si on incline le joystick vers la droite (x_value élevé)
  else if (x_value > 750) {
    motor1.run(BACKWARD);  // Moteurs à l'arrière à gauche
    motor2.run(FORWARD);   // Moteurs à l'avant à droite
    motor3.run(FORWARD);   // Moteurs à l'avant à droite
    motor4.run(BACKWARD);  // Moteurs à l'arrière à gauche
    delay(200);
    stopAllMotors();
  }
  


  
  // Si on incline le joystick vers la gauche (x_value faible)
  else if (x_value < 250) {
    motor1.run(FORWARD);   // Moteurs à l'avant à gauche
    motor2.run(BACKWARD);  // Moteurs à l'arrière à droite
    motor3.run(BACKWARD);  // Moteurs à l'arrière à droite
    motor4.run(FORWARD);   // Moteurs à l'avant à gauche
    delay(200);
    stopAllMotors();
  }
}
