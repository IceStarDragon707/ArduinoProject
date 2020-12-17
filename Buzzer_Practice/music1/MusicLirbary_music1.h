#define TONE_USE_INT
#define TONE_PITCH 440
#include <Pitch.h>

#ifndef MUSICLIBRARY_MUSIC1_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define MUSICLIBRARY_MUSIC1_H
#include "MusicLirbary_music1.h"
void play_music1_in_loop(bool flag);
void play_music1_by_index(bool flag);
#endif

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
