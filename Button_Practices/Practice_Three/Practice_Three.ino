int Button_pin =  11;
int LED_y = 3;
int LED_r = 2;
int LED_g = 5;

int ButtonValue = 0;
int current_state = 0;
int last_state = 0;


void setup(){
  pinMode(LED_y, OUTPUT);
  pinMode(LED_r, OUTPUT);
  pinMode(LED_g, OUTPUT);
  pinMode(Button_pin, INPUT);
  Serial.begin(9600);
  digitalWrite(LED_g, HIGH);
}


void loop(){
  current_state = digitalRead(Button_pin);
  if(current_state==1){
    delay(180);
    ButtonValue = ButtonValue + 1;
    digitalWrite(LED_y, HIGH);
  }
  if(last_state!=current_state){
    if(last_state==1){
      digitalWrite(LED_g, LOW);
      digitalWrite(LED_y, LOW);
      digitalWrite(LED_r, HIGH);
      delay(200);
      digitalWrite(LED_r, LOW);
      Serial.println(ButtonValue);
      ButtonValue = 0;
      digitalWrite(LED_g, HIGH);
    }
  }
  
  last_state = current_state;
}
