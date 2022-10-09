/*
Write a program to print a histogram of the lengths of words in
its input.

here i use '!' as indicator that the input data is done
max input words is 50
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c;
    int arr_count_each_word[50]={0};
    int count_words=0;
    int count_char_of_word=0;
    int end_of_word=0;
    int min_char=26, max_char=0;
    c=getchar();
    while( c != '!')
    {
        if(c==' ' || c=='\t' || c=='\n')
        {
            count_words++;
            end_of_word=1;

        }
        else
        {
            count_char_of_word++;
            end_of_word=0;
        }
        if(end_of_word==1)
        {
            arr_count_each_word[count_words-1]=count_char_of_word;
            if(count_char_of_word>max_char)
                max_char=count_char_of_word;
            if(count_char_of_word<min_char)
                min_char=count_char_of_word;
            count_char_of_word=0;
        }
         c=getchar();
    }
/*for(int y=0;y<count_words;y++)
        printf("%d ",arr_count_each_word[y]);
printf("\n");*/
    int *ptr= (int*)calloc((max_char-min_char+1),sizeof(int));
    for(int i=0; i<count_words; i++)
    {
/*printf("%d ", arr_count_each_word[i]-min_char);*/
       ++ptr[ (arr_count_each_word[i]-min_char) ];
    }
/*printf("\n");
for(int y=0; y<(max_char-min_char+1);y++)
        printf("%d ",ptr[ y ]);*/


    printf("\nhistogram of your input text\n");
    for(int i=min_char; i<=max_char; i++)
    {
        printf("%2d : ",i);

        for(int j=0; j<ptr[i-min_char]; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    free(ptr);
  return 0;
}
