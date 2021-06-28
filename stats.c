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
	while(t[i].nom != NULL){
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
	while(t[i].maxPV != 0){
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
	while(t[i].maxPV != 0){
		printf("| %*s | %10d | %10d |\n",
		-_NAME_LENGHT, t[i].nom, t[i].maxPV,t[i].degat);
		i++;
	}
	print_line(30+_NAME_LENGHT);
}
