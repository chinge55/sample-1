extern int yylineno;
void yyerror(char *s, ...);

// Nodes in the abstract syntax tree

struct ast
{
    int nodetype;
    struct ast *l;
    struct ast *r;
};

struct numval
{
    int nodetype;
    double number;
};

// Build an AST

struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newnum(double d);

// Evaluate The AST(not to be written by me(not required in COmpiler))
double eval(struct ast *);

// delete the ast

void treefree(struct ast *);