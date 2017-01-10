#include "defines.h"



#define POKE_ROTOM POKE_TREECKO

enum rotom_forms
{
    POKE_ROTOM_HEAT=POKE_FLAREON,
    POKE_ROTOM_WASH=POKE_VAPOREON,
    POKE_ROTOM_FROST=POKE_HYPNO,
    POKE_ROTOM_FAN=POKE_ABRA,
    POKE_ROTOM_MOW=POKE_AGGRON
};

struct rotom_set
{
    enum rotom_forms form_index;
    u16 special_move;
};

struct rotom_set rotom_move_mapping[5] = {{POKE_ROTOM_HEAT,MOVE_OVERHEAT},{POKE_ROTOM_WASH,MOVE_HYDRO_PUMP},
            {POKE_ROTOM_FROST,MOVE_BLIZZARD},{POKE_ROTOM_FAN,MOVE_AIR_SLASH},{POKE_ROTOM_MOW,MOVE_LEAF_STORM}};

void find_rotom()
{
    for(u8 i=0;i<6;i++)
    {
        bool valid_rotom=false;
        struct pokemon* poke = &party_player[i];
        u16 species = get_attributes(poke,ATTR_SPECIES,0);
        if(species==POKE_ROTOM)
        {
            var_8004=i;
            break;
        }
        else
        {
            for(u8 j=0;j<5;j++)
            {
                if(species==rotom_move_mapping[j].form_index)
                {
                    var_8003=rotom_move_mapping[j].special_move;
                    valid_rotom=true;
                    break;
                }
            }
            if(valid_rotom)
            {
                var_8004=i;
                break;
            }
        }
    }
}

void rotom_map()
{
    if(var_800D_lastresult==0x5)
    {
        var_8005=POKE_ROTOM;
    }
    else
    {
        var_8005=rotom_move_mapping[var_800D_lastresult].form_index;
    }
}

void rotom_change()
{
    u16 target_species=var_8005;
    u8 move_slot_to_purge=4;
    u16 special_move_to_remove=var_8003;
    u8 i=var_8004;

    struct pokemon* poke = &party_player[i];
    u16 species = get_attributes(poke,ATTR_SPECIES,0);
    if(species!=target_species)
    {
        if(species!=POKE_ROTOM)
        {
            for(u8 j=0;j<4;j++)
            {
                u16 moveset_move=get_attributes(poke,ATTR_ATTACK_1+j,0);
                if(moveset_move==0)
                {
                    break;
                }
                if(special_move_to_remove==moveset_move) //0x0 in rotom's case
                {
                    move_slot_to_purge=j;
                    break;
                }
            }
            if(move_slot_to_purge==4)
            {
                var_800D_lastresult=2;
            }
            else
            {
                var_8005=move_slot_to_purge;
                if(target_species==POKE_ROTOM)
                {
                    var_800D_lastresult=3;
                }
                else
                {
                    var_800D_lastresult=1;
                }
            }
        }
        else
        {
            var_800D_lastresult=2;
        }
        set_attributes(poke,ATTR_SPECIES,&target_species);
        calculate_stats_pokekmon(poke);
        var_8004=i;
    }
    else
    {
        if(species!=POKE_ROTOM)
        {
            var_800D_lastresult=0;
        }
        else
        {
            var_800D_lastresult=4;
        }

    }
}


void rotom_determing_special_move()
{
    var_800D_lastresult=0;
    u16 special_move_to_learn=0;
    u8 i=var_8004;
    struct pokemon* poke = &party_player[i];
    u16 species = get_attributes(poke,ATTR_SPECIES,0);
    if(species!=POKE_ROTOM)
    {
        for(u8 j=0;j<5;j++)
        {
            if(species==rotom_move_mapping[j].form_index)
            {
                special_move_to_learn=rotom_move_mapping[j].special_move;
                break;
            }
        }
    }
    else
    {
        if(!get_attributes(poke,ATTR_ATTACK_1,0))
        {
            special_move_to_learn=MOVE_THUNDER_SHOCK;
        }
    }
    if(special_move_to_learn)
    {
        var_8006=special_move_to_learn;
    }
}

void rotom_learn_move()
{
    struct pokemon* poke=&party_player[var_8004];
    teach_move_in_available_slot(poke,var_8006);
}

void store_move_to_var8003_from_var8005_in_slot_var8004()
{
    struct pokemon* poke=&party_player[var_8004];
    var_8003 = get_attributes(poke,ATTR_ATTACK_1+var_8005,0);
}
