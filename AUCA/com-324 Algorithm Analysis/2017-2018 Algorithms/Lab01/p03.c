#include <stdio.h>

#define N 10

int main(void)
{
    int a[N];
    
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", a[i]);
    }
    

    int s1 = 0;
    for (int i = 0; i < N; ++i)
    {
        s1 += a[i];
    }
  
    printf("%d\n", s1);
    
    int s2 = 0;
    for (int* p = a; p != a + N; ++p)
    {
        s2 += *p;
    }
    
    printf("%d\n", s2);
    
    
    return 0;
}