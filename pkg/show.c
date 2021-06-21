#include "stats.h"

// affiche les perso
void show_team(perso **t){
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

// affiche les intel
void show_intel(intel t[]){
	int i = 0;
	char *titre[] = {"nom","pv","armure","attaque","mana"};
	printf("\n");
	printf("------------------------------------------------------------------\n");
	printf("| %*s | %*s | %*s | %*s | %*s |\n",
	-10, titre[0],10,titre[1],10,titre[2],10,titre[3],10,titre[4]);
	printf("------------------------------------------------------------------\n");
	while(t[i].nom != NULL){
		printf("| %-10s | %10d | %10d | %10d | %10d |\n",
		t[i].nom, t[i].maxPV,t[i].armure,t[i].degat, t[i].mana);
		i++;
	}
	printf("------------------------------------------------------------------\n");
}

// affiche les semi
void show_semi(semi t[]){
	int i = 0;
	char *titre[] = {"nom","pv","armure","attaque"};
	printf("\n");
	printf("-----------------------------------------------------\n");
	printf("| %*s | %*s | %*s | %*s |\n",
	-10, titre[0],10,titre[1],10,titre[2],10,titre[3]);
	printf("-----------------------------------------------------\n");
	while(t[i].maxPV != 0){
		printf("| %-10s | %10d | %10d | %10d |\n",
		t[i].nom, t[i].maxPV,t[i].armure,t[i].degat);
		i++;
	}
	printf("-----------------------------------------------------\n");
}

// affiche les idiots
void show_idiot(idiot t[]){
	int i = 0;
	char *titre[] = {"nom","pv","attaque"};
	printf("\n");
	printf("----------------------------------------\n");
	printf("| %*s | %*s | %*s |\n",
	-10, titre[0],10,titre[1],10,titre[2]);
	printf("----------------------------------------\n");
	while(t[i].maxPV != 0){
		printf("| %-10s | %10d | %10d |\n",
		t[i].nom, t[i].maxPV,t[i].degat);
		i++;
	}
	printf("----------------------------------------\n");
}