#include "f.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _FLUSH while(getchar()!='\n');

int main(){
	clear();
	//perso **team = init();
	perso **team = malloc(sizeof(perso)*3);

	team[0] = malloc(sizeof(perso));
	team[0]->nom = "Azz";
	team[0]->armure = 1;
	team[0]->degat = 1;
	team[0]->mana = 1;
	team[0]->maxPV = 1;

	team[1] = malloc(sizeof(perso));
	team[1]->nom = "Mega";
	team[1]->armure = 1;
	team[1]->degat = 1;
	team[1]->mana = 1;
	team[1]->maxPV = 1;
	//show_team(team);
	//show_intel(intel_mobs);
	//show_semi(semi_mobs);
	//show_idiot(idiot_mobs);
	set_order(team);
	team_round(team);
	//free(team);
	return 0;
}
