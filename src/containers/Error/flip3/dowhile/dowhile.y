%{
#include <stdio.h>

int yylex();
int yyerror(char *s);
%}

%token IF COND SEMICOLON OPEN CLOSE ID NUM OP

%%

program: stmts{printf("accepted");}
    
stmts: IF OPEN conds CLOSE
     ;

conds: lit op lit
    ;

lit: ID
    | NUM

op: OP;

%%

int main() {
    extern FILE *yyin;
    yyin =  fopen("input.txt","r");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("error - %s\n", s);
    return 0;
}