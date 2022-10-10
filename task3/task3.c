/*
Write a program to print all input lines that are longer than 80
characters.

max allowed input len =150
*/

#include <stdio.h>
#include <stdlib.h>

#define max_len 150

int func_to_test(char *s, int maxlen);
void printline(char *s, int len);
int main(void)
{
    char line[max_len];
    int actuallen=func_to_test(line, max_len);
    while(actuallen>0)
    {
        if(actuallen>80)
            printline(line,actuallen);
        actuallen=func_to_test(line, max_len);
    }

    return 0;
}

int func_to_test(char *s, int maxlen)
{
    int numofchars=0;
    char c;
    c=getchar();
    while(c !='\n' )
    {
        s[numofchars]=c;
        c=getchar();
        numofchars++;

    }
    if( numofchars < maxlen)
        return numofchars;
    else
        return 0;
}

void printline(char *s, int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%c",s[i]);
    }
    printf("\n");
}




