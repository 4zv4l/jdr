#include "f.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _FLUSH while(getchar()!='\n');

int main(){
	clear();
	perso **team = init();
	//show_team(team);
	//show_intel(intel_mobs);
	//show_semi(semi_mobs);
	//show_idiot(idiot_mobs);
	set_order(team);
	printf("After order :\n");
	show_team(team);
	free(team);
	return 0;
}
