%{
#include<stdio.h>
%}

%%

bool|int|float                { printf("Keyword\n"); }
[-+]?([0-9]+(\.[0-9]+)?)      { printf("Constant\n"); }
[,.'"]+                       { printf("Punctuation Char\n"); }
[!@#$%^&*()]+                 { printf("Special Char\n"); }
[a-zA-Z][a-zA-Z0-9]*          { printf("Identifier\n"); }

%%

int main()
{
    yylex();
    return 0;
}
