#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PROGSIZE 10240


char* stringify(char c){
	char* s=malloc(2);
	s[0]=c; s[1]=0;
	return s;
}

int main(int argc, char**argv){
	char code[PROGSIZE]; code[0]=0;
	strcpy(code,argv[1]);

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
			printf("%s\n",temp);
			strcpy(temp,"");
		}
		else if(code[i]=='c') l--;
		if(l>0) strcat(temp,stringify(code[i]));
		if(code[i]=='f') l++;

	}
	return 0;
}
