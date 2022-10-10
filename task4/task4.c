/*
Write a function reverse (s) that reverses the character
string s. Use it to write a program that reverses its input a line at a time.

max allowed input len =150
*/

#include <stdio.h>
#include <stdlib.h>

#define max_len 150

int func_to_read(char *s, int maxlen);
void printline(char *s, int len);
int main(void)
{
    char line[max_len];
    int actuallen=func_to_read(line, max_len);
    while(actuallen>0)
    {
        printline(line,actuallen);
        actuallen=func_to_read(line, max_len);
    }

    return 0;
}

int func_to_read(char *s, int maxlen)
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
    for(int i=len-1;i>=0;i--)
    {
        printf("%c",s[i]);
    }
    printf("\n");
}




