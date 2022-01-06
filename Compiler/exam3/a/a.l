%{
    #include "a.tab.h"
%}

NUM [0-9]+

%% 

push {return PUSH;}
inverse {return INVERSE;}
inc {return INC;}
dec {return DEC;}

"$" {return yytext[0];}
{NUM} {
    yylval.ival = atoi(yytext);
    return VALUE;
}

.|\n {}

%%