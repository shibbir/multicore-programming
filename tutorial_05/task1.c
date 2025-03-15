#include <stdio.h>
#include <omp.h>

int fun(int i, int j, int k, int h)
{
    return 0;
}

int main()
{
    int i, j, k, h;
    int A[5][5][5][5];

    #pragma omp parallel
    {
        #pragma loop_coalesce
        {
            for (i=1; i<=2; i++)
                for(j=1; j<=3; j++)
                    for(k=1; k<=2; k++)
                        for(h=1; h<=3; h++)
                            A[i][j][k][h] = fun(i, j, k, h);
        }
    }
}
