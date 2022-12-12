#include<stdio.h>
#include<string.h>
char op[2],arg1[5],arg2[5],result[5];
void main()
{
FILE *fp1,*fp2;
fp1=fopen("input.txt","r");
fp2=fopen("output.txt","w");
while(!feof(fp1))
{
 fscanf(fp1,"%s%s%s%s",op,arg1,arg2,result);
if(strcmp(op,"+")==0)
{
 fprintf(fp2,"\nMOV RO %s",arg1);
 fprintf(fp2,"\nADD RO %s",arg2);
 fprintf(fp2,"\nMOV %s ,R0\n",result);
}
if(strcmp(op,"*")==0)
{
 fprintf(fp2,"\nMOV RO %s",arg1);
 fprintf(fp2,"\nMUL RO %s",arg2);
 fprintf(fp2,"\nMOV %s ,R0\n",result);
}
if(strcmp(op,"/")==0)
{
 fprintf(fp2,"\nMOV RO %s",arg1);
 fprintf(fp2,"\nDIV RO %s",arg2);
 fprintf(fp2,"\nMOV %s ,R0\n",result);
}
if(strcmp(op,"-")==0)
{
 fprintf(fp2,"MOV RO %s",arg1);
 fprintf(fp2,"\nSUB RO %s",arg2);
 fprintf(fp2,"\nMOV %s ,R0\n",result);
}
if(strcmp(op,"=")==0)
{
 fprintf(fp2,"\nMOV RO %s",arg1);
 fprintf(fp2,"\nMOV %s ,R0\n",result);
}
}
fclose(fp1);
fclose(fp2);
}

/*
input.txt
- a b t1
+ a b t1
/ a b t1
* a b t1
= a t1


*/