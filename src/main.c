#include "parse.c"
#include <stdio.h>
#include <string.h>
int main(int argc, char** argv){
	char code[PROGSIZE]; code[0]=0;
	strcpy(code,argv[1]);
	if(argc>1){
		printAllFuns(parse(code));
	}
	else {
		printf("too little arguments");
		return 1;
	}
	return 0;
}
