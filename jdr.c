#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _FLUSH while(getchar()!='\n')

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
	printf("\n");
	printf("-----------------------------------------------------------------\n");
	printf("| nom\t\t| pv\t\t| armure\t| mana\t\t|\n");
	printf("-----------------------------------------------------------------\n");
	while(t[i] != NULL){
		printf("| %s\t\t| %d\t\t| %d\t\t| %d\t\t|\n",t[i]->nom,t[i]->maxPV,t[i]->armure,t[i]->mana);
		i++;
	}
	printf("-----------------------------------------------------------------\n");
}

int main(){
	perso **team = init();
	show(team);
	free(team);
	return 0;
}
