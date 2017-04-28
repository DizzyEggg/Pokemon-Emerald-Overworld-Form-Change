#include "defines.h"

void *shaymin_script();

void run_script_from_item(int taskID)
{
    script_env2_enable(taskID);
    script_run(shaymin_script);
    task_delete(taskID);
}

#define SHAYMIN_FLY POKE_TROPIUS
#define SHAYMIN_LAND POKE_TREECKO

void item_forme_change_handler()
{
    routine_to_run_after_graphics = (void *) &run_script_from_item;
    run_after_graphics();
}

void shaymin_change_species()
{
    u8 i=var_8004;
    u16 target_species=SHAYMIN_FLY;
    struct pokemon* poke = &party_player[i];
    set_attributes(poke,ATTR_SPECIES,&target_species);
    calculate_stats_pokekmon(poke);
}

void check_shaymin()
{
    struct pokemon* poke = &party_player[var_8004];
    u16 species = get_attributes(poke,ATTR_SPECIES,0);
    if(species==SHAYMIN_LAND)
    {
        var_800D_lastresult=1;
    }
    else
    {
        var_800D_lastresult=0;
    }
}
