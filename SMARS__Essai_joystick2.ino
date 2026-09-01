#include <AFMotor.h>

AF_DCMotor motor1(1); // création de l'objet "motor1"
AF_DCMotor motor2(2); // création de l'objet "motor2"
AF_DCMotor motor3(3); // création de l'objet "motor2"
AF_DCMotor motor4(4); // création de l'objet "motor2"
int x_pin1=A1;
int y_pin1=A0;
int x_value1;
int y_value1;

int x_pin2=A2;
int y_pin2=A3;
int x_value2;
int y_value2;

void setup(){
  Serial.begin(9600);
  pinMode(x_pin1,INPUT);
  pinMode(y_pin1, INPUT);
  pinMode(x_pin2,INPUT);
  pinMode(y_pin2, INPUT);
  motor1.setSpeed(150);//vitesse=150       
  motor1.run(RELEASE);//stop
  motor2.setSpeed(150);//vitesse=150   
  motor2.run(RELEASE);//stop
  motor3.setSpeed(150);//vitesse=150   
  motor3.run(RELEASE);//stop
  motor4.setSpeed(150);//vitesse=150   
  motor4.run(RELEASE);//stop
}

void loop(){
  x_value1= analogRead(x_pin1);
  y_value1= analogRead(y_pin1);
  x_value2= analogRead(x_pin2);
  y_value2= analogRead(y_pin2);
  Serial.print("Valeur X : ");
  Serial.println(x_value1);
  Serial.print("Valeur y : ");
  Serial.println(y_value1);
  
  //J1
    if(y_value1<250){
    motor1.run(FORWARD);
    motor4.run(FORWARD);
    motor1.setSpeed(150);//vitesse=150    
    motor4.setSpeed(150);//vitesse=150   
    delay(200); // attend 100 ms
    motor1.run(RELEASE);
    motor4.run(RELEASE);
    }
  
    if(y_value1>750){
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    motor1.setSpeed(150);//vitesse=150   
    motor2.setSpeed(150);//vitesse=150   
    motor3.setSpeed(150);//vitesse=150   
    motor4.setSpeed(150);//vitesse=150   
    delay(200); // attend 100 ms
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    }
  
  //POUR ALLER A DROITE
    if(x_value2<250){
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
    motor1.setSpeed(150);//vitesse=150   
    motor2.setSpeed(150);//vitesse=150   
    motor3.setSpeed(150);//vitesse=150   
    motor4.setSpeed(150);//vitesse=150   
    delay(200); // attend 100 ms
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    }
  
  //POUR ALLER A GAUCHE
    if(x_value2>750){
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
    motor1.setSpeed(150);//vitesse=150   
    motor2.setSpeed(150);//vitesse=150   
    motor3.setSpeed(150);//vitesse=150   
    motor4.setSpeed(150);//vitesse=150   
    delay(200); // attend 100 ms
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    }
    
}
