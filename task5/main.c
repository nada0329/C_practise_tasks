/*
Write a program to remove all comments from a C program.

*/
#include <stdio.h>
#include <stdlib.h>

FILE* ptr_input;
FILE* ptr_output;
void func();
void func2();
int main()
{

    unsigned char quote=0;
    unsigned char comm=0;
    char ch='0';
    int flag=0;

    ptr_input = fopen("input_test.txt", "r");
    ptr_output= fopen("output_file.txt","w");

    if (NULL == ptr_input) {
        printf("file can't be opened \n");
    }

    do {
        ch = fgetc(ptr_input);
        // ignore to handle any thing quoted
        if (ch== '\"')
            quote ^= 1;
        if(quote==1)
        {
            fputc (ch, ptr_output);
            continue;
        }
        else if(quote==0 && ch=='"')
        {
            fputc (ch, ptr_output);
            quote=0;
            continue;
        }
        // check existing of comments using func
        if( ch =='/')
        {

            func();

        }
        // reach here when you deal with normal char of the file
        else
        {
            fputc (ch, ptr_output);
        }



    } while (ch != EOF);


    fclose(ptr_input);
    fclose(ptr_output);


    return 0;
}

void func()
{
    unsigned char flag;
    char c,t;
    c=fgetc(ptr_input);
    if(c=='/')
    {
        while(fgetc(ptr_input) != '\n')
        {
            /* wait tell the end of the commented line */
        }
        fputc('\n',ptr_output);
    }
    else if(c=='*')
    {
        //func to test its end of commented lines or just * sign
    func2();
    }
    else
    {
        // here you deal with default / sign
        fputc('/',ptr_output);
        fputc(c,ptr_output);
    }


}

void func2()
{

    int f=0;
    while(fgetc(ptr_input) != '*' )
    {

    }
    if(fgetc(ptr_input) =='/')
        return;
    else
        func2();

}
