/*
Write a program to print a histogram of the frequencies of different characters in its input

here i use '!' as indicator that the input data is done
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c;
    int arr_chars[26]={0};
    int arr_digits[10]={0};

    c=getchar();
    while( c != '!')
    {
        if(c!=' ' || c!='\t' || c!='\n')
        {
            if(c>='0' && c<='9')
                ++arr_digits[c-'0'];
            else if(c>='a' && c <='z')
                ++arr_chars[c-'a'];
        }
         c=getchar();
    }
    printf("\nhistogram of your input text based on char freq\n");
    for(int i=0; i<26; i++)
    {
        printf("%c : ",(i+'a') );
        for(int j=0; j<arr_chars[i]; j++)
            printf("*");
        printf("\n");
    }
    for(int i=0; i<10; i++)
    {
        printf("%d : ",i );
        for(int j=0; j<arr_digits[i]; j++)
            printf("*");
        printf("\n");
    }

  return 0;
}

