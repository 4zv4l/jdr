#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "pkg/stats.c"
#include "pkg/show.c"
#define _FLUSH while(getchar()!='\n');

// scan pour un entier
int scan(char* s){
	int buff;
	printf("%s",s);
	while(scanf("%d",&buff) == 0){
		_FLUSH
		printf("%s",s);
	}
	return buff;
}

// demande les infos d'un perso
void ask(intel *p){
	printf("\tnom    : ");
	p->nom = malloc(200); _FLUSH fgets(p->nom, 200, stdin);
	p->nom[strlen(p->nom)-1] = '\0';
	p->maxPV  = scan("\tpv     : ");
	p->armure = scan("\tarmure : ");
	p->degat  = scan("\tdegat  : ");
	p->mana   = scan("\tmana   : ");
}

// créer les perso
intel** init(){
	int nPlayer = scan("How many players : ");
	intel **p = malloc(sizeof(intel)*nPlayer);
	for(int i = 0; i < nPlayer; i++){
		printf("perso %d\t:\n",i+1);
		p[i] = malloc(sizeof(intel));
		ask(p[i]);
	}
	return p;
}

int main(){
	intel **team = init();
	show_team(team);
	show_intel(intel_mobs);
	show_semi(semi_mobs);
	show_idiot(idiot_mobs);
	free(team);
	return 0;
}
