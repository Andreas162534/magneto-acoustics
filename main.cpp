#include <PID_v1.h>   //https://www.youtube.com/watch?v=7Gu4Gx1BEIM

int Magnet = 3; //digital Pin 3
double Setpoint, Input, Output;
double Kp=2, Ki=5, Kd=1; //PID Tuning Parameters

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  pinMode(Magnet, OUTPUT);
  Input = analogRead(A0); //initial value
  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(1); //1 ms sample time
  Setpoint = 100; //desired value

}

void loop() {
  Input = analogRead(A0); //read current value
  myPID.Compute();
  analogWrite(Magnet, Output); //apply PID output to Magnet
  delay(1); //wait for next sample
}
