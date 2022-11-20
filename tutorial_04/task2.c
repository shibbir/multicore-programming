#include <stdio.h>
#include <omp.h>
#define N 10

int fib(int n)
{
    if(n < 2) return n;

    int x, y;

    #pragma omp task shared(x)
    x = fib(n - 1);

    #pragma omp task shared(y)
    y = fib(n - 2);

    #pragma omp taskwait
    return x + y;
}

int main(void)
{
    int f;

    #pragma omp parallel
    #pragma omp single
    f = fib(N);

    printf("%d\n", f);
}
