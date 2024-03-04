#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "com.h"


struct fn* parse(char ic[PROGSIZE]){
	char code[PROGSIZE*15]=" ";
	strcat(code,ic);
	struct fn fun[PROGSIZE];
	static int stack[PROGSIZE];
	static int nameStack[PROGSIZE];
	//fill namestack
	for(int i=0;i<PROGSIZE;i++){
		nameStack[i]=-1;
	}
	int acc=0;
	for(int i=0;i<=PROGSIZE;i++){
		if(acc==256 || acc==-1) acc=0;
		if(code[i]=='i') acc++;
		if(code[i]=='d') acc--;
		if(code[i]=='s') acc*=acc;
		if(code[i]=='f') {
			stack[getLastNonZeroInt(stack)+1]=i;
			nameStack[getLastNonNegativeInt(nameStack)+1]=acc;

		}
		//handle non pairs C's
		if(code[i]=='c' && getLastNonZeroInt(stack)==0){
			// printf("%d,%d do something lol\n", i,getLastNonZeroInt(stack)); - indeed does something\
			//TODO: fix a retarded fuck up
			if(doesFnExist(fun,acc)) strcpy(code,insertSubstrAtIndex(code,fun[getFnIndexByName(fun,acc)].fn,acc));
			printf("\n%s\n", code); exit(1);
		}
		//handle pair C's 
		if(code[i]=='c' && getLastNonNegativeInt(nameStack)>-1){
			fun[fnLastElement(fun)+1].name=nameStack[getLastNonNegativeInt(nameStack)];
			fun[fnLastElement(fun)+1].fn=removeAllInlineBloat(getSubstr(code,stack[getLastNonZeroInt(stack)],i));
			stack[getLastNonZeroInt(stack)]=0;
			nameStack[getLastNonNegativeInt(nameStack)]=-1;
		}
	}
	//printf("\n%d\n",getFnIndexByName(fun,5));
	struct fn*ret=calloc(PROGSIZE,sizeof(struct fn));
	for(int i=0;i<fnLastElement(fun);i++){
		ret[i].name=fun[i].name;
		ret[i].fn=fun[i].fn;
	}
	return ret;
}
