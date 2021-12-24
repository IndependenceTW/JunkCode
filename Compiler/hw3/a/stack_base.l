%{
    #include "stack_base.tab.h"
%}

NUM [0-9]+

%%

load {
    return (LOAD);
}

add {
    return (ADD);
}

sub {
    return (SUB);
}

mul {
    return (MUL);
}

mod {
    return (MOD);
}

inc {
    return (INC);
}

dec {
    return (DEC);
}

{NUM} {
    yylval.ival = atoi(yytext);
    return (VALUE);
}

.|\n {}
%%
