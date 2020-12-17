#define TONE_USE_INT
#define TONE_PITCH 440
#include <Pitch.h>

#ifndef MUSICPLAYER_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define MUSICPLAYER_H
#include "MusicPlayer.h"
void play_music1_in_loop(bool flag);
void play_music1_by_index(bool flag);
#endif
