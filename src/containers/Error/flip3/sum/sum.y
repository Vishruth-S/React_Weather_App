%{
#include <stdio.h>
#include <stdlib.h>
int yylex();    
int yyerror();
%}
%token NUMBER;
%token MINUS;
%token PLUS;

%%
program: 
    program expr '\n' {printf("\nResult: %d\n", $2);}
    | ;

expr: NUMBER {$$ = $1;}
    | expr PLUS expr {$$ = $1 + $3;}
    | expr MINUS expr {$$ = $1 - $3;}
%%
int main() {
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("\nExpression invalid");
}