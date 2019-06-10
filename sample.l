%{
    #include "sample.h"
    #include "sample.tab.h"    
    int yylex();
%}


%%
[-+=/*|()]      {return yytext[0];}
[0-9]+          {yylval.d = atof(yytext); return NUMBER;}
[a-z]+          {yylval.name = yytext; return NAME;}
"int"           {yylval.c = yytext; return INT;}
"//".*
[ \t]           {/*ignore whitespace*/}
%%
int yywrap(void)    {return 1;}