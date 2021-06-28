#include "f.h"
#include "save.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _FLUSH while(getchar()!='\n');

int main(int argc, char** argv){
	clear();
	perso **team;
	if(argc >= 2){
		team = loadForNow(argv[1]);
	}
	if(team == NULL){
		team = init();
	}

	//show_team(team);
	//show_intel(intel_mobs);
	//show_semi(semi_mobs);
	//show_idiot(idiot_mobs);

/*
inclure une sorte de shell pour 
	- lancer un combat
	- sauvegarder
	- changer les stats des joueurs
*/

	set_order(team);
	//team_round(team);
	add(team);
	set_order(team);
	scan("Do you wanna save (1YES/2NO): ")==1 ? saveForLater(team) : 0;
	free(team);
	return 0;
}
