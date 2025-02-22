#include<stdio.h>
#include<stdlib.h>

#define NUM 256

int tokenVal;

int isDigit(char digit){

    if(digit > 48 && digit < 58){
        return 1;
    }

    return 0;

}

int analex(){

    char ch = getchar();

    if(
        ch == '+' ||
        ch == '-' ||
        ch == '/' ||
        ch == '*' ||
        ch == '(' ||
        ch == ')' ||
        ch == ';'
    ) return ch;

    if(isDigit(ch)) return NUM;

    printf("Lexical Error, invalid token.\n");

}