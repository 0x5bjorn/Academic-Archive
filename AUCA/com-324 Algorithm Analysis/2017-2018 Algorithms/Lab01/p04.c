#include <stdio.h>

#define N 10
#define M 5

void printArray(int* p, int len)
{
    int* e = p + len;
    while (p != e)
    {
        printf("%d ", *p++);
    }
    printf("\n");
}

int main(void)
{
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[M] = {10, 20, 30, 40, 50};
    
    printArray(a, N);
    printArray(&b[0], M);
    
    return 0;
}