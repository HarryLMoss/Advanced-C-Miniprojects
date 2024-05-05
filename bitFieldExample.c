#include <stdio.h>
#include <stdbool.h> //C99, defines bool, true, false

/* line styles     */
#define SOLID   0
#define DOTTED  1
#define DASHED  2

/* primary colors  */
#define BLUE    4
#define GREEN   2
#define RED     1

/* mixed colors    */
#define BLACK   0
#define YELLOW  (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN    (GREEN | BLUE)
#define WHITE   (RED | GREEN | BLUE)

const char *colours[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

/* Declare bitfields in box properties struct */
struct boxProps
{
    bool opaque :               1;
    unsigned int fillColour :   3;
    /* Pad 4 bits with unnamed variable */
    unsigned int :              4;
    bool showBorder :           1;
    unsigned int borderColour : 3;
    unsigned int borderStyle :  2;
    /* Pad as before */
    unsigned int :              2;
};

/* showSettings function avoids duplication of code */
void showSettings(const struct boxProps *boxPointer);

int main(void)
{
    /* Create and initialize boxProps struct */
    struct boxProps box = {true, YELLOW , true, GREEN, DASHED};

    printf("Original box settings:\n");
    showSettings(&box);

    box.opaque = false;
    box.fillColour = WHITE;
    box.borderColour = MAGENTA;
    box.borderStyle = SOLID;
    printf("\nModified box settings:\n");
    showSettings(&box); 

    return 0;
}

void showSettings(const struct boxProps *boxPointer)
{
    printf("Box is %s.\n", boxPointer->opaque == true ? "opaque": "transparent");
    printf("The fill colour is %s.\n", colours[boxPointer->fillColour]);
    printf("Border %s.\n",  boxPointer->showBorder == true ? "shown" : "not shown");
    printf("The border colour is %s.\n", colours[boxPointer->borderColour]);
    printf ("The border style is ");
    switch (boxPointer->borderStyle)
    {
        case SOLID  : printf("solid.\n"); break;
        case DOTTED : printf("dotted.\n"); break;
        case DASHED : printf("dashed.\n"); break;
        default     : printf("unknown type.\n");
    }

}
