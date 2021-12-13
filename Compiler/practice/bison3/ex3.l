%{
    #include <string.h>
    #include "ex3.tab.h"
%}
digits [0-9]*
num {digits}(\.{digits})?
op [\+\-\*\/]
brac [\(\)]
%%

{num} {
    yylval.dval = atof(yytext);
    return (NUM);
    // ECHO;
    // printf ("\n");
}
{op} {
    // ECHO;
    // printf ("\n");
    return (yytext[0]);
}
{brac} {
    return (yytext[0]);
}
\n {
    return (0);
}
. {
    return (yytext[0]);
}

%%

