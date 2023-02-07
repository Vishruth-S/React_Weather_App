%{
    #include <stdio.h>
    #include <stdlib.h>
    int yyerror();
    int yylex();
    int sym[26];
%}
%token num id
%left '(' ')'
%left '+' '-'
%left '*' '/'
%%
program: program stmt '\n'
    | ;

stmt: expr {printf("\nResult: %d\n", $1);}
    | id '=' expr {sym[$1] = $3;}

expr: expr '+' term {$$ = $1 + $3;}
    | expr '-' term {$$ = $1 - $3;}
    | expr '*' term {$$ = $1 * $3;}
    | expr '/' term {$$ = $1 / $3;}
    | term {$$ = $1;}
    ;

term:'(' expr ')' {$$ = $2;}
    | id {$$ = sym[$1];}
    | num {$$ = $1;}
    ;

%%
int main() {
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Error");
}