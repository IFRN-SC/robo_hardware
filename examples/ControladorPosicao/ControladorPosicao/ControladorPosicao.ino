#include <robo_hardware2.h>
#include <Servo.h>
#include <PID_v1.h>


#define PIN_INPUT 0

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp = 2, Ki = 5, Kd = 1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);



void setup() {
  robo.configurar(false);
  Serial.begin(9600);

  Input = robo.getAngEncoderDir();
  Setpoint = 100;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-100,100);
  Setpoint=100;
}


void loop() {
  Input = robo.getAngEncoderDir();;
  myPID.Compute();
  robo.acionarMotores(0, Output);
  delay(100);
  Serial.print("Angulo: ");
  Serial.print(robo.getAngEncoderDir());
  Serial.print("; ");
  Serial.println(Output);

  Setpoint=ler();
}

float ler(){
  static char c;
  if(Serial.available()){
    c = Serial.read();
  }
  //Serial.println(c);
  switch(c){
    case '0':
    return 0;
    break;
    case '1':
    return 90;
    break;
    case '2':
    return 180;
    break;
    default:
    return 270;
    break;
  }
  return 0;
  
}
