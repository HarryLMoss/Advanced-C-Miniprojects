#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    printf( "__LINE__ = %d\n", __LINE__ );
    printf( "__FILE__ = %s\n", __FILE__ );
    // Date and time are the compilation times, not current time
    printf( "__DATE__ = %s\n", __DATE__ );
    printf( "__TIME__ = %s\n", __TIME__ );
    printf( "__STDC__ = %d\n", __STDC__ );

    return 0;
}