%{
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

%}

%token IF ELSE RETURN WHILE VOID INT
%token ID NUM
%token ASSIGN EQ NE LT LE GT GE PLUS MINUS TIMES OVER SEMI COMMA LPAREN RPAREN LBRACE RBRACE LCURLY RCURLY
%token ERROR 

%% /* Grammar for TINY */

program     : dec_list
                 { savedTree = $1;} 
            ;

dec_list    : dec_list dec
              {
                d = $1;
                if(d==NULL){
                  $$ = $2;
                }else{
                  while(d->sibling != NULL){
                    d = d->sibling;
                  }
                  d->sibling = $2;
                  $$ = $1;
                }
              }
              
            | dec { $$ = $1; }
            ;

dec         : var_dec { $$ = $1; }
            | fun_dec { $$ = $1; }
            ;

id          : ID
              {
                savedName = copyString(tokenString);
              };


var_dec     : type_spec id SEMI
              {
                $$ = $1;
                $$->attr.name = savedName;
              }
            | type_spec id 
              {
                $$ = $1;
                $$->attr.name = savedName;
                $$->type = Array;
              }
              LBRACE NUM
              {
                $$ = $3;
                $$->size = atoi(tokenString);
              }
              RBRACE SEMI
              {
                $$ = $6;
              }
            ;

type_spec   : INT
              {
                $$ = newDecNode(VarK);
                $$->type = Integer;
              }
            | VOID
              {
                $$ = newDecNode(VarK);
                $$->type = Void;
              }
            ;

fun_dec     : type_spec id 
                {
                  $$ = $1;
                  $$->kind.dec = FunK;
                  $$->attr.name = savedName;
                }
              LPAREN params RPAREN comp_stmt
              {
                $$ = $3;
                
                $$->child[0] = $5;
                $$->child[1] = $7;
              }
            ;

params      : params_list {$$ = $1;}
            | VOID
              {
                $$ = newDecNode(ParamK);
                $$->type = Void;
              }
            ;

params_list : params_list COMMA param
              {
                p = $1;
                if(p==NULL){
                  $$ = $3;
                }else{
                  while(p->sibling != NULL){
                    p = p->sibling;
                  }
                  p->sibling = $3;
                  $$ = $1;
                }
              }
            | param { $$ = $1; }
            ;

param       : type_spec id
              {
                $$ = $1;
                $$->kind.dec = ParamK;
                $$->attr.name = savedName;
              }
            | type_spec id LBRACE RBRACE
              {
                $$ = $1;
                $$->kind.dec = ParamK;
                $$->type = Array;
                $$->size = 0;
                $$->attr.name = savedName;
              }
            ;

comp_stmt   : LCURLY local_dec stmt_list RCURLY
              {
                $$ = newStmtNode(CompK);
                $$->child[0] = $2;
                $$->child[1] = $3;
              }
            ;

local_dec   : local_dec var_dec
              {
                l = $1;
                if(l==NULL){
                  $$ = $2;
                }else{
                  while(l->sibling != NULL){
                    l = l->sibling;
                  }
                  l->sibling = $2;
                  $$ = $1;
                }
              }
            | { $$ = NULL; }
            ;

stmt_list   : stmt_list stmt
              {
                s = $1;
                if(s==NULL){
                  $$ = $2;
                }else{
                  while(s->sibling != NULL){
                    s = s->sibling;
                  }
                  s->sibling = $2;
                  $$ = $1;
                }
              }
            | { $$ = NULL; }
            ;

stmt        : exp_stmt { $$ = $1; }
            | comp_stmt { $$ = $1; }
            | select_stmt { $$ = $1; }
            | iter_stmt { $$ = $1; }
            | return_stmt { $$ = $1; }
            ;

exp_stmt    : exp SEMI {$$ = $1;}
            | SEMI {$$ = NULL;}
            ;

select_stmt : IF LPAREN exp RPAREN stmt
                { $$ = newStmtNode(IfK);
                  $$->child[0] = $3;
                  $$->child[1] = $5;
                  $$->child[2] = NULL;
                }
            | IF LPAREN exp RPAREN stmt ELSE stmt
                { $$ = newStmtNode(IfK);
                  $$->child[0] = $3;
                  $$->child[1] = $5;
                  $$->child[2] = $7;
                }
            ;

iter_stmt   : WHILE LPAREN exp RPAREN stmt
              {
                $$ = newStmtNode(WhileK);
                $$->child[0] = $3;
                $$->child[1] = $5;
              }
            ;

return_stmt : RETURN SEMI
              {
                $$ = newStmtNode(RetK);
              }
            | RETURN exp SEMI
              {
                $$ = newStmtNode(RetK);
                $$->child[0] = $2;
              }
            ;

exp         : var ASSIGN exp
              {
                $$ = newExpNode(OpK);
                $$->attr.op = ASSIGN;
                $$->child[0] = $1;
                $$->child[1] = $3;
              }
            | simple_exp {$$ = $1;}
            ;

var         : id
              {
                $$ = newExpNode(IdK);
                $$->attr.name = savedName;
              }
            | id 
              {
                $$ = newExpNode(ArrIdK);
                $$->attr.name = savedName;
              }
              LBRACE exp RBRACE
              {
                $$ = $2;
                $$->child[0] = $4;
              }
            ;

simple_exp  : add_exp relop add_exp
              {
                $$ = $2;
                $$->child[0] = $1;
                $$->child[1] = $3;
              }
            | add_exp {$$ = $1;}
            ;

relop       : LE {
                $$ = newExpNode(OpK);
                $$->attr.op = LE;
              }
              | LT {
                $$ = newExpNode(OpK);
                $$->attr.op = LT;
              }
              | GT {
                $$ = newExpNode(OpK);
                $$->attr.op = GT;
              }
              | GE {
                $$ = newExpNode(OpK);
                $$->attr.op = GE;
              }
              | EQ {
                $$ = newExpNode(OpK);
                $$->attr.op = EQ;
              }
              | NE {
                $$ = newExpNode(OpK);
                $$->attr.op = NE;
              }
            ;

add_exp     : add_exp addop term
              {
                $$ = $2;
                $$->child[0] = $1;
                $$->child[1] = $3;
              }
            | term {$$ = $1;}
            ;

addop       : PLUS {
                $$ = newExpNode(OpK); 
                $$->attr.op = PLUS;
              }
              | MINUS {
                $$ = newExpNode(OpK);
                $$->attr.op = MINUS;
              }
            ;

term        : term mulop factor
              {
                $$ = $2;
                $$->child[0] = $1;
                $$->child[1] = $3;
              }
            | factor {$$ = $1;}
            ;

mulop       : TIMES {
                $$ = newExpNode(OpK); 
                $$->attr.op = TIMES;
              }
              | OVER {
                $$ = newExpNode(OpK);
                $$->attr.op = OVER;
              }
            ;

factor      : LPAREN exp RPAREN
              {
                $$ = $2;
              }
            | var
              {
                $$ = $1;
              }
            | call
              {
                $$ = $1;
              }
            | NUM
              {
                $$ = newExpNode(ConstK);
                $$->attr.val = atoi(tokenString);
              }
            ;

call        : id 
                {
                  $$ = newExpNode(CallK);
                  $$->attr.name = savedName;  
                }
              LPAREN args RPAREN
              {
                $$ = $2;
                $$->child[0] = $4;
              }
            ;

args        : arg_list {$$ = $1;}
            | { $$ = NULL; }
            ;

arg_list    : arg_list COMMA exp
              {
                a = $1;
                if(a==NULL){
                  $$ = $3;
                }else{
                  while(a->sibling != NULL){
                    a = a->sibling;
                  }
                  a->sibling = $3;
                  $$ = $1;
                }
              }
            | exp {$$ = $1;}


%%

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
