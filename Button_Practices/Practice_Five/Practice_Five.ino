//define the array max handling boundry
int const max_multiple_click_num = 5;

//the state that used to detect Button_ state
int ButtonValue = 0;
int lose = 0;

//the array that store Button_ state, and for later output detection
int index = 0;
int vec[max_multiple_click_num+1] = {0};//need one more space in case problem occur

//element pins
int Button_ = 11;
int LED_y = 3;
int LED_r = 2;
int LED_g = 5;

//state variable
int last_state=1;
int current_state=0;

//show light or not
bool light_signal=true;
int print_mode=2;

void setup(){
  Serial.begin(9600);
  pinMode(Button_, INPUT);
  pinMode(LED_y, OUTPUT);
  Serial.println("Get Started !!");
  
  //initial state settings
  last_state=0;
  index=-1;
}

void loop(){
  digitalWrite(LED_r, LOW);
  lose = lose + 1;
  current_state = digitalRead(Button_);
  if (current_state==1){
    lose=0;
    ButtonValue = ButtonValue + 1;
    Serial.println(ButtonValue);
    if(last_state!=current_state){
      index=index+1;
      if(index>max_multiple_click_num){
        Serial.println("multiple_click");
        print_vec(print_mode);
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
    if( is_vec_empty() ){
      Serial.println("\nget");
      print_vec(print_mode);
      Serial.println("-------\n\n");
    }
    index=-1;clear_vec();
    lose=0;
    if(light_signal){
      digitalWrite(LED_r, HIGH);delay(1000);
      digitalWrite(LED_r, LOW);delay(500);
      digitalWrite(LED_r, HIGH);digitalWrite(LED_y, HIGH);delay(500);
      digitalWrite(LED_y, LOW);delay(500);
    }
  }
  
  last_state=current_state;
}

//1 = get(with counts)
//2 = multiple count answer
void print_vec(int mode){
  if(mode==1){
    for(int i=0;i<max_multiple_click_num;i=i+1){
      Serial.println(vec[i]);
    }
  }else if(mode==2){
    int flag=0, i_flag=0, h_flag=0;bool ff=false, have_print=false;String s[21]={"", "mono-click", "double-click", "triple-click", "quadra-click", "penta-click", "hexa-click", "hepta-click", "octa-click", "nona-click", "deca-click", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20"};
    int place[11]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//0:nothing, 1:>=100, 2:<10
    for(int i=0;i<max_multiple_click_num;i=i+1){
      if(vec[i]>=100){
        place[i]=1;
        ff=true;
        h_flag+=1;
      }else if(vec[i]>10){
        flag+=1;
      }else if(vec[i]>0){
        i_flag+=1;
        place[i]=2;
      }else{
        break;
      }
    }

    int ll = flag+i_flag+h_flag;
    if(flag==1 && vec[0]>=100){
        Serial.println("Long Click");
        Serial.print("With missing "), Serial.print(i_flag), Serial.println(" clicks");
    }else{
      if(ff){
        int counts=0;
        for(int i=0;i<ll;i=i+1){
          if(place[i]==0){
            counts+=1;
            //Serial.print("@"), Serial.println(place[i]);
          }
          if(place[i]==1){
            if(counts!=0){
              if(have_print==true){
                Serial.print(" // ");
              }
              have_print=true;
              Serial.print("A " + s[counts] + " Click");
              counts=0;
            }
            if(i==ll-1){
              if(have_print==true){
                Serial.print(" // ");
              }
              have_print=true;
              Serial.println("A LongClick");
            }else{
              if(have_print==true){
                Serial.print(" // ");
              }
              have_print=true;
              Serial.print("A LongClick");
            }
          }
          
          if(i==ll-1 && counts!=0){
            if(have_print==true){
              Serial.print(" // ");
            }
            have_print=true;
            Serial.println("A " + s[counts] + " Click");
          }
        }
      }else{
        Serial.println("Click = " + s[flag]);
        Serial.print("With missing "), Serial.print(i_flag), Serial.println(" clicks");
      }
    }
    
  }
}

bool is_vec_empty(){
  bool x = 0;
  for(int i=0;i<max_multiple_click_num;i=i+1){
    x = x | vec[i];
  }
  return x>0;
}

void clear_vec(){
  for(int i=0;i<max_multiple_click_num;i=i+1){
    vec[i] = 0;
  }
}
