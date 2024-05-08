// Author: Harry Moss
// Date: 08.05.2024

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char ch = '\0';
    int word = 1, charc = 1;

    /* check for command line argument for a file*/
    if (argc == 1)
        /* argument NOT passed, set to stdin*/
        fp = stdin;
    else if (argc == 2)
    {
    /* if there are 2 arguments, open the first argument */
        if ((fp = fopen(argv[1], "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    else 
    {
    // If argument is neither, user has run program incorrectly
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Read from file and include word count for spaces & line feed
    while(ch != EOF)
    {
        if(ch == ' ' || ch == '\n')
        {
            word++;
        }
        else
        {
            charc++;
        }
        ch = getc(fp);
    }
    printf("\n The number of words in the file are: %d\n", word);
    printf(" The number of characters in the file are: %d\n\n", charc);

    fclose(fp);

    return 0;
}
