%{
#include <stdio.h>
%}

%token IDENTIFIER
%left 'void' 'id'

%token DATATYPE
%left 'bool' 'float'
%left 'int' 'char'

%token PARENTESIS
%left '(' ')'

%token EMPTYSTRING
%left 'ES' ''

%token KEYS
%left '{' '}'

%token RETURN
%left 'return' 

%token UNION
%left '||' '&&'

%token EQUAL
%left '¡=' '=='
%left '='

%token COMPARATOR
%left '>' '<'
%left '>=' '<='

%token ARITMETIC

%left '-' '+'
%left '/' '*'

%token PRIME
%left  'p'


%token WHILE
%left 'while' 

%token FOR
%left 'for'


%token SEMICOLON
%left ';' ':'

%token WARNING 
%left '!'

%token COMA 
%left ','


%token NUMCONST 
%left '0' '1' '2'
%left '3' '4'
%left '5' '6' 
%left '7' '8' '9' 

%token IF 
%left 'if'

%token ELSE 
%left 'else'
%%

Program:
    Typeld Decl { printf("Typeld Decl "); }
    | IDENTIFIER IDENTIFIER Funcs { printf("IDENTIFIER "); }
    ;

Typeld:
    TypeSpec IDENTIFIER { printf("IDENTIFIER "); }
    ;

Decl:
    Vars { printf("Vars"); }
    ;

TypeSpec:
    DATATYPE { printf("DATATYPE "); }
    ;

Vars:
    ArrayDecl VarDeclInit DecList SEMICOLON Decl2 { printf("ArrayDecl "); }
    ;

ArrayDecl:
    [NUMCONST] { printf("ArrayDecl "); }
    |EMPTYSTRING { printf("EMPTY STRING "); }
    ;

VarDeclInit:
    COMPARATOR Expresion { printf("COMPARATOR "); }
    | EMPTYSTRING { printf("EMPTY STRING "); }
    ;

DecList:
    COMA VarNames { printf("COMA"); }
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

VarNames:
    IDENTIFIER ArrayDecl VarDeclInit DecList { printf("IDENTIFIER"); }
    ;

Dec2:
    Type Decl { printf("Type"); }
    | IDENTIFIER  IDENTIFIER Funcs { printf("ID"); }
    ;

Funcs:
    PARENTESIS PARAMS PARENTESIS stmnt FunDecListp { printf("COMA"); }
    ;

FunDecListp:
    FunDecList FunDecListp { printf("COMA"); }
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

FunDecList:
    PARENTESIS TypeSpec PARENTESIS IDENTIFIER  FunDecListp { printf("COMA"); }
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

Params:
    Param Paramsp { printf("Param"); }   
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

Paramsp:
    COMA Param Params  { printf("COMA"); }
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

Param:
    TypeSpec IDENTIFIER  { printf("IDENTIFIER"); }
    ;

FuncStmt:
    KEYS Stmts ReturnStmt KEYS Param Params  { printf("KEYS"); }
    ;

ReturnStmt:
    RETURN SEMICOLON { printf("RETURN"); }
    | RETURN Expresion SEMICOLON { printf("RETURN"); }
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

Stmts:
    Stmt Stmts { printf("STATEMENT"); }
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

Stmt:
    Stmt Stmts { printf("STATEMENT"); }
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

ExprStmt:
    Expresion { printf("EXPRESION"); }
    ;

Expresion:
    Assignament { printf("ASSIGNAMENT"); }
    ;

Assignament:
    IDENTIFIER EQUAL Assignament { printf("ID"); }
    | LogicOr { printf("EMPTY STRING"); }
    ;

LogicOr:
    LogicAnd LogicOrp  { printf("LOGIC AND"); }
    ;

LogicOrp:
    UNION LogicAnd LogicOrp { printf("UNION"); }
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

LogicAnd:
    Equality LogicAndp { printf("Equality"); }
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

Equality:
    Comparison Equalityp { printf("Comparison"); }
    ;

Equalityp:
    CompOper Comparison Equalityp { printf("ComOper"); }
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

CompOper:
    WARNING EQUAL  { printf("WARNING"); }
    | EQUAL { printf("EQUAL"); }
    ;

Comparison:
    Term Comparisonp { printf("Term"); }
    ;

Comparisonp:
    LogicOperator Term Comparisonp { printf("LogicOperator"); }
    ;

LogicOperator:
    COMPARATOR  { printf("COMPARATOR"); }
    | COMPARATOR  { printf("COMPARATOR"); }
    | COMPARATOR  { printf("COMPARATOR"); }
    | COMPARATOR  { printf("COMPARATOR"); }
    ;

Term:
    Factor Termp{ printf("Factor"); }
    ;

Termp:
    ARITMETIC Factor Termp  { printf("ARITMETIC"); }
    | ARITMETIC Factor Termp { printf("ARITMETIC"); }
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

Factor:
    Unary Factorp { printf("UNARY"); }
    ;

Factorp:
    ARITMETIC Unary Factorp { printf("ARITMETIC"); }
    | ARITMETIC Factor Factorp { printf("ARITMETIC"); }
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

Unary:
    UnaryOp Unary { printf("unary op"); }
    | Call { printf("Call"); }
    ;

UnaryOp:
    WARNING { printf("WARNING"); }
    | ARITMETIC  { printf("ARITMETIC"); }
    ;

Call:
    Primary CallFunc  { printf("PRIMARY"); }
    ;

CallFunc:
    PARENTESIS Params PARENTESIS   { printf("PARENTESIS"); }
    | EMPTYSTRING { printf("EMPTY STRING"); }
    ;

Primary:
    DATATYPE { printf("DATATYPE"); }
    | DATATYPE { printf("DATATYPE"); }
    | IDENTIFIER { printf("ID"); }
    ;

Ifstmt:
    IF PARENTESIS Expresion PARENTESIS KEYS Stmts KEYS ElseStmt { printf("IF"); }
    ;

ElseStmt:
    ELSE KEYS Stmt KEYS { printf("DATATYPE"); }
    | EMPTYSTRING { printf("EMPTYSTRING"); }
    ;

WhileStmt:
    WHILE PARENTESIS Expresion PARENTESIS KEYS Stmts KEYS  KEYS { printf("WHILE"); }
    ;

ForStmt:
    FOR PARENTESIS ForExpresion SEMICOLON ForExpresion SEMICOLON ForExpresion PARENTESIS KEYS Stmts KEYS { printf("FOR"); }
    ;

ForExpr:
    Expresion { printf("EXPRESION"); }
    | EMPTYSTRING { printf("EMPTYSTRING"); }




%%

int main() {
    yyparse();
    return 0;
}
