// Implement sleep sort in C

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *SleepAndPrint(void *duration)
{
    int int_duration = *(int *)duration;
    sleep(int_duration);
    printf("%i ", int_duration);
    fflush(stdout);
    return NULL;
}

void SleepSort(int *arr, size_t size)
{
    pthread_t threads[size];

    for (size_t i = 0; i < size; i++)
    {
        pthread_create(&threads[i], NULL, SleepAndPrint, &arr[i]);
    }

    for (size_t i = 0; i < size; i++)
    {
        pthread_join(threads[i], NULL);
    }
    printf("\n");
}

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        printf("usage: ./ar-slpsrt [num num ...]\n", argv[0]);
        return 1;
    }

    const size_t arr_size = argc - 1;
    int arr[arr_size];

    for (size_t i = 0; i < arr_size; i++)
    {
        sscanf(argv[i + 1], "%i", &arr[i]);
    }

    SleepSort(arr, arr_size);
}