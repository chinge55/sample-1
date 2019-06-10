#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "sample.h"

struct ast *newast(int nodetype, struct ast *l, struct ast *r)
{
    struct ast *temp = malloc(sizeof(struct ast));
    if(!temp)
    {
        yyerror("OUt of Space");
        exit(0);
    }
    temp->nodetype = nodetype;
    temp->l = l;
    temp->r = r; 
}

struct ast *newnum(double d)
{
    struct numval *temp = malloc(sizeof(struct numval));
    if(!temp)
    {
        yyerror("Out of Space");
        exit(0);
    }
    temp->nodetype = 'K';
    temp->number = d;
    return (struct ast *)temp;
}

 struct ast *newassign(int nodetype, char *type, char *name)
 {
     struct var_val *temp = malloc(sizeof(struct var_val));
     if(!temp)
     {
         yyerror("Out of space");
         exit(0);
     }
     temp->nodetype = nodetype;
     temp->type = type;
     temp-> name = name;
     return (struct ast*)temp;
 }

double eval(struct ast *a)
{
    /*double v;
    switch(a->nodetype)
    {
    case 'K': v = ((struct numval*)a)->number; break;
    case '+': v = eval(a->l) + eval(a->r); break;
    case '-': v = eval(a->l) - eval(a->r); break;
    case '*': v = eval(a->l) * eval(a->r); break;
    case '/': v = eval(a->l) / eval(a->r); break;
    case '|': v = eval(a->l); if(v<0) v = -v; break;
    case 'M': v = -eval(a->l); break;
    default: printf("ERROR On Node:%c\n",a->nodetype);
    }
    return v;
    */
}

void treefree(struct ast *a)
{
    // switch(a->nodetype)
    // {
    // case '+':
    // case '-':
    // case '*':
    // case '/':
    //     treefree(a->r);
    // case '|':
    // case 'M':
    //     treefree(a->l);
    // case 'K':
    //     free(a);
    //     break;
    // default: printf("Internal ERROR on Node %c\n",a->nodetype);
    // }
}

void yyerror(char *s, ...)
{
    va_list ap;
    va_start(ap, s);
    fprintf(stderr, "%d: error", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}
int main()
{
    printf(">");
    return yyparse();
}