#include <stdio.h>
#include <omp.h>


int main()
{
    int tid, thread_count;
    double time1 = omp_get_wtime();
    printf("Start at %f\n", time1);

    #pragma omp parallel private(tid)
    {
        // All threads
        tid = omp_get_thread_num();
        printf("%d: Lets do drugs!\n", tid);

        // Master thread only
        if(tid == 0)
        {
            thread_count = omp_get_num_threads();
            printf("I AM THE DEALER = %d\n", thread_count);
        }
    }
    // Threads join automatically
    double time2 = omp_get_wtime();
    printf("Stop at %f\n", time2);
    printf("Trip was %f long\n", time2 - time1);

    return 0;
}