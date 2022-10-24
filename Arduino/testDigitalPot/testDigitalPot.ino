
int INC = 12;
int UD = 11;
int CS = 10;


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
  Serial.begin(9600);
  pinMode(CS, OUTPUT);
  pinMode(UD, OUTPUT);
  pinMode(INC, OUTPUT);
  
  // put your setup code here, to run once:
  setZero();
}

void loop() {
  // put your main code here, to run repeatedly:
  //maximize();
  //Serial.println("RUNNING");

  String command;
  if (Serial.available() != 0) {
    command = Serial.readString();
    Serial.println("Processing Command");
    if (command = "reset") {
      Serial.println("Zeroing...");
      setZero();
      Serial.println("Complete");
      }
    if (command = "maximize") {
      Serial.println("Maximizing...");
      maximize();
      Serial.println("Complete");
      }

  }
  

}
