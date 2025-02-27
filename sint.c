#include <stdio.h>
#include <stdlib.h>
#include "analex.h"

#define NUM 256

int token;

void E();
void E_();
void T();
void T_();
void F();
void consume(int tokenToConsume);
void syntacticError();

int main(void){


    token = analex();
    E();

    printf("%d", token);
    if(token == ';'){
        printf("No Syntactic Errors!\n");
    }else {
        syntacticError();
    }
    
    return 0;
}

void E(){
    printf("E\n");
    T();
    E_();
}

void T(){
    printf("T\n");
    F();
    T_();
}

void T_(){
    printf("T_\n");
    if(token == '*'){
        consume('*');
        F();
        T_();
        return;
    }
    if(token == '/'){
        consume('/');
        F();
        T_();
        return;
    }

    if(token == ';') return;

    return;

    syntacticError();
    
}

void E_(){
    printf("E_\n");
    if(token == '+'){
        consume('+');
        T();
        E_();
        return;
    }
    if(token == '-'){
        consume('-');
        T();
        E_();
        return;
    }

    if(token == ';') return;

    return;

    syntacticError();
}

void F() {

    printf("F\n");
    if(token == NUM){
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

    return;

    syntacticError();
}

void syntacticError(){
    printf("Syntactic Error.");
    exit(1);
}


void consume(int tokenToConsume) {
    if (token == tokenToConsume) {
        printf("%d\n", token);
        token = analex();
    } else {
        syntacticError();
    }
}