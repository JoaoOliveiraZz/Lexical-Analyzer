#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "analex.h"

#define NUM 256
#define space 

int token;
char infixForm[100];
char number[4];

void E();
void E_();
void T();
void T_();
void F();
void consume(int tokenToConsume);
void syntacticError();
void concatInfixForm(int token);

int main(void){


    token = analex();
    E();
    if(token == ';'){
        printf("No Syntactic Errors!\n");
    }else {
        syntacticError();
    }

    printf("%s", infixForm);
    
    return 0;
}

void E(){
    T();
    E_();
}

void T(){
    F();
    T_();
}

void T_(){
    if(token == '*'){
        consume('*');
        F();
        T_();
        concatInfixForm('*');

        return;
    }
    if(token == '/'){
        consume('/');
        F();
        T_();
        concatInfixForm('/');

        return;
    }

    if(token == ';') return;
    
    
}

void E_(){
    if(token == '+'){
        consume('+');
        T();
        E_();
        concatInfixForm('+');
        return;
    }
    if(token == '-'){
        consume('-');
        T();
        E_();
        concatInfixForm('-');
        return;
    }

    if(token == ';') return;


    
}

void F() {

    if(token == NUM){
        concatInfixForm(NUM);
        consume(NUM);
        return;
    }
    if(token == '('){
        consume('(');
        E();
        consume(')');
        return;
    }

    if(token == ';') return;


    
}

void syntacticError(){
    printf("Syntactic Error.");
    exit(1);
}


void consume(int tokenToConsume) {
    if (token == tokenToConsume) {
        token = analex();
    } else {
        syntacticError();
    }
}

void concatInfixForm(int token){

    if(token == NUM){
        sprintf(number, "%d ", tokenVal);
        strcat(infixForm, number);
        return;
    }

    char character = (char)token;
    strncat(infixForm, &character, 1);
    strcat(infixForm, " ");

}