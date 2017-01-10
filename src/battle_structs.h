#ifndef B_STRUCTS
#define B_STRUCTS

#include "types.h"
#include "defines.h"

struct iv_set
{
    u32 iv_hp: 5;
    u32 iv_atk: 5;
    u32 iv_def: 5;
    u32 iv_spd: 5;
    u32 iv_sp_atk: 5;
    u32 iv_sp_def: 5;
};

struct pokemon{
	u32 PID;
	u32 OTID;
	char name[10];
	u16 language;
	u8 OT_name[7];
	u8 markings;
	u16 checksum;
	u16 padding_maybe;
	u8 data[48];
	u32 ailment;
	u8 level;
	u8 pokerus;
	u16 current_hp;
	u16 total_hp;
	u16 attack;
	u16 defense;
	u16 speed;
	u16 sp_attack;
	u16 sp_defense;
};

extern struct pokemon party_opponent[6];
extern struct pokemon party_player[6];

struct palette {
  u16 c[16];
};

extern struct palette palette_obj_faded[16];

struct task{
    void* function;
    u8 id;
    u8 previous;
    u8 next;
    u8 priority;
    u16 private[16];
};

extern struct task tasks[16];

struct frame {
  u16 data;
  u16 duration;
};

struct rotscale_frame {
  u16 scale_delta_x;
  u16 scale_delta_y;
  u8 rot_delta;
  u8 duration;
  u16 field_6;
};

struct sprite{
    u8 y;
    u8 flags1;
    u16 x_and_flag2;
    u16 attr2;
    u16 rotscaleinfo;
};

struct coords16{
    u16 x;
    u16 y;
};

struct coords8{
    u8 x;
    u8 y;
};

struct object;
typedef void (*object_callback)(struct object*);

struct template{
  u16 tiles_tag;
  u16 pal_tag;
  struct sprite *oam;
  struct frame **animation;
  u32 *graphics;
  struct rotscale_frame **rotscale;
  object_callback callback;
};

struct object{
    struct sprite final_oam;
    struct frame **animation_table;
    void* gfx_table;
    void* rotscale_table;
    struct template* template;
    u32 field_18;
    void* callback;
    struct coords16 pos1;
    struct coords16 pos2;
    struct coords8 pos_neg_center;
    u8 anim_number;
    u8 anim_frame;
    u8 anim_delay_countdown;
    u8 anim_unkown_counter;
    u16 private[8];
    u8 in_use : 1;
    u8 flag2 : 1;
    u8 invisible : 1;
    u8 flags : 5;
    u8 bitfield2;
    u16 anim_data_offset;
    u8 field_42;
    u8 y_height_related;
};

struct image_resource{
    void *image;
    u16 size;
    u16 tag;
};

extern struct object objects[64];

//Pokemon Basestats table

struct poke_basestats{
    u8 base_hp;
    u8 base_atk;
    u8 base_def;
    u8 base_spd;
    u8 base_spatk;
    u8 base_spdef;
    u8 type1;
    u8 type2;
    u8 catch_rate;
    u8 exp_yield;
    u16 evs_hp : 2;
    u16 evs_atk : 2;
    u16 evs_def : 2;
    u16 evs_spd : 2;
    u16 evs_spatk : 2;
    u16 evs_spdef : 2;
    u16 unused : 4;
    u16 item1;
    u16 item2;
    u8 gender_ratio;
    u8 hatching;
    u8 friendship;
    u8 exp_curve;
    u8 egg_group1;
    u8 egg_group2;
    u8 ability1;
    u8 ability2;
    u8 safari_flee_rate;
    u8 dex_colour;
    u8 padding1;
    u8 padding2;
};

struct basestat_data{
    struct poke_basestats poke_stats[ALL_POKES];
};

extern struct basestat_data* basestat_table;


//Item Table

struct item_struct
{
    u8 name[14];
    u16 index;
    u16 price;
    u8 held_effect;
    u8 held_effect_quality;
    void *desc_pointer;
    u16 mystery_value;
    u8 pocket_no;
    u8 type_of_item;
    void *field_usage_code;
    u32 battle_usage;
    void *battle_usage_code;
    u32 extra_param;
};

struct item_data{
    struct item_struct items[ALL_ITEMS];
};

extern struct item_data* item_table;

//Evolution table

struct evolution_sub{
    u16 method;
    u16 paramter;
    u16 poke;
    u16 padding;
};

struct evolutions_of_poke{
    struct evolution_sub evos[NUM_OF_EVOS];
};

struct evolution_all_pokes{
    struct evolutions_of_poke poke_evo[ALL_POKES];
};

extern struct evolution_all_pokes* evo_table;

struct sprite_poke{
    void* sprite;
    u16 unkown;
    u16 species;
};

struct sprite_table{
    struct sprite_poke p_sprite[ALL_POKES];
};

extern struct sprite_table* front_sprites;
extern struct sprite_table* back_sprites;

struct pokenames{
    u8 letter[11];
};

struct pokenames_all{
    struct pokenames pokename[ALL_POKES];
};

extern struct pokenames_all* poke_name_table;

struct superstate{
    void* callback1;
    void* callback2;
    void* callback_backup;
    void* vblank_callback;
    void* hblank_callback;
    void* field14;
    void* field18;
    u32 bits_to_wait_for;
    u32 some_timer;
    u32 field24;
};

extern struct superstate super;

struct saveblock1{
    u8 will_do_later_if_needed[0x234];
    u8 poke_quantity;
    u8 alignment_padding[3];
    struct pokemon player_party[6];
    u32 money;
    u16 coints;
    u16 item_on_select;
};

extern struct saveblock1* sav1;

struct stat_fractions{
    u8 dividend;
    u8 divisor;
};

#endif /* B_STRUCTS */
