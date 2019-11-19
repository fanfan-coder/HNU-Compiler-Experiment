#include "globals.h"
#include "util.h"

char *typeStrings[] = { "void", "int", "int[]" };
/* Procedure printToken prints a token
 * and its lexeme to the listing file
 */
void printToken(TokenType token, const char* tokenString)
{
	switch (token)
	{
	case IF:
	case ELSE:
	case WHILE:
	case RETURN:
	case INT:
	case VOID:
		fprintf(listing,
			"reserved word: %s\n", tokenString);
		break;
	case ASSIGN: fprintf(listing, "=\n"); break;
	case EQ: fprintf(listing, "==\n"); break;
	case NE: fprintf(listing, "!=\n"); break;
	case LT: fprintf(listing, "<\n"); break;
	case LE: fprintf(listing, "<=\n"); break;
	case GT: fprintf(listing, ">\n"); break;
	case GE: fprintf(listing, ">=\n"); break;
	case LPAREN: fprintf(listing, "(\n"); break;
	case RPAREN: fprintf(listing, ")\n"); break;
	case LBRACE: fprintf(listing, "[\n"); break;
	case RBRACE: fprintf(listing, "]\n"); break;
	case LCURLY: fprintf(listing, "{\n"); break;
	case RCURLY: fprintf(listing, "}\n"); break;
	case SEMI: fprintf(listing, ";\n"); break;
	case COMMA: fprintf(listing, ",\n"); break;
	case PLUS: fprintf(listing, "+\n"); break;
	case MINUS: fprintf(listing, "-\n"); break;
	case TIMES: fprintf(listing, "*\n"); break;
	case OVER: fprintf(listing, "/\n"); break;
	case ENDFILE: fprintf(listing, "EOF\n"); break;
	case NUM:
		fprintf(listing,
			"NUM, val= %s\n", tokenString);
		break;
	case ID:
		fprintf(listing,
			"ID, name= %s\n", tokenString);
		break;
	case ERROR:
		fprintf(listing,
			"ERROR: %s\n", tokenString);
		break;
	default: /* should never happen */
		fprintf(listing, "Unknown token: %d\n", token);
	}
}

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode * newStmtNode(StmtKind kind)
{
	TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		fprintf(listing, "Out of memory error at line %d\n", lineno);
	else {
		for (i = 0; i < MAXCHILDREN; i++) t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = StmtK;
		t->kind.stmt = kind;
		t->lineno = lineno;
	}
	return t;
}

TreeNode * newDecNode(DecKind kind)
{
	TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		fprintf(listing, "Out of memory error at line %d\n", lineno);
	else {
		for (i = 0; i < MAXCHILDREN; i++) t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = DecK;
		t->kind.dec = kind;
		t->lineno = lineno;
	}
	return t;
}

/* Function newExpNode creates a new expression
 * node for syntax tree construction
 */
TreeNode * newExpNode(ExpKind kind)
{
	TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		fprintf(listing, "Out of memory error at line %d\n", lineno);
	else {
		for (i = 0; i < MAXCHILDREN; i++) t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = ExpK;
		t->kind.exp = kind;
		t->lineno = lineno;
		t->type = Void;
	}
	return t;
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char * copyString(char * s)
{
	int n;
	char * t;
	if (s == NULL) return NULL;
	n = strlen(s) + 1;
	t = malloc(n);
	if (t == NULL)
		fprintf(listing, "Out of memory error at line %d\n", lineno);
	else strcpy(t, s);
	return t;
}

/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{
	int i;
	for (i = 0; i < indentno; i++)
		fprintf(listing, " ");
}

/* procedure printTree prints a syntax tree to the
 * listing file using indentation to indicate subtrees
 */
void printTree(TreeNode * tree)
{
	int i;
	INDENT;
	while (tree != NULL) {
		printSpaces();
		if (tree->nodekind == StmtK)
		{
			switch (tree->kind.stmt) {
			case IfK:
				if (tree->child[2] == NULL)
					fprintf(listing, "If (condition) (body)\n");
				else
					fprintf(listing, "If (condition) (body) (else)\n");
				break;
			case WhileK:
				fprintf(listing, "While\n");
				break;
			case CompK:
				fprintf(listing, "Compound statement :\n");
				break;
			case RetK:
				fprintf(listing, "Return\n");
				break;
			default:
				fprintf(listing, "Unknown StmtNode kind\n");
				break;
			}
		}
		else if (tree->nodekind == ExpK)
		{
			switch (tree->kind.exp) {
			case OpK:
				if (tree->attr.op == ASSIGN) {
					fprintf(listing, "Assign :(destination) (source)\n");
				}
				else {
					fprintf(listing, "Op: ");
					printToken(tree->attr.op, "");
				}
				break;
			case ConstK:
				fprintf(listing, "Const: %d\n", tree->attr.val);
				break;
			case IdK:
				fprintf(listing, "Id: %s\n", tree->attr.name);
				break;
			case CallK:
				fprintf(listing, "Call, name: %s, with arguments below\n", tree->attr.name);
				break;
			case ArrIdK:
				fprintf(listing, "Array : [%s]\n", tree->attr.name);
				break;
			default:
				fprintf(listing, "Unknown ExpNode kind\n");
				break;
			}
		}
		else if (tree->nodekind == DecK)
		{
			switch (tree->kind.dec) {
			case VarK:
				if (tree->type == Array)
					fprintf(listing, "Var declaration, name: %s, type: %s, size: %d\n", tree->attr.name, typeStrings[tree->type], tree->size);
				else
					fprintf(listing, "Var declaration, name: %s, type: %s\n", tree->attr.name, typeStrings[tree->type]);
				break;
			case FunK:
				fprintf(listing, "Function declaration, name: %s, return type: %s\n", tree->attr.name, typeStrings[tree->type]);
				break;
			case ParamK:
				/*
				if(tree->type == 0)
				  fprintf(listing,"Param: %s\n",tree->type);
				else
				*/
				if (tree->type == Array)
					fprintf(listing, "array Param, name: %s, type: %s , size: %d\n", tree->attr.name, typeStrings[tree->type], tree->size);
				else
					fprintf(listing, "single Parameter, name: %s, type: %s\n", tree->attr.name, typeStrings[tree->type]);
				break;
			default:
				fprintf(listing, "Unknown DecNode kind\n");
				break;
			}
		}
		else fprintf(listing, "Unknown node kind\n");
		for (i = 0; i < MAXCHILDREN; i++)
			printTree(tree->child[i]);
		tree = tree->sibling;
	}
	UNINDENT;
}