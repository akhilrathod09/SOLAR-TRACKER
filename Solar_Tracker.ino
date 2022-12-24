//Tinkering project
//Group-4
//solar Tracker-dual axis
//using servo library in order to use servos
#include <Servo.h>
//defining horizontal servo limits
Servo servohorizontal;
int servoh = 90;
int servohLH= 160;
int servohLL = 20;
//defining horizontal servo limits
Servo servovertical;
int servov = 90; 
int servovLH = 160;
int servovLL = 20; 
//defining the LDR sensors connection points
int ldrtl = A2; 
int ldrtr = A3; 
int ldrbl = A1; 
int ldrbr = A0; 

 void setup () 
 {
  //connecting servo monitor
  servohorizontal.attach(5);
  servohorizontal.write(90);
  servovertical.attach(9);
  servovertical.write(90);
  //initiating serial monitor
  Serial.begin(9600);
  delay(500);
  
 }

void loop()
{
  
  servoh = servohorizontal.read();
  servov = servovertical.read();
  //getting the input from LDR sensors
  int tl = analogRead(ldrtl);
  int tr = analogRead(ldrtr);
  int bl = analogRead(ldrbl);
  int br = analogRead(ldrbr);
  Serial.println(tl);
  Serial.println(tr);
  Serial.println(bl);
  Serial.println(br);
 //findind the averages of top 2 quadrants, bottom 2 quadrants, left 2 quadrants, right 2 quadrants
  int atop = (tl + tr) / 2; 
  int abot = (bl + br) / 2; 
  int aleft = (tl + bl) / 2; 
  int aright = (tr + br) / 2; 
  //adjusting the servo according to the averages
  if (atop < abot)
  {
    servovertical.write(servov+1);
    if (servov > servovLH) 
     { 
      servov = servovLH;
     }
    delay(10);
  }
  else if (abot < atop)
  {
    servovertical.write(servov-1);
    if (servov < servovLL)
  {
    servov = servovLL;
  }
    delay(10);
  }
  else 
  {
    servovertical.write(servov);
  }
  
  if (aleft > aright)
  {
    servohorizontal.write(servoh +1);
    if (servoh > servohLH)
    {
    servoh = servohLH;
    }
    delay(10);
  }
  else if (aright > aleft)
  {
    servohorizontal.write(servoh -1);
    if (servoh < servohLL)
     {
     servoh = servohLL;
     }
    delay(10);
  }
  else 
  {
    servohorizontal.write(servoh);
  }
  delay(50);
  
}
