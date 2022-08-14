// Servor motor
#include <Servo.h>

int s1 = 11;
int s2 = 10;
int s3 = 9;
int s4 =5;
int s5 = 3;



Servo myservo;

int cur_pos = 90;

int Sensor_prev [] = {0, 0, 0, 0, 0}; 
int Sensor_Status; 

int positions[] = {140, 110, 90, 70, 40};
int sensors[] = {s1, s2, s3, s4, s5};


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(7);
  
  for(int i = 0; i<5; i++){
    pinMode(sensors[i], INPUT);}
    
    
//kalibrieren
  Serial.println("Calibrating Sensors");
  for(int i=0; i<20; i++)
  {Serial.println("calibrating");
   delay(500);
  }
  Serial.println("done");
  for(int i=0; i<180; i++)
  {myservo.write(i);
   delay(5);
  }
myservo.write(90);
delay(500);
}
void loop() {
  // put your main code here, to run repeatedly:
  
for (int i=0; i<5; i++)
{Sensor_Status = digitalRead(sensors[i]);
 if(Sensor_Status and not Sensor_prev[i] and cur_pos != positions[i])
 {cur_pos = positions[i];
  myservo.write(cur_pos);}
 Sensor_prev[i] = Sensor_Status;}
 
}
