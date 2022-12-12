\\.l
%{
#include<stdio.h>
%}
%%
[0-9]+ {
 yylval=atoi(yytext);
 return NUMBER;
 }
[\t] ;
[\n] return 0;
. {return yytext[0];}
%%
int yywrap()
{
return 1;
}
\\.y
%{
 #include<stdio.h>
 int flag=0;
 int yylex();
 void yyerror();
%}
%token NUMBER
%left '+''-'
%left '*''/''%'
%left '('')'
%% 
ArithmeticExpression:E{printf("\nResult=%d\n",$$);
 return 0;
 }
E:E'+'E {$$=$1+$3;}
 |E'-'E {$$=$1-$3;}
 |E'*'E {$$=$1*$3;}
 |E'/'E {$$=$1/$3;}
 |E'%'E {$$=$1%$3;}
 |'('E')' {$$=$2;}
 |NUMBER {$$=$1;}
;
%%
void main()
{
printf("Enter any arthimetic Expression which can have operations 
Addition,subtraction,Multipication,Division,Mdulus and Round brackets:\n");
yyparse();
if(flag==0)
printf("Entered arithmetic expression is Valid\n\n");
}
void yyerror()
{
printf("Entered arithmetic expreession is Invalid \n\n");
flag=1;
}
