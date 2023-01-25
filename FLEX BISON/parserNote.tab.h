
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_DIV = 258,
     T_MULT = 259,
     T_MINUS = 260,
     T_PLUS = 261,
     T_OR = 262,
     T_AND = 263,
     T_NOTEQUAL = 264,
     T_GREATER = 265,
     T_GREATER_EQUAL = 266,
     T_LESS = 267,
     T_LESS_EQUAL = 268,
     T_NUMBER = 269,
     T_LPAREN = 270,
     T_RPAREN = 271,
     T_LBRACKET = 272,
     T_RBRACKET = 273,
     T_EOLs = 274,
     T_ID = 275,
     T_STRING = 276,
     T_NUMCONST = 277,
     T_ASSIG = 278,
     T_COMMA = 279,
     T_SEMICOLON = 280,
     T_NOT = 281,
     T_RETURN = 282,
     T_IF = 283,
     T_ELSE = 284,
     T_WHILE = 285,
     T_FOR = 286,
     T_TRUE = 287,
     T_FALSE = 288,
     T_VOID = 289,
     T_DATATYPE = 290,
     T_LKEY = 291,
     T_RKEY = 292,
     T_EQUAL = 293
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


