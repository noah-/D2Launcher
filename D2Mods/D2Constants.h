#pragma once
#ifndef _CONSTANTS_H
#define _CONSTANTS_H
enum TextColor {
    Disabled = -1,
    White = 0,
    Red,
    Green,
    Blue,
    Gold,
    Grey,
    Black,
    Tan,
    Orange,
    Yellow,
    DarkGreen,
    Purple,
    Silver = 15
};
enum BoxTrans { BTThreeFourths, BTOneHalf, BTOneFourth, BTWhite, BTBlack, BTNormal, BTScreen, BTHighlight, BTFull };
//////////////////////////////////////////////////////////////////////
// Attack Types
//////////////////////////////////////////////////////////////////////
#define ATTACKTYPE_SHIFTLEFT 0xE5
#define ATTACKTYPE_UNITLEFT 0xC5
#define ATTACKTYPE_SHIFTRIGHT 0x66
#define ATTACKTYPE_RIGHT 0x46

///////////////////////////////////////////////////
// Game UI Flags(From D2JSP, updated with info from TheUnknownSoldier)
///////////////////////////////////////////////////
#define UI_GAME 0x00
#define UI_INVENTORY 0x01
#define UI_CHARACTER 0x02
#define UI_MINISKILL 0x03
#define UI_SKILLTREE 0x04
#define UI_CHAT_CONSOLE 0x05
#define UI_UNK 0x06    // auto disabled
#define UI_UNK_EX 0x07 // auto disabled
#define UI_NPCMENU 0x08
#define UI_DIALOG 0x08
#define UI_ESCMENU_MAIN 0x09
#define UI_AUTOMAP 0x0A
#define UI_HOTKEY_CONFIG 0x0B
#define UI_NPCSHOP 0x0C
#define UI_ALTDOWN 0x0D
#define UI_GROUND_ITEMS 0x0D
#define UI_ANVIL 0x0E
#define UI_QUEST 0x0F
#define UI_BARKSCROLL 0x10
#define UI_QUEST_LOG 0x11
#define UI_STATUS_AREA 0x12
#define UI_ESCMENU_EX 0x13
#define UI_WPMENU 0x14 // Waypoints Menu
#define UI_MINIPANEL 0x15
#define UI_PARTY 0x16
#define UI_TRADE 0x17
#define UI_MESSAGE_LOG 0x18
#define UI_STASH 0x19
#define UI_CUBE 0x1A
#define UI_UNUSED 0x1B
#define UI_INVENTORY_EX 0x1C
#define UI_INVENTORY_EXX 0x1D
#define UI_UNUSED_EX 0x1E
#define UI_BELT 0x1F
#define UI_UNUSED_EXX 0x20
#define UI_HELP_MENU 0x21
#define UI_HELP_BUTTON 0x22
#define UI_ESCMENU 0x23 // unused??
#define UI_MERC 0x24
#define UI_SCROLL 0x25

///////////////////////////////////////////////////
// Control types
///////////////////////////////////////////////////
#define CONTROL_EDITBOX 0x01
#define CONTROL_IMAGE 0x02
#define CONTROL_UNUSED 0x03
#define CONTROL_TEXTBOX 0x04
#define CONTROL_SCROLLBAR 0x05
#define CONTROL_BUTTON 0x06
#define CONTROL_LIST 0x07
#define CONTROL_TIMER 0x08
#define CONTROL_SMACK 0x09
#define CONTROL_PROGRESSBAR 0x0a
#define CONTROL_POPUP 0x0b
#define CONTROL_ACCOUNTLIST 0x0c

///////////////////////////////////////////////////
// Out of Game Locations (From ControlInfo.dbl)
///////////////////////////////////////////////////
enum OOG_Location {
    OOG_NONE = 0,
    OOG_LOBBY,
    OOG_INLINE,
    OOG_CHAT,
    OOG_CREATE,
    OOG_JOIN,
    OOG_LADDER,
    OOG_CHANNEL,
    OOG_MAIN_MENU,
    OOG_LOGIN,
    OOG_LOGIN_ERROR,
    OOG_UNABLE_TO_CONNECT,
    OOG_CHAR_SELECT,
    OOG_REALM_DOWN,
    OOG_DISCONNECTED,
    OOG_NEW_CHARACTER,
    OOG_CHARACTER_SELECT_PLEASE_WAIT,
    OOG_LOST_CONNECTION,
    OOG_D2SPLASH,
    OOG_CDKEY_IN_USE,
    OOG_DIFFICULTY,
    OOG_MAIN_MENU_CONNECTING,
    OOG_INVALID_CDKEY,
    OOG_CONNECTING,
    OOG_SERVER_DOWN,
    OOG_PLEASE_WAIT,
    OOG_GAME_EXIST,
    OOG_GATEWAY,
    OOG_GAME_DOES_NOT_EXIST,
    OOG_CHARACTER_CREATE,
    OOG_CHARACTER_CREATE_ALREADY_EXISTS,
    OOG_AGREE_TO_TERMS,
    OOG_NEW_ACCOUNT,
    OOG_PLEASE_READ,
    OOG_REGISTER_EMAIL,
    OOG_CREDITS,
    OOG_CINEMATICS,
    OOG_CHARACTOR_CHANGE_REALM,
    OOG_GAME_IS_FULL,
    OOG_OTHER_MULTIPLAYER,
    OOG_TCP_IP,
    OOG_ENTER_IP_ADDRESS,
    OOG_CHARACTER_SELECT_NO_CHARS,
    OOG_CHARACTER_SELECT_CHANGE_REALM,
    OOG_UNABLE_TO_CONNECT_TCPIP
};
//////////////////////////////////////////////////////////////////////
// PVP Flags
//////////////////////////////////////////////////////////////////////
#define PVP_INVITED_YOU 0x01     // Invited you, but you may not have accepted
#define PVP_INVITED_BY_YOU 0x02  // Invited by you, but he may not have accepted
#define PVP_ALLIED 0x04          // Allied
#define PVP_HOSTILED_YOU 0x08    // Hostiled you, but you may not have hostiled him
#define PVP_HOSTILED_BY_YOU 0x10 // Hostiled by you, but he may not have hostiled you

//////////////////////////////////////////////////////////////////////////
// Player Type Flags
//////////////////////////////////////////////////////////////////////////
#define PLAYER_TYPE_HARDCORE 4
#define PLAYER_TYPE_EXPAC 32
#define PLAYER_TYPE_LADDER 64

//////////////////////////////////////////////////////////////////////////
// Trade Flags
//////////////////////////////////////////////////////////////////////////
#define TRADE_OPEN 3
#define TRADE_ACCEPTED 5
#define TRADE_ACCEPT 7

//////////////////////////////////////////////////////////////////////////
// Ladder Flags
//////////////////////////////////////////////////////////////////////////

#define LADDERFLAG_NONE 0x00
#define LADDERFLAG_SET 0x01 // classic ladder, classic ladder hc, expansion ladder hc
#define LADDERFLAG_EXPANSION_NORMAL 0x03

///////////////////////////////////////////////////
// Mercenary Class ID's
///////////////////////////////////////////////////
#define MERC_A1 0x010f
#define MERC_A2 0x0152
#define MERC_A3 0x0167
#define MERC_A5 0x0231

///////////////////////////////////////////////////
// Unit Stat ID Definition (Partial)
///////////////////////////////////////////////////
#define STAT_STRENGTH 0  // str
#define STAT_ENERGY 1    // energy
#define STAT_DEXTERITY 2 // dexterity
#define STAT_VITALITY 3  // vitality
#define STAT_STATPOINTSLEFT 4
#define STAT_SKILLPOINTSLEFT 5
#define STAT_HP 6          // life
#define STAT_MAXHP 7       // max life
#define STAT_MANA 8        // mana
#define STAT_MAXMANA 9     // max mana
#define STAT_STAMINA 10    // stamina
#define STAT_MAXSTAMINA 11 // max stamina
#define STAT_LEVEL 12      // level
#define STAT_EXP 13        // experience
#define STAT_GOLD 14       // gold
#define STAT_GOLDBANK 15   // stash gold
#define STAT_ENHANCEDDEFENSE 16
#define STAT_ENHANCEDDAMAGEMAX 17 // njipStats["itemmaxdamagepercent"]=[17,0];
#define STAT_ENHANCEDDAMAGEMIN 18 // njipStats["itemmindamagepercent"]=[18,0];	njipStats["enhanceddamage"]=[18,0];
#define STAT_TOBLOCK 20           // to block
#define STAT_LASTEXP 29
#define STAT_NEXTEXP 30
#define STAT_DAMAGEREDUCTION 36      // damage reduction
#define STAT_MAGICDAMAGEREDUCTION 35 // magic damage reduction
#define STAT_MAGICRESIST 37          // magic resist
#define STAT_MAXMAGICRESIST 38       // max magic resist
#define STAT_FIRERESIST 39           // fire resist
#define STAT_MAXFIRERESIST 40        // max fire resist
#define STAT_LIGHTNINGRESIST 41      // lightning resist
#define STAT_MAXLIGHTNINGRESIST 42   // max lightning resist
#define STAT_COLDRESIST 43           // cold resist
#define STAT_MAXCOLDRESIST 44        // max cold resist
#define STAT_POISONRESIST 45         // poison resist
#define STAT_MAXPOISONRESIST 46      // max poison resist
#define STAT_LIFELEECH 60            // Life Leech
#define STAT_MANALEECH 62            // Mana Leech
#define STAT_VELOCITYPERCENT 67      // effective run/walk
#define STAT_AMMOQUANTITY 70         // ammo quantity(arrow/bolt/throwing)
#define STAT_DURABILITY 72           // item durability
#define STAT_MAXDURABILITY 73        // max item durability
#define STAT_GOLDFIND 79             // Gold find (GF)
#define STAT_MAGICFIND 80            // magic find (MF)
#define STAT_ITEMLEVELREQ 92
#define STAT_IAS 93                     // IAS
#define STAT_FASTERRUNWALK 96           // faster run/walk
#define STAT_FASTERHITRECOVERY 99       // faster hit recovery
#define STAT_FASTERBLOCK 102            // faster block rate
#define STAT_FASTERCAST 105             // faster cast rate
#define STAT_POISONLENGTHREDUCTION 110  // Poison length reduction
#define STAT_OPENWOUNDS 135             // Open Wounds
#define STAT_CRUSHINGBLOW 136           // crushing blow
#define STAT_DEADLYSTRIKE 141           // deadly strike
#define STAT_FIREABSORBPERCENT 142      // fire absorb %
#define STAT_FIREABSORB 143             // fire absorb
#define STAT_LIGHTNINGABSORBPERCENT 144 // lightning absorb %
#define STAT_LIGHTNINGABSORB 145        // lightning absorb
#define STAT_COLDABSORBPERCENT 148      // cold absorb %
#define STAT_COLDABSORB 149             // cold absorb
#define STAT_SLOW 150                   // slow %

///////////////////////////////////////////////////
// NodePages
///////////////////////////////////////////////////
#define NODEPAGE_STORAGE 1
#define NODEPAGE_BELTSLOTS 2
#define NODEPAGE_EQUIP 3

///////////////////////////////////////////////////
// Body Locations
///////////////////////////////////////////////////
enum {
    EQUIP_NONE = 0,        // Not equipped
    EQUIP_HEAD,            // Head
    EQUIP_AMULET,          // Amulet
    EQUIP_BODY,            // Body armor
    EQUIP_RIGHT_PRIMARY,   // Right primary slot
    EQUIP_LEFT_PRIMARY,    // Left primary slot
    EQUIP_RIGHT_RING,      // Right ring
    EQUIP_LEFT_RING,       // Left ring
    EQUIP_BELT,            // Belt
    EQUIP_FEET,            // Feet
    EQUIP_GLOVES,          // Gloves
    EQUIP_RIGHT_SECONDARY, // Right secondary slot
    EQUIP_LEFT_SECONDARY,  // Left secondary slot
};

///////////////////////////////////////////////////
// Storage Buffers
///////////////////////////////////////////////////
// Constants pertaining to GameLocation
#define LOCATION_GROUND 0
#define LOCATION_EQUIP 1
#define LOCATION_BELT 2
#define LOCATION_INVENTORY 3
#define LOCATION_STORE 4
#define LOCATION_TRADE 5
#define LOCATION_CUBE 6
#define LOCATION_STASH 7
#define LOCATION_NULL 255

// Constants pertaining to ItemLocation
#define CLICKTARGET_INVENTORY 0
#define CLICKTARGET_TRADE 2
#define CLICKTARGET_CUBE 3
#define CLICKTARGET_STASH 4
#define CLICKTARGET_BELT 5

///////////////////////////////////////////////////
// Item Quality
///////////////////////////////////////////////////
#define ITEM_QUALITY_INFERIOR 0x01
#define ITEM_QUALITY_NORMAL 0x02
#define ITEM_QUALITY_SUPERIOR 0x03
#define ITEM_QUALITY_MAGIC 0x04
#define ITEM_QUALITY_SET 0x05
#define ITEM_QUALITY_RARE 0x06
#define ITEM_QUALITY_UNIQUE 0x07
#define ITEM_QUALITY_CRAFT 0x08

///////////////////////////////////////////////////
// Player Mode Definition
///////////////////////////////////////////////////
enum {
    PLAYER_MODE_DEATH = 0,     // death
    PLAYER_MODE_STAND_OUTTOWN, // standing outside town
    PLAYER_MODE_WALK_OUTTOWN,  // walking outside town
    PLAYER_MODE_RUN,           // running
    PLAYER_MODE_BEING_HIT,     // being hit
    PLAYER_MODE_STAND_INTOWN,  // standing inside town
    PLAYER_MODE_WALK_INTOWN,   // walking outside town
    PLAYER_MODE_ATTACK1,       // attacking 1
    PLAYER_MODE_ATTACK2,       // attacking 2
    PLAYER_MODE_BLOCK,         // blocking
    PLAYER_MODE_CAST,          // casting spell
    PLAYER_MODE_THROW,         // throwing
    PLAYER_MODE_KICK,          // kicking (assassin)
    PLAYER_MODE_USESKILL1,     // using skill 1
    PLAYER_MODE_USESKILL2,     // using skill 2
    PLAYER_MODE_USESKILL3,     // using skill 3
    PLAYER_MODE_USESKILL4,     // using skill 4
    PLAYER_MODE_DEAD,          // dead
    PLAYER_MODE_SEQUENCE,      // sequence
    PLAYER_MODE_BEING_KNOCKBACK
}; // being knocked back

///////////////////////////////////////////////////
// NPC Mode Definition
///////////////////////////////////////////////////
enum {
    NPC_MODE_DEATH = 0,       // NPC death
    NPC_MODE_STAND,           // NPC standing still
    NPC_MODE_WALK,            // NPC walking
    NPC_MODE_BEING_HIT,       // NPC getting hit
    NPC_MODE_ATTACK1,         // NPC attacking 1
    NPC_MODE_ATTACK2,         // NPC attacking 2
    NPC_MODE_BLOCK,           // NPC blocking
    NPC_MODE_CAST,            // NPC casting spell skill
    NPC_MODE_USESKILL1,       // NPC using skill 1
    NPC_MODE_USESKILL2,       // NPC using skill 2
    NPC_MODE_USESKILL3,       // NPC using skill 3
    NPC_MODE_USESKILL4,       // NPC using skill 4
    NPC_MODE_DEAD,            // NPC dead
    NPC_MODE_BEING_KNOCKBACK, // NPC being knocked back
    NPC_MODE_SEQUENCE,        // NPC sequence
    NPC_MODE_RUN
}; // NPC running

///////////////////////////////////////////////////
// Object Mode Definition
///////////////////////////////////////////////////
enum {
    OBJ_MODE_IDLE = 0,  // Object idle
    OBJ_MODE_OPERATING, // Object operating
    OBJ_MODE_OPENED,    // Object opened
    OBJ_MODE_SPECIAL1,  // Object special 1
    OBJ_MODE_SPECIAL2,  // Object special 2
    OBJ_MODE_SPECIAL3,  // Object special 3
    OBJ_MODE_SPECIAL4,  // Object special 4
    OBJ_MODE_SPECIAL5
}; // Object special 5

///////////////////////////////////////////////////
// Item Mode Definition
///////////////////////////////////////////////////
enum {
    ITEM_MODE_INV_STASH_CUBE_STORE = 0, // Item inven stash cube store
    ITEM_MODE_EQUIPPED,                 // Item equipped self or merc
    ITEM_MODE_IN_BELT,                  // Item in belt
    ITEM_MODE_ON_GROUND,                // Item on ground
    ITEM_MODE_ON_CURSOR,                // Item on cursor
    ITEM_MODE_BEING_DROPPED,            // Item being dropped
    ITEM_MODE_SOCKETED_IN_ITEM
}; // Item socketed in item

///////////////////////////////////////////////////
// Unit Types
///////////////////////////////////////////////////
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define EXIT 6
#define XY 7
#define EXIT_MULTI 8

///////////////////////////////////////////////////
// Spell Stats
///////////////////////////////////////////////////
#define DSI_PASSIVE 0x00000001      // Spell is passive
#define DSI_RIGHTONLY 0x00000002    // Spell must be on right side, like paladin auras
#define DSI_TARGETABLE 0x00000004   // Spell cannot target, like Nova
#define DSI_NEEDCORPSE 0x00000008   // Spell requires a corpse, like Revive
#define DSI_ENABLEINTOWN 0x00000010 // Spell is enabled in town
#define DSI_PHYSICAL 0x00000020     // Spell causes physical damage
#define DSI_MAGICAL 0x00000040      // Spell causes magical damage
#define DSI_FIRE 0x00000080         // Spell causes fire damage
#define DSI_COLD 0x00000100         // Spell causes cold damage
#define DSI_LIGHTNING 0x00000200    // Spell causes lightning damage
#define DSI_POISON 0x00000400       // Spell causes poison damage
#define DSI_KNOCKBACK 0x00000800    // Spell knocks target(s) back
#define DSI_STUN 0x00001000         // Spell stuns target(s)
#define DSI_AFFECTGROUP 0x00002000  // Spell affects multuple targets
#define DSI_MELEE 0x00004000        // Spell only affects target(s) within melee range
#define DSI_SUMMON 0x00008000       // Spell summons minion(s), like Valkyrie
#define DSI_PARTYCAST 0x00010000    // Spell castable on other party members
#define DSI_GUIDED 0x00020000       // Spell is guided to enemies

///////////////////////////////////////////////////
// Character Classes
///////////////////////////////////////////////////
enum { CLASS_AMA = 0, CLASS_SOR, CLASS_NEC, CLASS_PAL, CLASS_BAR, CLASS_DRU, CLASS_ASN, CLASS_NA };

///////////////////////////////////////////////////
// Common Spells
///////////////////////////////////////////////////

#define D2S_INVALID 0xffff // should never happen
#define D2S_ATTACK 0x0000
#define D2S_KICK 0x0001
#define D2S_THROW 0x0002
#define D2S_UNSUMMON 0x0003
#define D2S_LEFTTHROW 0x0004
#define D2S_LEFTSWING 0x0005
#define D2S_TOMEOFIDENTIFY 0x00da
#define D2S_SCROLLOFIDENTIFY 0x00d9
#define D2S_TOMEOFTOWNPORTAL 0x00dc
#define D2S_SCROLLOFTOWNPORTAL 0x00db

///////////////////////////////////////////////////////////////
// Amazon Spells
///////////////////////////////////////////////////////////////

// Javelin and Spear spells
#define D2S_JAB 0x000a
#define D2S_IMPALE 0x0013
#define D2S_FEND 0x001e
#define D2S_POWERSTRIKE 0x000e
#define D2S_CHARGEDSTRIKE 0x0018
#define D2S_LIGHTNINGSTRIKE 0x0022
#define D2S_POISONJAVELIN 0x000f
#define D2S_LIGHTNINGBOLT 0x0014
#define D2S_PLAGUEJAVELIN 0x0019
#define D2S_LIGHTNINGFURY 0x0023

// Passive and Magic spells
#define D2S_INNERSIGHT 0x0008
#define D2S_SLOWMISSILES 0x0011
#define D2S_DECOY 0x001c
#define D2S_VALKYRIE 0x0020
#define D2S_DODGE 0x000d
#define D2S_AVOID 0x0012
#define D2S_EVADE 0x001d
#define D2S_CRITICALSTRIKE 0x0009
#define D2S_PENETRATE 0x0017
#define D2S_PIERCE 0x0021

// Bow and Crossbow spells
#define D2S_COLDARROW 0x000b
#define D2S_ICEARROW 0x0015
#define D2S_FREEZINGARROW 0x001f
#define D2S_MAGICARROW 0x0006
#define D2S_MULTIPLESHOT 0x000c
#define D2S_GUIDEDARROW 0x0016
#define D2S_STRAFE 0x001a
#define D2S_FIREARROW 0x0007
#define D2S_EXPLODINGARROW 0x0010
#define D2S_IMMOLATIONARROW 0x001b

///////////////////////////////////////////////////////////////
// Assassin Spells
///////////////////////////////////////////////////////////////

// Martial Arts
#define D2S_FISTSOFFIRE 0x0103
#define D2S_CLAWSOFTHUNDER 0x010d
#define D2S_BLADESOFICE 0x0112
#define D2S_TIGERSTRIKE 0x00fe
#define D2S_COBRASTRIKE 0x0109
#define D2S_PHOENIXSTRIKE 0x0118
#define D2S_DRAGONTALON 0x00ff
#define D2S_DRAGONCLAW 0x0104
#define D2S_DRAGONTAIL 0x010e
#define D2S_DRAGONFLIGHT 0x0113

// Shadow Disciplines
#define D2S_BURSTOFSPEED 0x0102
#define D2S_FADE 0x010b
#define D2S_VENOM 0x0116
#define D2S_CLAWMASTERY 0x00fc
#define D2S_WEAPONBLOCK 0x0107
#define D2S_SHADOWWARRIOR 0x010c
#define D2S_SHADOWMASTER 0x0117
#define D2S_PSYCHICHAMMER 0x00fd
#define D2S_CLOAKOFSHADOWS 0x0108
#define D2S_MINDBLAST 0x0111

// Traps
#define D2S_SHOCKWEB 0x0100
#define D2S_CHARGEDBOLTSENTRY 0x0105
#define D2S_LIGHTNINGSENTRY 0x010f
#define D2S_DEATHSENTRY 0x0114
#define D2S_FIREBLAST 0x00fb
#define D2S_WAKEOFFIRE 0x0106
#define D2S_WAKEOFINFERNO 0x0110
#define D2S_BLADESENTINEL 0x0101
#define D2S_BLADEFURY 0x010a
#define D2S_BLADESHIELD 0x0115

///////////////////////////////////////////////////////////////
// Barbarian Spells
///////////////////////////////////////////////////////////////

// Warcries
#define D2S_HOWL 0x0082
#define D2S_TAUNT 0x0089
#define D2S_BATTLECRY 0x0092
#define D2S_WARCRY 0x009a
#define D2S_SHOUT 0x008a
#define D2S_BATTLEORDERS 0x0095
#define D2S_BATTLECOMMAND 0x009b
#define D2S_FINDPOTION 0x0083
#define D2S_FINDITEM 0x008e
#define D2S_GRIMWARD 0x0096

// Combat Masteries
#define D2S_SWORDMASTERY 0x007f
#define D2S_POLEARMMASTERY 0x0086
#define D2S_INCREASEDSTAMINA 0x008d
#define D2S_INCREASEDSPEED 0x0094
#define D2S_AXEMASTERY 0x0080
#define D2S_THROWINGMASTERY 0x0087
#define D2S_MACEMASTERY 0x0081
#define D2S_SPEARMASTERY 0x0088
#define D2S_IRONSKIN 0x0091
#define D2S_NATURALRESISTANCE 0x0099

// Combat spells
#define D2S_LEAP 0x0084
#define D2S_LEAPATTACK 0x008f
#define D2S_WHIRLWIND 0x0097
#define D2S_BASH 0x007e
#define D2S_STUN 0x008b
#define D2S_CONCENTRATE 0x0090
#define D2S_BERSERK 0x0098
#define D2S_DOUBLESWING 0x0085
#define D2S_DOUBLETHROW 0x008c
#define D2S_FRENZY 0x0093

///////////////////////////////////////////////////////////////
// Druid Spells
///////////////////////////////////////////////////////////////

// Elemental
#define D2S_FIRESTORM 0x00e1
#define D2S_MOLTENBOULDER 0x00e5
#define D2S_FISSURE 0x00ea
#define D2S_VOLCANO 0x00f4
#define D2S_ARMAGEDDON 0x00f9
#define D2S_TWISTER 0x00f0
#define D2S_TORNADO 0x00f5
#define D2S_HURRICANE 0x00fa
#define D2S_ARCTICBLAST 0x00e6
#define D2S_CYCLONEARMOR 0x00eb

// Shape Shifting
#define D2S_WEREWOLF 0x00df
#define D2S_FERALRAGE 0x00e8
#define D2S_RABIES 0x00ee
#define D2S_FURY 0x00f8
#define D2S_LYCANTHROPY 0x00e0
#define D2S_FIRECLAWS 0x00ef
#define D2S_HUNGER 0x00f2
#define D2S_WEREBEAR 0x00e4
#define D2S_MAUL 0x00e9
#define D2S_SHOCKWAVE 0x00f3

// Summoning
#define D2S_OAKSAGE 0x00e2
#define D2S_HEARTOFWOLVERINE 0x00ec
#define D2S_SPIRITOFBARBS 0x00f6
#define D2S_RAVEN 0x00dd
#define D2S_SUMMONSPIRITWOLF 0x00e3
#define D2S_SUMMONDIREWOLF 0x00ed
#define D2S_SUMMONGRIZZLY 0x00f7
#define D2S_POISONCREEPER 0x00de
#define D2S_CARRIONVINE 0x00e7
#define D2S_SOLARCREEPER 0x00f1

///////////////////////////////////////////////////////////////
// Necromancer Spells
///////////////////////////////////////////////////////////////

// Summoning Spells
#define D2S_SKELETONMASTERY 0x0045
#define D2S_GOLEMMASTERY 0x004f
#define D2S_SUMMONRESIST 0x0059
#define D2S_CLAYGOLEM 0x004b
#define D2S_BLOODGOLEM 0x0055
#define D2S_IRONGOLEM 0x005a
#define D2S_FIREGOLEM 0x005e
#define D2S_RAISESKELETON 0x0046
#define D2S_RAISESKELETALMAGE 0x0050
#define D2S_REVIVE 0x005f

// Poison and Bone Spells
#define D2S_POISONDAGGER 0x0049
#define D2S_POISONEXPLOSION 0x0053
#define D2S_POISONNOVA 0x005c
#define D2S_TEETH 0x0043
#define D2S_CORPOSEEXPLOSION 0x004a
#define D2S_BONESPEAR 0x0054
#define D2S_BONESPIRIT 0x005d
#define D2S_BONEARMOR 0x0044
#define D2S_BONEWALL 0x004e
#define D2S_BONEPRISON 0x0058

// Curses
#define D2S_DIMVISION 0x0047
#define D2S_CONFUSE 0x0051
#define D2S_ATTRACT 0x0056
#define D2S_AMPLIFYDAMAGE 0x0042
#define D2S_IRONMAIDEN 0x004c
#define D2S_LIFETAP 0x0052
#define D2S_LOWERRESIST 0x005b
#define D2S_WEAKEN 0x0048
#define D2S_TERROR 0x004d
#define D2S_DECREPIFY 0x0057

///////////////////////////////////////////////////////////////
// Paladin Spells
///////////////////////////////////////////////////////////////

// Defensive Auras
#define D2S_PRAYER 0x0063
#define D2S_CLEANSING 0x006d
#define D2S_MEDITATION 0x0078
#define D2S_DEFIANCE 0x0068
#define D2S_VIGOR 0x0073
#define D2S_REDEMPTION 0x007c
#define D2S_RESISTFIRE 0x0064
#define D2S_RESISTCOLD 0x0069
#define D2S_RESISTLIGHTNING 0x006e
#define D2S_SALVATION 0x007d

// Offensive Auras
#define D2S_MIGHT 0x0062
#define D2S_BLESSEDAIM 0x006c
#define D2S_CONCENTRATION 0x0071
#define D2S_FANATICISM 0x007a
#define D2S_HOLYFIRE 0x0066
#define D2S_HOLYFREEZE 0x0072
#define D2S_HOLYSHOCK 0x0076
#define D2S_THORNS 0x0067
#define D2S_SANCTUARY 0x0077
#define D2S_CONVICTION 0x007b

// Combat spells
#define D2S_SACRIFICE 0x0060
#define D2S_ZEAL 0x006a
#define D2S_VENGEANCE 0x006f
#define D2S_CONVERSION 0x0074
#define D2S_HOLYBOLT 0x0065
#define D2S_BLESSEDHAMMER 0x0070
#define D2S_FISTOFTHEHEAVENS 0x0079
#define D2S_SMITE 0x0061
#define D2S_CHARGE 0x006b
#define D2S_HOLYSHIELD 0x0075

///////////////////////////////////////////////////////////////
// Sorceress Spells
///////////////////////////////////////////////////////////////

// Cold Spells
#define D2S_FROSTNOVA 0x002c
#define D2S_BLIZZARD 0x003b
#define D2S_FROZENORB 0x0040
#define D2S_ICEBOLT 0x0027
#define D2S_ICEBLAST 0x002d
#define D2S_GLACIALSPIKE 0x0037
#define D2S_COLDMASTERY 0x0041
#define D2S_FROZENARMOR 0x0028
#define D2S_SHIVERARMOR 0x0032
#define D2S_CHILLINGARMOR 0x003c

// Lightning Spells
#define D2S_STATICFIELD 0x002a
#define D2S_NOVA 0x0030
#define D2S_THUNDERSTORM 0x0039
#define D2S_CHARGEDBOLT 0x0026
#define D2S_LIGHTNING 0x0031
#define D2S_CHAINLIGHTNING 0x0035
#define D2S_LIGHTNINGMASTERY 0x003f
#define D2S_TELEKINESIS 0x002b
#define D2S_TELEPORT 0x0036
#define D2S_ENERGYSHIELD 0x003a

// Fire Spells
#define D2S_INFERNO 0x0029
#define D2S_BLAZE 0x002e
#define D2S_FIREWALL 0x0033
#define D2S_FIREBOLT 0x0024
#define D2S_FIREBALL 0x002f
#define D2S_METEOR 0x0038
#define D2S_FIREMASTERY 0x003d
#define D2S_WARMTH 0x0025
#define D2S_ENCHANT 0x0034
#define D2S_HYDRA 0x003e

///////////////////////////////////////////////////
// Map Definition
///////////////////////////////////////////////////
#define MAP_UNKNOWN 0x00

///////////////////////////////////////////////////
// Act 1 Maps
///////////////////////////////////////////////////
#define MAP_A1_ROGUE_ENCAMPMENT 0x01
#define MAP_A1_BLOOD_MOOR 0x02
#define MAP_A1_COLD_PLAINS 0x03
#define MAP_A1_STONY_FIELD 0x04
#define MAP_A1_DARK_WOOD 0x05
#define MAP_A1_BLACK_MARSH 0x06
#define MAP_A1_TAMOE_HIGHLAND 0x07
#define MAP_A1_DEN_OF_EVIL 0x08
#define MAP_A1_CAVE_LEVEL_1 0x09 // Cave in Cold plains
#define MAP_A1_UNDERGROUND_PASSAGE_LEVEL_1 0x0a
#define MAP_A1_HOLE_LEVEL_1 0x0b
#define MAP_A1_PIT_LEVEL_1 0x0c
#define MAP_A1_CAVE_LEVEL_2 0x0d // Cave in Cold plains
#define MAP_A1_UNDERGROUND_PASSAGE_LEVEL_2 0x0e
#define MAP_A1_HOLE_LEVEL_2 0x0f
#define MAP_A1_PIT_LEVEL_2 0x10
#define MAP_A1_BURIAL_GROUNDS 0x11
#define MAP_A1_CRYPT 0x12
#define MAP_A1_MAUSOLEUM 0x13
#define MAP_A1_FORGOTTEN_TOWER 0x14
#define MAP_A1_TOWER_CELLAR_LEVEL_1 0x15
#define MAP_A1_TOWER_CELLAR_LEVEL_2 0x16
#define MAP_A1_TOWER_CELLAR_LEVEL_3 0x17
#define MAP_A1_TOWER_CELLAR_LEVEL_4 0x18
#define MAP_A1_TOWER_CELLAR_LEVEL_5 0x19
#define MAP_A1_MONASTERY_GATE 0x1a
#define MAP_A1_OUTER_CLOISTER 0x1b
#define MAP_A1_BARRACKS 0x1c
#define MAP_A1_JAIL_LEVEL_1 0x1d
#define MAP_A1_JAIL_LEVEL_2 0x1e
#define MAP_A1_JAIL_LEVEL_3 0x1f
#define MAP_A1_INNER_CLOISTER 0x20
#define MAP_A1_INNER_CLOISTER_2 0x21
#define MAP_A1_CATHEDRAL 0x21
#define MAP_A1_CATACOMBS_LEVEL_1 0x22
#define MAP_A1_CATACOMBS_LEVEL_2 0x23
#define MAP_A1_CATACOMBS_LEVEL_3 0x24
#define MAP_A1_CATACOMBS_LEVEL_4 0x25
#define MAP_A1_TRISTRAM 0x26
#define MAP_A1_THE_SECRET_COW_LEVEL 0x27

///////////////////////////////////////////////////
// Act 2 Maps
///////////////////////////////////////////////////
#define MAP_A2_LUT_GHOLEIN 0x28
#define MAP_A2_ROCKY_WASTE 0x29
#define MAP_A2_DRY_HILLS 0x2a
#define MAP_A2_FAR_OASIS 0x2b
#define MAP_A2_LOST_CITY 0x2c
#define MAP_A2_VALLEY_OF_SNAKES 0x2d
#define MAP_A2_CANYON_OF_THE_MAGI 0x2e
#define MAP_A2_SEWERS_LEVEL_1 0x2f
#define MAP_A2_SEWERS_LEVEL_2 0x30
#define MAP_A2_SEWERS_LEVEL_3 0x31
#define MAP_A2_HAREM_LEVEL_1 0x32
#define MAP_A2_HAREM_LEVEL_2 0x33
#define MAP_A2_PALACE_CELLAR_LEVEL_1 0x34
#define MAP_A2_PALACE_CELLAR_LEVEL_2 0x35
#define MAP_A2_PALACE_CELLAR_LEVEL_3 0x36
#define MAP_A2_STONY_TOMB_LEVEL_1 0x37
#define MAP_A2_HALLS_OF_THE_DEAD_LEVEL_1 0x38
#define MAP_A2_HALLS_OF_THE_DEAD_LEVEL_2 0x39
#define MAP_A2_CLAW_VIPER_TEMPLE_LEVEL_1 0x3a
#define MAP_A2_STONY_TOMB_LEVEL_2 0x3b
#define MAP_A2_HALLS_OF_THE_DEAD_LEVEL_3 0x3c
#define MAP_A2_CLAW_VIPER_TEMPLE_LEVEL_2 0x3d
#define MAP_A2_MAGGOT_LAIR_LEVEL_1 0x3e
#define MAP_A2_MAGGOT_LAIR_LEVEL_2 0x3f
#define MAP_A2_MAGGOT_LAIR_LEVEL_3 0x40
#define MAP_A2_ANCIENT_TUNNELS 0x41
#define MAP_A2_TAL_RASHAS_TOMB_1 0x42
#define MAP_A2_TAL_RASHAS_TOMB_2 0x43
#define MAP_A2_TAL_RASHAS_TOMB_3 0x44
#define MAP_A2_TAL_RASHAS_TOMB_4 0x45
#define MAP_A2_TAL_RASHAS_TOMB_5 0x46
#define MAP_A2_TAL_RASHAS_TOMB_6 0x47
#define MAP_A2_TAL_RASHAS_TOMB_7 0x48
#define MAP_A2_TAL_RASHAS_CHAMBER 0x49
#define MAP_A2_ARCANE_SANCTUARY 0x4a

///////////////////////////////////////////////////
// Act 3 Maps
///////////////////////////////////////////////////
#define MAP_A3_KURAST_DOCKS 0x4b
#define MAP_A3_SPIDER_FOREST 0x4c
#define MAP_A3_GREAT_MARSH 0x4d
#define MAP_A3_FLAYER_JUNGLE 0x4e
#define MAP_A3_LOWER_KURAST 0x4f
#define MAP_A3_KURAST_BAZAAR 0x50
#define MAP_A3_UPPER_KURAST 0x51
#define MAP_A3_KURAST_CAUSEWAY 0x52
#define MAP_A3_TRAVINCAL 0x53
#define MAP_A3_ARCHNID_LAIR 0x54
#define MAP_A3_SPIDER_CAVERN 0x55
#define MAP_A3_SWAMPY_PIT_LEVEL_1 0x56
#define MAP_A3_SWAMPY_PIT_LEVEL_2 0x57
#define MAP_A3_FLAYER_DUNGEON_LEVEL_1 0x58
#define MAP_A3_FLAYER_DUNGEON_LEVEL_2 0x59
#define MAP_A3_SWAMPY_PIT_LEVEL_3 0x5a
#define MAP_A3_FLAYER_DUNGEON_LEVEL_3 0x5b
#define MAP_A3_SEWERS_LEVEL_1 0x5c
#define MAP_A3_SEWERS_LEVEL_2 0x5d
#define MAP_A3_RUINED_TEMPLE 0x5e
#define MAP_A3_DISUSED_FANE 0x5f
#define MAP_A3_FORGOTTEN_RELIQUARY 0x60
#define MAP_A3_FORGOTTEN_TEMPLE 0x61
#define MAP_A3_RUINED_FANE 0x62
#define MAP_A3_DISUSED_RELIQUARY 0x63
#define MAP_A3_DURANCE_OF_HATE_LEVEL_1 0x64
#define MAP_A3_DURANCE_OF_HATE_LEVEL_2 0x65
#define MAP_A3_DURANCE_OF_HATE_LEVEL_3 0x66

///////////////////////////////////////////////////
// Act 4 Maps
///////////////////////////////////////////////////
#define MAP_A4_THE_PANDEMONIUM_FORTRESS 0x67
#define MAP_A4_OUTER_STEPPES 0x68
#define MAP_A4_PLAINS_OF_DESPAIR 0x69
#define MAP_A4_CITY_OF_THE_DAMNED 0x6a
#define MAP_A4_RIVER_OF_FLAME 0x6b
#define MAP_A4_THE_CHAOS_SANCTUARY 0x6c

///////////////////////////////////////////////////
// Act 5 Maps
///////////////////////////////////////////////////
#define MAP_A5_HARROGATH 0x6d
#define MAP_A5_THE_BLOODY_FOOTHILLS 0x6e
#define MAP_A5_FRIGID_HIGHLANDS 0x6f
#define MAP_A5_ARREAT_PLATEAU 0x70
#define MAP_A5_CRYSTALLINE_PASSAGE 0x71
#define MAP_A5_FROZEN_RIVER 0x72
#define MAP_A5_GLACIAL_TRAIL 0x73
#define MAP_A5_DRIFTER_CAVERN 0x74
#define MAP_A5_FROZEN_TUNDRA 0x75
#define MAP_A5_THE_ANCIENTS_WAY 0x76
#define MAP_A5_ICY_CELLAR 0x77
#define MAP_A5_ARREAT_SUMMIT 0x78
#define MAP_A5_NIHLATHAKS_TEMPLE 0x79
#define MAP_A5_HALLS_OF_ANGUISH 0x7a
#define MAP_A5_HALLS_OF_PAIN 0x7b
#define MAP_A5_HALLS_OF_VAUGHT 0x7c
#define MAP_A5_ABADDON 0x7d
#define MAP_A5_PIT_OF_ACHERON 0x7e
#define MAP_A5_INFERNAL_PIT 0x7f
#define MAP_A5_WORLDSTONE_KEEP_LEVEL_1 0x80
#define MAP_A5_WORLDSTONE_KEEP_LEVEL_2 0x81
#define MAP_A5_WORLDSTONE_KEEP_LEVEL_3 0x82
#define MAP_A5_THRONE_OF_DESTRUCTION 0x83
#define MAP_A5_WORLDSTONE_KEEP 0x84
#define MAP_A5_MATRONS_DEN 0x85
#define MAP_A5_FORGOTTEN_SANDS 0x86
#define MAP_A5_FURNACE_OF_PAIN 0x87
#define MAP_A5_TRISTRAM 0x88

///////////////////////////////////////////////////
// Item Flags (From D2jsp scripting document)
///////////////////////////////////////////////////
#define ITEM_FLAG_IDENTIFIED 0x00000010   // Identified
#define ITEM_FLAG_SWITCHIN 0x00000040     // Switched in(activated)
#define ITEM_FLAG_SWITCHOUT 0x00000080    // Switched out(deactivated)
#define ITEM_FLAG_BROKEN 0x00000100       // Broken(0 durability)
#define ITEM_FLAG_HASSOCKETS 0x00000800   // Has sockets
#define ITEM_FLAG_INSTORE 0x00002000      // In npc store or gamble screen
#define ITEM_FLAG_ISEAR 0x00010000        // Player's ear
#define ITEM_FLAG_STARTITEM 0x00020000    // Start item(1 selling value each)
#define ITEM_FLAG_ETHEREAL 0x00400000     // Ethreal
#define ITEM_FLAG_PERSONALIZED 0x01000000 // Personalized
#define ITEM_FLAG_RUNEWORD 0x04000000     // Runeword

///////////////////////////////////////////////////
// Unit Stat ID Definition
// (Completed using the heroin_glands D2 library)
///////////////////////////////////////////////////
#define STAT_STRENGTH				0		// str
#define	STAT_ENERGY					1		// energy
#define	STAT_DEXTERITY				2		// dexterity
#define	STAT_VITALITY				3		// vitality
#define STAT_STATPOINTSLEFT			4
#define STAT_NEWSKILLS				5
#define	STAT_HP						6		// life
#define	STAT_MAXHP					7		// max life
#define	STAT_MANA					8		// mana
#define	STAT_MAXMANA				9		// max mana
#define	STAT_STAMINA				10		// stamina
#define	STAT_MAXSTAMINA				11		// max stamina
#define	STAT_LEVEL					12		// level
#define STAT_EXP					13		// experience
#define	STAT_GOLD					14		// gold
#define	STAT_GOLDBANK				15		// stash gold
#define STAT_ENHANCEDDEFENSE		16
#define STAT_ENHANCEDMAXIMUMDAMAGE	17
#define STAT_ENHANCEDMINIMUMDAMAGE	18
#define STAT_ATTACKRATING			19
#define	STAT_TOBLOCK				20		// to block
#define STAT_MINIMUMDAMAGE			21
#define STAT_MAXIMUMDAMAGE			22
#define STAT_SECONDARYMINIMUMDAMAGE	23
#define STAT_SECONDARYMAXIMUMDAMAGE	24
#define STAT_ENHANCEDDAMAGE			25
#define STAT_MANARECOVERY			26
#define STAT_MANARECOVERYBONUS		27
#define STAT_STAMINARECOVERYBONUS	28
#define STAT_LASTEXPERIENCE			29
#define STAT_NEXTEXPERIENCE			30
#define STAT_DEFENSE				31
#define STAT_DEFENSEVSMISSILES		32
#define STAT_DEFENSEVSMELEE			33
#define STAT_DMGREDUCTION			34
#define	STAT_MAGICDMGREDUCTION		35		// magic damage reduction
#define	STAT_DMGREDUCTIONPCT		36		// damage reduction
#define	STAT_MAGICDMGREDUCTIONPCT	37		// magic damage reduction percentage
#define	STAT_MAXMAGICDMGREDUCTPCT	38		// max magic damage reduction percentage
#define	STAT_FIRERESIST				39		// fire resist
#define	STAT_MAXFIRERESIST			40		// max fire resist
#define	STAT_LIGHTNINGRESIST		41		// lightning resist
#define	STAT_MAXLIGHTNINGRESIST		42		// max lightning resist
#define	STAT_COLDRESIST				43		// cold resist
#define	STAT_MAXCOLDRESIST			44		// max cold resist
#define	STAT_POISONRESIST			45		// poison resist
#define	STAT_MAXPOISONRESIST		46		// max poison resist
#define STAT_DAMAGEAURA				47
#define STAT_MINIMUMFIREDAMAGE		48
#define STAT_MAXIMUMFIREDAMAGE		49
#define STAT_MINIMUMLIGHTNINGDAMAGE	50
#define STAT_MAXIMUMLIGHTNINGDAMAGE	51
#define STAT_MINIMUMMAGICALDAMAGE	52
#define STAT_MAXIMUMMAGICALDAMAGE	53
#define STAT_MINIMUMCOLDDAMAGE		54
#define STAT_MAXIMUMCOLDDAMAGE		55
#define STAT_COLDDAMAGELENGTH		56
#define STAT_MINIMUMPOISONDAMAGE	57
#define STAT_MAXIMUMPOISONDAMAGE	58
#define STAT_POISONDAMAGELENGTH		59
#define STAT_LIFELEECH				60		// Life Leech (min life stolen per hit)
#define STAT_MAXLIFESTOLENPERHIT	61
#define STAT_MANALEECH				62		// Mana Leech (min mana stolen per hit)
#define STAT_MAXMANASTOLENPERHIT	63
#define STAT_MINIMUMSTAMINADRAIN	64
#define STAT_MAXIMUMSTAMINADRAIN	65
#define STAT_STUNLENGTH				66
#define	STAT_VELOCITYPERCENT		67		// effective run/walk
#define STAT_ATTACKRATE				68
#define STAT_OTHERANIMATIONRATE		69
#define STAT_AMMOQUANTITY			70		// ammo quantity(arrow/bolt/throwing)
#define STAT_VALUE					71
#define STAT_DURABILITY				72		// item durability
#define STAT_MAXDURABILITY			73		// max item durability
#define STAT_REPLENISHLIFE			74
#define STAT_ENHANCEDMAXDURABILITY	75
#define STAT_ENHANCEDLIFE			76
#define STAT_ENHANCEDMANA			77
#define STAT_ATTACKERTAKESDAMAGE	78
#define STAT_GOLDFIND				79		// Gold find (GF)
#define	STAT_MAGICFIND				80		// magic find (MF)
#define STAT_KNOCKBACK				81
#define STAT_TIMEDURATION			82
#define STAT_CLASSSKILLS			83
#define STAT_UNSENTPARAMETER		84
#define STAT_ADDEXPERIENCE			85
#define STAT_LIFEAFTEREACHKILL		86
#define STAT_REDUCEVENDORPRICES		87
#define STAT_DOUBLEHERBDURATION		88
#define STAT_LIGHTRADIUS			89
#define STAT_LIGHTCOLOUR			90
#define STAT_REDUCEDREQUIREMENTS	91
#define STAT_REDUCEDLEVELREQ		92
#define	STAT_IAS					93		// IAS
#define STAT_REDUCEDLEVELREQPCT		94
#define STAT_LASTBLOCKFRAME			95
#define	STAT_FASTERRUNWALK			96		// faster run/walk
#define STAT_NONCLASSSKILL			97
#define STAT_STATE					98
#define	STAT_FASTERHITRECOVERY		99		// faster hit recovery
#define STAT_MONSTERPLAYERCOUNT		100
#define STAT_SKILLPOISONOVERRIDELEN	101
#define	STAT_FASTERBLOCK			102		// faster block rate
#define STAT_SKILLBYPASSUNDEAD		103
#define STAT_SKILLBYPASSDEMONS		104
#define	STAT_FASTERCAST				105		// faster cast rate
#define STAT_SKILLBYPASSBEASTS		106
#define STAT_SINGLESKILL			107
#define STAT_SLAINMONSTERSRIP		108
#define STAT_CURSERESISTANCE		109
#define STAT_POISONLENGTHREDUCTION	110		// Poison length reduction
#define STAT_ADDSDAMAGE				111
#define STAT_HITCAUSESMONSTERTOFLEE	112
#define STAT_HITBLINDSTARGET		113
#define STAT_DAMAGETOMANA			114
#define STAT_IGNORETARGETSDEFENSE	115
#define STAT_REDUCETARGETSDEFENSE	116
#define STAT_PREVENTMONSTERHEAL		117
#define STAT_HALFFREEZEDURATION		118
#define STAT_TOHITPERCENT			119
#define STAT_MONSTERDEFDUCTPERHIT	120
#define STAT_DAMAGETODEMONS			121
#define STAT_DAMAGETOUNDEAD			122
#define STAT_ATTACKRATINGVSDEMONS	123
#define STAT_ATTACKRATINGVSUNDEAD	124
#define STAT_THROWABLE				125
#define STAT_ELEMENTALSKILLS		126
#define STAT_ALLSKILLS				127
#define STAT_ATTACKERTAKESLTNGDMG	128
#define STAT_IRONMAIDENLEVEL		129
#define STAT_LIFETAPLEVEL			130
#define STAT_THORNSPERCENT			131
#define STAT_BONEARMOR				132
#define STAT_MAXIMUMBONEARMOR		133
#define STAT_FREEZESTARGET			134
#define STAT_OPENWOUNDS				135		// Open Wounds
#define	STAT_CRUSHINGBLOW			136		// crushing blow
#define STAT_KICKDAMAGE				137
#define STAT_MANAAFTEREACHKILL		138
#define STAT_LIFEAFTEREACHDEMONKILL	139
#define STAT_EXTRABLOOD				140
#define	STAT_DEADLYSTRIKE			141		// deadly strike
#define	STAT_FIREABSORBPERCENT		142		// fire absorb %
#define	STAT_FIREABSORB				143		// fire absorb
#define	STAT_LIGHTNINGABSORBPERCENT	144		// lightning absorb %
#define	STAT_LIGHTNINGABSORB		145		// lightning absorb
#define	STAT_MAGICABSORBPERCENT		146		// magic absorb %
#define STAT_MAGICABSORB			147
#define	STAT_COLDABSORBPERCENT		148		// cold absorb %
#define	STAT_COLDABSORB				149		// cold absorb
#define STAT_SLOW					150		// slow %
#define STAT_AURA					151
#define STAT_INDESTRUCTIBLE			152
#define STAT_CANNOTBEFROZEN			153
#define STAT_STAMINADRAINPERCENT	154
#define STAT_REANIMATE				155
#define STAT_PIERCINGATTACK			156
#define STAT_FIRESMAGICARROWS		157
#define STAT_FIREEXPLOSIVEARROWS	158
#define STAT_MINIMUMTHROWINGDAMAGE	159
#define STAT_MAXIMUMTHROWINGDAMAGE	160
#define STAT_SKILLHANDOFATHENA		161
#define STAT_SKILLSTAMINAPERCENT	162
#define STAT_SKILLPASSIVESTAMINAPCT	163
#define STAT_CONCENTRATION			164
#define STAT_ENCHANT				165
#define STAT_PIERCE					166
#define STAT_CONVICTION				167
#define STAT_CHILLINGARMOR			168
#define STAT_FRENZY					169
#define STAT_DECREPIFY				170
#define STAT_SKILLARMORPERCENT		171
#define STAT_ALIGNMENT				172
#define STAT_TARGET0				173
#define STAT_TARGET1				174
#define STAT_GOLDLOST				175
#define STAT_CONVERSIONLEVEL		176
#define STAT_CONVERSIONMAXIMUMLIFE	177
#define STAT_UNITDOOVERLAY			178
#define STAT_ATTCKRTNGVSMONSTERTYPE	179
#define STAT_DAMAGETOMONSTERTYPE	180
#define STAT_FADE					181
#define STAT_ARMOROVERRIDEPERCENT	182
#define STAT_UNUSED183				183
#define STAT_UNUSED184				184
#define STAT_UNUSED185				185
#define STAT_UNUSED186				186
#define STAT_UNUSED187				187
#define STAT_SKILLTAB				188
#define STAT_UNUSED189				189
#define STAT_UNUSED190				190
#define STAT_UNUSED191				191
#define STAT_UNUSED192				192
#define STAT_UNUSED193				193
#define STAT_SOCKETS				194
#define STAT_SKILLONSTRIKING		195
#define STAT_SKILLONKILL			196
#define STAT_SKILLONDEATH			197
#define STAT_SKILLONHIT				198
#define STAT_SKILLONLEVELUP			199
#define STAT_UNUSED200				200
#define STAT_SKILLWHENSTRUCK		201
#define STAT_UNUSED202				202
#define STAT_UNUSED203				203
#define STAT_CHARGED				204
#define STAT_UNUSED204				205
#define STAT_UNUSED205				206
#define STAT_UNUSED206				207
#define STAT_UNUSED207				208
#define STAT_UNUSED208				209
#define STAT_UNUSED209				210
#define STAT_UNUSED210				211
#define STAT_UNUSED211				212
#define STAT_UNUSED212				213
#define STAT_DEFENSEPERLEVEL		214
#define STAT_ENHANCEDDEFENSEPERLVL	215
#define STAT_LIFEPERLEVEL			216
#define STAT_MANAPERLEVEL			217
#define STAT_MAXDAMAGEPERLEVEL		218
#define STAT_MAXENHANCEDDMGPERLEVEL	219
#define STAT_STRENGTHPERLEVEL		220
#define STAT_DEXTERITYPERLEVEL		221
#define STAT_ENERGYPERLEVEL			222
#define STAT_VITALITYPERLEVEL		223
#define STAT_ATTACKRATINGPERLEVEL	224
#define STAT_BONUSATTCKRTNGPERLEVEL	225
#define STAT_MAXCOLDDMGPERLVL		226
#define STAT_MAXFIREDMGPERLVL		227
#define STAT_MAXLIGHTNINGDMGPERLVL	228
#define STAT_MAXPOISONDMGPERLVL		229
#define STAT_COLDRESPERLEVEL		230
#define STAT_FIRERESPERLEVEL		231
#define STAT_LIGHTNINGRESPERLEVEL	232
#define STAT_POISONRESPERLEVEL		233
#define STAT_COLDABSORBPERLVL		234
#define STAT_FIREABSORBPERLVL		235
#define STAT_LIGHTNINGABSORBPERLVL	236
#define STAT_POISONABSORBPERLVL		237
#define STAT_THORNSPERLEVEL			238
#define STAT_EXTRAGOLDPERLEVEL		239
#define STAT_MAGICFINDPERLEVEL		240
#define STAT_STAMINAREGENPERLEVEL	241
#define STAT_STAMINAPERLEVEL		242
#define STAT_DAMAGETODEMONSPERLEVEL	243
#define STAT_DAMAGETOUNDEADPERLEVEL	244
#define STAT_ATTKRTNGVSDEMONSPERLVL	245
#define STAT_ATTKRTNGVSUNDEADPERLVL	246
#define STAT_CRUSHINGBLOWPERLEVEL	247
#define STAT_OPENWOUNDSPERLEVEL		248
#define STAT_KICKDAMAGEPERLEVEL		249
#define STAT_DEADLYSTRIKEPERLEVEL	250
#define STAT_FINDGEMSPERLEVEL		251
#define STAT_REPAIRSDURABILITY		252
#define STAT_REPLENISHESQUANTITY	253
#define STAT_INCREASEDSTACKSIZE		254
#define STAT_FINDITEM				255
#define STAT_SLASHDAMAGE			256
#define STAT_SLASHDAMAGEPERCENT		257
#define STAT_CRUSHDAMAGE			258
#define STAT_CRUSHDAMAGEPERCENT		259
#define STAT_THRUSTDAMAGE			260
#define STAT_THRUSTDAMAGEPERCENT	261
#define STAT_SLASHDAMAGEABSORPTION	262
#define STAT_CRUSHDAMAGEABSORPTION	263
#define STAT_THRUSTDAMAGEABSORPTION	264
#define STAT_SLASHDAMAGEABSORBPCT	265
#define STAT_CRUSHDAMAGEABSORBPCT	266
#define STAT_THRUSTDAMAGEABSORBPCT	267
#define STAT_DEFENSEPERTIME			268
#define STAT_ENHANCEDDEFENSEPERTIME	269
#define STAT_LIFEPERTIME			270
#define STAT_MANAPERTIME			271
#define STAT_MAXDAMAGEPERTIME		272
#define STAT_MAXENHANCEDDMGPERTIME	273
#define STAT_STRENGTHPERTIME		274
#define STAT_DEXTERITYPERTIME		275
#define STAT_ENERGYPERTIME			276
#define STAT_VITALITYPERTIME		277
#define STAT_ATTACKRATINGPERTIME	278
#define STAT_CHANCETOHITPERTIME		279
#define STAT_MAXCOLDDAMAGEPERTIME	280
#define STAT_MAXFIREDAMAGEPERTIME	281
#define STAT_MAXLIGHTNINGDMGPERTIME	282
#define STAT_MAXDAMAGEPERPOISON		283
#define STAT_COLDRESPERTIME			284
#define STAT_FIRERESPERTIME			285
#define STAT_LIGHTNINGRESPERTIME	286
#define STAT_POISONRESPERTIME		287
#define STAT_COLDABSORPTIONPERTIME	288
#define STAT_FIREABSORPTIONPERTIME	289
#define STAT_LIGHTNINGABSORBPERTIME	290
#define STAT_POISONABSORBPERTIME	291
#define STAT_EXTRAGOLDPERTIME		292
#define STAT_MAGICFINDPERTIME		293
#define STAT_REGENSTAMINAPERTIME	294
#define STAT_STAMINAPERTIME			295
#define STAT_DAMAGETODEMONSPERTIME	296
#define STAT_DAMAGETOUNDEADPERTIME	297
#define STAT_ATTRTNGVSDEMONSPERTIME	298
#define STAT_ATTRTNGVSUNDEADPERTIME	299
#define STAT_CRUSHINGBLOWPERTIME	300
#define STAT_OPENWOUNDSPERTIME		301
#define STAT_KICKDAMAGEPERTIME		302
#define STAT_DEADLYSTRIKEPERTIME	303
#define STAT_FINDGEMSPERTIME		304
#define STAT_ENEMYCOLDRESREDUCTION	305
#define STAT_ENEMYFIRERESREDUCTION	306
#define STAT_ENEMYLIGHTRESREDUCTION	307
#define STAT_ENEMYPSNRESREDUCTION	308
#define STAT_DAMAGEVSMONSTERS		309
#define STAT_ENHANCEDDMGVSMONSTERS	310
#define STAT_ATTACKRATINGVSMONSTERS	311
#define STAT_BONUSATTRTNGVSMONSTERS	312
#define STAT_DEFENSEVSMONSTERS		313
#define STAT_ENHANCEDDEFVSMONSTERS	314
#define STAT_FIREDAMAGELENGTH		315
#define STAT_MINFIREDAMAGELENGTH	316
#define STAT_MAXFIREDAMAGELENGTH	317
#define STAT_PROGRESSIVEDAMAGE		318
#define STAT_PROGRESSIVESTEAL		319
#define STAT_PROGRESSIVEOTHER		320
#define STAT_PROGRESSIVEFIRE		321
#define STAT_PROGRESSIVECOLD		322
#define STAT_PROGRESSIVELIGHTNING	323
#define STAT_EXTRACHARGES			324
#define STAT_PROGRESSIVEATTACKRTNG	325
#define STAT_POISONCOUNT			326
#define STAT_DAMAGEFRAMERATE		327
#define STAT_PIERCEIDX				328
#define STAT_FIREMASTERY			329
#define STAT_LIGHTNINGMASTERY		330
#define STAT_COLDMASTERY			331
#define STAT_POISONMASTERY			332
#define STAT_PSENEMYFIRERESREDUC	333		// passive enemy fire resist reduction
#define STAT_PSENEMYLIGHTNRESREDUC	334		// passive enemy lightning resist reduction
#define STAT_PSENEMYCOLDRESREDUC	335		// passive enemy cold resist reduction
#define STAT_PSENEMYPSNRESREDUC		336		// passive enemy poison resist reduction
#define STAT_CRITICALSTRIKE			337
#define STAT_DODGE					338
#define STAT_AVOID					339
#define STAT_EVADE					340
#define STAT_WARMTH					341
#define STAT_MELEEARMASTERY			342		// melee attack rating mastery
#define STAT_MELEEDAMAGEMASTERY		343
#define STAT_MELEECRITHITMASTERY	344
#define STAT_THROWNWEAPONARMASTERY	345		// thrown weapon attack rating mastery
#define STAT_THROWNWEAPONDMGMASTERY	346
#define STAT_THROWNCRITHITMASTERY	347		// thrown weapon critical hit mastery
#define STAT_WEAPONBLOCK			348
#define STAT_SUMMONRESIST			349
#define STAT_MODIFIERLISTSKILL		350
#define STAT_MODIFIERLISTLEVEL		351
#define STAT_LASTSENTLIFEPERCENT	352
#define STAT_SOURCEUNITTYPE			353
#define STAT_SOURCEUNITID			354
#define STAT_SHORTPARAMETER1		355
#define STAT_QUESTITEMDIFFICULTY	356
#define STAT_PASSIVEMAGICDMGMASTERY	357
#define STAT_PASSIVEMAGICRESREDUC	358

///////////////////////////////////////////////////
// Item Stats
///////////////////////////////////////////////////
#define ITEMSTAT_SOCKETS 0xC2
#define AFFECT_JUST_PORTALED 102

///////////////////////////////////////////////////
// Unit Enchantments
///////////////////////////////////////////////////
#define ENCH_EXTRA_STRONG			5
#define ENCH_EXTRA_FAST				6
#define ENCH_CURSED					7
#define ENCH_MAGIC_RESISTANT		8
#define ENCH_FIRE_ENCHANTED			9
#define ENCH_LIGHTNING_ENCHANTED	17
#define ENCH_COLD_ENCHANTED			18
#define ENCH_MANA_BURN				25
#define ENCH_TELEPORTATION			26
#define ENCH_SPECTRAL_HIT			27
#define ENCH_STONE_SKIN				28
#define ENCH_MULTIPLE_SHOTS			29

#endif