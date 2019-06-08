%{
    #include "sample.h"
    #include "sample.tab.h"    
    int yylex();
%}


%%
[-+=/*|()]      {return yytext[0];}
[0-9]+          {yylval.d = atof(yytext); return NUMBER;}
\n              {return EOL;}
[a-z]+          {return NAME;}
"int"           {return INT;}
"//".*
[ \t]           {/*ignore whitespace*/}
%%
int yywrap(void)    {return 1;}