#ifndef STATS_H
#define STATS_H
#define _NAME_LENGHT 15
#define _NPERSO 20
#define INV_SIZE 100


// stats intelligent
typedef struct perso{
	char* nom;
	int maxPV;
	int armure;
	int mana;
	int arme;
	char** inv;
} perso;

// stats intelligent
typedef struct intel{
	const char* nom;
	int maxPV;
	int armure;
	int mana;
	int arme;
	
} intel;

// stats semi intel
typedef struct semi_A{
	const char* nom;
	int maxPV;
	int armure;
	int mana;
	int arme;
} semi_A;

typedef struct semi_B{
	const char* nom;
	int maxPV;
	int armure;
	int mana;
} semi_B;

// stats animal
typedef struct animal{
	const char* nom;
	int maxPV;
	int armure;
} animal;

// mobs intel
static intel intel_mobs[] = {
    /* nom         pv   armure    mana   arme*/
    {"elfe",       35,     15,     35,      5},
    {"nain",      45,      20,     25,      2},
    {"elfe noir", 30,      25,     40,      1},  
    {"humain",    40,      10,     30,      3},
    // ajouter
	{0,0,0,0,0},
};

// mobs semi-intel
static semi_A semi_A_mobs[] = {
    /* nom          pv     armure     mana    arme*/
    {"gobelin",    25,         5,       5,       1},
    {"troll",      95,         0,      10,       4},
    {"gargouille", 25,        10,      35,       0},
    {"wargal",     30,         7,       5,       3},
    {"kalkaras",   15,        45,      40,       2},
    // ajouter
	{0,0,0,0},
};

static semi_B semi_B_mobs[] = {
    /* nom          pv     armure     mana    arme*/
    {"whorte",     20,         0,       40,      0},
    // ajouter
	{0,0,0,0},
};


// mobs 白痴 animal
static animal animal_mobs[] = {
    /* nom             pv   armure*/
    {"blaktar",       45,        6},
    {"nixe",          15,        5},
    {"serpent géant", 45,       23},
    // ajouter
	{0,0,0},
};

#endif // STATS_H
