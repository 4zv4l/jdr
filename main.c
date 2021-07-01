#include "f.h"
#include "save.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _FLUSH while(getchar()!='\n');

void help(){
	printf(
	"Usage :\n"
	"\th      -> show help\n"
	"\tclear  -> clear the screen\n"
	"\texit   -> quit\n"
	"\tbattle -> start a battle\n"
	"\tmodify team :\n"
	"\t\tadd    -> add a perso\n"
	"\t\trem    -> remove a perso\n"
	"\t\torder  -> change order of the team\n"
	"\tshow :\n"
	"\t\tsteam  -> show the team\n"
	"\t\tsintel -> show the team\n"
	"\t\tssemi  -> show the team\n"
	"\t\tssilly -> show the team\n"
	"\tsave :\n"
	"\t\tload   -> load a team from a file\n"
	"\t\tsave   -> save the team for later\n"
	);
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
		} else if(!strcmp(cmd,"battle")){
			if(t == 0){
				printf("No team to battle with...\n");
			}else{
				int diff = scan("Difficulty : ");
				intel **enemis = malloc(sizeof(intel*)*diff+1);
				enemis = init_battle(diff);
				team_round(t,enemis);
				free(enemis);
			}
		} else if(!strcmp(cmd,"rem")){
			rem(t);
		} else if(!strcmp(cmd,"order")){
			set_order(t);
		} else if(!strcmp(cmd,"steam")){
			show_team(t);
		} else if(!strcmp(cmd,"sintel")){
			show_intel(intel_mobs);
		} else if(!strcmp(cmd,"ssemi")){
			show_semi(semi_mobs);
		} else if(!strcmp(cmd,"ssilly")){
			show_idiot(idiot_mobs);
		} else if(!strcmp(cmd,"save")){
			saveForLater(t);
		} else if(!strcmp(cmd,"load")){
			char* fname = malloc(_NAME_LENGHT);
			printf("file : ");
			fgets(fname, _NAME_LENGHT, stdin);
			if(fname[strlen(fname)-1] != '\n')
				_FLUSH
			fname[strlen(fname)-1] = '\0';
			t = loadForNow(fname);
		} else if(!strcmp(cmd,"clear")){
			clear();
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
