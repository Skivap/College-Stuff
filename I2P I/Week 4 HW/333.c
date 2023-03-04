#include <stdio.h>
#include <ctype.h>
#define STOP '|'
int main(void)
{
    char c;
    char prev;
    long n_chars=0L;
    int n_lines=0;
    int n_words=0;
    int p_lines=0;
    int inword=0; // flag indicating whether the current character is in a word
    printf("Enter text to be analyzed (| to terminate): \n");
    prev='\n';
    while((c=getchar())!=STOP)
    {
        //a character
        n_chars++;
        //a line
        if(c=='\n')
            n_lines++;
        //a word
        if(!isspace(c)&&!inword)
        {
            inword=1;
            n_words++;
        }
        if(isspace(c)&&inword)
            inword=0;
        prev=c;
    }
    if(prev!='\n')
        p_lines=1;
    printf("characters=%ld,words=%d,lines=%d,",
        n_chars, n_words, n_lines);
    printf("partiallines=%d\n",p_lines);
    return 0;
}

