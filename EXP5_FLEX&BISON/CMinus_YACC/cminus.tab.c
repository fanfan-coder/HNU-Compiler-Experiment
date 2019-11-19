
/*  A Bison parser, made from cminus.y
 by  GNU Bison version 1.25
  */

#define YYBISON 1  /* Identify Bison output.  */

#define alloca

#define	IF	258
#define	ELSE	259
#define	RETURN	260
#define	WHILE	261
#define	VOID	262
#define	INT	263
#define	ID	264
#define	NUM	265
#define	ASSIGN	266
#define	EQ	267
#define	NE	268
#define	LT	269
#define	LE	270
#define	GT	271
#define	GE	272
#define	PLUS	273
#define	MINUS	274
#define	TIMES	275
#define	OVER	276
#define	SEMI	277
#define	COMMA	278
#define	LPAREN	279
#define	RPAREN	280
#define	LBRACE	281
#define	RBRACE	282
#define	LCURLY	283
#define	RCURLY	284
#define	ERROR	285

#line 1 "cminus.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedNum;
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void); // added 11/2/11 to ensure no conflict with lex

static TreeNode *l = NULL; /* local dec list */
static TreeNode *s = NULL; /* stmt list */
static TreeNode *d = NULL; /* dec list */
static TreeNode *p = NULL; /* params list */
static TreeNode *a = NULL; /* argument list */

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		108
#define	YYFLAG		32768
#define	YYNTBASE	31

#define YYTRANSLATE(x) ((unsigned)(x) <= 285 ? yytranslate[x] : 66)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     7,     9,    11,    13,    17,    18,    19,
    28,    30,    32,    33,    41,    43,    45,    49,    51,    54,
    59,    64,    67,    68,    71,    72,    74,    76,    78,    80,
    82,    85,    87,    93,   101,   107,   110,   114,   118,   120,
   122,   123,   129,   133,   135,   137,   139,   141,   143,   145,
   147,   151,   153,   155,   157,   161,   163,   165,   167,   171,
   173,   175,   177,   178,   184,   186,   187,   191
};

static const short yyrhs[] = {    32,
     0,    32,    33,     0,    33,     0,    35,     0,    39,     0,
     9,     0,    38,    34,    22,     0,     0,     0,    38,    34,
    36,    26,    10,    37,    27,    22,     0,     8,     0,     7,
     0,     0,    38,    34,    40,    24,    41,    25,    44,     0,
    42,     0,     7,     0,    42,    23,    43,     0,    43,     0,
    38,    34,     0,    38,    34,    26,    27,     0,    28,    45,
    46,    29,     0,    45,    35,     0,     0,    46,    47,     0,
     0,    48,     0,    44,     0,    49,     0,    50,     0,    51,
     0,    52,    22,     0,    22,     0,     3,    24,    52,    25,
    47,     0,     3,    24,    52,    25,    47,     4,    47,     0,
     6,    24,    52,    25,    47,     0,     5,    22,     0,     5,
    52,    22,     0,    53,    11,    52,     0,    55,     0,    34,
     0,     0,    34,    54,    26,    52,    27,     0,    57,    56,
    57,     0,    57,     0,    15,     0,    14,     0,    16,     0,
    17,     0,    12,     0,    13,     0,    57,    58,    59,     0,
    59,     0,    18,     0,    19,     0,    59,    60,    61,     0,
    61,     0,    20,     0,    21,     0,    24,    52,    25,     0,
    53,     0,    62,     0,    10,     0,     0,    34,    63,    24,
    64,    25,     0,    65,     0,     0,    65,    23,    52,     0,
    52,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    30,    34,    48,    51,    52,    55,    61,    66,    72,    77,
    83,    88,    95,   101,   110,   111,   118,   131,   134,   140,
   150,   158,   171,   174,   187,   190,   191,   192,   193,   194,
   197,   198,   201,   207,   215,   223,   227,   234,   241,   244,
   249,   254,   261,   267,   270,   274,   278,   282,   286,   290,
   296,   302,   305,   309,   315,   321,   324,   328,   334,   338,
   342,   346,   353,   358,   365,   366,   369,   382
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","IF","ELSE",
"RETURN","WHILE","VOID","INT","ID","NUM","ASSIGN","EQ","NE","LT","LE","GT","GE",
"PLUS","MINUS","TIMES","OVER","SEMI","COMMA","LPAREN","RPAREN","LBRACE","RBRACE",
"LCURLY","RCURLY","ERROR","program","dec_list","dec","id","var_dec","@1","@2",
"type_spec","fun_dec","@3","params","params_list","param","comp_stmt","local_dec",
"stmt_list","stmt","exp_stmt","select_stmt","iter_stmt","return_stmt","exp",
"var","@4","simple_exp","relop","add_exp","addop","term","mulop","factor","call",
"@5","args","arg_list", NULL
};
#endif

static const short yyr1[] = {     0,
    31,    32,    32,    33,    33,    34,    35,    36,    37,    35,
    38,    38,    40,    39,    41,    41,    42,    42,    43,    43,
    44,    45,    45,    46,    46,    47,    47,    47,    47,    47,
    48,    48,    49,    49,    50,    51,    51,    52,    52,    53,
    54,    53,    55,    55,    56,    56,    56,    56,    56,    56,
    57,    57,    58,    58,    59,    59,    60,    60,    61,    61,
    61,    61,    63,    62,    64,    64,    65,    65
};

static const short yyr2[] = {     0,
     1,     2,     1,     1,     1,     1,     3,     0,     0,     8,
     1,     1,     0,     7,     1,     1,     3,     1,     2,     4,
     4,     2,     0,     2,     0,     1,     1,     1,     1,     1,
     2,     1,     5,     7,     5,     2,     3,     3,     1,     1,
     0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
     3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
     1,     1,     0,     5,     1,     0,     3,     1
};

static const short yydefact[] = {     0,
    12,    11,     1,     3,     4,     0,     5,     2,     6,     8,
     7,     0,     0,     0,     0,     9,    12,     0,     0,    15,
    18,     0,    19,     0,     0,     0,     0,    23,    14,    17,
    10,    20,    25,    22,     0,     0,     8,     0,     0,     0,
    62,    32,     0,    21,    40,    27,    24,    26,    28,    29,
    30,     0,    60,    39,    44,    52,    56,    61,     0,    36,
     0,     0,     0,     0,     0,    31,     0,    49,    50,    46,
    45,    47,    48,    53,    54,     0,     0,    57,    58,     0,
     0,    37,     0,    59,     0,    66,    38,    60,    43,    51,
    55,     0,     0,     0,    68,     0,    65,    33,    35,    42,
    64,     0,     0,    67,    34,     0,     0,     0
};

static const short yydefgoto[] = {   106,
     3,     4,    45,     5,    12,    22,     6,     7,    13,    19,
    20,    21,    46,    33,    36,    47,    48,    49,    50,    51,
    52,    53,    64,    54,    76,    55,    77,    56,    80,    57,
    58,    65,    96,    97
};

static const short yypact[] = {    58,
-32768,-32768,    58,-32768,-32768,     0,-32768,-32768,-32768,   -17,
-32768,   -14,    -6,    31,    60,-32768,    18,     0,    20,    36,
-32768,    22,    47,    34,    58,    52,    48,-32768,-32768,-32768,
-32768,-32768,    58,-32768,     0,     5,    54,    55,    26,    56,
-32768,-32768,    -7,-32768,    13,-32768,-32768,-32768,-32768,-32768,
-32768,    59,    66,-32768,    39,    49,-32768,-32768,    -7,-32768,
    61,    -7,    57,    62,    63,-32768,    -7,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    -7,    -7,-32768,-32768,    -7,
    64,-32768,    65,-32768,    -7,    -7,-32768,-32768,    53,    49,
-32768,    16,    16,    51,-32768,    67,    68,    80,-32768,-32768,
-32768,    -7,    16,-32768,-32768,    85,    86,-32768
};

static const short yypgoto[] = {-32768,
-32768,    90,    -5,    69,-32768,-32768,    -9,-32768,-32768,-32768,
-32768,    70,    72,-32768,-32768,   -61,-32768,-32768,-32768,-32768,
   -39,   -16,-32768,-32768,-32768,    21,-32768,    17,-32768,    19,
-32768,-32768,-32768,-32768
};


#define	YYLAST		102


static const short yytable[] = {    61,
    10,     9,    41,    63,    11,    18,   -13,    38,     9,    39,
    40,    14,    23,     9,    41,    18,    43,    15,    38,    81,
    39,    40,    83,    35,     9,    41,    42,    87,    43,    37,
    98,    99,    28,    44,     9,    41,   -63,    42,   -41,    43,
    16,   105,   -16,    28,    24,    94,    95,    60,    26,    43,
    68,    69,    70,    71,    72,    73,    74,    75,    25,    88,
    88,    28,   104,    88,     1,     2,    17,     2,    78,    79,
    74,    75,    27,    31,    32,    11,    67,   100,    59,    62,
    66,    84,    82,   103,   107,   108,    86,    85,    92,    93,
   102,   101,     8,    90,    30,    29,    89,     0,    91,     0,
     0,    34
};

static const short yycheck[] = {    39,
     6,     9,    10,    43,    22,    15,    24,     3,     9,     5,
     6,    26,    18,     9,    10,    25,    24,    24,     3,    59,
     5,     6,    62,    33,     9,    10,    22,    67,    24,    35,
    92,    93,    28,    29,     9,    10,    24,    22,    26,    24,
    10,   103,    25,    28,    25,    85,    86,    22,    27,    24,
    12,    13,    14,    15,    16,    17,    18,    19,    23,    76,
    77,    28,   102,    80,     7,     8,     7,     8,    20,    21,
    18,    19,    26,    22,    27,    22,    11,    27,    24,    24,
    22,    25,    22,     4,     0,     0,    24,    26,    25,    25,
    23,    25,     3,    77,    25,    24,    76,    -1,    80,    -1,
    -1,    33
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 31 "cminus.y"
{ savedTree = yyvsp[0];;
    break;}
case 2:
#line 35 "cminus.y"
{
                d = yyvsp[-1];
                if(d==NULL){
                  yyval = yyvsp[0];
                }else{
                  while(d->sibling != NULL){
                    d = d->sibling;
                  }
                  d->sibling = yyvsp[0];
                  yyval = yyvsp[-1];
                }
              ;
    break;}
case 3:
#line 48 "cminus.y"
{ yyval = yyvsp[0]; ;
    break;}
case 4:
#line 51 "cminus.y"
{ yyval = yyvsp[0]; ;
    break;}
case 5:
#line 52 "cminus.y"
{ yyval = yyvsp[0]; ;
    break;}
case 6:
#line 56 "cminus.y"
{
                savedName = copyString(tokenString);
              ;
    break;}
case 7:
#line 62 "cminus.y"
{
                yyval = yyvsp[-2];
                yyval->attr.name = savedName;
              ;
    break;}
case 8:
#line 67 "cminus.y"
{
                yyval = yyvsp[-1];
                yyval->attr.name = savedName;
                yyval->type = Array;
              ;
    break;}
case 9:
#line 73 "cminus.y"
{
                yyval = yyvsp[-2];
                yyval->size = atoi(tokenString);
              ;
    break;}
case 10:
#line 78 "cminus.y"
{
                yyval = yyvsp[-2];
              ;
    break;}
case 11:
#line 84 "cminus.y"
{
                yyval = newDecNode(VarK);
                yyval->type = Integer;
              ;
    break;}
case 12:
#line 89 "cminus.y"
{
                yyval = newDecNode(VarK);
                yyval->type = Void;
              ;
    break;}
case 13:
#line 96 "cminus.y"
{
                  yyval = yyvsp[-1];
                  yyval->kind.dec = FunK;
                  yyval->attr.name = savedName;
                ;
    break;}
case 14:
#line 102 "cminus.y"
{
                yyval = yyvsp[-4];
                
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              ;
    break;}
case 15:
#line 110 "cminus.y"
{yyval = yyvsp[0];;
    break;}
case 16:
#line 112 "cminus.y"
{
                yyval = newDecNode(ParamK);
                yyval->type = Void;
              ;
    break;}
case 17:
#line 119 "cminus.y"
{
                p = yyvsp[-2];
                if(p==NULL){
                  yyval = yyvsp[0];
                }else{
                  while(p->sibling != NULL){
                    p = p->sibling;
                  }
                  p->sibling = yyvsp[0];
                  yyval = yyvsp[-2];
                }
              ;
    break;}
case 18:
#line 131 "cminus.y"
{ yyval = yyvsp[0]; ;
    break;}
case 19:
#line 135 "cminus.y"
{
                yyval = yyvsp[-1];
                yyval->kind.dec = ParamK;
                yyval->attr.name = savedName;
              ;
    break;}
case 20:
#line 141 "cminus.y"
{
                yyval = yyvsp[-3];
                yyval->kind.dec = ParamK;
                yyval->type = Array;
                yyval->size = 0;
                yyval->attr.name = savedName;
              ;
    break;}
case 21:
#line 151 "cminus.y"
{
                yyval = newStmtNode(CompK);
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[-1];
              ;
    break;}
case 22:
#line 159 "cminus.y"
{
                l = yyvsp[-1];
                if(l==NULL){
                  yyval = yyvsp[0];
                }else{
                  while(l->sibling != NULL){
                    l = l->sibling;
                  }
                  l->sibling = yyvsp[0];
                  yyval = yyvsp[-1];
                }
              ;
    break;}
case 23:
#line 171 "cminus.y"
{ yyval = NULL; ;
    break;}
case 24:
#line 175 "cminus.y"
{
                s = yyvsp[-1];
                if(s==NULL){
                  yyval = yyvsp[0];
                }else{
                  while(s->sibling != NULL){
                    s = s->sibling;
                  }
                  s->sibling = yyvsp[0];
                  yyval = yyvsp[-1];
                }
              ;
    break;}
case 25:
#line 187 "cminus.y"
{ yyval = NULL; ;
    break;}
case 26:
#line 190 "cminus.y"
{ yyval = yyvsp[0]; ;
    break;}
case 27:
#line 191 "cminus.y"
{ yyval = yyvsp[0]; ;
    break;}
case 28:
#line 192 "cminus.y"
{ yyval = yyvsp[0]; ;
    break;}
case 29:
#line 193 "cminus.y"
{ yyval = yyvsp[0]; ;
    break;}
case 30:
#line 194 "cminus.y"
{ yyval = yyvsp[0]; ;
    break;}
case 31:
#line 197 "cminus.y"
{yyval = yyvsp[-1];;
    break;}
case 32:
#line 198 "cminus.y"
{yyval = NULL;;
    break;}
case 33:
#line 202 "cminus.y"
{ yyval = newStmtNode(IfK);
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
                  yyval->child[2] = NULL;
                ;
    break;}
case 34:
#line 208 "cminus.y"
{ yyval = newStmtNode(IfK);
                  yyval->child[0] = yyvsp[-4];
                  yyval->child[1] = yyvsp[-2];
                  yyval->child[2] = yyvsp[0];
                ;
    break;}
case 35:
#line 216 "cminus.y"
{
                yyval = newStmtNode(WhileK);
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              ;
    break;}
case 36:
#line 224 "cminus.y"
{
                yyval = newStmtNode(RetK);
              ;
    break;}
case 37:
#line 228 "cminus.y"
{
                yyval = newStmtNode(RetK);
                yyval->child[0] = yyvsp[-1];
              ;
    break;}
case 38:
#line 235 "cminus.y"
{
                yyval = newExpNode(OpK);
                yyval->attr.op = ASSIGN;
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              ;
    break;}
case 39:
#line 241 "cminus.y"
{yyval = yyvsp[0];;
    break;}
case 40:
#line 245 "cminus.y"
{
                yyval = newExpNode(IdK);
                yyval->attr.name = savedName;
              ;
    break;}
case 41:
#line 250 "cminus.y"
{
                yyval = newExpNode(ArrIdK);
                yyval->attr.name = savedName;
              ;
    break;}
case 42:
#line 255 "cminus.y"
{
                yyval = yyvsp[-3];
                yyval->child[0] = yyvsp[-1];
              ;
    break;}
case 43:
#line 262 "cminus.y"
{
                yyval = yyvsp[-1];
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              ;
    break;}
case 44:
#line 267 "cminus.y"
{yyval = yyvsp[0];;
    break;}
case 45:
#line 270 "cminus.y"
{
                yyval = newExpNode(OpK);
                yyval->attr.op = LE;
              ;
    break;}
case 46:
#line 274 "cminus.y"
{
                yyval = newExpNode(OpK);
                yyval->attr.op = LT;
              ;
    break;}
case 47:
#line 278 "cminus.y"
{
                yyval = newExpNode(OpK);
                yyval->attr.op = GT;
              ;
    break;}
case 48:
#line 282 "cminus.y"
{
                yyval = newExpNode(OpK);
                yyval->attr.op = GE;
              ;
    break;}
case 49:
#line 286 "cminus.y"
{
                yyval = newExpNode(OpK);
                yyval->attr.op = EQ;
              ;
    break;}
case 50:
#line 290 "cminus.y"
{
                yyval = newExpNode(OpK);
                yyval->attr.op = NE;
              ;
    break;}
case 51:
#line 297 "cminus.y"
{
                yyval = yyvsp[-1];
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              ;
    break;}
case 52:
#line 302 "cminus.y"
{yyval = yyvsp[0];;
    break;}
case 53:
#line 305 "cminus.y"
{
                yyval = newExpNode(OpK); 
                yyval->attr.op = PLUS;
              ;
    break;}
case 54:
#line 309 "cminus.y"
{
                yyval = newExpNode(OpK);
                yyval->attr.op = MINUS;
              ;
    break;}
case 55:
#line 316 "cminus.y"
{
                yyval = yyvsp[-1];
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              ;
    break;}
case 56:
#line 321 "cminus.y"
{yyval = yyvsp[0];;
    break;}
case 57:
#line 324 "cminus.y"
{
                yyval = newExpNode(OpK); 
                yyval->attr.op = TIMES;
              ;
    break;}
case 58:
#line 328 "cminus.y"
{
                yyval = newExpNode(OpK);
                yyval->attr.op = OVER;
              ;
    break;}
case 59:
#line 335 "cminus.y"
{
                yyval = yyvsp[-1];
              ;
    break;}
case 60:
#line 339 "cminus.y"
{
                yyval = yyvsp[0];
              ;
    break;}
case 61:
#line 343 "cminus.y"
{
                yyval = yyvsp[0];
              ;
    break;}
case 62:
#line 347 "cminus.y"
{
                yyval = newExpNode(ConstK);
                yyval->attr.val = atoi(tokenString);
              ;
    break;}
case 63:
#line 354 "cminus.y"
{
                  yyval = newExpNode(CallK);
                  yyval->attr.name = savedName;  
                ;
    break;}
case 64:
#line 359 "cminus.y"
{
                yyval = yyvsp[-3];
                yyval->child[0] = yyvsp[-1];
              ;
    break;}
case 65:
#line 365 "cminus.y"
{yyval = yyvsp[0];;
    break;}
case 66:
#line 366 "cminus.y"
{ yyval = NULL; ;
    break;}
case 67:
#line 370 "cminus.y"
{
                a = yyvsp[-2];
                if(a==NULL){
                  yyval = yyvsp[0];
                }else{
                  while(a->sibling != NULL){
                    a = a->sibling;
                  }
                  a->sibling = yyvsp[0];
                  yyval = yyvsp[-2];
                }
              ;
    break;}
case 68:
#line 382 "cminus.y"
{yyval = yyvsp[0];;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 385 "cminus.y"


int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ 
  yyparse();
  return savedTree;
}
