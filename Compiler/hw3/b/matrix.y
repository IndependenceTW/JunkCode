%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void yyerror (const char *message);
    void semantic_err (int col);
%}

%union {
    int ival;
    int loc;
    struct degree {
        int x;
        int y;
    } mat;
}

%type <mat> matrix
%token <loc> LP RP LBR RBR PLS_SUB COMMA TRANS MUL
%token <ival> NUM

%left PLS_SUB
%left MUL
%nonassoc TRANS
%%
stmt    :matrix {printf("Accepted\n");}
matrix  :matrix PLS_SUB matrix {
            if ($1.x == $3.x && $1.y == $3.y) {
                $$ = $1;
            }
            else {
                semantic_err ($2);
            }
        }
        |matrix MUL matrix {
            if ($1.y == $3.x) {
                $$.x = $1.x;
                $$.y = $3.y;
            }
            else {
                semantic_err ($2);
            }
        }
        |LP matrix RP {
            $$ = $2;
        }
        |matrix TRANS {
            $$.x = $1.y;
            $$.y = $1.x;
        }
        |LBR NUM COMMA NUM RBR {
            $$.x = $2;
            $$.y = $4;
        }
%%
void yyerror (const char *message) {
    fprintf (stderr, "%s\n", message);
}

void semantic_err(int col) {
    printf ("Semantic error on col %d\n", col);
    exit (1);
}

int main () {
    yyparse ();
    return (0);
}