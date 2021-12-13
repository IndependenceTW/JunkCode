%{
    #include <stdio.h>
    #include <string.h>

    void yyerror (const char *message);
%}

%union {
    double dval;
}
%token<dval> NUM
%type<dval> expr

%left '+' '-'
%left '*' '/'
%%
line: expr {
    printf("%.1lf", $1);
}
;
expr: expr '+' expr {$$ = $1 + $3;}
    | '(' expr '+' expr ')' {$$ = $2 + $4;}
    | expr '-' expr {$$ = $1 - $3;}
    | '(' expr '-' expr ')' {$$ = $2 - $4;}
    | expr '*' expr {$$ = $1 * $3;}
    | '(' expr '*' expr ')' {$$ = $2 * $4;}
    | expr '/' expr {$$ = $1 / $3;}
    | '(' expr '/' expr ')' {$$ = $2 / $4;}
    | NUM
;

%%
void yyerror (const char *message) {
    fprintf (stderr, "%s\n", message);
}

int main (int argc, char *argv[]) {
    yyparse ();
    return (0);
}