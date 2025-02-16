#include <stdio.h>

#define N 10
//macros

void printArray(int* p, int len) {
	
	int* end = p + len;
	while (p != end) {
		printf ("%d ", *p++);
	}
	printf ("\n");
	
	// for (int i = 0; i < len; ++i) {
		// printf ("%d ", p[i]);
	// }
	// printf ("\n");
}

//	while (*p++ = *q++)
//		;

int main(void) {
	
	int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[N] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	
	printArray(a, N);
	printArray(b, N);
	
	return 0;
}