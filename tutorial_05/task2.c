#include <stdio.h>
#include <omp.h>

int main()
{
    int i, j, k, h;
    const int N1=1, N2=1, N3=1, N4=1;
    int A[2][2][2][2];

    #pragma omp parallel
    {
        #pragma loop_coalesce
        {
            for(i=0; i<N4; i++)
                for(j=0; j<N3; j++)
                    for(k=0; k<N2; k++)
                        for(h=0; h<N1; h++)
                            A[i][j][k][h]= A[i][j+1][k][h+1];
        }
    }
}
