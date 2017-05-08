#ifndef CONFIG_H
#define CONFIG_H

#include "types.h"

#define ALL_POKES       412     //number of all pokemon
#define ALL_ITEMS       377     //number of all items
#define NUM_OF_EVOS     5       //number of evolutions per pokemon
#define SAVE_FUSEE 0x2060000

//////////////////////////////////////////////////////////////////////////////
////                       GIRATINA CONFIG                                ////
//////////////////////////////////////////////////////////////////////////////
#define POKE_GIRATINA 1250
#define POKE_GIRATINA_O 1251


//////////////////////////////////////////////////////////////////////////////
////                       SHAYMIN CONFIG                                  ////
//////////////////////////////////////////////////////////////////////////////

#define SHAYMIN_FLY POKE_TROPIUS
#define SHAYMIN_LAND POKE_TREECKO


//////////////////////////////////////////////////////////////////////////////
////                       HOOPA CONFIG                                  ////
//////////////////////////////////////////////////////////////////////////////

#define HOOPA_UNBOUND POKE_MANECTRIC
#define HOOPA_CONFINED POKE_POOCHYENA


//////////////////////////////////////////////////////////////////////////////
////                       FORCES OF NATURE CONFIG                                  ////
//////////////////////////////////////////////////////////////////////////////

#define TORNADUS_INCARNATE POKE_WALREIN
#define TORNADUS_THERIAN POKE_TREECKO
#define THUNDURUS_INCARNATE POKE_MANECTRIC
#define THUNDURUS_THERIAN POKE_TORCHIC
#define LANDORUS_INCARNATE POKE_TROPIUS
#define LANDORUS_THERIAN POKE_MUDKIP


//////////////////////////////////////////////////////////////////////////////
////                       KYUREM CONFIG                                  ////
//////////////////////////////////////////////////////////////////////////////

#define POKE_RESHIRAM POKE_POOCHYENA
#define POKE_ZEKROM POKE_WURMPLE
#define POKE_KYUREM POKE_TREECKO
#define POKE_KYUREM_BLACK POKE_BEAUTIFLY
#define POKE_KYUREM_WHITE POKE_SHIFTRY


//////////////////////////////////////////////////////////////////////////////
////                       ARCEUS CONFIG                                  ////
//////////////////////////////////////////////////////////////////////////////

#define POKE_ARCEUS 1300
enum arceus_formes_idx {
    POKE_ARCEUS_FIGHTING = 1301,  // This a enum. The subsequent value of indexes will be 1302, 1303 etc.
    POKE_ARCEUS_FLYING,
    POKE_ARCEUS_POISON,
    POKE_ARCEUS_GROUND,
    POKE_ARCEUS_ROCK,
    POKE_ARCEUS_BUG,
    POKE_ARCEUS_GHOST,
    POKE_ARCEUS_STEEL,
    POKE_ARCEUS_FIRE,
    POKE_ARCEUS_WATER,
    POKE_ARCEUS_GRASS,
    POKE_ARCEUS_ELECTRIC,
    POKE_ARCEUS_PSYCHIC,
    POKE_ARCEUS_ICE,
    POKE_ARCEUS_DRAGON,
    POKE_ARCEUS_DARK,
    POKE_ARCEUS_FAIRY,
};

//////////////////////////////////////////////////////////////////////////////
////                       SILVALLY CONFIG                                ////
//////////////////////////////////////////////////////////////////////////////
#define ABILITY_RKS_SYSTEM 240
#define POKE_SILVALLY 1340
enum silvally_forms_idx {
    POKE_SILVALLY_FIGHTING = 1341,
    POKE_SILVALLY_FLYING,
    POKE_SILVALLY_POISON,
    POKE_SILVALLY_GROUND,
    POKE_SILVALLY_ROCK,
    POKE_SILVALLY_BUG,
    POKE_SILVALLY_GHOST,
    POKE_SILVALLY_STEEL,
    POKE_SILVALLY_FIRE,
    POKE_SILVALLY_WATER,
    POKE_SILVALLY_GRASS,
    POKE_SILVALLY_ELECTRIC,
    POKE_SILVALLY_PSYCHIC,
    POKE_SILVALLY_ICE,
    POKE_SILVALLY_DRAGON,
    POKE_SILVALLY_DARK,
    POKE_SILVALLY_FAIRY,
};

//////////////////////////////////////////////////////////////////////////////
////                       GENESECT CONFIG                                ////
//////////////////////////////////////////////////////////////////////////////
#define POKE_GENESECT 1380
enum genesect_formes{
    POKE_GENESECT_DOUSE = 1381,
    POKE_GENESECT_BURN,
    POKE_GENESECT_CHILL,
    POKE_GENESECT_SHOCK
};

enum drives
{
    DOUSE_DRIVE_EFFECT=1,
    BURN_DRIVE_EFFECT,
    CHILL_DRIVE_EFFECT,
    SHOCK_DRIVE_EFFECT
};


//////////////////////////////////////////////////////////////////////////////
////                        ROTOM CONFIG                                  ////
//////////////////////////////////////////////////////////////////////////////
#define POKE_ROTOM 1400

enum rotom_forms
{
    POKE_ROTOM_HEAT=1401,
    POKE_ROTOM_WASH,
    POKE_ROTOM_FROST,
    POKE_ROTOM_FAN,
    POKE_ROTOM_MOW
};

//////////////////////////////////////////////////////////////////////////////
////                        DEOXYS CONFIG                                 ////
//////////////////////////////////////////////////////////////////////////////
enum deoxys_forms
{
    POKE_DEOXYS_ATTACK=1450,
    POKE_DEOXYS_DEFENSE,
    POKE_DEOXYS_SPEED,
};

#endif /* CONFIG_H */
