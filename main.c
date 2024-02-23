#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PROGSIZE 10240

struct fn {
	int name;
	char* fn;
};

//used to convert char to string to be able to use string.h functions
char* stringify(char c){
	char* s=malloc(2);
	s[0]=c; s[1]=0;
	return s;
}
//finds last occupied element if the array of fn struct
//done this way beacuse ofc C cant have convenient mechanism for this
//and implementing a proper C list is too much job
int fnLastElement(struct fn fun[PROGSIZE]){
	int l=0;
	for(int i=0;i<PROGSIZE;i++){
		if(fun[i].fn!=0) l=i;
	}
	return l;
}
int main(int argc, char**argv){
	char code[PROGSIZE]; code[0]=0;
	strcpy(code,argv[1]);
	
	struct fn fun[PROGSIZE];
	char temp[PROGSIZE]; temp[0]=0;
	int l=0;
	int acc=0;
	for(int i=0;i<=strlen(code);i++){
		if(acc==256 || acc==-1) acc=0;
		if(code[i]=='i') acc++;
		if(code[i]=='d') acc--;
		if(code[i]=='s') acc*=acc;

		if(code[i]=='c' && l==1) {
			l=0;
			fun[fnLastElement(fun)+1].name=acc;
			//strcpy(fun[fnLastElement(fun)+1].fn,temp);
			fun[fnLastElement(fun)+1].fn=temp;
			strcpy(temp,"");
		}
		else if(code[i]=='c' && l>0) l--;
		if(l>0) strcat(temp,stringify(code[i]));

		if(code[i]=='f') l++;
	}
	printf("%u",fnLastElement(fun));
	return 0;
}
