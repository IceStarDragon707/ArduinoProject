/**
 * Proposition
 *
 * when importing the "Arduino.h" library (this is implicit in the Arduino IDE),
 * one of the headers "Pitches.h" there are not very accurate values for musical notes
 *
 * @example NOTE_C4, NOTE_D4...
 */
#include <Arduino.h>

/**
 * Libary Configuration
 * 
 * @see set up tune 
 *
 * @example TONE_DEFAULT
 * @example TONE_PITCH 432
 * @example TONE_PITCH 434
 * @example TONE_PITCH 436
 * @example TONE_PITCH 438
 * @example TONE_PITCH 440
 * @example TONE_PITCH 442
 * @example TONE_PITCH 444
 * @example TONE_PITCH 446
 *
 *
 * @see set up typing 
 *
 * @example TONE_USE_INT
 * @example TONE_USE_DOUBLE
 *
 */

#define TONE_USE_INT
#define TONE_PITCH 440

/**
 * 
 * Import dependency
 *
 * after configuring, when importing the library the old values will be replaced by new and more refined.
 * this makes it compatible with any library or third-party code previously worked on.
 *
 */
#include <Pitch.h>

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


float melody2[] = {
  610.94, 407.75, 457.69, NOTE_B4, 457.69, NOTE_B4, 544.29, NOTE_B4, 457.69, 363.27, 407.75
};
float noteDurations2[] = {
  8, 8, 8, 8/3, 8, 8, 4, 4, 4, 4, 8
};

//music1 ： ABCBD
//平常音用5
float music1_A[] = {
  NOTE_A4, NOTE_E5, NOTE_A4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4,
  NOTE_G4, NOTE_E3, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4,
  NOTE_C5, NOTE_D6, NOTE_D5, NOTE_C5, NOTE_B4,NOTE_G3, NOTE_G4, NOTE_E5,
  NOTE_E5, 0, 0,
  NOTE_A4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_G3, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_A4, 0,
  NOTE_A4, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_G3, NOTE_G4, NOTE_A3, NOTE_B3,
  NOTE_A4, 0, 0//here=53
};
float music_noteDurations1_A[] = {
  8, 8, 8, 8, 8, 8, 8, 8,
  16/3, 16, 8, 8, 4, 8, 8,
  16/3, 16, 8, 8, 16/3, 16, 8, 8,
  4, 4, 2,//27
  8, 8, 8, 8, 4, 8, 8,
  16/3, 16, 8, 8, 8, 4, 4,//41
  8, 8, 8, 8, 16/3, 16, 8, 16, 16,
  4, 4, 2//53
};

float music1_B[] = {
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
  NOTE_E5, NOTE_D5, NOTE_A4, NOTE_E5, NOTE_D5, NOTE_G3, NOTE_G4, NOTE_C5//here=99
};

float music_noteDurations1_B[] = {
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
};

float music1_C[] = {
  1
};

float music1_D[] = {
  1
};


void setup(){
  pinMode(7, OUTPUT);
  pinMode(11, INPUT);
}

void loop(){
  if(digitalRead(11)==1){
    play_music_in_loop(true);
  }
}

void play_music_in_loop(bool flag){  
  for (int thisNote = 0; thisNote < 102; thisNote++) {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / music_noteDurations1_B[thisNote]; // 500/music_noteDuration..
    tone(7, music1_B[thisNote], noteDuration);
    delay(350); // delay(350)
  }
}


int index=0, max_=102;
void play_music_by_index(bool flag){
  if(index<max_){
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 500 / 4, eighth note = 500/8, etc.
    int noteDuration = 500 / music_noteDurations1_B[index]; // 500/music_noteDuration..
    tone(7, music1_B[index], noteDuration);
    delay(350); // delay(350)
    index+=1;
    //should stop the calling loop
  }else{
    index=0;
  }
}
