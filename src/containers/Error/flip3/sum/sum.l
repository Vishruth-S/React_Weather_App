%{
#include <stdio.h>    
#include "sum.tab.h"
%}
%%
[0-9]+ {yylval = atoi(yytext); return NUMBER;}
"-" return MINUS;
"+" return PLUS;
[ \t]+ ;
[\n] return *yytext;
%%
int yywrap() {return 1;}
