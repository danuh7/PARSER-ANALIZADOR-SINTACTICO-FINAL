%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(char *);

int result;

%}

%left T_PLUS T_MINUS T_MULT T_DIV
%left T_OR
%left T_AND
%left T_NOTEQUAL
%left T_GREATER
%left T_GREATER_EQUAL
%left T_LESS
%left T_LESS_EQUAL
%token <int> T_NUMBER
%token T_LPAREN T_RPAREN
%token T_LBRACKET T_RBRACKET
%token T_EOLs
%token T_ID
%token T_STRING
%token T_NUMCONST
%token T_ASSIG
%token T_COMMA
%token T_SEMICOLON
%token T_NOT
%token T_RETURN
%token T_IF
%token T_ELSE 
%token T_WHILE
%token T_FOR
%token T_TRUE
%token T_FALSE
%token T_VOID
%token T_DATATYPE
%token T_LKEY
%token T_RKEY
%token T_EQUAL

%%

Program : Typeld Decl { printf("Program \n"); }
     | T_VOID T_ID Decl { printf("Program \n"); }
     ;

Typeld : TypeSpec T_ID { printf("Typeld \n"); }
     ;

Decl : Vars { printf("Decl \n"); }
       | Funcs { printf("Decl \n"); }
       ;

TypeSpec : T_DATATYPE { printf("TypeSpec \n"); }
       ;

Vars : ArrayDecl VarDeclInit DeclList T_SEMICOLON Decl2 { printf("Vars \n"); }
       ;

ArrayDecl : T_LBRACKET T_NUMCONST T_RBRACKET { printf("ArrayDecl \n"); }
       | ;
       ;

VarDeclInit : T_ASSIG Expresion { printf("VarDeclInit \n"); }
       | ;
       ;

DeclList : T_COMMA VarNames { printf("Decllist \n"); }
       | ;
       ;

VarNames : T_ID ArrayDecl VarDeclInit VarDeclInit { printf("VarNames \n"); }
       ;

Decl2 : Typeld Decl { printf("Decl2 \n"); }
       | T_VOID T_ID Funcs { printf("Decl2 \n"); }
       ;

Funcs : T_LPAREN Params T_RPAREN Stmt FunDecListp { printf("Funcs \n"); }
       ;

FunDecListp : FunDecList FunDecListp { printf("FunDecListp \n"); }
       | ;
       ;

FunDecList : T_LPAREN TypeSpec T_OR T_VOID T_RPAREN T_ID T_LPAREN Params T_RPAREN FuncStmt { printf("FunDecList \n"); }
       | ;
       ;


FuncStmt :  T_LKEY Stmts ReturnStmt T_RKEY { printf("FuncStmt \n"); }
       ;

Params : Param Paramsp { printf("Params \n"); }
       | ;
       ;

Paramsp :  T_COMMA Param Paramsp { printf("Paramsp \n"); }
       | ;
       ;

Param :  TypeSpec T_ID { printf("Params \n"); }
       ;


ReturnStmt :  T_RETURN T_SEMICOLON { printf("ReturnStmt \n"); }
       | T_RETURN Expresion T_SEMICOLON { printf("ReturnStmt \n"); }
       | ;
       ;

Stmts :  Stmt Stmts { printf("Stmts \n"); }
       ;

Stmt :  ExprStmt  { printf("Stmt \n"); }
       | IfStmt { printf("Stmt \n"); }
       | WhileStmt { printf("Stmt \n"); }
       | ForStmt { printf("IfStmt \n"); }
       ;

ExprStmt :  Expresion  { printf("ExprStmt \n"); }
       ;

Expresion : Assignament { printf("Expresion \n"); }
       ;

Assignament: T_ID T_ASSIG Assignament { printf("Assignament \n"); }
       | LogicOr  { printf("Assignament \n"); }
       ;

LogicOr : LogicAnd LogicOr { printf("LogicOr \n"); }
       ;

LogicOrp : T_OR LogicAnd LogicOrp { printf("LogicOrp \n"); }
       | ;
       ;

LogicAnd : Equality LogicAndp { printf("LogicAnd \n"); }
       ;

LogicAndp : T_AND Equality LogicAndp { printf("LogicAndp \n"); }
       ;

Equality : Comparison Equalityp { printf("Equality \n"); }
       ;

Equalityp : CompOper Comparison Equalityp { printf("Equalityp \n"); }
        | ;
        ;

CompOper : T_NOT T_ASSIG  { printf("CompOper \n"); }
        | T_EQUAL { printf("CompOper \n"); }
        ;

Comparison : Term Comparisonp  { printf("Comparison \n"); }
        ;

Comparisonp : LogicOperator Term Comparisonp  { printf("Comparisonp \n"); }
        | ;
        ;

LogicOperator : T_GREATER   { printf("LogicOperator \n"); }
        | T_GREATER_EQUAL { printf("LogicOperator \n"); }
        | T_LESS { printf("LogicOperator \n"); }
        | T_LESS_EQUAL { printf("LogicOperator \n"); }
        ;

Term : Factor Termp  { printf("Term \n"); }
        ;

Termp : T_MINUS Factor Termp  { printf("Term \n"); }
        | T_PLUS Factor Termp { printf("Term \n"); }
        | ;
        ;

Factor : Unary Factorp  { printf("Factor \n"); }
        ;

Factorp : T_DIV Unary Factorp  { printf("Factorp \n"); }
        | T_MULT Unary Factorp
        | ;
        ;

Unary : UnaryOp Unary  { printf("Unary \n"); }
        | Call { printf("Unary \n"); } 
        ;

UnaryOp : T_NOT   { printf("UnaryoP \n"); }
        | T_MINUS { printf("Unary OP\n"); } 
        ;

Call : Primary CallFunc  { printf("Call \n"); }
        ;

CallFunc : T_LPAREN Params T_RPAREN { printf("CallFunc \n"); }
         | ;
         ;

Primary : T_TRUE  { printf("Primary \n"); }
         | T_FALSE  { printf("Primary \n"); }
         | T_NUMBER  { printf("Primary \n"); }
         | T_STRING  { printf("Primary \n"); }
         | T_ID  { printf("Primary \n"); }
         | T_LPAREN Expresion T_RPAREN  { printf("Primary \n"); }
         ;

IfStmt : T_IF T_LPAREN Expresion T_RPAREN T_LKEY Stmts T_RKEY ElseStmt { printf("IfStmt \n"); }
        ;

ElseStmt : T_ELSE T_LKEY Stmts T_RKEY  { printf("ElseStmt \n"); }
        ;

WhileStmt : T_WHILE T_LPAREN Expresion T_RPAREN T_LKEY Stmts T_RKEY  { printf("whileStmt \n"); }
        ;

ForStmt : T_FOR T_LPAREN ForExpresion T_SEMICOLON ForExpresion T_SEMICOLON ForExpresion T_RPAREN  { printf("ForStmt \n"); }
        ;

ForExpresion : Expresion { printf("Forexp\n"); }
        | ;
        ;


%%

int main(int argc, char *argv[]) {
    yyparse();
    printf("Result: %d\n", result);
    return 0;
}

void yyerror(char *s) {
    printf("Error: %s\n", s);
    exit(1);
}
