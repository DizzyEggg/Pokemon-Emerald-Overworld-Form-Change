#include "defines.h"

void *shaymin_script();
void *hoopa_script();
void *therain_trio_script();

void run_script_from_item_shaymin(int taskID)
{
    script_env2_enable(taskID);
    script_run(shaymin_script);
    task_delete(taskID);
}

void run_script_from_item_hoopa(int taskID)
{
    script_env2_enable(taskID);
    script_run(hoopa_script);
    task_delete(taskID);
}

void run_script_from_item_therain_trio(int taskID)
{
    script_env2_enable(taskID);
    script_run(therain_trio_script);
    task_delete(taskID);
}

#define SHAYMIN_FLY POKE_TROPIUS
#define SHAYMIN_LAND POKE_TREECKO

void item_forme_change_handler_shaymin()
{
    routine_to_run_after_graphics = (void *) &run_script_from_item_shaymin;
    run_after_graphics();
}

void item_forme_change_handler_hoopa()
{
    routine_to_run_after_graphics = (void *) &run_script_from_item_hoopa;
    run_after_graphics();
}

void item_forme_change_handler_therain_trio()
{
    routine_to_run_after_graphics = (void *) &run_script_from_item_therain_trio;
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

#define HOOPA_UNBOUND POKE_TROPIUS
#define HOOPA_CONFINED POKE_TREECKO

void check_hoopa()
{
    struct pokemon* poke = &party_player[var_8004];
	u16 species = get_attributes(poke,ATTR_SPECIES,0);
	if (species==HOOPA_CONFINED)
	{
		var_800D_lastresult=1;
	}
	else
	{
		var_800D_lastresult=0;
	}
}

void hoopa_change_species()
{
    u8 i=var_8004;
    u16 target_species=HOOPA_UNBOUND;
    struct pokemon* poke = &party_player[i];
    set_attributes(poke,ATTR_SPECIES,&target_species);
    calculate_stats_pokekmon(poke);
}

#define TORNADUS_INCARNATE POKE_WALREIN
#define TORNADUS_THERIAN POKE_TREECKO
#define THUNDURUS_INCARNATE POKE_MANECTRIC
#define THUNDURUS_THERIAN POKE_TORCHIC
#define LANDORUS_INCARNATE POKE_TROPIUS
#define LANDORUS_THERIAN POKE_MUDKIP

void check_therain_trio()
{
	struct pokemon* poke = &party_player[var_8004];
	u16 species = get_attributes(poke,ATTR_SPECIES,0);
	u16 target_species=0;
	
	switch (species)
	{
		case TORNADUS_INCARNATE:
		target_species = TORNADUS_THERIAN;
		break;
		
		case TORNADUS_THERIAN:
		target_species = TORNADUS_INCARNATE;
		break;
		
		case THUNDURUS_INCARNATE:
		target_species = THUNDURUS_THERIAN;
		break;
		
		case THUNDURUS_THERIAN:
		target_species = THUNDURUS_INCARNATE;
		break;
		
		case LANDORUS_INCARNATE:
		target_species = LANDORUS_THERIAN;
		break;
		
		case LANDORUS_THERIAN:
		target_species = LANDORUS_INCARNATE;		
		break;		
	}
	
	if(target_species)
    {
    set_attributes(poke,ATTR_SPECIES,&target_species);
    calculate_stats_pokekmon(poke);
    var_800D_lastresult=1;
    }
    else
    {
    var_800D_lastresult=0;
    }
        
}