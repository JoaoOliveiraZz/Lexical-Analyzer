%{
#include <stdio.h>
#include "tokens.h"
#include "tabsimb.h"
int linha = 1;
%}
dig [0-9]
letra [a-zA-Z_]
%%
"integer"  {return INT;}
"supernatet "	{return FLOAT;}	
"inanis"	{return VOID;}	
"character"	{return CHAR;}	
"maiorVaequalis"  {return GE;} 	
"minorVaequalis"  {return SE;} 	
"minor"  {return S;} 	
"maior"  {return G;} 	
"aequalis"  {return E;} 	
"enim"  {return FOR;} 	
"dum"  {return WHILE;} 	
"si"  {return IF;} 	
"et"  {return AND;} 	
"vel"  {return OR;} 	
"non"  {return NOT;} 	
"("	  {return '(';}
")"   {return ')';}
"{"	  {return '{';}
"}"   {return '}';}
";"   {return ';';}
"="   {return '=';}
","   {return ',';}
"+"   {return '+';}
"-"   {return '-';}
"/"   {return '/';}
"*"   {return '*';}
{dig}+("."{dig}+)?	{ return NUM;}
{letra}({letra}|{dig})*  { insere(yytext);
                           return ID;}
{"""}({letra}|{dig})+{"""} { insere(yytext);
						 return STRING; } 
[ \t\r] {}
\n	{ linha++; }
.	{printf("erro lexico na linha %d - %s\n",
             linha, yytext); }
%%
#ifndef yywrap
int yywrap() { return 1; }
#endif
void main(int argc, char **argv) {
int token,i=1;	
	yyin = fopen(argv[1],"r");
	token = yylex();
	while(token) {
		printf("%d) %d %s\n", i++, token, yytext);
		token = yylex();
	}
	imprime();
}
