#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "main.h"


status AnalyzeFile(const char *filename) 
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        printf("Error: Unable to open file\n");
        return FAILURE;
    }
    printf ("Open : %s  : succes\n", filename);

    char buffer[300];
    printf("Parsing...\n");

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char token[256];
        char ch;
        int index = 0;
        int i = 0;
        int str_flag = 0;
        while ((ch = buffer[i]) != '\0')
        {
            if (ch == '#') 
            {
                // Handle preprocessor directives
                printf("Preprocessor directive: %s\n", buffer);
                break;
            }
            else if (isspace(ch) || strchr(operator, ch) || strchr(o_braces, ch) || strchr(c_braces, ch) || ch == ';') 
            {

                if (index > 0 && ch!='[' && (str_flag != 1)) 
                {
                    // Terminate and classify the token
                    token[index] = '\0';
                    classifytoken(token);
                    index = 0;
                }
                if (str_flag)
                {
                    token[index++]=ch;
                }
                if (ch == '[') 
                {
                    // Handle array specifically
                    token[index++] = ch;
                    i++;
                    while (buffer[i] != '\0' && buffer[i] != ']')
                    {
                        token[index++] = buffer[i++];
                    }
                    if (buffer[i] == ']') 
                    {
                        token[index++] = buffer[i];
                    }
                    token[index] = '\0';
                    classifytoken(token);
                    index = 0;
                } 
                else if (strchr(o_braces, ch)) 
                {
                    printf("Open brace: %c\n", ch);
                } 
                else if (strchr(c_braces, ch)) 
                {
                    printf("Closing brace: %c\n", ch);
                } 
                else if (strchr(operator, ch)) 
                {
                    printf("Operator: %c\n", ch);
                } 
                else if (ch == ';') 
                {
                    printf("End terminator: %c\n", ch);
                }
            } 
            else 
            {
                if (ch == '"')
                {
                    str_flag = !str_flag; 
                }
                // Append character to the token
                token[index++] = ch;
            }
            i++;
        }
    }

    fclose(fp);
}
void classifytoken(char *token)
{
    if (iskeyword(token))
    {
        printf ("Keyword: %s\n",token);
    }
    else if (isarray(token))
    {
        printf ("Array: %s\n",token);
    }
    else if (ischarliteral(token))
    {
        printf ("character literal: %s\n",token);
    }
    else if (isstringliteral(token))
    {
        printf ("string literal: %s\n",token);
    }
    else if (isintegerliteral(token))
    {
        printf ("Integer literal: %s\n",token);
    }
    else if (isfloatliteral(token))
    {
        printf ("float literal: %s\n",token);
    }
    else if (isidentifier(token))
    {
        printf ("identifier: %s\n",token);
    }
    else
    {
        printf("unknown: %s\n",token);
    }
}