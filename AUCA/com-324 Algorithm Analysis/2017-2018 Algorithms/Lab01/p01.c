#include <stdio.h>

int main(void)
{
    int x;
    int y;
    int* p;
    
    x = 1;
    p = &x;
    
    printf("p = %p\n", p);
    printf("x = %d\n", x);
    printf("x = %d\n", *p);
    *p = 2;
    printf("x = %d\n", x);

    y = *p * *p;
    
    printf("y = %d\n", y);
    
    return 0;
}