%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(char *);

%}

%%

[_a-zA-Z][_a-zA-Z0-9]* { yylval = yytext; return T_ID; }
\"[^\"]*\" { yylval = yytext; return T_STRING; }
[1-9][0-9]*    { yylval = yytext; return T_NUMCONST; }
"+"           { return T_PLUS; }
"-"           { return T_MINUS; }
"*"           { return T_MULT; }
"/"           { return T_DIV; }
"="           { return T_ASSIG; }
"=="           { return T_EQUAL; }
","           { return T_COMMA; }
"("           { return T_LPAREN; }
")"           { return T_RPAREN; }
"["           { return T_LBRACKET; }
"]"           { return T_RBRACKET; }
";"           { return T_SEMICOLON; }
"||"           { return T_OR; }
"&&"           { return T_AND; }
"!="           { return T_NOTEQUAL; }
">"            { return T_GREATER; }
">="           { return T_GREATER_EQUAL; }
"<"            { return T_LESS; }
"<="           { return T_LESS_EQUAL; }
"!"           { return T_NOT; }
"{"           { return T_LKEY; }
"}"           { return T_RKEY; }
(return|RETURN)[ \t\r]* { return T_RETURN; }
if[ \t\r]* { return T_IF; }
else[ \t\r]* { return T_ELSE; }
while[ \t\r]* { return T_WHILE; }
for[ \t\r]* { return T_FOR; }
true[ \t\r]* { return T_TRUE; }
false[ \t\r]* { return T_FALSE; }
void[ \t\r]* { return T_VOID; }
[ \t\r]*int[ \t\r]*|[ \t\r]*char[ \t\r]*|[ \t\r]*bool[ \t\r]*|[ \t\r]*float[ \t\r]*|[ \t\r]*double[ \t\r]* { return T_DATATYPE; }



"\n"          { return T_EOL; }
[ \t\r]       { /* ignore whitespace */ }
.             { yyerror("Invalid character"); }

%%

int main(int argc, char *argv[]) {
    yylex();
    return 0;
}

void yyerror(char *s) {
    printf("Error: %s\n", s);
    exit(1);
}
