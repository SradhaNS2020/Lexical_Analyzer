#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

status iskeyword(char *token)
{
    for(int i=0;keywords[i]!=NULL;i++)
    {
        if (strcmp(token,keywords[i]) == 0)
        {
            return SUCCESS;
        }
    }
    return FAILURE;
}
status ischarliteral(char *token)
{
    if (token[0]=='\'' && token[strlen(token)-1]=='\'')
    {
        return SUCCESS;
    }
    return FAILURE;
}
status isstringliteral(char *token)
{
    if (token[0]=='"' && token[strlen(token)-1]=='"')
    {
        return SUCCESS;
    }
    return FAILURE; 
}
status isarray(char *token)
{
    if (strchr(token, '[') && strchr(token, ']'))
    {
        return SUCCESS;
    }
    return FAILURE;
}
status isintegerliteral(char *token)
{
    for (int i=0;token[i]!='\0';i++)
    {
        if (!isdigit(token[i]))
        {
            return FAILURE;
        }
    }
    return SUCCESS;
}
status isfloatliteral(char *token)
{
    int dotcount=0;
    for (int i=0;token[i]!='\0';i++)
    {
        if (!(isdigit(token[i]) || token[i] == '.'))
        {
            return FAILURE;
        }
        if (token[i] == '.')
        {
            dotcount++;
        }
    }
    if (dotcount>1)
    {
        return FAILURE;
    }
    return SUCCESS;
}
status isidentifier (char *token)
{
    int len = strlen(token);
    
    // Check if the first character is a letter or underscore
    if (!isalpha(token[0]) && token[0] != '_') 
    {
        return FAILURE; // Invalid identifier
    }
    
    // Check the rest of the characters
    for (int i = 1; i < len; i++)
    {
        if (!isalnum(token[i]) && token[i] != '_')
        {
            return FAILURE; // Invalid identifier
        }
    }
    return SUCCESS;
}
