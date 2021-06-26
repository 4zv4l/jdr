#include "save.h"
#include<stdio.h>

// load from file
perso** loadForNow(char* fname){
	FILE* f  = fopen(fname, "rb");
	if(f == NULL){
		printf("Error while opening : %s\n",fname);
		return 0;
	}
	return 0;
}

// save to file
perso** saveForLater(char* f);
