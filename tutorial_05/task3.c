#include <stdio.h>
#include <omp.h>
#include <stdint.h>
#include <inttypes.h>
#define N 10

void function(int64_t i)
{
    printf("%" PRId64 "\n", i);
}

int main()
{
    int64_t i;

    #pragma omp parallel private(i)
    {
        int id = omp_get_thread_num();

        for(i=0; i<N; i++) {
            if(i == id) {
                function(i);
            }
            #pragma omp barrier
        }
    }
}
