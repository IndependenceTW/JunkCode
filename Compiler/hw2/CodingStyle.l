%{
unsigned int counter = 0;
unsigned int isNewLine = 0;
%}
lft_brac \{
rt_brac \}
word [^\t\n\{\}]*
nl \n


%%
{lft_brac} {if(isNewLine == 1){for(int i = 0; i < counter ;i++) printf("\t");} isNewLine = 0; counter ++; ECHO;}
{rt_brac} {counter --; if(isNewLine == 1){for(int i = 0; i < counter ;i++) printf("\t");} isNewLine = 0; ECHO;}
{word} {if(isNewLine == 1){for(int i = 0; i < counter ;i++) printf("\t");} isNewLine = 0; ECHO;}
{nl} {ECHO; isNewLine = 1;}
. 

%%

int main (void) {
    yylex();
    return(0);
}