#include "stats.h"
#define _FLUSH while(getchar()!='\n');

int scan(char*);
void ask(perso*, int);
void clear();
perso** init();
void print_line(int);
void show_team(perso**);
void show_intel(intel t[]);
void show_semi(semi t[]);
void show_idiot(idiot t[]);
void set_order(perso** t);
void team_round(perso** t);
int askName(perso** t, char*);
int get_length(perso** t);
void add (perso** t);
