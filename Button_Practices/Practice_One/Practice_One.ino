
int ButtonValue = 0;

int Button = 11;
int LED = 3;

void setup(){
  Serial.begin(9600);
  pinMode(Button, INPUT);
  pinMode(LED, OUTPUT);
}

void loop(){
  ButtonValue = digitalRead(Button);
  Serial.println(digitalRead(Button));
  if(ButtonValue != 0){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}
