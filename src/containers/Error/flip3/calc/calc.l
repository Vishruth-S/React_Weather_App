%{
    #include <stdio.h>
    #include "y.tab.h"
%}
%%
[0-9]+ {yylval = atoi(yytext); return num;}
[a-z] {yylval = *yytext-'a'; return id;}
[ /t]+ ;
[\n] {return *yytext;}
. {return yytext[0];}
%%
int yywrap() {return 1;}