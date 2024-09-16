#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct myArray
{
    int arrayLength;
    int array[];
};

int main(void)
{
    int desiredSize = 0;
    struct myArray *ptr = NULL;

    printf("Enter size of array: ");
    scanf("%d", &desiredSize);
    
    ptr = malloc(sizeof(struct myArray) + desiredSize * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    else
    {
        ptr->arrayLength = desiredSize;
        for (int i = 0; i < desiredSize; i++)
        {
            ptr->array[i] = 1;
        }
    }

    for (int i = 0; i < desiredSize; i++)
    {
        printf("%d ", ptr->array[i]);
    }
    printf("\n");

    free(ptr);

    return 0;
}