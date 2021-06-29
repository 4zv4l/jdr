dep = f.c stats.c save.c
ob = f.o stats.o save.o
f = obj/

all: obj main

main:
	@echo Building...
	cc main.c obj/*
	@echo Done!

obj:
	cc -c $(dep)
	mkdir $(f)
	mv *.o $(f)
	@echo object file ready!

debug: obj
	@echo Building...
	cc -g main.c obj/*
	@echo Done!

clean:
	rm -rf $(f) a.out
	@echo project cleaned
# jdr
aide pour jeu de rôle

## stats.h
* contient les structures des personnages
* contient les données relatives aux mobs

## show.c
affiche les personnages et mobs dans un tableau

# TODO
- [x] afficher les perso
- [x] créer les structures
- [x] changer l'odre de la team
- [ ] ajouter des mobs
- [ ] mettre les bonnes caractéristiques aux mobs
- [ ] tour par tour
- [ ] gérer les attaques/défenses/autres

# To compile
`make all`   for common usage
`make obj`   to compile dependences to object files
`make debug` to compile with debug informations
`make clean` clear the binary and object files
#include "f.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// clear the screen
void clear(){
    system("cls||clear");
}

// scan pour un int + gestion des erreurs
//
// return la valeur obtenu
int scan(char* s){
	int buff = -1;
	while(buff < 0){
		printf("%s",s);
		while(scanf("%d",&buff) == 0){
			_FLUSH
			printf("%s",s);
		}
	}
	_FLUSH
	return buff;
}

// demande les infos d'un perso
//
// prend comme argument un pointeur vers un perso
void ask(perso *p, int i){
	printf("perso %d\t:\n",i+1);
	printf("\tnom    : ");
	p->nom = malloc(_NAME_LENGHT); fgets(p->nom, _NAME_LENGHT, stdin);
	if(p->nom[strlen(p->nom)-1] != '\n')
		_FLUSH
	p->nom[strlen(p->nom)-1] = '\0';
	p->maxPV  = scan("\tpv     : ");
	p->armure = scan("\tarmure : ");
	p->degat  = scan("\tdegat  : ");
	p->mana   = scan("\tmana   : ");
}

// créer les perso
//
// return un tableau de perso
perso** init(){
	int nPlayer = scan("How many players : ");
	if(nPlayer == 0){
		return 0;
	}
	perso **p = malloc(sizeof(intel)*nPlayer);
	for(int i = 0; i < nPlayer; i++){
		p[i] = malloc(sizeof(intel));
		ask(p[i],i);
	}
	return p;
}

int get_length(perso **t){
	int i = 0;
	while(t[i]!=NULL){
		i++;
	}
	return i;
}

void add(perso** t){
	clear();
	int index = get_length(t);
	t[index] = malloc(sizeof(perso));
	ask(t[index],index);
}

void rem(perso** t){
	int index = askName(t, "who do you wanna remove : ");
	while(index == -1){
		index = askName(t, "who do you wanna remove : ");
	}
	if(index == -3){
		return;
	}
	while(t[index]!=NULL){ // swich the indexes to remove the perso
		t[index] = t[index+1];
		index++;
	}
}

// ask for a name and return the index of this one
//
// return -1 if not found
//
// return -3 if \n
int askName(perso** t, char* s){
	if(t == 0){
		return -3;
	}
	int i = 0;
	printf("%s",s);
	char* buff = malloc(_NAME_LENGHT); fgets(buff, _NAME_LENGHT, stdin);
	if(!strcmp(buff,"\n")){ // if just press ENTER
		return -3;
	}
	if(buff[strlen(buff)-1] != '\n') // si le nom est trop grand -> vide stdin
		_FLUSH
	buff[strlen(buff)-1] = '\0';
	while(t[i]!=NULL){
		if(!strcmp(buff,t[i]->nom)){ // if name in list of name
			return i;
		}
		i++;
	}
	return -1;
}

// permet de changer l'ordre de la team
void set_order(perso** t){
    int n,i = 0;
	char* ask = malloc(200);
    perso *buff = malloc(sizeof(perso));
    while(t[i]!=NULL){
        clear();
        show_team(t);
		sprintf(ask, "who takes the place of [%s] : ", t[i]->nom);
        n = askName(t, ask);
		if(n != -1 && n != -3) { // switch the two names
        	buff = t[i];
        	t[i] = t[n];
        	t[n] = buff; 
        	i++;
		}
		n == -3 ? i++ : 0;
    }
	clear();
	// printf("After order :");
	// show_team(t);
}

// ask each character what to do
void team_round(perso** t){
	clear();
	show_team(t);
	int i=0,n;
	while(t[i]!=NULL){
		printf("%s's turn :\n",t[i++]->nom);
		printf("\t1. attaque\n");
		printf("\t2. defense\n");
		printf("\t3. rien\n\n");
		n= scan("> ");
		while(n <= 0 && n >= 4){
			n= scan("> ");
		}
		switch (n) {
		case 1:
			printf("Go go go!\n");
			//attaque(t[i]);
			break;
		case 2:
			printf("defending!\n");
			//defense(t[i]);
			break;
		case 3:
			printf("nothing...\n");
			break;
		}
	}
}
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
void add(perso** t);
void rem(perso** t);
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
#include "save.h"
#include "stats.h"
#include "f.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// load from file
perso** loadForNow(char* fname){
	// open the file and print error if cannot open
	FILE* f  = fopen(fname, "r");
	if(f == NULL){
		printf("Error while opening : %s\n",fname);
		return 0;
	}	
	// allocate the memory for the team
	perso** team = malloc(sizeof(perso)*_NPERSO);
	char* line = malloc(_NAME_LENGHT);
	int i = 0;
	// read info from the file
	while(fgets(line, _NAME_LENGHT, f)!=0){
		if(!strcmp(line,"\n")){
			printf("EMPTY LINE\n");
			break;
		}
		line[strlen(line)-1] = '\0';
		team[i] = malloc(sizeof(perso));
		team[i]->nom = malloc(_NAME_LENGHT);
		strcpy(team[i]->nom,line);
		fscanf(f,"%d\n",&team[i]->maxPV);
		fscanf(f,"%d\n",&team[i]->armure);
		fscanf(f,"%d\n",&team[i]->degat);
		fscanf(f,"%d\n",&team[i]->mana);
		// if any negative number
		if(team[i]->maxPV < 0 || team[i]->armure < 0 || team[i]->degat < 0 || team[i]->mana < 0){
			fclose(f);
			printf("Bad file format...\n");
			return 0;
		}
		i++;
	}
	fclose(f);
	return team;
}

// save to file
int saveForLater(perso** t){
	char* fname = malloc(_NAME_LENGHT);
	printf("filename (save) : ");
	fgets(fname, _NAME_LENGHT, stdin);
	fname[strlen(fname)-1] = '\0';
	FILE* f = fopen(fname, "w");
	if(f == NULL){
		printf("Error while opening : %s\n",fname);
		return 1;
	}
	int i = 0;
	while(t[i] != NULL){
		fprintf(f,"%s\n%d\n%d\n%d\n%d\n",t[i]->nom,t[i]->maxPV,t[i]->armure,t[i]->degat,t[i]->mana);
		i++;
	}
	fclose(f);
	return 0;
}
#include "stats.h"

perso** loadForNow(char* fname);
int saveForLater(perso** t);
#include "stats.h"
#include "f.h"
#include<stdio.h>

// show line for the table
void print_line(int n){
	for(int i=0; i<n;i++){
		printf("-");
	}
	printf("\n");
}

// affiche les perso
void show_team(perso **t){
	if(t == 0){
		printf("No one to show...\n");
		return;
	}
	clear();
	int i = 0;
	char *titre[] = {"nom","pv","armure","attaque","mana"};
	printf("\n");
	print_line(56+_NAME_LENGHT);
	printf("| %*s | %*s | %*s | %*s | %*s |\n",
	-_NAME_LENGHT, titre[0],10,titre[1],10,titre[2],10,titre[3],10,titre[4]);
	print_line(56+_NAME_LENGHT);
	while(t[i] != NULL){
		printf("| %*s | %10d | %10d | %10d | %10d |\n",
		-_NAME_LENGHT, t[i]->nom, t[i]->maxPV,t[i]->armure,t[i]->degat, t[i]->mana);
		i++;
	}
	print_line(56+_NAME_LENGHT);
}

// affiche les intel
void show_intel(intel t[]){
	int i = 0;
	char *titre[] = {"nom","pv","armure","attaque","mana"};
	printf("\n");
	print_line(56+_NAME_LENGHT);
	printf("| %*s | %*s | %*s | %*s | %*s |\n",
	-_NAME_LENGHT, titre[0],10,titre[1],10,titre[2],10,titre[3],10,titre[4]);
	print_line(56+_NAME_LENGHT);
	while(t[i].nom != 0){
		printf("| %*s | %10d | %10d | %10d | %10d |\n",
		-_NAME_LENGHT, t[i].nom, t[i].maxPV,t[i].armure,t[i].degat, t[i].mana);
		i++;
	}
	print_line(56+_NAME_LENGHT);
}

// affiche les semi
void show_semi(semi t[]){
	int i = 0;
	char *titre[] = {"nom","pv","armure","attaque"};
	printf("\n");
	print_line(43+_NAME_LENGHT);
	printf("| %*s | %*s | %*s | %*s |\n",
	-_NAME_LENGHT, titre[0],10,titre[1],10,titre[2],10,titre[3]);
	print_line(43+_NAME_LENGHT);
	while(t[i].nom != 0){
		printf("| %*s | %10d | %10d | %10d |\n",
		-_NAME_LENGHT, t[i].nom, t[i].maxPV,t[i].armure,t[i].degat);
		i++;
	}
	print_line(43+_NAME_LENGHT);
}

// affiche les idiots
void show_idiot(idiot t[]){
	int i = 0;
	char *titre[] = {"nom","pv","attaque"};
	printf("\n");
	print_line(30+_NAME_LENGHT);
	printf("| %*s | %*s | %*s |\n",
	-_NAME_LENGHT, titre[0],10,titre[1],10,titre[2]);
	print_line(30+_NAME_LENGHT);
	while(t[i].nom != 0){
		printf("| %*s | %10d | %10d |\n",
		-_NAME_LENGHT, t[i].nom, t[i].maxPV,t[i].degat);
		i++;
	}
	print_line(30+_NAME_LENGHT);
}
#ifndef STATS_H
#define STATS_H
#define _NAME_LENGHT 15
#define _NPERSO 20


// stats intelligent
typedef struct perso{
	char* nom;
	int maxPV;
	int armure;
	int degat;
	int mana;
} perso;

// stats intelligent
typedef struct intel{
	const char* nom;
	int maxPV;
	int armure;
	int degat;
	int mana;
} intel;

// stats semi semi
typedef struct semi{
	const char* nom;
	int maxPV;
	int armure;
	int degat;
} semi;

// stats semi idiot
typedef struct idiot{
	const char* nom;
	int maxPV;
	int degat;
} idiot;

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
