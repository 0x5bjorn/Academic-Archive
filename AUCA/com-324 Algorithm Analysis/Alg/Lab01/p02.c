#include <stdio.h>

void badSwap(int x, int y) {
	int t = x;
	x = y;
	y = t;
}

void goodSwap(int* p, int* q) {
	int t = *p;
	*p = *q;
	*q = t;
}

int main(void) {
	
	int x = 2;
	int y = 3;
	
	scanf("%d%d", &x, &y);
	
	printf("Before swap: x = %d, y = %d\n", x, y);
	badSwap(x, y);
	printf("After swap: x = %d, y = %d\n", x, y);
	
	printf("Before swap: x = %d, y = %d\n", x, y);
	goodSwap(&x, &y);
	printf("After swap: x = %d, y = %d\n", x, y);
	
	return 0;
}