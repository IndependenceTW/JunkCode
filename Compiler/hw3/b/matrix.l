%{
    #include "matrix.tab.h"
    int col = 0;
%}

%%
"[" {col += yyleng; yylval.loc = col; return (LBR);}
"]" {col += yyleng; yylval.loc = col; return (RBR);}
"(" {col += yyleng; yylval.loc = col; return (LP);}
")" {col += yyleng; yylval.loc = col; return (RP);}
[0-9]+ {col += yyleng; yylval.ival = atoi(yytext); return (NUM);}
"," {col += yyleng; yylval.loc = col; return (COMMA);}
"^T" {col += yyleng; yylval.loc = col; return (TRANS);}
"*" {col += yyleng; yylval.loc = col; return (MUL);}
[\+\-] {col += yyleng; yylval.loc = col; return (PLS_SUB);}
[ \t] {col += yyleng;}
\n {}
. {col += yyleng; yylval.loc = col; return (yytext[0]);}

%%
