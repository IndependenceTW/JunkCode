%{
    #include <stdio.h>
    #include <string.h>
    void yyerror (const char *message);

    int stack[100];
    int size = 0;

    void push(int num);
    void inverse();
    void inc();
    void dec();
    int top();
%}
%union{
    int ival;
}
%token <ival> VALUE
%token PUSH INVERSE INC DEC

%%
prog    :stmts '$' {printf("%d\n", top());}
;
stmts   :stmts stmt
        |stmt
;
stmt    :PUSH VALUE {push($2);}
        |INVERSE {inverse();}
        |INC {inc();}
        |DEC {dec();}
;
%%
void yyerror (const char *message) {
    fprintf (stderr, "%s\n", message);
}

void push(int num) {
    stack[size++] = num;
}
void inverse() {
    int t = stack[size - 1];
    stack[size - 1] = stack[size - 2];
    stack[size - 2] = t;
}
void inc() {
    stack[size - 1] ++;
}
void dec() {
    stack[size - 1] --;
}
int top() {
    return stack[size - 1];
}


int main (int argc, char *argv[]) {
    yyparse ();
    return (0);
}