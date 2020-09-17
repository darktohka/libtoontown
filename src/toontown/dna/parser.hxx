/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_DNAYY_PARSER_HXX_INCLUDED
# define YY_DNAYY_PARSER_HXX_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int dnayydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    STRING = 259,                  /* STRING  */
    FRONT_DOOR_POINT_ = 260,       /* FRONT_DOOR_POINT_  */
    SIDE_DOOR_POINT_ = 261,        /* SIDE_DOOR_POINT_  */
    STREET_POINT_ = 262,           /* STREET_POINT_  */
    COGHQ_IN_POINT_ = 263,         /* COGHQ_IN_POINT_  */
    COGHQ_OUT_POINT_ = 264,        /* COGHQ_OUT_POINT_  */
    ANIM = 265,                    /* ANIM  */
    ANIM_BUILDING = 266,           /* ANIM_BUILDING  */
    ANIM_PROP = 267,               /* ANIM_PROP  */
    ARTICLE = 268,                 /* ARTICLE  */
    BATTLE_CELL = 269,             /* BATTLE_CELL  */
    CELL_ID = 270,                 /* CELL_ID  */
    CODE = 271,                    /* CODE  */
    COLOR = 272,                   /* COLOR  */
    COUNT = 273,                   /* COUNT  */
    CORNICE = 274,                 /* CORNICE  */
    DOOR = 275,                    /* DOOR  */
    FLAT_BUILDING = 276,           /* FLAT_BUILDING  */
    FLAT_DOOR = 277,               /* FLAT_DOOR  */
    DNAGROUP = 278,                /* DNAGROUP  */
    INTERACTIVE_PROP = 279,        /* INTERACTIVE_PROP  */
    HEIGHT = 280,                  /* HEIGHT  */
    HOOD_MODEL = 281,              /* HOOD_MODEL  */
    BUILDING_TYPE = 282,           /* BUILDING_TYPE  */
    PLACE_MODEL = 283,             /* PLACE_MODEL  */
    HPR = 284,                     /* HPR  */
    NHPR = 285,                    /* NHPR  */
    LANDMARK_BUILDING = 286,       /* LANDMARK_BUILDING  */
    MODEL = 287,                   /* MODEL  */
    NODE = 288,                    /* NODE  */
    POS = 289,                     /* POS  */
    PROP = 290,                    /* PROP  */
    SCALE = 291,                   /* SCALE  */
    SIGN = 292,                    /* SIGN  */
    BASELINE = 293,                /* BASELINE  */
    INDENT = 294,                  /* INDENT  */
    KERN = 295,                    /* KERN  */
    WIGGLE = 296,                  /* WIGGLE  */
    STUMBLE = 297,                 /* STUMBLE  */
    FLAGS = 298,                   /* FLAGS  */
    STOMP = 299,                   /* STOMP  */
    TEXT_ = 300,                   /* TEXT_  */
    LETTERS = 301,                 /* LETTERS  */
    GRAPHIC = 302,                 /* GRAPHIC  */
    STORE_FONT = 303,              /* STORE_FONT  */
    STORE_NODE = 304,              /* STORE_NODE  */
    STORE_TEXTURE = 305,           /* STORE_TEXTURE  */
    STREET = 306,                  /* STREET  */
    SUIT_EDGE = 307,               /* SUIT_EDGE  */
    STORE_SUIT_POINT = 308,        /* STORE_SUIT_POINT  */
    TEXTURE = 309,                 /* TEXTURE  */
    TITLE = 310,                   /* TITLE  */
    VIS = 311,                     /* VIS  */
    VISGROUP = 312,                /* VISGROUP  */
    WALL = 313,                    /* WALL  */
    WIDTH = 314,                   /* WIDTH  */
    WINDOWS = 315                  /* WINDOWS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUMBER 258
#define STRING 259
#define FRONT_DOOR_POINT_ 260
#define SIDE_DOOR_POINT_ 261
#define STREET_POINT_ 262
#define COGHQ_IN_POINT_ 263
#define COGHQ_OUT_POINT_ 264
#define ANIM 265
#define ANIM_BUILDING 266
#define ANIM_PROP 267
#define ARTICLE 268
#define BATTLE_CELL 269
#define CELL_ID 270
#define CODE 271
#define COLOR 272
#define COUNT 273
#define CORNICE 274
#define DOOR 275
#define FLAT_BUILDING 276
#define FLAT_DOOR 277
#define DNAGROUP 278
#define INTERACTIVE_PROP 279
#define HEIGHT 280
#define HOOD_MODEL 281
#define BUILDING_TYPE 282
#define PLACE_MODEL 283
#define HPR 284
#define NHPR 285
#define LANDMARK_BUILDING 286
#define MODEL 287
#define NODE 288
#define POS 289
#define PROP 290
#define SCALE 291
#define SIGN 292
#define BASELINE 293
#define INDENT 294
#define KERN 295
#define WIGGLE 296
#define STUMBLE 297
#define FLAGS 298
#define STOMP 299
#define TEXT_ 300
#define LETTERS 301
#define GRAPHIC 302
#define STORE_FONT 303
#define STORE_NODE 304
#define STORE_TEXTURE 305
#define STREET 306
#define SUIT_EDGE 307
#define STORE_SUIT_POINT 308
#define TEXTURE 309
#define TITLE 310
#define VIS 311
#define VISGROUP 312
#define WALL 313
#define WIDTH 314
#define WINDOWS 315

/* Value type.  */


extern YYSTYPE dnayylval;

int dnayyparse (void);

#endif /* !YY_DNAYY_PARSER_HXX_INCLUDED  */
