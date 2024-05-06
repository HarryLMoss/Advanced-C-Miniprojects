#include <stdio.h>
#include <stdlib.h>

#define BUF 256

int hasChar(char ch, const char *line);

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char ch = '\0';
    char line[BUF];

    /* Error if arguments aren't 3 in total */
    if (argc != 3)
    {
        printf("Usage: %s character filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*
    the 0 in the column slot represents the 1st 
    character of the string to be searched for
    */
    ch = argv[1][0];

    /* if argv[2] (the file) is null then error */
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, BUF, fp) != NULL)
    {
        /* Call helper function*/
        if (hasChar(ch, line))
            fputs(line, stdout);
    }

    fclose(fp);
    return 0;
}

int hasChar(char ch, const char *line)
{
    /* Dereference linePtr and compare with ch */
    while(*line)
        if(ch == *line++)
            return 1;

    return 0;
}