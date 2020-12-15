
int ButtonValue = 0;

int Button = 11;
int LED = 3;
int Sig = 2;

void setup(){
  Serial.begin(9600);
  pinMode(Button, INPUT);
  pinMode(LED, OUTPUT);
  Serial.println("Get Started !!");
}

void loop(){
  if (digitalRead(Button)==1){
    ButtonValue += 1;
    Serial.println(ButtonValue);
  }
  if(ButtonValue==10){
    digitalWrite(LED, HIGH);
  }
  if(ButtonValue>200){
    ButtonValue=0;
    delay(2000);
    digitalWrite(LED, LOW);
    Serial.println("ReStart !!");
  }
}
