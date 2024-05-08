// Author: Harry Moss
// Date: 08.05.2024

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

int main(void)
{
#ifdef __STDC_NO_COMPLEX__
    printf("complex not supported\n");
    exit(1);
#else
    printf("complex numbers are supported\n");
#endif


    complex double z1 = 2.5 + 3.0i;
    complex double z2 = 2.5 - 4.0i;

    double imag1 = cimag(z1);
    double imag1sqr = imag1 * imag1;

    double imag2 = cimag(z2);
    double imag2sqr = pow(imag2, 2);


    printf("z1 real = %.2f\n", creal(z1));
    printf("z1 imag = %.2f\n", imag1sqr);

    printf("z2 real = %.2f\n", creal(z2));
    printf("z2 imag = %.2f\n", imag2sqr);

    return 0;
}
