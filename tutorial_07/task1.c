#include <stdio.h>
#include <pthread.h>

void *calc() {
    int j;
    int intervals = 1000000000;
    double delta, x, pi = 0.0;

    delta = 1.0 / (double) intervals;

    for (j=0; j<=intervals; j++) {
        x = ((double) j - 0.5) * delta;
        pi += 4.0 / (1.0 + ( x * x ));
    }

    pi /= intervals;

    return NULL;
}

int main()
{
    pthread_t threads[4];

    for(int i=0; i<4; i++) {
        pthread_create(&threads[i], NULL, calc, NULL);
    }

    printf("%f", pi);
}
