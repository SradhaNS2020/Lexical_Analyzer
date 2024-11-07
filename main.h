#ifndef MAIN_H
#define MAIN_H

typedef enum
{
    FAILURE,
    SUCCESS
}status;

static const char *keywords[] = {"auto","break","case","char",
"const","continue","default","do",
"double","else","enum",	"extern",
"float","for","goto","if",
"int","long","register","return",
"short","signed","sizeof","static",
"struct","switch","typedef","union",
"unsigned","void","volatile","while",NULL};

static const char *operator = "+-*/|&=%,?:><^!";
static const char *o_braces = "{([";
static const char *c_braces = ")}]";

status AnalyzeFile(const char *);
void classifytoken(char *token);
status iskeyword(char*);
status ischarliteral(char*);
status isintegerliteral(char*);
status isfloatliteral(char*);
status isstringliteral(char *);
status isarray(char *);
status isidentifier(char *);

#endif 
