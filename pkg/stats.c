// stats intelligent
typedef struct intel{
	char* nom;
	int maxPV;
	int armure;
	int degat;
	int mana;
} intel;

// stats semi semi
typedef struct semi{
	char* nom;
	int maxPV;
	int armure;
	int degat;
} semi;

// stats semi idiot
typedef struct idiot{
	char* nom;
	int maxPV;
	int degat;
} idiot;

// semi-intélligent stats
static intel intel_mobs[] = {
    /* nom      pv     armure     attaque       mana*/
    {"golblin", 5,     5,         5,            5},
    {"cyclope", 15,    10,        10,           2},
    // ajouter
};

static semi semi_mobs[] = {
    /* nom      pv     armure     attaque*/
    {"chien",   5,     0,         7},
    {"loup",    10,    0,         10},
    // ajouter
};

static idiot idiot_mobs[] = {
    /* nom          pv   attaque*/
    {"pain",        5,   7},
    {"baguette",    10,  10},
    // ajouter
};