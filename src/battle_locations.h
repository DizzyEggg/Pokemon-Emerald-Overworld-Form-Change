#ifndef B_LOCATIONS
#define B_LOCATIONS

#include "types.h"

u16 battle_turn_random_no;
u8 last_used_ability;
u16 last_used_item;
u8 bank_attacker;
u8 bank_target;
u8 bank_partner_atk;
u8 bank_partner_def;
u8 crit_loc;
u8 abilities_by_banks[4];
u16 move_power;
u16 current_move;
u16 last_used_move;
u16 last_used_moves[4];
s32 damage_loc;
u8 no_of_all_banks;
u8 battle_text_buff1[0x10];
u8 battle_text_buff2[0x10];
u8 battle_text_buff3[0x10];
u8 displayed_string_in_battle[0x100];
u8 active_bank;
void* battlescripts_curr_instruction;
void* move_anim_cursor;
u8 multihit_counter;
u16 chosen_move_by_banks[4];
u16 dynamic_base_power;
u8 animation_bank_attacker;
u8 animation_bank_target;
u8 turn_order[4];
u16 battle_team_id_by_side[4];
u16 sketchable_move_used[4];
u16 calling_move_used[4];
u16 current_move_used[4];
u8 attacked_by[4];
u8 another_active_bank;
u8 absent_bank_flags;
u8 battle_outcome;
u8 current_move_position;
u8 current_move_turn;
u16 move_hit_with_pbs[4];
u16 move_type_hit_with_pbs[4];
u16 locked_move[4];
u16 payday_money;
u32 status_flags_for_move_effects[0x3F];
void* battlescripts_for_moveeffects[0x3F];
s32 hp_dealt;
u8 battle_state_mode;
u8 battle_state_mode_first_assigned;
u8 terrain_to_type_table[10];
u8 battle_background;
u32 taken_damage[4];
u8 hurt_by[4];
u8 slot_in_learnset_table;
u16 move_to_learn;
void* tai_current_instruction;
u8 tai_bank;
u32 battle_execution_buffer;
u16 some_strings_table[4];
u16 protect_chance_table[4];
void *b_c;
u8 menu_choice_pbs[4];
u8 objID_pbs_moveanimations[4];
u8 anim_execution_buffer;
u16 var_8015_trainer_opponent_A;
u16 trainer_opponent_B;
void* tasks_for_banks[4];
u8 graphical_elements_pbs[4];
void *b_x[4];
u8 healthbox_obj_id_pbs[4];
u8 move_selection_chosen_target_pbs[4];
u8 moves_to_choose_pbs[4];
u8 move_selection_cursor_pbs[4];
u32 bits_table[32];
u32 PiD_pbs[4];
u8 decompression_buffer[0xF80];
u8 nick_male_sign[5];
u8 nick_female_sign[5];
u8 nick_genderless_sign[4];
u8 text_Wild_[6];
u8 text_Foe_[5];
u8 text_Foe[4];
u8 text_Ally[5];
u8 castform_form[4];
u8 viewing_recorded_battle;
u16 no_of_recorded_bytes[4];
u16 var_800D_lastresult;
u16 randomly_chosen_move;
s16 bg2X_battle;
s16 bg2Y_battle;

u32 poison_status_flag;
u32 sleep_status_flag;
u32 paralysis_status_flag;
u32 burn_status_flag;
u32 freeze_status_flag;

#endif /* B_LOCATIONS */
