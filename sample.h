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
struct var_val
{
    int nodetype;
    char *type;
    char *name;

}; 

// Build an AST

struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newnum(double d);
struct ast *newassign(int nodetype, char *type, char *name);
// Evaluate The AST(not to be written by me(not required in COmpiler))
double eval(struct ast *);

// delete the ast

void treefree(struct ast *);