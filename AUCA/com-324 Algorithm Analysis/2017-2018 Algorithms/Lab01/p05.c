#include <stdio.h>
#include <stdlib.h>

int globalArray[100000] = {1, 2, 3};

void f()
{
    int localArray[100];
    
    printf("local array: %d %d\n", localArray[0], localArray[1]);
}

int* createDynArray(int len, int initValue)
{
    int* res = malloc(len * sizeof(int));
 
    for (int i = 0; i < len; ++i)
    {
        res[i] = initValue;
    }
    
    return res;
}

int main()
{
    int localArray[100];

    f();
    
    // int[] a = new int[100];
    
    int n;
    scanf("%d", &n);
    
    int* a = createDynArray(n, 10);
    
    printf("dynamic array: %d %d\n", a[0], a[1]);
    
    
    free(a);
    
    return 0;
}