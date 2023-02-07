%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
"if" {return IF;}
\( {return OPEN;}
\) {return CLOSE;}
; {return SEMICOLON;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}
[0-9]+ {return NUM;}
">"|"<"|">="|"<="|"==" {return OP;}
[ \t] ;
"\n" {return 0;}
%%
int yywrap() {return 1;}