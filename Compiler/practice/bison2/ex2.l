%{
    #include "ex2.tab.h"
    #include <string.h>
%}
%%
\n {
    return (0);
}
[\t]+ {}
[0-9]+ {
    yylval.ival = atoi(yytext);
    return (INUMBER);
}
[a-zA-Z]+ {
    /* action of yytext value to yylval */
    yylval.word = strdup(yytext);
    return (WORD);
}
[\ ] {}
. {
    return (yytext[0]);
}
%%