#include "GLOBALS.H"
#include "ANALYZE.H"
#include "SYMTAB.H"

static int location = 0;

static void traverse(TreeNode * t, void (* preProc) (TreeNode *), void (* postProc) (TreeNode *))
{ 
    if(t == NULL) return;

    preProc(t);
    for (int i = 0; i < MAXCHILDREN; ++i)
        traverse(t->child[i], preProc, postProc);
    postProc(t);
    traverse(t->sibling, preProc, postProc);
}

static void nullProc(TreeNode * t)
{ 
    return;
}

static void insertNode(TreeNode * t)
{ 
    switch (t->nodekind)
    { 
        case StmtK:
            switch (t->kind.stmt)
            { 
                case AssignK:
                case ReadK:
                    st_insert(t->attr.name, t->lineno, &location);
                    break;
                default:
                    break;
            }
            break;
        case ExpK:
            switch (t->kind.exp)
            { 
                case IdK:
					st_insert(t->attr.name, t->lineno, &location);
					break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void buildSymtab(TreeNode * syntaxTree)
{ 
    traverse(syntaxTree, insertNode, nullProc);
    if (TraceAnalyze)
    { 
		fprintf(listing, "\nSymbol table:\n\n");
        printSymTab(listing);
    }
}

static void typeError(TreeNode * t, char * message)
{ 
	fprintf(listing, "Type error at line %d: %s\n", t->lineno, message);
    Error = TRUE;
}

static void checkNode(TreeNode * t)
{ 
    switch (t->nodekind)
    { 
        case StmtK:
            switch (t->kind.stmt)
            { 
                case IfK:
                    if (t->child[0]->type == Integer)
                        typeError(t->child[0], "if test is not Boolean");
                    break;
                case RepeatK:
                    if (t->child[1]->type == Integer)
                        typeError(t->child[1], "repeat test is not Boolean");
                    break;
                case AssignK:
                    if (t->child[0]->type != Integer)
                        typeError(t->child[0], "assignment of non-integer value");
                    break;
                case WriteK:
                    if (t->child[0]->type != Integer)
                        typeError(t->child[0], "write of non-integer value");
                    break;
                default:
                    break;
            }
            break;
        case ExpK:
            switch (t->kind.exp)
            { 
                case OpK:
                    if ((t->child[0]->type != Integer) || (t->child[1]->type != Integer))
                        typeError(t, "Op applied to non-integer");
                    if ((t->attr.op == EQ) || (t->attr.op == LT))
                        t->type = Boolean;
                    else
                        t->type = Integer;
                    break;
                case ConstK:
                case IdK:
                    t->type = Integer;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
  }
}

void typeCheck(TreeNode * syntaxTree)
{ 
    traverse(syntaxTree, nullProc, checkNode);
}
