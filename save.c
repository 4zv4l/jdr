#include "save.h"
#include "stats.h"
#include "f.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// load from file
perso** loadForNow(char* fname){
	// open the file and print error if cannot open
	FILE* f  = fopen(fname, "r");
	if(f == NULL){
		printf("Error while opening : %s\n",fname);
		return 0;
	}	
	// allocate the memory for the team
	perso** team = malloc(sizeof(perso)*_NPERSO);
	char* line = malloc(_NAME_LENGHT);
	int i = 0;
	// read info from the file
	while(fgets(line, _NAME_LENGHT, f)!=0){
		if(!strcmp(line,"\n")){
			printf("EMPTY LINE\n");
			break;
		}
		line[strlen(line)-1] = '\0';
		printf("-> %s\n",line);
		team[i] = malloc(sizeof(perso));
		team[i]->nom = malloc(_NAME_LENGHT);
		strcpy(team[i]->nom,line);
		fscanf(f,"%d\n",&team[i]->maxPV);
		fscanf(f,"%d\n",&team[i]->armure);
		fscanf(f,"%d\n",&team[i]->degat);
		fscanf(f,"%d\n",&team[i]->mana);
		int j = 0; // index of item
		char* inv = malloc(100); // buff for inventory
		// init the inventory of the current user
		team[i]->inv = malloc(INV_SIZE);
		fgets(inv, 100,f);
		inv[strlen(inv)-1] = '\0';
		while(strcmp(inv,"-1") != 0){ // -1 stop the loop
			team[i]->inv[j] = malloc(INV_SIZE);
			strcpy(team[i]->inv[j],inv);
			fgets(inv,INV_SIZE,f);
			inv[strlen(inv)-1] = '\0';
			j++;
		}
		free(inv); // free the buffer inv
		// if any negative number	
		if(team[i]->maxPV < 0 || team[i]->armure < 0 || team[i]->degat < 0 || team[i]->mana < 0){
			fclose(f);
			printf("Bad file format...\n");
			return 0;
		}
		
		i++;
	}
	free(line);
	fclose(f);
	return team;
}

// save to file
int saveForLater(perso** t){
	char* fname = malloc(_NAME_LENGHT);
	printf("filename (save) : ");
	fgets(fname, _NAME_LENGHT, stdin);
	fname[strlen(fname)-1] = '\0';
	FILE* f = fopen(fname, "w");
	if(f == NULL){
		printf("Error while opening : %s\n",fname);
		return 1;
	}
	int i = 0;
	while(t[i] != NULL){
		fprintf(f,"%s\n%d\n%d\n%d\n%d\n",t[i]->nom,t[i]->maxPV,t[i]->armure,t[i]->degat,t[i]->mana);
		if(t[i]->inv != 0){ // if inv not created
			int j = 0;
			while(t[i]->inv[j]!=0){
				fprintf(f,"%s\n",t[i]->inv[j]);
				j++;
			}
		}
			fprintf(f,"-1\n");
			i++;
	}
	fclose(f);
	return 0;
}
