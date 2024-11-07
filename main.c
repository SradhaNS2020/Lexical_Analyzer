#include <stdio.h>
#include "main.h"

int main(int argc,char* argv[])
{
   if (argc<2)
   {
     printf("usage: %s <filename>\n",argv[0]);
     return FAILURE; 
   }
   AnalyzeFile(argv[1]);
   printf ("Parsing : %s : Done\n",argv[0]);
   return SUCCESS;
}