int ledPin = 13;

int rCtrlA = 11;
int rCtrlB = 12;
int rEnb = 5;

int lCtrlA = 9;
int lCtrlB = 10;
int lEnb = 3;

int byte1 = 0;
int byte2 = 0;
int byte3 = 0;
int byte4 = 0;

void setup() {
  //Setting the pin mode and initial LOW 
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600); // Default communication rate

  //set up for r
  digitalWrite(rCtrlA, HIGH);
  digitalWrite(rCtrlB, LOW);
  analogWrite(rEnb, 0);

  //set up for l
  digitalWrite(lCtrlA, HIGH);
  digitalWrite(lCtrlB, LOW);
  analogWrite(lEnb, 0);
}
void loop() {
  // Checks if the data is coming from the serial port
 if(Serial.available() >= 4){ 
    byte1 = Serial.read(); 
    byte2 = Serial.read();
    byte3 = Serial.read();
    byte4 = Serial.read();

    if(byte1 == '0'){
      digitalWrite(lCtrlA, HIGH);
      digitalWrite(lCtrlB, LOW);
    }else{
      digitalWrite(lCtrlA, LOW);
      digitalWrite(lCtrlB, HIGH);
    }

    if(byte3 == '0'){
      digitalWrite(rCtrlA, HIGH);
      digitalWrite(rCtrlB, LOW);
    }else{
      digitalWrite(rCtrlA, LOW);
      digitalWrite(rCtrlB, HIGH);
    }
    
    analogWrite(lEnb, (byte2 - 48) * 28);
    analogWrite(rEnb, (byte4 - 48) * 28);
    
 } 

 
}
