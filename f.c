#include "f.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

static int size_enemis;

// clear the screen
void clear(){
    system("cls||clear");
}

// scan pour un int + gestion des erreurs
//
// return la valeur obtenu
int scan(char* s){
	int buff = -1;
	while(buff < 0){
		printf("%s",s);
		while(scanf("%d",&buff) == 0){
			_FLUSH
			printf("%s",s);
		}
	}
	_FLUSH
	return buff;
}

// demande les infos d'un perso
//
// prend comme argument un pointeur vers un perso
void ask(perso *p, int i){
	printf("perso %d\t:\n",i+1);
	printf("\tnom    : ");
	p->nom = malloc(_NAME_LENGHT); fgets(p->nom, _NAME_LENGHT, stdin);
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
// return un tableau de perso
perso** init(){
	int nPlayer = scan("How many players : ");
	if(nPlayer == 0){
		return 0;
	}
	perso **p = malloc(sizeof(intel)*nPlayer);
	for(int i = 0; i < nPlayer; i++){
		p[i] = malloc(sizeof(intel));
		ask(p[i],i);
		p[i]->inv = 0;
	}
	return p;
}

// return the length of the perso array
int get_length(perso **t){
	int i = 0;
	while(t[i]!=NULL){
		i++;
	}
	return i;
}

// add a perso
void add(perso** t){
	clear();
	int index = get_length(t);
	t[index] = malloc(sizeof(perso));
	ask(t[index],index);
}

// remove a perso
void rem(perso** t){
	int index = askName(t, "who do you wanna remove : ");
	while(index == -1){
		index = askName(t, "who do you wanna remove : ");
	}
	if(index == -3){
		return;
	}
	while(t[index]!=NULL){ // swich the indexes to remove the perso
		t[index] = t[index+1];
		index++;
	}
}

// ask for a name and return the index of this one
//
// return -1 if not found
//
// return -3 if \n
int askName(perso** t, char* s){
	if(t == 0){
		return -3;
	}
	int i = 0;
	printf("%s",s);
	char* buff = malloc(_NAME_LENGHT); fgets(buff, _NAME_LENGHT, stdin);
	if(!strcmp(buff,"\n")){ // if just press ENTER
		return -3;
	}
	if(buff[strlen(buff)-1] != '\n') // si le nom est trop grand -> vide stdin
		_FLUSH
	buff[strlen(buff)-1] = '\0';
	while(t[i]!=NULL){
		if(!strcmp(buff,t[i]->nom)){ // if name in list of name
			return i;
		}
		i++;
	}
	return -1;
}

// permet de changer l'ordre de la team
void set_order(perso** t){
    int n,i = 0;
	char* ask = malloc(200);
    perso *buff = malloc(sizeof(perso));
    while(t[i]!=NULL){
        clear();
        show_team(t);
		sprintf(ask, "who takes the place of [%s] : ", t[i]->nom);
        n = askName(t, ask);
		if(n != -1 && n != -3) { // switch the two names
        	buff = t[i];
        	t[i] = t[n];
        	t[n] = buff; 
        	i++;
		}
		n == -3 ? i++ : 0;
    }
	clear();
	// printf("After order :");
	// show_team(t);
}

// initialise the battle choosing random enemis
intel** init_battle(int diff){
	if(diff == 0){
		printf("combat with 0 mob isn't allowed...\n");
		diff = 2;
	}
	size_enemis = diff;
	srand(time(NULL));
	int i,j;
	int size = sizeof(intel_mobs)/sizeof(intel_mobs[0]);
	size--;
	intel** mobs = malloc(sizeof(intel*)*diff+1);
	for(i = 0; i<diff;i++){
		j = (rand()%size);
		//memcpy(mobs[i],&intel_mobs[j],sizeof(intel));
		//mobs[i] = &intel_mobs[j];
		mobs[i] = malloc(sizeof(intel));
		mobs[i]->nom = malloc(_NAME_LENGHT);
		mobs[i]->nom = intel_mobs[j].nom;
		mobs[i]->maxPV = intel_mobs[j].maxPV;
		mobs[i]->armure = intel_mobs[j].armure;
		mobs[i]->degat = intel_mobs[j].degat;
		mobs[i]->mana = intel_mobs[j].mana;
	
	}
	mobs[diff] = 0;
	return mobs;
}

// remove life
//
// who is to know who attaque who
//
// 1 -> p; 0 -> i
int attaque(perso* p, intel* i,int who){
	if(p->maxPV == 0 || i->maxPV == 0){
		return -1;
	}
	if(who == 1){
		i->maxPV -= p->degat;
		if(i->maxPV < 0){
			i->maxPV = 0;
		}
	} else {
		p->maxPV -= i->degat;
		if(p->maxPV < 0){
			p->maxPV = 0;
		}
	}
	printf("%s -> %dpv\n%s -> %dpv\n",
			p->nom,p->maxPV,
			i->nom,i->maxPV);
	return 0;
}

// ask players what to do until all enemis are dead
void player_turn(perso** t, int i, intel** e){
	int n;
	while(t[i]!=NULL){
		printf(
		"%s's turn :\n"
		"\t1. attaque\n"
		"\t2. defense\n"
		"\t3. rien\n"
		, t[i]->nom);
		n=scan("> ");
		while(n <= 0 || n >= 4){
			n = scan("> ");
		}
		switch (n) {
		case 1:
			printf("Go go go %s\n",t[i]->nom);
			n = scan("which enemi : ");
			while(n < 0 || n > size_enemis-1){
				n = scan("which enemi : ");
			}
			while(attaque(t[i],e[n],1)!=0){
				n = scan("which enemi : ");
				while(n < 0 || n > size_enemis-1){
					n = scan("which enemi : ");
				}
				attaque(t[i], e[n],1);
			}
			break;
		case 2:
			printf("defending!\n");
			//defense(t[i]);
			break;
		case 3:
			printf("nothing...\n");
			break;
		}
		i++;
		show_enemis(e);
	}

}

// return -1 if all enemis aren't down
//
// return 0 if all enemis are down
int enemisDown(intel** e){
	int i=0;
	while(e[i]!=NULL){
		if(e[i]->maxPV != 0){
			return -1;
		}
		i++;
	}
	return 0;
}

// handle the battle
void team_round(perso** t, intel** e){
	clear();
	show_team(t);
	printf("VS\n");
	show_enemis(e);
	int i,n;
	while(enemisDown(e)!=0){
		i = 0;
		player_turn(t,i,e);
	}
	printf("all enemis are dead...\n");
}
