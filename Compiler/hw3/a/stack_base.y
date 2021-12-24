%{
    #include <stdio.h>
    #include <string.h>
    void yyerror (const char *message);
    void push(int num);
    int pop();
    int size();

    int stack[100];
    int head = 0;
    int is_valid = 1;
%}
%union{
    int ival;
    char *str;
}
%token <ival> VALUE
%token <str> LOAD ADD SUB MUL MOD INC DEC

%%
prog    :stmts {
    if (is_valid == 0 || head != 1) {
        printf("Invalid format\n");
    }
    else {
        printf("%d\n", stack[0]);
    }
}
;
stmts   :stmt stmts
        |stmt
;
stmt    :LOAD VALUE {
            push ($2);
        }
        |ADD {
            if (is_valid == 0) {}
            else if (size () < 2) {
                is_valid = 0;
            }
            else {
                int n1 = pop ();
                int n2 = pop ();
                push (n1 + n2);
            }
        }
        |SUB {
            if (is_valid == 0) {}
            else if (size () < 2) {
                is_valid = 0;
            }
            else {
                int n1 = pop ();
                int n2 = pop ();
                push (n1 - n2);
            }
        }
        |MUL {
            if (is_valid == 0) {}
            else if (size () < 2) {
                is_valid = 0;
            }
            else {
                int n1 = pop ();
                int n2 = pop ();
                push (n1 * n2);
            }
        }
        |MOD {
            if (is_valid == 0) {}
            else if (size () < 2) {
                is_valid = 0;
            }
            else {
                int n1 = pop ();
                int n2 = pop ();
                push (n1 % n2);
            }
        }
        |INC {
            if (is_valid == 0) {}
            else if (size () < 1) {
                is_valid = 0;
            }
            else {
                int n1 = pop ();
                push (n1 + 1);
            }
        }
        |DEC {
            if (is_valid == 0) {}
            else if (size () < 1) {
                is_valid = 0;
            }
            else {
                int n1 = pop ();
                push (n1 - 1);
            }
        }
;
%%
void yyerror (const char *message) {
    fprintf (stderr, "%s\n", message);
}

void push (int num) {
    stack[head++] = num;
}

int pop () {
    return stack[--head];
}

int size () {
    return head;
}

int main (int argc, char *argv[]) {
    yyparse ();
    return (0);
}
