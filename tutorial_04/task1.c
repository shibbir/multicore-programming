#include <stdio.h>
#include <omp.h>

int main()
{
    int j;
    int intervals = 1000000000;
    double delta, x, pi = 0.0;

    delta = 1.0 / (double) intervals;

    #pragma omp parallel private(x)
    {
        #pragma omp for reduction(+:pi)
        for (j=0; j<=intervals; j++) {
            x = ((double) j - 0.5) * delta;
            pi += 4.0 / (1.0 + ( x * x ));
        }
    }

    pi /= intervals;

    printf("%f", pi);
}
