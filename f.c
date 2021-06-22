#include "f.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void clear(){
    system("cls||clear");
}

// scan pour un int + gestion des erreurs
//
// return la valeur obtenu
int scan(char* s){
	int buff;
	printf("%s",s);
	while(scanf("%d",&buff) == 0){
		_FLUSH
		printf("%s",s);
	}
	_FLUSH
	return buff;
}

// demande les infos d'un perso
//
// prend comme argument un pointeur vers un perso
void ask(perso *p){
	printf("\tnom    : ");
	p->nom = malloc(NAME_LENGHT); fgets(p->nom, NAME_LENGHT, stdin);
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
	perso **p = malloc(sizeof(intel)*nPlayer);
	for(int i = 0; i < nPlayer; i++){
		printf("perso %d\t:\n",i+1);
		p[i] = malloc(sizeof(intel));
		ask(p[i]);
	}
	return p;
}

// permet de changer l'ordre de la team
void set_order(perso** t){
    int n,i = 0;
    perso *buff;
    while(t[i]!=NULL){
        clear();
        show_team(t);
        printf("who takes the place of the %d [%s] : ", i+1,t[i]->nom);
        while(scanf("%d",&n)==0){
			printf("who takes the place of the %d [%s] : ", i+1,t[i]->nom);
			while(getchar()!='\n');
		}
        buff = t[i];
        t[i] = t[n-1];
        t[n-1] = buff; 
        i++;
    }
	printf("After order :");
	show_team(t);
}

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