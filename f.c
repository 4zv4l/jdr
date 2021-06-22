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
        scanf("%d",&n);
        buff = t[i];
        t[i] = t[n-1];
        t[n-1] = buff; 
        i++;
    }
}