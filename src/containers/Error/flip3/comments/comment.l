%{
    #include<stdio.h>
    int comment = 0;
%}
%%
\/\/(.*) {};					
\/\*(.*\n)*.*\*\/  {};			
%%
int main() {
    extern FILE *yyin;
    yyin = fopen("input.txt","r");
    yylex();
    return 0;
}
int yywrap() {return 1;}