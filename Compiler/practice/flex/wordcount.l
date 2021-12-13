%{
unsigned int charCount=0, wordCount=0, lineCount=0;
%}
digit [0-9]
digits {digit}+
integer [+-]?{digits}
float {digits}\.{digits}
letter [a-zA-Z_]
identifier {letter}({letter}|{digit})+

%%
{integer} { ECHO; printf(" is integer.\n"); }
{float} { ECHO; printf(" is float.\n"); }
{letter} { ECHO; printf(" is letter.\n"); }
{identifier} { ECHO; printf(" is identifier.\n"); }
. {}

%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
