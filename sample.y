%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "sample.h"
%}

%union
{
    struct ast *a;
    double d;
    char *c;
    char* name;
}

%token <d> NUMBER
%token EOL
%token <name>NAME
%token <c>INT
%type <a> exp factor term

%%
calclist:
        | calclist exp EOL{
            // printf("=%4.4g\n",eval($2));
            // treefree($2);
            // printf(">");
        }
        | calclist EOL {printf(">");}
        ;

exp: factor
        | exp '+' factor    {$$ = newast('+', $1, $3);}
        | exp '-' factor    {$$ = newast('-', $1, $3);}
        ;

factor: term
        | factor '*' term    {$$ = newast('*', $1, $3);}
        | factor '/' term    {$$ = newast('/', $1, $3);}
        ;

term: NUMBER                {$$ = newnum($1);}
    | '|' term              {$$ = newast('|', $2, NULL);}
    | '(' exp ')'           {$$ = $2;}
    | '-' term              {$$ = newast('M', $2, NULL);}
    | INT NAME              {$$ = newassign('D', $1, $2);}
    ;
%%