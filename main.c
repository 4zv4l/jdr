#include "f.h"
#include "save.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _FLUSH while(getchar()!='\n');

void help(){
	printf("Usage :\n"
	"\th     -> show help\n"
	"\tadd   -> add a perso\n"
	"\trem   -> remove a perso\n"
	"\tshow  -> show the team\n"
	"\tsave  -> save the team for later\n"
	"\tclear -> clear the screen\n"
	"\texit  -> quit\n");
}

// allow the user to type command to interact with the program
int shell(perso** t){
	char* cmd = malloc(_NAME_LENGHT);
	while(strcmp(cmd,"exit")){
		printf("(h for help)> ");
		fgets(cmd, _NAME_LENGHT, stdin);
		if(cmd[strlen(cmd)-1] != '\n')
			_FLUSH
		cmd[strlen(cmd)-1] = '\0';
		if(!strcmp(cmd,"h")){
			help();
		} else if(!strcmp(cmd,"add")){
			if(t == 0){
				t = init();
			}else{
				add(t);
			}
		} else if(!strcmp(cmd,"rem")){
			rem(t);
		} else if(!strcmp(cmd,"show")){
			show_team(t);
		} else if(!strcmp(cmd,"save")){
			saveForLater(t);
		}else if(!strcmp(cmd,"clear")){
			clear();
		} else if(strcmp(cmd,"exit")){
			printf("%s : Command not found...\n", cmd);
		}
	}
	free(cmd);
	return 0;
}

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
	shell(team);
	//set_order(team);
	//team_round(team);
	//rem(team);
	//add(team);
	//scan("Do you wanna save (1YES/2NO): ")==1 ? saveForLater(team) : 0;
	free(team);
	return 0;
}
