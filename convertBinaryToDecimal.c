#include <stdio.h>
#include <math.h>

int convertBinaryToDecimal(long long n);

int main(void)
{
    long long n;
    int result = 0;

    printf("Enter a binary number: ");
    scanf("%lld", &n);

    result = convertBinaryToDecimal(n);

    printf("%lld in binary = %d in decimal", n, result);

    return 0;
}

int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder = 0;

    while (n != 0)
    {
        /* get the last digit */
        remainder = n % 10;
        /* reprocess n */
        n = n / 10;
        /* running tally */
        decimalNumber += remainder * pow(2,i);
        ++i;
    }
}