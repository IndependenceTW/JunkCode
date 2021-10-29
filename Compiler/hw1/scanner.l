NUM ([1-9][0-9]*)|0
PLUS \+
MINUS \-
MUL \*
DIV \/
LPR \(
RPR \)

%%

{NUM} { printf("NUM "); ECHO; printf("\n");}
{PLUS} { printf("PLUS\n");}
{MINUS} { printf("MINUS\n");}
{MUL} { printf("MUL\n");}
{DIV} { printf("DIV\n");}
{LPR} { printf("LPR\n");}
{RPR} { printf("RPR\n");}
.|\n {}

%%

int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
