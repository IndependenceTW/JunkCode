%{
    int inList = 0;
    int inQuote = 0;
    int isStrong = 0;
%}

text [ 0-9A-Za-z]*
header_sign #
h1toh6 ({header_sign}{1,6}\ )
header ^{h1toh6}{text}
distribute ^---
image ^\!\[{text}\]\(.*\)
todolist ^-\ \[(\ |X|x)?\]\ {text}
tolist ^(\*\ )
hyperlink ^\[{text}\]\(.*\)
toquote ^(>\ )
strong \*\*

%%
{strong} {
    if(isStrong) {
        isStrong = 0;
        printf("</strong>");
    }
    else {
        isStrong = 1;
        printf("<strong>");
    }
}

{toquote} {
    if(!inQuote){
        printf("<blockquote>\n");
        inQuote = 1;
    }
    else {
        printf("\n");
    }
}

{hyperlink} {
    char inSpan[201];
    int size = 0;
    int iterator = 1;
    for(; iterator < yyleng; iterator++) {
        char c = yytext[iterator];
        if(c != ']') {
            inSpan[size++] = c;
        }
        else {
            break;
        }
    }
    iterator += 2;
    inSpan[size] = '\0';
    printf("<a href=\"");
    for(; iterator < yyleng; iterator++) {
        char c = yytext[iterator];
        if(c != ')') {
            printf("%c", c);
        }
    }
    printf("\">\n");
    printf("\t<span>%s</span>\n", inSpan);
    printf("</a>\n");
}

{tolist} {
    if(!inList) printf("<ul>\n");
    inList = 1;
}

{todolist} {
    printf("<p>\n\t");
    printf("<input ");
    int iterator = 3;
    if(yytext[iterator] == 'x' || yytext[iterator] == 'X') {
        printf("checked=\"checked\" ");
    }
    printf("type=\"checkbox\" /> ");
    iterator++;
    if(yytext[iterator] == ']') iterator++;
    char* context = yytext + iterator + 1;
    printf("%s\n", context);
    printf("</p>\n");

}

{header} {
    int counter = 0;
    for(int i = 0; i < yyleng; i++) {
        if(yytext[i] == '#') {
            counter++;
        }
        else {
            break;
        }
    }
    printf("<h%d>", counter);
    char *text = yytext + counter + 1;
    printf("%s", text);
    printf("</h%d>\n", counter);
}

{distribute} {
    if(inList) {
        printf("</ul>\n");
        inList = 0;
    }
    if(inQuote) {
        printf("\n</blockquote>\n");
        inQuote = 0;
    }
    printf("<hr />\n");
}

{image} {
    printf("<img alt=\"");
    int i = 2;
    for(; i < yyleng; i++){
        char c = yytext[i];
        if(c != ']') {
            printf("%c", c);
        }
        else {
            break;
        }
    }
    printf("\" src=\"");
    i+=2;
    for(;i < yyleng; i++) {
        char c = yytext[i];
        if(c != ')') {
            printf("%c", c);
        }
        else {
            break;
        }
    }
    printf("\">\n");
}

{text} {
    if(inList) {
        printf("\t<li>");
    }
    ECHO;
    if(inList) {
        printf("</li>");
    }
    if(!inQuote){
        printf("\n");
    }
}
\n {}
. {
    if(inQuote) {
        ECHO;
    }
}

%%
int main(void) {
    yylex();    
    return(0);
}
