#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define LINE_LEN 100
void lex(char* line);
int Delimeter(char c);
int Operator(char c);
char* subString(char* line, int left, int right);
int Keyword(char* line);
int Integer(char* line);
int RealNumber(char* line);

int main()
{
    printf("***CENG2002 LEXICAL PARSER HOMEWORK FOR FINAL EXAM***\n");
    printf("***The String Is:\n");

    char line[LINE_LEN];
    FILE *inp;
    inp= fopen("stringtoparse.txt","r");
    fgets(line,LINE_LEN,inp);
    printf("%s\n",line);

    printf("\n***TOKENIZED VERSION IS***\n");

    lex(line);

    fclose(inp);

    return 0;
}

void lex (char* line)
{
    int left=0, right=0;
    int len = strlen(line);
    while (right <= len && left <= right) {


        if (Delimeter(line[right]) == 1 && right == left) {
            right++;

            while(right <= len && Operator(line[right]) == 1){

                    printf("'%c' IS AN OPERATOR\n", line[right]);
                    right++;

                }
            left= right;

        }else if (Delimeter(line[right])== 1 && left!=right ||
                  (right== len && left !=right)){

            char* subStr = subString (line, left, right-1);

            if (Keyword(subStr)== 1)
                printf("'%s' IS A KEYWORD\n", subStr);

            else if (Integer(subStr) == 1)
                printf("'%s' IS AN INTEGER\n", subStr);

            else if (RealNumber(subStr) == 1)
                printf("'%s' IS A REAL NUMBER\n", subStr);

            else if (validIdentifier(subStr) == 1)
                printf("'%s' IS A VALID IDENTIFIER\n", subStr);

            else if (validIdentifier(subStr) == 0 )
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);

            left = right;



        }else{
            right++;

        }


    }
    return;
}


int Delimeter(char c)
{
    if(c==' '|| c == '{' || c == '}' ||
       c == '[' || c == ']' || c == '(' || c == ')')
       return (1);
    return(0);

}

int Operator(char c)
{
    if (c == '+' || c == '-' || c == '*' ||
        c == '/' || c == '>' || c == '<' ||
        c == '=')
        return (1);
    return (0);
}


char* subString(char* line, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = line[i];
     subStr[right - left + 1] = '\0';


    return (subStr);
}

int Keyword(char* line)
{
    if (!strcmp(line, "if") || !strcmp(line, "else") ||
        !strcmp(line, "do") || !strcmp(line, "while") ||
        !strcmp(line, "break") ||!strcmp(line, "continue")||
        !strcmp(line, "switch") || !strcmp(line, "case")||
        !strcmp(line, "short") || !strcmp(line, "int") ||
        !strcmp(line, "long") || !strcmp(line, "double") ||
        !strcmp(line, "float") || !strcmp(line, "char") ||
        !strcmp(line, "return") || !strcmp(line, "void") ||
        !strcmp(line, "NULL") || !strcmp(line, "struct"))
        return (1);
    return (0);
}
int Integer(char* line)
{
    int i, len = strlen(line);

    if (len == 0)
        return (0);
    for (i = 0; i < len; i++) {
        if (line[i] != '0' && line[i] != '1' && line[i] != '2'
            && line[i] != '3' && line[i] != '4' && line[i] != '5'
            && line[i] != '6' && line[i] != '7' && line[i] != '8'
            && line[i] != '9' || (line[i] == '-' && i > 0))
            return (0);
    }
    return (1);
}

int RealNumber(char* line)
{
    int i, len = strlen(line);
    int hasDecimal = 0;

    if (len == 0)
        return (0);
    for (i = 0; i < len; i++) {
        if (line[i] != '0' && line[i] != '1' && line[i] != '2'
            && line[i] != '3' && line[i] != '4'&& line[i] != '5'
            && line[i] != '6' && line[i] != '7' && line[i] != '8'
            && line[i] != '9' && line[i] != '.' ||
            (line[i] == '-' && i > 0))
            return (0);
        if (line[i] == '.')
            hasDecimal = 1;
        }
        return (hasDecimal);

}
int validIdentifier(char* line)
{
    if (line[0] == '0' || line[0] == '1' || line[0] == '2' ||
        line[0] == '3' || line[0] == '4' || line[0] == '5' ||
        line[0] == '6' || line[0] == '7' || line[0] == '8' ||
        line[0] == '9' || line[0] == '\0')
        return (0);


    else
        return (1);
}

