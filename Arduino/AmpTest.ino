#include <PWM.h>

int INC = 12;
int UD = 11;
int CS = 10;
int command;
int32_t frequency = 150;


void percentPotTurn(int percent) {
  int x = 0;
  setZero();
  while (x <= percent) {
    stepUp();
    x++;
    }
  }

void stepUp(){
  /*When (UD) in a high state and CS is low, any high−to−low
transition on INC will cause the wiper to move one
increment toward the RH terminal.*/
  digitalWrite(CS, LOW);
  digitalWrite(UD, HIGH);
  digitalWrite(INC, HIGH);
  digitalWrite(INC, LOW);
  }

void stepDown(){
  /*When (UD) in a low state and
CS is low, any high-to-low transition on INC will cause the
wiper to move one increment towards the RL terminal.*/
  digitalWrite(CS, LOW);
  digitalWrite(UD, LOW);
  digitalWrite(INC, HIGH);
  digitalWrite(INC, LOW);
  }



void setZero() {
  
int x = 0;
while (x < 101) {
    stepDown();
    x++;
  }
}

void maximize() {
int x = 0;
while (x <= 101) {
    stepUp();
    x++;
  }
}


void setup() {
  bool success = SetPinFrequency(6, frequency);
  Serial.begin(9600);
  pinMode(CS, OUTPUT);
  pinMode(UD, OUTPUT);
  pinMode(INC, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("sucess");

  // put your setup code here, to run once:
  //maximize();
  percentPotTurn(100);

}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
    digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  // put your main code here, to run repeatedly:
  //maximize();
  //Serial.println("RUNNING");
  analogWrite(6, 50);
  //digitalWrite(6, HIGH);
 /* if (Serial.available() != 0) {
    command = Serial.parseInt();
    Serial.println("Processing Command");
    Serial.println(command);
    percentPotTurn(command);
    Serial.println("Complete"); 


  }
  */

}
