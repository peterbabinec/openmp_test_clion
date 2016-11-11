//
// Created by Peter on 11.11.2016.
//

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 1000
#define CHUNKSIZE 100

int main(int argc, char *argv[])
{
    int i, chunk;
    float a[N], b[N], c[N];

    // Initialization
    for (i = 0; i < N; i++)
        a[i] = b[i] = i * 1.0;
    chunk = CHUNKSIZE;

    #pragma omp parallel shared(a, b, c, chunk) private(i)
    {
        #pragma omp schedule(dynamic, chunk) nowait
        {
            for (i = 0; i < N; i++) {
                int tid = omp_get_thread_num();
                printf("Pracu vykonava %d %d\n", tid , i);
                c[i] = a[i] + b[i];
            }
        }

    }

    return 0;
}