#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "com.h"

char* insertSubstrAtIndex(char* i,char* t, int n){
	char* o=malloc(strlen(i)+strlen(t)+5); //+5 coz why the fuck not..
	o[0]=0;
	strncpy(o,i,n);
	strcat(o,t);
	strcat(o,getSubstr(i,n+1,strlen(i)));
	return o;
}



struct fn* parse(char ic[PROGSIZE]){
	printf("%s",insertSubstrAtIndex("hello world"," kys ",5));
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
		//TODO handle non pair 'c's
		if(code[i]=='c' && getLastNonNegativeInt(nameStack)>-1){
			fun[fnLastElement(fun)+1].name=nameStack[getLastNonNegativeInt(nameStack)];
			fun[fnLastElement(fun)+1].fn=removeAllInlineBloat(getSubstr(code,stack[getLastNonZeroInt(stack)],i));
			stack[getLastNonZeroInt(stack)]=0;
			nameStack[getLastNonNegativeInt(nameStack)]=-1;
		}
		else if(code[i]=='c') printf("do something lol");

	}
	struct fn*ret=calloc(PROGSIZE,sizeof(struct fn));
	for(int i=0;i<PROGSIZE;i++){
		ret[i].name=fun[i].name;
		ret[i].fn=fun[i].fn;
	}
	return ret;
}
