#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

#define NUM 256

int tokenVal;

int analex(){
    char ch = getchar();

    while(ch == ' ' || ch == '\n' || ch == '\t') ch = getchar();

    if(
        ch == '+' ||
        ch == '-' ||
        ch == '/' ||
        ch == '*' ||
        ch == '(' ||
        ch == ')' ||
        ch == ';'
    ) return ch;

    if(isdigit(ch)){
        tokenVal = ch - '0';
        while(isdigit(ch)){
            tokenVal = tokenVal * 10 + (ch - '0');
            ch = getchar();
        }

        ungetc(ch, stdin);

        return NUM;
    }

    printf("Lexical Error.\n");
    exit(1);
}