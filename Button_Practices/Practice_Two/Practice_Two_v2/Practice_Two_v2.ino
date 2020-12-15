
int ButtonValue = 0;
int lose = 0;
int index = 0;
int vec[4] = {0, 0, 0, 0};

int Button = 11;
int LED = 3;
int Sig = 2;

int last_state=1;
int current_state=0;

void setup(){
  Serial.begin(9600);
  pinMode(Button, INPUT);
  pinMode(LED, OUTPUT);
  Serial.println("Get Started !!");
  last_state=0;
  index=-1;
}

void loop(){
  digitalWrite(Sig, LOW);
  lose = lose + 1;
  current_state = digitalRead(Button);
  if (current_state==1){
    lose=0;
    ButtonValue = ButtonValue + 1;
    Serial.println(ButtonValue);
    if(last_state!=current_state){
      index=index+1;
      if(index>3){
        Serial.println("multiple_click");
        Serial.println(vec[0]),Serial.println(vec[1]),Serial.println(vec[2]),Serial.println(vec[3]);
        Serial.println("multiple_click");
        index=-1;
      }
    }
    vec[index] = ButtonValue;
  }else{
    if(ButtonValue>0){
      Serial.println('\n');
      ButtonValue = 0;
    }
  }
  //Serial.println(lose);
  if(lose >= 30000){
    if(vec[0] | vec[1] | vec[2] | vec[3]){
      Serial.println("\nget");
      Serial.println(vec[0]), Serial.println(vec[1]), Serial.println(vec[2]), Serial.println(vec[3]);
      Serial.println("-------\n\n");
    }
    index=-1, vec[0]=0, vec[1]=0, vec[2]=0, vec[3]=0;
    lose=0;
    digitalWrite(Sig, HIGH);delay(1000);
    digitalWrite(Sig, LOW);delay(500);
    digitalWrite(Sig, HIGH);digitalWrite(LED, HIGH);delay(500);
    digitalWrite(LED, LOW);delay(500);
  }
  
  last_state=current_state;
}
