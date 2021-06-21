#include<stdlib.h>
#include<string.h>
#include "pkg/show.c"
#define _FLUSH while(getchar()!='\n');

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
// return un tableau de pointeurs
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

int main(){
	perso **team = init();
	show_team(team);
	show_intel(intel_mobs);
	show_semi(semi_mobs);
	show_idiot(idiot_mobs);
	free(team);
	return 0;
}
