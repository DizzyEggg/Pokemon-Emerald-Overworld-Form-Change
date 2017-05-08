#ifndef VANILLA_FUNCTIONS
#define VANILLA_FUNCTIONS

#include "types.h"

void __attribute__((long_call)) run_after_graphics();
void __attribute__((long_call)) script_env2_enable(int taskID);
void __attribute__((long_call)) script_run(void *scriptLoc);
void __attribute__((long_call)) pokemon_slot_purge(struct pokemon* poke);
void __attribute__((long_call)) Special_E0_delete_move();
u8 __attribute__((long_call)) party_move_up_no_free_slots_in_between();

u16 __attribute__((long_call)) teach_move_in_available_slot(struct pokemon* , u16 move);
bool __attribute__((long_call)) bag_add_item(u16 item_id, u8 a);
char __attribute__((long_call)) *int_to_str(char *buffer, u8 lvl, u8 a, u8 b);
u8 __attribute__((long_call)) get_item_x12_battle_function(u16 item_id);
u8 __attribute__((long_call)) get_item_quality(u16 item_id);
u8 __attribute__((long_call)) read_byte(void*);
s16 __attribute__((long_call)) read_hword(void*);
u32 __attribute__((long_call)) read_word(void*);
u16 __attribute__((long_call)) rng();
void __attribute__((long_call)) calculate_stats_pokekmon(struct pokemon* poke);
u32 __attribute__((long_call)) get_attributes(struct pokemon* poke_address, u8 request, void* dst);
void __attribute__((long_call)) set_attributes(struct pokemon* poke_address, u8 request, void* new_value);
u8 __attribute__((long_call)) item_is_mail(u16 itemID);
u8 __attribute__((long_call)) get_lvl_from_exp(struct pokemon*);
void __attribute__((long_call)) task_delete(u8 taskID);
char* __attribute__((long_call)) get_player_name_address();
s8 __attribute__((long_call)) compare_two_strings(void* string1, void* string2);
char* __attribute__((long_call)) get_trainername_address(u16 trainerID);
void __attribute__((long_call)) play_sound(u16 songID);
void __attribute__((long_call)) play_cry(u16 species, u8 param1, u8 param2);
u32 __attribute__((long_call)) get_item_lastword(u16 itemID);
u8 __attribute__((long_call)) checkitem(u16 itemID, u16 quantity);
u8 __attribute__((long_call)) get_poke_ability(struct pokemon* poke);
u8 __attribute__((long_call)) prepare_party_mail_to_give(struct pokemon* poke, u16 item);



#include<string.h>
#include<stdlib.h>

#endif /* VANILLA_FUNCTIONS */
