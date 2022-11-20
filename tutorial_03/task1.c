#include<stdio.h>
#include<omp.h>

int main ()
{
    int sum = 0;
    omp_lock_t lock;
    omp_init_lock(&lock);

    #pragma omp parallel num_threads(4) //reduction(+:sum)
    {
        int local_sum = 0;
        #pragma omp for
        for(int i=0; i<10000; i++)
        {
            local_sum++;
        }
        omp_set_lock(&lock);
        sum += local_sum;
        omp_unset_lock(&lock);
    }

    printf("Sum: %d\n", sum);
    omp_destroy_lock(&lock);
    return 0;
}

void a()
{
    int num = 0;
    int id = 0;

    #pragma omp parallel num_threads(8) shared(num) private(id)
    {
        #pragma omp single
        {
            num = omp_get_num_threads();
        }

        id = omp_get_thread_num();

        for(int i = 0; i < 8; i++)
        {
            if(id == i)
            {
                printf("This is thread %d of %d\n", id, num);
            }
            #pragma omp barrier
        }
    }
}
