#ifndef VANILLA_FUNCTIONS
#define VANILLA_FUNCTIONS

#include "types.h"

void run_after_graphics();
void script_env2_enable(int taskID);
void script_run(void *scriptLoc);


u16 teach_move_in_available_slot(struct pokemon* , u16 move);
bool bag_add_item(u16 item_id, u8 a);
char *int_to_str(char *buffer, u8 lvl, u8 a, u8 b);
u8 get_item_x12_battle_function(u16 item_id);
u8 get_item_quality(u16 item_id);
u8 read_byte(void*);
s16 read_hword(void*);
u32 read_word(void*);
u16 rng();
void calculate_stats_pokekmon(struct pokemon* poke);
u8 calc_total_move_pp(u16 move_id, u8 pp_bonus, u8 moveset_slot);
u8 get_item_pocket_id(u16 itemID);
void* strcpy_xFF_terminated_0(void* destination, void* text_to_copy);
u8 gender_from_pid(u16 species, u32 PID);
s8 itemid_to_berryid(u16 itemID);
u16 species_to_national_dex(u16 species);
u16 get_height_or_weight(u16 national_dex_index, u8 which_one);
s8 get_poke_flavour_relation(u32 pid, u8 flavour);
u8 is_poke_disobedient();
u32 get_attributes(struct pokemon* poke_address, u8 request, void* dst);
void set_attributes(struct pokemon* poke_address, u8 request, void* new_value);
u8 item_is_mail(u16 itemID);
u8 get_lvl_from_exp(struct pokemon*);
void task_delete(u8 taskID);
char* get_player_name_address();
s8 compare_two_strings(void* string1, void* string2);
char* get_trainername_address(u16 trainerID);
void play_sound(u16 songID);
void play_cry(u16 species, u8 param1, u8 param2);
u32 get_item_lastword(u16 itemID);
u8 checkitem(u16 itemID, u16 quantity);
void prepare_fainting_cry(u8 bufferID);
u8 gpu_pal_tags_index_of(u16 tag);
void set_callback2(void* ptr);
void set_obj_pos(u8 ID, u16 x, u16 y);
void c2_80777E8();
void obj_delete(struct object*);
u8 get_poke_ability(struct pokemon* poke);
u32 malloc_and_clear(u16 size);
void free(void* address);
void* poke_get_pal(u16 species, u32 TiD, u32 PiD);
void LZ77UnCompWram(void* src, void* dst);
void gpu_pal_apply(struct palette* src, u16 index, u16 num_colours);
void* shorten_str_to_10(void* src);
void* str_append(void* dst, void* src);
enum poke_gender poke_get_gender(struct pokemon* poke);
void* sub_8075094(void* string, u16 arg2, u16 arg3, u16 arg4, u8* rboxID);
void sub_8075198(void* ptr, void* pixles, u8 arg3);
void rboxid_08003574(u8 rboxID);
void pal_fade_1(u16 arg1, u16 arg2, u8 arg3, u16 arg4);
void CpuSet(void* src, void* dst, u32 mode);
u8 prepare_party_mail_to_give(struct pokemon* poke, u16 item);
u8 specific_pokerus_check(struct pokemon* poke, u8 caseid);


u32 __udivsi3(u32 numerator, u32 denumerator);
u32 __umodsi3(u32 numerator, u32 denumerator);

#endif /* VANILLA_FUNCTIONS */
