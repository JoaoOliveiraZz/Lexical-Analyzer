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
    if(token == ';'){
        printf("No Syntactic Errors!\n");
    }else {
        syntacticError();
    }
    
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
        return;
    }
    if(token == '/'){
        consume('/');
        F();
        T_();
        return;
    }

    if(token == ';') return;
    
    
}

void E_(){
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


    
}

void F() {

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