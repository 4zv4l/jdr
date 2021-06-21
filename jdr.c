#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "struct.c"
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
void ask(perso *p){
	printf("\tnom    : ");
	p->nom = malloc(200); _FLUSH fgets(p->nom, 200, stdin);
	p->nom[strlen(p->nom)-1] = '\0';
	p->maxPV  = scan("\tpv     : ");
	p->armure = scan("\tarmure : ");
	p->degat  = scan("\tdegat  : ");
	p->mana   = scan("\tmana   : ");
}

// créer les perso
perso** init(){
	int nPlayer = scan("How many players : ");
	perso **p = malloc(sizeof(perso)*nPlayer);
	for(int i = 0; i < nPlayer; i++){
		printf("perso %d\t:\n",i+1);
		p[i] = malloc(sizeof(perso));
		ask(p[i]);
	}
	return p;
}

// affiche les perso
void show(perso **t){
	int i = 0;
	char *titre[] = {"nom","pv","armure","attaque","mana"};
	printf("\n");
	printf("------------------------------------------------------------------\n");
	printf("| %*s | %*s | %*s | %*s | %*s |\n",
	-10, titre[0],10,titre[1],10,titre[2],10,titre[3],10,titre[4]);
	printf("------------------------------------------------------------------\n");
	while(t[i] != NULL){
		printf("| %-10s | %10d | %10d | %10d | %10d |\n",
		t[i]->nom, t[i]->maxPV,t[i]->armure,t[i]->degat, t[i]->mana);
		i++;
	}
	printf("------------------------------------------------------------------\n");
}

int main(){
	perso **team = init();
	show(team);
	free(team);
	return 0;
}
