#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define PROGSIZE 10240

struct fn {
        int name;
        char* fn;
};

//used to convert char to string to be able to use string.h functions
char* stringify(char c){
        char* s=(char *) malloc(2);
        s[0]=c; s[1]=0;
        return s;
}
//gets substring in defined interval
char* getSubstr(char* str, int s, int e){
        char* o=(char *) malloc(PROGSIZE); o[0]=0;
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
//same
int getLastNonNegativeInt(int arr[PROGSIZE]){
        int o=0;
        for(int i=0;i<PROGSIZE;i++){
                if(arr[i]>-1) o=i;
        }
        return o;
}
int fnLastElement(struct fn fun[PROGSIZE]){
        int l=0;
        for(int i=0;i<PROGSIZE;i++){
                if(fun[i].fn!=0) l=i;
        }
        return l;
}

//'bloat' being considered all other 'f's and 'c's
char* removeAllInlineBloat(char* str){
        strcpy(str,getSubstr(str,1,strlen(str)-1)); //do i have to do this??
        int ff=false;
        char*t=(char *) malloc(PROGSIZE); t[0]=0; //uhhh...
        for(int i=0;i<PROGSIZE;i++){

                if(str[i]=='f') ff=true;
                if(!ff && str[i]!='c') strcat(t,stringify(str[i]));
                if(str[i]=='c') ff=false;
        }

        return t;

}
//for debugging
void printAllFuns(struct fn fun[PROGSIZE]){
        for(int i=0;i<=fnLastElement(fun);i++){
                if(fun[i].fn!=0) printf("%u => %s \n", fun[i].name, fun[i].fn);
        }
}
char* insertSubstrAtIndex(char* i,char* t, int n){
        char* o=(char*) malloc(strlen(i)+strlen(t)+5); //+5 coz why the fuck not..
        o[0]=0;
        strncpy(o,i,n);
        strcat(o,t);
        strcat(o,getSubstr(i,n+1,strlen(i)));
        return o;
}
bool doesFnExist(struct fn fun[PROGSIZE],int n){
        for(int i=0;i<PROGSIZE;i++){
                if(fun[i].name==n) return true;
        }
        return false;
}
int getFnIndexByName(struct fn fun[PROGSIZE], int n){
        //doing this too often, eh?
        for(int i=0;i<PROGSIZE;i++){
                if(fun[i].name==n) return i;
        }
        return -1;
}

