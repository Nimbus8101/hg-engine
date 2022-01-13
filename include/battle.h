#ifndef BATTLE_H
#define BATTLE_H

#include "types.h"
#include "sprite.h"

#define MAX_MOVE_NUM 742 //old 467
#define CLIENT_MAX 4

#define TYPE_NORMAL   0x00
#define TYPE_FIGHTING 0x01
#define TYPE_FLYING   0x02
#define TYPE_POISON   0x03
#define TYPE_GROUND   0x04
#define TYPE_ROCK     0x05
#define TYPE_BUG      0x06
#define TYPE_GHOST    0x07
#define TYPE_STEEL    0x08
#define TYPE_MYSTERY  0x09
#define TYPE_FIRE     0x0a
#define TYPE_WATER    0x0b
#define TYPE_GRASS    0x0c
#define TYPE_ELECTRIC 0x0d
#define TYPE_PSYCHIC  0x0e
#define TYPE_ICE      0x0f
#define TYPE_DRAGON   0x10
#define TYPE_DARK     0x11

#define SELECT_FIGHT_COMMAND 1
#define SELECT_ITEM_COMMAND 2
#define SELECT_POKEMON_COMMAND 3
#define SELECT_ESCAPE_COMMAND 4

#define ADD_STATE_ATKUP 0xF
#define ADD_STATE_DEFUP 0x10
#define ADD_STATE_SPEUP 0x11
#define ADD_STATE_SPATKUP 0x12

#define ADD_STATE_ATKDOWN 0x16
#define ADD_STATE_DEFDOWN 0x17
#define ADD_STATE_SPEDOWN 0x18

#define ADD_STATE_ATKUP2    0x27
#define ADD_STATE_ATKDOWN2  0x2e

#define ADD_EFFECT_ABILITY 3


// defines that i believe are straight from source
#define SERVER_STATUS_FLAG2_U_TURN          (0x00000010)        //u-turn flag

#define WAZA_STATUS_FLAG_NOHIT                  (0x00000001)
#define WAZA_STATUS_FLAG_BATSUGUN               (0x00000002)
#define WAZA_STATUS_FLAG_IMAHITOTSU             (0x00000004)
#define WAZA_STATUS_FLAG_KOUKANAI               (0x00000008)
#define WAZA_STATUS_FLAG_CRITICAL               (0x00000010)
#define WAZA_STATUS_FLAG_ICHIGEKI               (0x00000020)
#define WAZA_STATUS_FLAG_UMAKUKIMARAN           (0x00000040)
#define WAZA_STATUS_FLAG_KORAETA                (0x00000080)
#define WAZA_STATUS_FLAG_ITEM_KORAETA           (0x00000100)
#define WAZA_STATUS_FLAG_PP_NONE                (0x00000200)
#define WAZA_STATUS_FLAG_LOCK_ON                (0x00000400)
#define WAZA_STATUS_FLAG_JIMEN_NOHIT            (0x00000800)
#define WAZA_STATUS_FLAG_ICHIGEKI_NOHIT         (0x00001000)
#define WAZA_STATUS_FLAG_NANIMOOKORAN           (0x00002000)
#define WAZA_STATUS_FLAG_RENZOKU_NOHIT          (0x00004000)
#define WAZA_STATUS_FLAG_MAMORU_NOHIT           (0x00008000)
#define WAZA_STATUS_FLAG_KIE_NOHIT              (0x00010000)
#define WAZA_STATUS_FLAG_WAZA_KOYUU_NOHIT       (0x00020000)
#define WAZA_STATUS_FLAG_BATSUGUN_NOHIT         (0x00040000)
#define WAZA_STATUS_FLAG_GANZYOU_NOHIT          (0x00080000)
#define WAZA_STATUS_FLAG_DENZIHUYUU_NOHIT       (0x00100000)

#define WAZA_STATUS_FLAG_SIPPAI                 (0x80000000)

#define WAZA_STATUS_FLAG_NOHIT_OFF      (WAZA_STATUS_FLAG_NOHIT^0xffffffff)
#define WAZA_STATUS_FLAG_BATSUGUN_OFF   (WAZA_STATUS_FLAG_BATSUGUN^0xffffffff)
#define WAZA_STATUS_FLAG_IMAHITOTSU_OFF (WAZA_STATUS_FLAG_IMAHITOTSU^0xffffffff)

#define WAZA_STATUS_FLAG_HAZURE         (WAZA_STATUS_FLAG_NOHIT|WAZA_STATUS_FLAG_KOUKANAI|\
                                         WAZA_STATUS_FLAG_UMAKUKIMARAN|\
                                         WAZA_STATUS_FLAG_JIMEN_NOHIT|\
                                         WAZA_STATUS_FLAG_ICHIGEKI_NOHIT|\
                                         WAZA_STATUS_FLAG_RENZOKU_NOHIT|\
                                         WAZA_STATUS_FLAG_MAMORU_NOHIT|\
                                         WAZA_STATUS_FLAG_KIE_NOHIT|\
                                         WAZA_STATUS_FLAG_WAZA_KOYUU_NOHIT|\
                                         WAZA_STATUS_FLAG_BATSUGUN_NOHIT|\
                                         WAZA_STATUS_FLAG_GANZYOU_NOHIT|\
                                         WAZA_STATUS_FLAG_DENZIHUYUU_NOHIT)

#define WAZA_STATUS_FLAG_NO_OUT         (WAZA_STATUS_FLAG_HAZURE|\
                                         WAZA_STATUS_FLAG_PP_NONE|\
                                         WAZA_STATUS_FLAG_SIPPAI)

#define WAZA_STATUS_FLAG_SOUSAI         (WAZA_STATUS_FLAG_BATSUGUN|\
                                         WAZA_STATUS_FLAG_IMAHITOTSU)

#define ADD_STATUS_NONE (0)       //追加効果種類：追加効果なし
#define ADD_STATUS_DIRECT (1)     //追加効果種類：直接
#define ADD_STATUS_INDIRECT (2)   //追加効果種類：間接
#define ADD_STATUS_TOKUSEI (3)    //追加効果種類：特性
#define ADD_STATUS_WAZA_KOUKA (4) //追加効果種類：技効果
#define ADD_STATUS_SOUBIITEM (5)  //追加効果種類：装備アイテム効果
#define ADD_STATUS_DOKUBISI (6)   //追加効果種類：どくびし追加効果
#define ADD_STATUS_IGNORE (7)     //追加効果種類：いうことをきかない時の追加効果

#define COND_HP             (0x00)  ///<体力
#define COND_POW            (0x01)  ///<攻撃力
#define COND_DEF            (0x02)  ///<防御力
#define COND_AGI            (0x03)  ///<素早さ
#define COND_SPEPOW         (0x04)  ///<特攻
#define COND_SPEDEF         (0x05)  ///<特防
#define COND_HIT            (0x06)  ///<命中率
#define COND_AVOID          (0x07)  ///<回避率
#define COND_MAX            (0x08)  ///<CONDのMAX（くろいきり用）





// battle type defines
#define BATTLE_TYPE_SINGLE 0x00
#define BATTLE_TYPE_TRAINER 0x01
#define BATTLE_TYPE_DOUBLE 0x02
#define BATTLE_TYPE_WIRELESS 0x04
#define BATTLE_TYPE_MULTI 0x08
#define BATTLE_TYPE_TAG 0x10
#define BATTLE_TYPE_SAFARI 0x20
#define BATTLE_TYPE_NPC_MULTI 0x40
#define BATTLE_TYPE_BATTLE_TOWER 0x80
#define BATTLE_TYPE_ROAMER 0x100
#define BATTLE_TYPE_POKE_PARK 0x200
#define BATTLE_TYPE_CATCHING_DEMO 0x400

// move effect flags/waza_kouka
#define MOVE_EFFECT_FLAG_CHARGE (0x200)
#define MOVE_EFFECT_FLAG_MUD_SPORT (0x10000)
#define MOVE_EFFECT_FLAG_WATER_SPORT (0x20000)

// status condition flags
#define STATUS_FLAG_POISONED (0x8)
#define STATUS_FLAG_BURNED (0x10)
#define STATUS_FLAG_FROZEN (0x20)
#define STATUS_FLAG_BADLY_POISONED (0x80)

// status2/condition2 flags
#define STATUS2_FLAG_TRANSFORMED (0x200000)

// side status flags
#define SIDE_STATUS_REFLECT 0x1
#define SIDE_STATUS_LIGHT_SCREEN 0x2

// physical/special split values
#define SPLIT_PHYSICAL 0
#define SPLIT_SPECIAL 1
#define SPLIT_STATUS 2

// field status
#define WEATHER_RAIN                    (0x00000001)
#define WEATHER_RAIN_PERMANENT          (0x00000002)
#define WEATHER_RAIN_ANY                (WEATHER_RAIN | WEATHER_RAIN_PERMANENT)
#define WEATHER_SANDSTORM               (0x00000004)
#define WEATHER_SANDSTORM_PERMANENT     (0x00000008)
#define WEATHER_SANDSTORM_ANY           (WEATHER_SANDSTORM | WEATHER_SANDSTORM_PERMANENT)
#define WEATHER_SUNNY                   (0x00000010)
#define WEATHER_SUNNY_PERMANENT         (0x00000020)
#define WEATHER_SUNNY_ANY               (WEATHER_SUNNY | WEATHER_SUNNY_PERMANENT)
#define WEATHER_HAIL                    (0x00000040)
#define WEATHER_HAIL_PERMANENT          (0x00000080)
#define WEATHER_HAIL_ANY                (WEATHER_HAIL | WEATHER_HAIL_PERMANENT)

#define FIELD_STATUS_UPROAR             (0x00000f00)
#define FIELD_STATUS_GRAVITY            (0x00007000)
#define FIELD_STATUS_FOG                (0x00008000)
#define FIELD_STATUS_TRICK_ROOM         (0x00070000)

//技能flag
#define FLAG_CONTACT 1  //接触类招式

struct __attribute__((packed)) sDamageCalc
{
    u16 species;
    s16 hp;
    u16 maxhp;
    u16 dummy;
    int item_held_effect;
    int item_power;

    u32 condition;

    u8 ability;
    u8 sex;
    u8 type1;
    u8 type2;
};

struct __attribute__((packed)) BattleMove
{
    u16 effect;
    u8 split;
    u8 power;

    u8 type;
    u8 accuracy;
    u8 pp;
    u8 secondaryEffectChance;

    u16 target;
    s8 priority;
    u8 flag;
    u8 unk[4];
};

struct __attribute__((packed)) OneTurnEffect
{
    u32 waruagaki_flag : 1; //わるあがきフラグ
    u32 pp_dec_flag : 1;    //PPを減らしたフラグ
    u32 mamoru_flag : 1;    //まもるフラグ
    u32 helping_hand_flag : 1;  //てだすけフラグ
    u32 magic_cort_flag : 1;
    u32 yokodori_flag : 1;
    u32 haneyasume_flag : 1;
    u32 escape_flag : 2;  //にげたフラグ（特性or装備道具効果）
    u32 koraeru_flag : 1; ///<こらえるフラグ
    u32 : 22;

    int butsuri_otf_damage[4];
    int butsuri_otf_client;
    int butsuri_otf_client_bit;
    int tokusyu_otf_damage[4];
    int tokusyu_otf_client;
    int tokusyu_otf_client_bit;
    int last_otf_damage;
    int last_otf_client;
    int dameoshi_damage;
};

struct __attribute__((packed)) OneSelfTurnEffect
{
    u32 no_pressure_flag : 1;  ///<特性プレッシャーの効果を受けない
    u32 hiraisin_flag : 1;     ///<特性ひらいしんの効果が発動
    u32 yobimizu_flag : 1;     ///<特性よびみずのの効果が発動
    u32 katayaburi_flag : 1;   ///<特性かたやぶりの効果が発動
    u32 trickroom_flag : 1;    ///<トリックルーム発動
    u32 item_koraeru_flag : 1; ///<こらえるフラグ（装備道具効果）
    u32 korogaru_count : 3;    ///<ころがるカウント（メトロノーム判定で使用）
    u32 : 23;                  ///<ステータス上昇下降エフェクトを発動

    int butsuri_ostf_damage;   ///存在物理伤害量
    int butsuri_ostf_client;   ///<物理攻撃したクライアント
    int tokusyu_ostf_damage;   ///存在特殊伤害量
    int tokusyu_ostf_client;   ///<特殊攻撃したクライアント
    int status_flag;           ///<ステータスフラグ（battle_server.hにdefine定義）
    int kaigara_damage;        ///<かいがらのすず用ダメージ量
};

struct __attribute__((packed)) battle_moveflag
{
    u32 kanashibari_count : 3;      ///<かなしばりカウンタ
    u32 encore_count : 3;           ///<アンコールカウンタ
    u32 juuden_count : 2;           ///<じゅうでんカウンタ
    u32 chouhatsu_count : 3;        ///<ちょうはつカウンタ
    u32 success_count : 2;          ///<まもる、こらえるが成功したカウンタ
    u32 horobinouta_count : 2;      ///<ほろびのうたカウンタ
    u32 korogaru_count : 3;         ///<ころがるカウンタ
    u32 renzokugiri_count : 3;      ///<れんぞくぎりカウンタ
    u32 takuwaeru_count : 3;        ///<たくわえるカウンタ
    u32 takuwaeru_def_count : 3;    ///<たくわえるカウンタ（防御アップ）
    u32 takuwaeru_spedef_count : 3; ///<たくわえるカウンタ（特防アップ）
    u32 namake_bit : 1;             ///<なまけビット
    u32 moraibi_flag : 1;           ///<もらいびフラグ

    u32 lockon_client_no : 2;    ///<ロックオンされたClientNo
    u32 monomane_bit : 4;        ///<ものまねビット
    u32 shime_client_no : 2;     ///<しめつけたClientNo
    u32 manazashi_client_no : 2; ///<くろいまなざしをしたClientNo
    u32 totteoki_count : 3;      ///<とっておき用技を出したフラグ
    u32 denzihuyuu_count : 3;    ///<でんじふゆうカウンタ
    u32 healblock_count : 3;     ///<ヒールブロックカウンタ
    u32 shutout_count : 3;       ///<シャットアウトカウンタ
    u32 karuwaza_flag : 1;       ///<かるわざフラグ
    u32 metronome_work : 4;      ///<メトロノームワーク
    u32 once_hit_up : 1;         ///<装備効果で一度だけ命中UPフラグ
    u32 once_agi_up : 1;         ///<装備効果で一度だけ先制攻撃フラグ
    u32 sensei_flag : 1;
    u32 sakidori_flag : 1;
    u32 : 1;

    int handou_count;
    int nekodamashi_count;
    int slow_start_count;
    int sakidori_count;
    int migawari_hp;
    u32 henshin_rnd;

    u16 kanashibari_wazano;
    u16 shime_wazano;
    u16 encore_wazano;
    u16 encore_wazapos;
    u16 totteoki_wazano[4];
    u16 kodawari_wazano;
    u16 henshin_sex;

    int item_hp_recover;
};
struct __attribute__((packed)) BattlePokemon
{
    u16 species;
    u16 atk;
    u16 def;
    u16 spe;
    u16 spatk;
    u16 spdef;
    u16 move[4];
    u32 hp_iv : 5;
    u32 atk_iv : 5;
    u32 def_iv : 5;
    u32 spe_iv : 5;
    u32 spatk_iv : 5;
    u32 spdef_iv : 5;
    u32 is_egg : 1;
    u32 have_nickname : 1;
    s8 states[8];
    int weight;
    u8 type1; //25
    u8 type2;
    u8 form_no : 5;
    u8 rare : 1;
    u8 ability;

    u32 appear_check_flag : 1;   //2ch  登場時天候系特性チェックをしたかどうか
    u32 ikaku_flag : 1;          //2ch  登場時いかくチェックしたかどうか
    u32 trace_flag : 1;          //2ch  登場時トレースチェックしたかどうか
    u32 download_flag : 1;       //2ch  登場時ダウンロードチェック
    u32 kikenyochi_flag : 1;     //2ch  登場時きけんよちチェック
    u32 yochimu_flag : 1;        //2ch  登場時よちむチェック
    u32 slow_start_flag : 1;     //2ch  登場時スロースタートチェック
    u32 slow_start_end_flag : 1; //2ch  スロースタート終了チェック
    u32 omitooshi_flag : 1;      //2ch  登場時おみとおしチェック
    u32 katayaburi_flag : 1;     //2ch  登場時かたやぶりチェック
    u32 pressure_flag : 1;       //2ch  登場時プレッシャーチェック
    u32 canMega : 1;
    u32 : 20;                    //2ch

    u8 pp[4];
    u8 pp_count[4];
    u8 level;
    u8 friend;
    u16 nickname[11];
    s32 hp;
    u32 maxhp;
    u16 oyaname[8];
    u32 exp; //68
    u32 personal_rnd;
    u32 condition;
    u32 condition2;
    u32 id_no;
    u16 item;
    u16 dummy;
    u8 hit_count;
    u8 message_flag;
    u8 sex : 4;
    u8 oyasex : 4;
    u8 get_ball;
    u32 effect_of_moves; // think like charge, lock on
    u32 effect_of_moves_temp;

    struct battle_moveflag moveeffect;
};

struct __attribute__((packed)) BattleStruct
{
    /*0x0*/ u8 com_seq_no[CLIENT_MAX];
    /*0x4*/ u8 ret_seq_no[CLIENT_MAX];
    /*0x8*/ int server_seq_no;
    /*0xC*/ int next_server_seq_no;
    /*0x10*/ int fcc_seq_no;
    /*0x14*/ int fcc_work;
    /*0x18*/ int pcc_seq_no;
    /*0x1C*/ int pcc_work;
    /*0x20*/ int scc_seq_no;
    /*0x24*/ int scc_work;
    /*0x28*/ int sba_seq_no;
    /*0x2C*/ int sba_work;
    /*0x30*/ int swhac_seq_no;
    /*0x34*/ int swhac_work;
    /*0x38*/ int swoam_type;
    /*0x3C*/ int swoam_seq_no;
    /*0x40*/ int swoak_seq_no;
    /*0x44*/ int swoak_work;
    /*0x48*/ int wb_seq_no;
    /*0x4c*/ int woc_seq_no;
    /*0x50*/ int ssc_seq_no;
    /*0x54*/ int stc_seq_no;
    /*0x58*/ int spac_seq_no;
    /*0x5C*/ int svc_work;

    /*0x60*/ int waza_seq_adrs;
    /*0x64*/ int attack_client;
    /*0x68*/ int attack_client_temp;
    /*0x6C*/ int defence_client;
    /*0x70*/ int defence_client_temp;
    /*0x74*/ int kizetsu_client;
    /*0x78*/ int reshuffle_client;
    /*0x7C*/ int reshuffle_client_temp;
    /*0x80*/ int ability_client;
    /*0x84*/ int magic_cort_client;

    /*0x88*/ int addeffect_type;
    /*0x8C*/ int addeffect_param;
    /*0x90*/ int addeffect_flag;

    /*0x94*/ int state_client;
    /*0x98*/ u8 dummy2[0x80];
    /*0x118*/ int client_work;
    /*0x11C*/ int attack_client_work;
    /*0x120*/ int defence_client_work;
    /*0x124*/ int waza_work;
    /*0x128*/ int item_work;
    /*0x12C*/ int tokusei_work;
    /*0x130*/ int msg_work;
    /*0x134*/ int calc_work;
    /*0x138*/ int temp_work;
    /*0x13C*/ u32 client_status[CLIENT_MAX];
    /*0x14C*/ u32 koban_counter;
    /*0x150*/ int total_turn;
    /*0x154*/ int total_hinshi[CLIENT_MAX];
    /*0x164*/ int total_damage[CLIENT_MAX];
    /*0x174*/ int sakidori_total_turn;
    /*0x178*/ u8 unk_bytes5[8];
    /*0x180*/ int field_condition;
    /*0x184*/ u32 field_condition_count;
    /*0x188*/ u8 unk_bytes2[0x4C];
    /*0x1D4*/ struct OneTurnEffect oneTurnFlag[4];
    /*0x2D4*/ struct OneSelfTurnEffect oneSelfFlag[4];
    /*0x344*/ u8 dummy3[0x9A];

    /*0x3DE*/ struct BattleMove old_moveTbl[467 + 1]; //old
    /*0x211E*/ u8 dummy6[0x1E];
    /*0x213C*/ u32 server_status_flag;
    /*0x2140*/ u32 server_status_flag2;
    /*0x2144*/ int damage;
    /*0x2148*/ int hit_damage;
    /*0x214C*/ int critical_count;
    /*0x2150*/ int critical;
    /*0x2154*/ int damage_power;
    /*0x2158*/ int damage_value;
    /*0x215C*/ int hp_calc_work;
    /*0x2160*/ int move_type;
    /*0x2164*/ int waza_eff_cnt;
    /*0x2168*/ int okodukai_value;
    /*0x216C*/ u32 waza_status_flag;

    /*0x2170*/ u32 add_status_flag_direct;
    u32 add_status_flag_indirect;
    u32 add_status_flag_tokusei;
    u8 renzoku_count;
    u8 renzoku_count_temp;
    u8 client_loop;
    u8 hukurodataki_count;

    u32 loop_flag;
    u32 waza_out_check_on_off;
    u32 loop_hit_check;

    u32 condition2_off_req[CLIENT_MAX];
    /*0x219C*/ u8 sel_mons_no[CLIENT_MAX];
    /*0x21A0*/ u8 reshuffle_sel_mons_no[CLIENT_MAX];
    /*0x21A4*/ u8 ai_reshuffle_sel_mons_no[CLIENT_MAX];
    /*0x21A8*/ u32 client_act_work[4][4];
    /*0x21E8*/ u8 client_agi_work[4];
    /*0x21EC*/ u8 psp_agi_work[4];
    /*0x21F0*/ u32 psp_agi_point[4];
    /*0x2200*/ u8 ServerQue[4][4][16];
    /*0x2300*/ u8 server_buffer[4][256];
    /*0x2700*/ int SkillSeqWork[400];
    /*0x2D40*/ struct BattlePokemon battlemon[CLIENT_MAX]; //0xc0
    /*0x3040*/ u32 waza_no_temp;
    /*0x3044*/ u32 current_move_index;
    /*0x3048*/ u8 unk_bytes4[0xC0];
    /*0x3108*/ u8 no_reshuffle_client;
    /*0x3109*/ u8 level_up_pokemon;
    /*0x310A*/ u16 que_check_wait;
    /*0x310C*/ u16 agi_rand[CLIENT_MAX];
    /*0x3114*/ int nagetsukeru_work;
    /*0x3118*/ int nagetsukeru_seq_no;
    /*0x311C*/ u8 safari_get_count;
    /*0x311D*/ u8 safari_escape_count;
    /*0x311E*/ u8 escape_count;
    /*0x311F*/ u8 fight_end_flag;

    /*0x3120*/ u8 magnitude;
    /*0x3121*/ u8 weather_check_flag;
    /*0x3122*/ s16 hp_temp;

    /*0x3124*/ u16 recycle_item[CLIENT_MAX];
    /*0x312C*/ u8 unk4[0x52];
    /*0x317E*/ struct BattleMove moveTbl[MAX_MOVE_NUM + 1];
    /*...*/
};

struct __attribute__((packed)) tcb_skill_intp_work
{
    void *bw;
    struct BattleStruct *sp;
};

enum
{
    CHECK_PLAYER_SIDE_ALL = 0,
    CHECK_PLAYER_SIDE_ALIVE,
    CHECK_ENEMY_SIDE_ALL,
    CHECK_ENEMY_SIDE_ALIVE,
    CHECK_ALL_BATTLER_ALIVE = 8,
};

enum
{
    BATTLE_MON_DATA_SPECIES,
    BATTLE_MON_DATA_ATK,
    BATTLE_MON_DATA_DEF,
    BATTLE_MON_DATA_SPE,
    BATTLE_MON_DATA_SPATK,
    BATTLE_MON_DATA_SPDEF,
    BATTLE_MON_DATA_MOVE_1,
    BATTLE_MON_DATA_MOVE_2,
    BATTLE_MON_DATA_MOVE_3,
    BATTLE_MON_DATA_MOVE_4,
    BATTLE_MON_DATA_HP_RND,
    BATTLE_MON_DATA_ATK_RND,
    BATTLE_MON_DATA_DEF_RND,
    BATTLE_MON_DATA_SPD_RND,
    BATTLE_MON_DATA_SPATK_RND,
    BATTLE_MON_DATA_SPDEF_RND,
    BATTLE_MON_DATA_IS_EGG,
    BATTLE_MON_DATA_IS_NICKNAMED,
    BATTLE_MON_DATA_STATE_HP,
    BATTLE_MON_DATA_STATE_ATK,
    BATTLE_MON_DATA_STATE_DEF,
    BATTLE_MON_DATA_STATE_SPE,
    BATTLE_MON_DATA_STATE_SPATK,
    BATTLE_MON_DATA_STATE_SPDEF,
    BATTLE_MON_DATA_STATE_ACCURACY,
    BATTLE_MON_DATA_STATE_EVASIVENESS,
    BATTLE_MON_DATA_ABILITY,
    BATTLE_MON_DATA_TYPE1,
    BATTLE_MON_DATA_TYPE2,
    BATTLE_MON_DATA_SEX,
    BATTLE_MON_DATA_LEVEL = 43,
    BATTLE_MON_DATA_HP = 47,
    BATTLE_MON_DATA_MAX_HP,
    BATTLE_MON_DATA_MAX_CONDITION = 52,
    BATTLE_MON_DATA_STATUS2 = 53,
    BATTLE_MON_HELD_ITEM = 55,
    BATTLE_MON_FLASH_FIRE_ACTIVATED = 73,
    BATTLE_MON_DATA_SLOW_START_COUNTER = 89,
};

#define MEGA_NEED 1
#define MEGA_CHECK_APPER 2
#define MEGA_NO_NEED 0

struct __attribute__((packed)) newBattleStruct
{
    u8 SideMega[2];//检查双方是否mega过,0我方,1敌方
    u8 playerWantMega;
    u8 PlayerMegaed;
    u8 needMega[4];//需要mega

    CATS_ACT_PTR MegaOAM;
    CATS_ACT_PTR MegaButton;
    u8 MegaIconLight;
    u8 ChangeBgFlag:4;
    u8 CanMega:4;
};

struct __attribute__((packed)) BATTLE_PARAM
{
    u8 fill[0x1C0];
    void* savedata;
};

void BattleFormChange(int client, int form_no, void* bw,struct BattleStruct *sp, bool8 SwitchAbility);

extern struct newBattleStruct newBS;
extern const u8 SoubiItemWazaTypePowUpTbl[33][2];
extern const u16 TetsunoKobushiTable[0xF];
extern const u8 CondChgTable[][2];

BOOL __attribute__((long_call)) CheckDefenceAbility(void *, int, int, int);
int __attribute__((long_call)) BattlePokemonParamGet(void*,int ,int,void*);
int __attribute__((long_call)) GetTargetAbility(void *gBattleRam,int target);
s32 __attribute__((long_call)) ItemDataGet(void*,u16,u16);
u32 __attribute__((long_call)) BattleTypeGet(void*);
int __attribute__((long_call)) BattleWorkMonDataGet(void*,void*,int ,int);
int __attribute__((long_call)) CheckSideAbility(void *bw,void *sp,int flag,int client_no,int speabi);
u8 __attribute__((long_call)) CheckNumMonsHit(void*,void*,int ,int);
BOOL __attribute__((long_call)) CheckFieldMoveEffect(void *bw, void* ,int );
void __attribute__((long_call)) ST_ServerSequenceLoad(void*,int,int);
struct POKEMON_PARAM* __attribute__((long_call))BattleWorkPokemonParamGet(void*,int,int);

int __attribute__((long_call))BattleWorkEnemyClientNoGet(void*,int,int);
u16 __attribute__((long_call)) BattleWorkRandGet(void*);
int __attribute__((long_call)) BattleWorkPokeCountGet(void*,int);

BOOL __attribute__((long_call)) ServerCriticalMessage(void*,void*);
BOOL __attribute__((long_call)) ServerWazaStatusMessage(void*,void*);
BOOL __attribute__((long_call)) ST_ServerAddStatusCheck(void*,void*,int *seq_no);
BOOL __attribute__((long_call)) ServerIkariCheck(void*,void*);
BOOL __attribute__((long_call)) ST_ServerWazaHitTokuseiCheck_Old(void*,void*,int *seq_no);
BOOL __attribute__((long_call)) ServerHirumaseruCheck(void*,void*);
int __attribute__((long_call)) ST_ServerWaruagakiCheck(void *bw, void *sp, int client_no, int waza_bit, int check_bit);
struct Save_DexData* __attribute__((long_call)) BattleWorkZukanWorkGet(void *bw);
int __attribute__((long_call)) BattleWorkClientSetMaxGet(void*);
u8 __attribute__((long_call)) ST_ServerAgiCalc(void*,void*,int ,int,int);
u16 __attribute__((long_call)) ST_ServerSelectWazaGet(void*,int);
BOOL __attribute__((long_call))  ST_ServerNamakeCheck(void*,int);
void __attribute__((long_call)) SCIO_BlankMessage(void*);
BOOL __attribute__((long_call)) ServerSenseiCheck(void *bw, void *sp);
BOOL __attribute__((long_call)) ServerPPCheck(void *bw, void *sp);
BOOL __attribute__((long_call)) ServerWazaKoyuuCheck(void *bw, void *sp);
BOOL __attribute__((long_call)) ServerDefenceCheck(void *bw, void *sp);
BOOL __attribute__((long_call)) ServerStatusCheck(void *bw, void *sp);
int __attribute__((long_call)) ServerBadgeCheck(void *bw, void *sp, int *seq_no);
void __attribute__((long_call)) ST_ServerDefenceClientTokuseiCheck(void *bw, void *sp, int attack, u16 waza_no);
void __attribute__((long_call)) ST_ServerTotteokiCountCalc(void *bw,void *sp);
void __attribute__((long_call)) ST_ServerMetronomeBeforeCheck(void *bw,void *sp);
int __attribute__((long_call)) ST_ServerPokeAppearCheck(void *bw, void *sp);
void __attribute__((long_call))SCIO_StatusEffectSet(void *bw,void *sp,int send_client,int status);






/* new battle engine declarations*/
int __attribute__((long_call)) GetBattlerAbility(void *sp, int client);
u32 __attribute__((long_call)) MoldBreakerAbilityCheck(void *sp, int attacker, int defender, int ability);
int __attribute__((long_call)) BattleDamageDivide(int data, int divisor);

// defined in battle_calc_damage.c
u16 GetMonItem(struct BattleStruct *sp, int client_no);








#endif
