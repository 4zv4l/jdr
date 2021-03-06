#include "stats.h"
#define _FLUSH while(getchar()!='\n');


void help();
int shell(perso**);
int scan(char*);
void ask(perso*, int);
void clear();
perso** init();
intel** init_battle(int);
void print_line(int);
void show_team(perso**);
void show_enemis(intel**);
void show_intel(intel t[]);
void show_semi(semi t[]);
void show_idiot(idiot t[]);

void invent(perso**);
void inv_init(perso*);
void inv_add(perso*);
void inv_rem(perso*);
void inv_show(perso*);


void set_order(perso** t);
void team_round(perso** t, intel** enemis);
int askName(perso** t, char*);
int get_length(perso** t);
void add(perso** t);
void rem(perso** t);

void player_turn(perso**,int,intel**);
int attaque(perso*,intel*, int);
int enemisDown(intel**);
