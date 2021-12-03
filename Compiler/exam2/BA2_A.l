
digit [0-9]
sign [-+]
digits {digit}+
limit ({digits}\.{digits}?|{digits}?\.{digits})
limit_line ^{limit}\n
science_line ^({digits}|{limit})(e|E)({sign}?{digits})\n

%%

{limit_line} {ECHO;}
{science_line} {ECHO;}
\n {}
. {}

%%

int main(void) {
    yylex();
    return(0);
}