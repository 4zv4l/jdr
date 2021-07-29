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
    /* nom      pv     armure     attaque       mana*/
    {"golblin", 5,     5,         5,            5},
    {"cyclope", 15,    10,        10,           2},
    {"elf",     10,    8,         10,           10},
    {"griffon", 10,    8,         9,            11},
    // ajouter
	{0,0,0,0,0},
};

// mobs semi-intel
static semi semi_mobs[] = {
    /* nom      pv     armure     attaque*/
    {"chien",   5,     0,         7},
    {"loup",    10,    0,         10},
    {"vache",   15,    0,         2},
    {"cheval",  10,    0,         2},
    // ajouter
	{0,0,0,0},
};


// mobs 白痴
static idiot idiot_mobs[] = {
    /* nom          pv   attaque*/
    {"pain",        5,   7},
    {"baguette",    10,  10},
    // ajouter
	{0,0,0},
};

#endif // STATS_H
