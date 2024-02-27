#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
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
//gets substring in defined interval
char* getSubstr(char str[PROGSIZE], int s, int e){
	char* o=malloc(PROGSIZE); o[0]=0;
	for(;s<=e;s++){
		strcat(o,stringify(str[s]));
	}
	return o;
}
//last non zero.. INDEX, the name would be too long
int getLastNonZeroInt(int arr[PROGSIZE]){
	int o=0;
	for(int i=0;i<PROGSIZE;i++){
		if(arr[i]!=0) o=i;
	}
	return o;
}
//'bloat' being considered all other 'f's and 'c's
char* removeAllInlineBloat(char str[PROGSIZE]){
	char* w=malloc(PROGSIZE); w[0]=0;
	strcpy(w,getSubstr(str,1,strlen(str)-1)); //do i have to do this??
	int lc=0;
	for(int i=0;i<PROGSIZE;i++){
		if(w[i]=='c') lc=i;
	}
	int ff=false;
	char*t=malloc(PROGSIZE); t[0]=0; //uhhh...
	for(int i=0;i<PROGSIZE;i++){
		if(w[i]=='f') ff=true;
		if(!ff) strcat(t,stringify(w[i]));
		if(i==lc) ff=false;
	}

	return t;

}
int main(int argc, char**argv){
	char code[PROGSIZE]; code[0]=0;
	//pads the array by one space for.. reasons
	strcat(code," ");
	strcat(code,argv[1]);
	struct fn fun[PROGSIZE];
	static int stack[PROGSIZE];
	int acc=0;
	for(int i=0;i<=strlen(code);i++){
		if(acc==256 || acc==-1) acc=0;
		if(code[i]=='i') acc++;
		if(code[i]=='d') acc--;
		if(code[i]=='s') acc*=acc;
		if(code[i]=='f') stack[getLastNonZeroInt(stack)+1]=i;
		if(code[i]=='c'){
			printf("%s\n",removeAllInlineBloat(getSubstr(code,stack[getLastNonZeroInt(stack)],i)));
			stack[getLastNonZeroInt(stack)]=0;
		}

	}
	return 0;
}
