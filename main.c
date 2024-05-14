#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//a retarded workaround to try to avoid using stack
int nthLastF(char s[],int i,int n){
	while(i>=0){
		if(s[i]=='f' && n!=0) n--;
		else if(s[i]=='f' && n==0) return i;
		i--;
	}
	return -1;
}
int main(int argc, char** argv){
	char prog[] ="iifiiiocdic";
	size_t l=strlen(prog);
	char** fn=malloc(l*l);
	int acc=0;
	int lastFn=-1;
	for(int i=0;i<l;i++){
		if(acc==-1 || acc==256) acc=0;
		if(prog[i]=='i') acc++;
		if(prog[i]=='d') acc--;
		if(prog[i]=='s') acc=acc*acc;
		if(prog[i]=='o') printf("%u\n",acc);

	}
	/*char t[]="sdfsdfsdfsdf";
	printf("\n\n%d\n",nthLastF(t,strlen(t),4));*/
}
