#include "f.h"
#include "save.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _FLUSH while(getchar()!='\n');

int main(int argc, char** argv){
	clear();
	perso **team;
	if(argc >= 2){
		team = loadForNow(argv[1]);
	}
	char g
	printf("Bonjour! L'assistant de combat est pret, voulez-vous commencer?\n 1: oui\n 2: non\n");
	scanf("%c", &g);
	if (g!=1)
		break;
	shell(team);
	free(team);
	return 0;
}
