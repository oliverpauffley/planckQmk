#pragma once
#include "musical_notes.h"

#define SONG_LIST_H
#define NO_SOUND

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(ZELDA_P)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

#define TAPPING_TERM 200

// Define some songs:
#define IMPERIAL \
  HD_NOTE(_A4), \
        HD_NOTE(_A4), HD_NOTE(_A4), QD_NOTE(_F4), QD_NOTE(_C5), \
  HD_NOTE(_A4),  \
        QD_NOTE(_F4), QD_NOTE(_C5), WD_NOTE(_A4), \
  HD_NOTE(_E5),  \
        HD_NOTE(_E5), HD_NOTE(_E5), QD_NOTE(_F5), QD_NOTE(_C5), \
  HD_NOTE(_A4),  \
        QD_NOTE(_F4), QD_NOTE(_C5), WD_NOTE(_A4)

#define COIN\
    E__NOTE(_A5  ),\
    HD_NOTE(_E6  ),

#define ZELDA_P\
    Q__NOTE(_G5),\
    Q__NOTE(_FS5),\
    Q__NOTE(_DS5),\
    Q__NOTE(_A4),\
    Q__NOTE(_GS4),\
    Q__NOTE(_E5),\
    Q__NOTE(_GS5),\
    HD_NOTE(_C6),

#define ZELDA_T \
    Q__NOTE(_A4 ),\
    Q__NOTE(_AS4),\
    Q__NOTE(_B4 ),\
    HD_NOTE(_C5 ),

#define VICTORY \
    ED_NOTE(_C6),\
    ED_NOTE(_C6),\
    ED_NOTE(_C6),\
    ED_NOTE(_C6),\
    W__NOTE(_REST),\
    QD_NOTE(_GS5),\
    QD_NOTE(_AS5),\
    Q__NOTE(_C6),\
    Q__NOTE(_AS5),\
    Q__NOTE(_C6),

#define ANCIENTS \
  H__NOTE(_D6), H__NOTE(_EF6), B__NOTE(_EF6), H__NOTE(_EF6), H__NOTE(_D6), H__NOTE(_BF5), H__NOTE(_G5), BD_NOTE(_C6), H__NOTE(_D6),\
  H__NOTE(_EF6), B__NOTE(_EF6), H__NOTE(_EF6), H__NOTE(_D6), H__NOTE(_BF5), H__NOTE(_G5), BD_NOTE(_G6), H__NOTE(_G5),\
  H__NOTE(_AF5), B__NOTE(_G6), H__NOTE(_AF6), H__NOTE(_G6), H__NOTE(_F6), H__NOTE(_D6), H__NOTE(_D6), H__NOTE(_EF6),\
  B__NOTE(_EF6), WD_NOTE(_G5), WD_NOTE(_BF5), H__NOTE(_D6), H__NOTE(_EF6), B__NOTE(_EF6), H__NOTE(_EF6), H__NOTE(_D6),\
  H__NOTE(_BF5), H__NOTE(_G5), BD_NOTE(_C6), WD_NOTE(_B5), WD_NOTE(_G5), WD_NOTE(_G6), W__NOTE(_G6), H__NOTE(_AF6), \
  W__NOTE(_G6), H__NOTE(_AF6), H__NOTE(_G6), H__NOTE(_F6), H__NOTE(_D6), H__NOTE(_D6), H__NOTE(_EF6), B__NOTE(_EF6),\
  WD_NOTE(_E6), H__NOTE(_E6), H__NOTE(_F6), H__NOTE(_G6), H__NOTE(_BF6), H__NOTE(_AF6), W__NOTE(_AF6), H__NOTE(_C6),\
  H__NOTE(_BF6), H__NOTE(_AF6), W__NOTE(_AF6), H__NOTE(_C6), H__NOTE(_AF6), BD_NOTE(_G6), WD_NOTE(_B5), WD_NOTE(_G6),\
  W__NOTE(_G6), H__NOTE(_AF6), W__NOTE(_G6), H__NOTE(_AF6), H__NOTE(_G6), H__NOTE(_F6), H__NOTE(_D6), H__NOTE(_D6),\
  H__NOTE(_EF6), B__NOTE(_EF6), WD_NOTE(_E6), H__NOTE(_E6), H__NOTE(_F6), H__NOTE(_G6), H__NOTE(_BF6), H__NOTE(_AF6),\
  W__NOTE(_AF6), H__NOTE(_C6), H__NOTE(_AF6), H__NOTE(_G6), W__NOTE(_G6), H__NOTE(_F6), H__NOTE(_D6), BD_NOTE(_EF6),\
  WD_NOTE(_F6), WD_NOTE(_G6), BD_NOTE(_C7),

// enable basic MIDI features:
#define MIDI_BASIC

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4
