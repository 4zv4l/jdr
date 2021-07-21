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
	shell(team);
	free(team);
	return 0;
}
