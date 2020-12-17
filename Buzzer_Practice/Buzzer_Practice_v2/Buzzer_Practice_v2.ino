/*
xample TONE_DEFAULT
 * @example TONE_PITCH 432
 * @example TONE_PITCH 434
 * @example TONE_PITCH 436
 * @example TONE_PITCH 438
 * @example TONE_PITCH 440
 * @example TONE_PITCH 442
 * @example TONE_PITCH 444
 * @example TONE_PITCH 446
 */


#include <Arduino.h>

#define TONE_USE_INT
#define TONE_PITCH 440

#include <Pitch.h>

class MusicSheet{
  float *NoteKeys;               //音名
  float *NoteTypes;              //拍點，用幾分音符輸入
  int amounts=0;                 //length of array
  int pad_speed;                 //節拍器調為多少
  int one_pad_representative;    //1拍以幾分音符為標準
  
  public:
    MusicSheet(float* keys, float* types, int num, int sp, int re):NoteKeys(keys), 
      NoteTypes(types), amounts(num), pad_speed(sp), one_pad_representative(re){};
    void play_music();
};

//music1 ： ABCBD
//平常音用5
float Notes_X[] = {
  NOTE_E6, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_B5, NOTE_G5, //0+11
  NOTE_A5, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_A4, 0, NOTE_E5, NOTE_D5, NOTE_C5, //11+12
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_D5, //23+7
  NOTE_E5//31
};//float* keys_X = Notes_X;
float Types_X[] = {
  16, 16, 16, 16, 8, 16, 16, 8, 8, 8, 8,
  16, 16, 16, 16, 8, 16, 16, 4, 16, 16, 16, 16,
  8/3, 16, 16, 8, 8, 8, 8,
  1
};//float* types_X = Types_X;

float Notes_A[] = {
  NOTE_A4, NOTE_E5, NOTE_A4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4,
  NOTE_G4, NOTE_E3, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4,
  NOTE_C5, NOTE_D6, NOTE_D5, NOTE_C5, NOTE_B4,NOTE_G3, NOTE_G4, NOTE_E5,
  NOTE_E5, 0, 0,
  NOTE_A4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_G3, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_A4, 0,
  NOTE_A4, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_G3, NOTE_G4, NOTE_A3, NOTE_B3,
  NOTE_A4, 0, 0//here=52
};//float* keys_A = Notes_A;
float Types_A[] = {
  8, 8, 8, 8, 8, 8, 8, 8,
  16/3, 16, 8, 8, 4, 8, 8,
  16/3, 16, 8, 8, 16/3, 16, 8, 8,
  4, 4, 2,//27
  8, 8, 8, 8, 4, 8, 8,
  16/3, 16, 8, 8, 8, 4, 4,//41
  8, 8, 8, 8, 16/3, 16, 8, 16, 16,
  4, 4, 2//53
};//float* types_A = Types_A;

float Notes_B[] = {
  NOTE_A4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4,
  NOTE_G4, NOTE_A3, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_C5,
  NOTE_E5, NOTE_A3, NOTE_A4, NOTE_E5, NOTE_D5, NOTE_G3, NOTE_G4, NOTE_E5,
  NOTE_E5, 0, 0,
  NOTE_A5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_B4,
  NOTE_C5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_G3, NOTE_G4, NOTE_G3, NOTE_A3,
  NOTE_A4, 0, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_B5, NOTE_B5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_G5,
  NOTE_A5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_G5,
  NOTE_E5, 0, NOTE_E5, NOTE_G5, NOTE_E5,
  NOTE_A5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_C5,
  NOTE_E5, NOTE_D5, NOTE_A4, NOTE_E5, NOTE_D5, NOTE_G3, NOTE_G4, NOTE_C5//here=102
};//float* keys_B = Notes_B;
float Types_B[] = {
  8, 8, 8, 8, 8, 8, 8, 8,
  16/3, 16, 8, 8, 4, 8, 8,
  16/3, 16, 8, 8, 16/3, 16, 8, 8,
  4, 4, 2,//26
  16/3, 16, 8, 8, 4, 8, 8,
  16/3, 16, 8, 8, 4, 8, 8,//40
  16/3, 16, 8, 8, 16/3, 16, 8, 16, 16,
  4, 2, 8, 8,//49
  16/3, 16, 8, 8, 4, 8, 8,
  16/3, 16, 8, 16, 16, 4, 8, 8,
  16/3, 16, 8, 8, 4, 8, 8,
  4, 4, 8, 8, 8, 8,//77
  16/3, 16, 8, 8, 4, 8, 8,
  16/3, 16, 8, 8, 4, 8, 8,
  8, 8, 8, 8, 16/3, 16, 8, 8//102
};//float* types_B = Types_B;

float Notes_C[] = {
  NOTE_A4, 0,
  NOTE_E6, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_B5, NOTE_G5,
  NOTE_A5, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_A4, 0, NOTE_E5, NOTE_D5, NOTE_C5,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_D5,
  NOTE_E5, 0, NOTE_B5, NOTE_E6, NOTE_G6,
  NOTE_A6, NOTE_G6, NOTE_E6, NOTE_G6,
  NOTE_E6, NOTE_D6, NOTE_C6, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4,
  NOTE_A4, NOTE_C5, NOTE_D5, NOTE_A5, NOTE_G5, NOTE_E5,
  NOTE_A5, 0, 0, 0
};//float* keys_C = Notes_C;
float Types_C[] = {
  2, 2,
  16, 16, 16, 16, 8, 16, 16, 8, 8, 8, 8,//13
  16, 16, 16, 16, 8, 16, 16, 4, 16, 16, 16, 16,//25
  8/3, 16, 16, 8, 8, 8, 8,//32
  2, 8, 8, 8, 8,//37
  8/3, 16, 16, 2,//41
  16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 8,//55
  8, 8, 8, 8, 4, 4,
  1//62
};//float* types_C = Types_C;

float Notes_D[] = {
  NOTE_A4, 0, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_B5, NOTE_B5, NOTE_G5, NOTE_A5, NOTE_E5, NOTE_G5,
  NOTE_A5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_G5,
  NOTE_E5, 0, NOTE_E5, NOTE_G5, NOTE_E5,
  NOTE_A5, NOTE_G5, NOTE_G5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_B5, NOTE_B5, NOTE_G5, NOTE_A5, NOTE_A4, NOTE_C5,
  NOTE_E5, NOTE_D5, NOTE_A4, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_G4, NOTE_C5,
  NOTE_A4, NOTE_A4, NOTE_C5,
  NOTE_E5, NOTE_D5, NOTE_A4, NOTE_E5, NOTE_D5, NOTE_G4, 0, NOTE_B4,
  NOTE_A4, 0,
  NOTE_G5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_D5,
  NOTE_E5, NOTE_G5, NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5,
  0, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_G5,
  NOTE_A5,
};//float* keys_D = Notes_D;
float Types_D[] = {
  2, 4, 8, 8,//4
  8/3, 16, 8, 8, 4, 8, 8,//11
  8/3, 16, 8, 8, 4, 8, 8,//18
  8/3, 16, 8, 8, 4, 8, 8,//25
  2, 8, 8, 8, 8,//30
  8/3, 16, 8, 8, 4, 8, 8,//37
  8/3, 16, 8, 8, 4, 8, 8,//44
  8, 8, 8, 8, 8, 8, 8, 8,//52
  4/3, 8, 8,//55
  8, 8, 8, 8, 16/3, 16, 8, 8,//63
  2, 2,//65
  16, 8, 16, 8, 16, 16, 16, 16, 8, 4,//75
  16, 8, 16, 8, 16, 16, 16, 16, 8, 4,//85
  8, 8, 8, 8, 4, 4,//
  1//92
};//float* types_D = Types_D;

//original: 96 --> 60
MusicSheet sheetX(Notes_X, Types_X, 31, 60, 4);
MusicSheet sheetA(Notes_A, Types_A, 52, 60, 4);
//MusicSheet sheetB(Notes_B, Types_B, 102, 60, 4);
//MusicSheet sheetC(Notes_C, Types_C, 62, 60, 4);
//MusicSheet sheetD(Notes_D, Types_D, 92, 60, 4);
void setup(){
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(11, INPUT);
}

void loop(){
  if(digitalRead(11)==1){
    sheetX.play_music();
    sheetA.play_music();
//    sheetB.play_music();
//    sheetC.play_music();
//    sheetB.play_music();
//    sheetD.play_music();
  }
}

void MusicSheet::play_music(){
  for (int thisNote = 0; thisNote < amounts; thisNote++) {
    //60/pad_speed means：x sec/per pad
    //*1000, for 1 sec = 1000 millisec
    //one_pad_representative store the Note that represent as one human-pad
    //the time for each QuartarNote, so later if we devide QuartarNote(4), will means one pad
    const int pad = 60/pad_speed*1000*one_pad_representative;
    //the duration of the sound should remain
    int noteDuration = pad / NoteTypes[thisNote];
//    Serial.print(noteDuration);
    tone(7, NoteKeys[thisNote]);
    delay(noteDuration);
  }
  tone(7, 0, 10);
}


//void play_music_in_loop(bool flag, int amount){  
//  for (int thisNote = 0; thisNote < amount; thisNote++) {
//    // to calculate the note duration, take one second divided by the note type.
//    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//
//    const int pad_speed = 60;//original song = 96
//    const int pad = 60/pad_speed*1000*4; //the time for each QuartarNote, so later if we devide QuartarNote(4), will means one pad
//    int noteDuration = pad / music_noteTypes1_B[thisNote]; // 500/music_noteDuration..
//    Serial.print(noteDuration);
//    tone(7, music1_B[thisNote]);
//    delay(noteDuration); // delay(350)
//  }
//  tone(7, 0, 10);
//}

//int index=0, max_=102;
//void play_music_by_index(bool flag){
//  if(index<max_){
//    // to calculate the note duration, take one second divided by the note type.
//    //e.g. quarter note = 500 / 4, eighth note = 500/8, etc.
//    int noteDuration = 500 / music_noteTypes1_B[index]; // 500/music_noteDuration..
//    tone(7, music1_B[index], noteDuration);
//    delay(350); // delay(350)
//    index+=1;
//    //should stop the calling loop
//  }else{
//    index=0;
//  }
//}
