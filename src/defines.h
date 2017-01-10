#ifndef DEFINES_H
#define DEFINES_H

#include "types.h"

enum poke_sprite{
    SPRITE_BACK = 0,
    SPRITE_FRONT = 1
};

enum poke_gender{
    POKE_MALE = 0,
    POKE_FEMALE = 0xFE,
    POKE_GENDERLESS = 0xFF
};

#include "./defines/poke_types.h"
#include "./defines/abilities.h"
#include "./defines/moves.h"
#include "./defines/get_attr.h"
#include "./defines/items.h"
#include "./defines/item_effects.h"
#include "./defines/pokes.h"
#include "./defines/flavours.h"

#include "config.h"
#include "battle_structs.h"
#include "battle_locations.h"
#include "vanilla_functions.h"

#define STAT_ATTACK 1
#define STAT_DEFENCE 2
#define STAT_SPD 3
#define STAT_SP_ATK 4
#define STAT_SP_DEF 5
#define STAT_ACCURACY 6
#define STAT_EVASION 7

#define BACKGROUND_GRASS 0x0
#define BACKGROUND_LONG_GRASS 0x1
#define BACKGROUND_SAND 0x2
#define BACKGROUND_UNDERWATER 0x3
#define BACKGROUND_WATER 0x4
#define BACKGROUND_POND 0x5
#define BACKGROUND_ROCK 0x6
#define BACKGROUND_CAVE 0x7
#define BACKGROUND_INDOORS 0x8
#define BACKGROUND_INDOORS_2 0x9



#endif /* DEFINES_H */
