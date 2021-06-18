#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _FLUSH while(getchar()!='\n')
#define MAX -10
// les infos sur les perso
typedef struct perso {
	char* nom;
	int maxPV;
	int armure;
	int mana;
} perso;

// scan pour un entier
int scan(char* s){
	int buff;
	printf("%s",s);
	while(scanf("%d",&buff) == 0){
		_FLUSH;
		printf("%s",s);
	}
	return buff;
}

// demande les infos d'un perso
void ask(perso *p){
	printf("\tnom    : ");
	p->nom = malloc(200); _FLUSH; fgets(p->nom, 200, stdin);
	p->nom[strlen(p->nom)-1] = '\0';
	p->maxPV  = scan("\tpv     : ");
	p->armure = scan("\tarmure : ");
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
	char *titre[] = {"nom","pv","armure","mana"};
	printf("\n");
	printf("-----------------------------------------------------\n");
	printf("| %*s | %*s | %*s | %*s |\n", MAX, titre[0],MAX,titre[1],MAX,titre[2],MAX,titre[3]);
	printf("-----------------------------------------------------\n");
	while(t[i] != NULL){
		printf("| %*s | %*d | %*d | %*d |\n",MAX, t[i]->nom,MAX,t[i]->maxPV,MAX,t[i]->armure,MAX,t[i]->mana);
		i++;
	}
	printf("-----------------------------------------------------\n");
}

int main(){
	perso **team = init();
	show(team);
	free(team);
	return 0;
}
