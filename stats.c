#include "stats.h"
#include "f.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void show_enemis(intel **t){
	if(t == 0){
		printf("No one to show...\n");
		return;
	}
	int i = 0;
	char *titre[] = {"nom","pv","armure","attaque","mana"};
	printf("\n");
	print_line(56+_NAME_LENGHT);
	printf("| %*s | %*s | %*s | %*s | %*s |\n",
	-_NAME_LENGHT, titre[0],10,titre[1],10,titre[2],10,titre[3],10,titre[4]);
	print_line(56+_NAME_LENGHT);
	while(t[i] != NULL){
		printf("| %*s | %10d | %10d | %10d | %10d | %d\n",
		-_NAME_LENGHT, t[i]->nom, t[i]->maxPV,t[i]->armure,t[i]->degat, t[i]->mana, i);
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
	while(t[i].nom != 0){
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
	while(t[i].nom != 0){
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
	while(t[i].nom != 0){
		printf("| %*s | %10d | %10d |\n",
		-_NAME_LENGHT, t[i].nom, t[i].maxPV,t[i].degat);
		i++;
	}
	print_line(30+_NAME_LENGHT);
}

// return the index of the last item
int inv_last(char** i){
	int n = 0;
	while(i[n]!=0){
		n++;
	}
	return n;
}

// initialise the inventory with INV_SIZE of storage
void inv_init(perso* t){
	t->inv = malloc(sizeof(char*)*INV_SIZE);
	for(int i = 0; i<INV_SIZE;i++){
		t->inv[i] = 0;
	}
	printf("inventory created!\nsize : %d\n",INV_SIZE);
}

// add an item in the inventory
void inv_add(perso* t){
	char* item = malloc(100);
	printf("item to add : ");fgets(item,100,stdin);
	item[strlen(item)-1] = '\0';
	t->inv[inv_last(t->inv)] = item;
	//free(item);
}

// remove an item from the inventory
void inv_rem(perso* t){
	char* item = malloc(100);
	printf("item to del : ");fgets(item,100,stdin);
	item[strlen(item)-1] = '\0';
	printf("-> %s\n",item);
	int i = 0;
	while(t->inv[i]!=0){ // loop until finding the item or not
		if(strcmp(t->inv[i],item) == 0){ // if item found
			while(t->inv[i]!=0){ // swich the indexes to remove the perso
				t->inv[i] = t->inv[i+1];
				i++;
			}
			free(item);
			return;
		}
		i++;
	}
	free(item);
}

// show the inventory
void inv_show(perso* t){
	if(t->inv[0] == 0){
		return;
	}
	int n = 0;
	while(t->inv[n]!=NULL){
		printf("%s\n",t->inv[n]);
		n++;
	}
}

// handle the inventory add/rem/show
void invent(perso** t){
	show_team(t);
	int n;
	n = askName(t, "inventory of who : ");
	if(n == -3){
		return;
	}
	while(n == -1){
		n = askName(t, "inventory of who : ");
		if(n == -3){
			return;
		}
	}
	if(t[n]->inv == 0){
		inv_init(t[n]);
	}
	//inv_show(t[n]);
	char* choice = malloc(100);
	inv_show(t[n]);
	printf("add/rem : "); fgets(choice,100,stdin);
	choice[strlen(choice)-1] = '\0';
	if(strcmp(choice,"add") == 0){
		printf("add\n");
		inv_add(t[n]);
	} else if(strcmp(choice,"rem") == 0){
		printf("rem\n");
		inv_rem(t[n]);
	} else {
		printf("none\n");
	}
	free(choice);
}
