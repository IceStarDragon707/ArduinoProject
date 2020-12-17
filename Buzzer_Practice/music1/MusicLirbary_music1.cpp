//#define TONE_USE_INT
//#define TONE_PITCH 440
//
//#include <Pitch.h>
#include <Arduino.h>

#include "MusicLirbary_music1.h"

void play_music1_in_loop(bool flag){  
  for (int thisNote = 0; thisNote < 102; thisNote++) {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 500 / 4, eighth note = 500/8, etc.
    int noteDuration = 500 / music_noteDurations1_B[thisNote]; // 500/music_noteDuration..
    tone(7, music1_B[thisNote], noteDuration);
    delay(350); // delay(350)
  }
}


int index=0, max_=102;
void play_music1_by_index(bool flag){
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
