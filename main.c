#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FN 1024


char* charToStr(char c){
	char* s=malloc(2);
	s[0]=c;
	s[1]=c;
	return s;
}
int intStackLastElement(int f[MAX_FN]){
	int i=0;
	while(f[i]!=-1){
		i++;
	}
	return i;
}
int main(int argc, char** argv){
	char prog[] ="fiofifdofdcccicc";
	size_t l=strlen(prog);
	char** fn=malloc(l*MAX_FN);
	int acc=0;
	int fnStack[MAX_FN];
	for(int i=0;i<MAX_FN;i++){
		fnStack[i]=-1;
	}

	for(int i=0;i<l;i++){
		if(acc==-1 || acc==256) acc=0;
		if(prog[i]=='i') acc++;
		if(prog[i]=='d') acc--;
		if(prog[i]=='s') acc=acc*acc;
		if(prog[i]=='o') printf("%u\n",acc);
		if(prog[i]=='f'){
			fnStack[intStackLastElement(fnStack)]=acc;
			fn[acc]=malloc(l);
			fn[acc][0]=0x0;
		}
		if(intStackLastElement(fnStack)>0){
			for(int j=0;j<intStackLastElement(fnStack);j++){
				printf("%d\n",fnStack[j]);
				strcat(fn[fnStack[j]],charToStr(prog[i]));
			}
		}
	}
	for(int i=0;i<1024;i++){
		if(fnStack[i]!=-1)printf("%d: %d > %s\n",i,fnStack[i],fn[fnStack[i]]);
	}
	/*char t[]="sdfsdfsdfsdf";
	printf("\n\n%d\n",nthLastF(t,strlen(t),4));*/
}
