#include <stdio.h>
#include <stdlib.h>

void printArray(int* beg, int* end) {
	
	while (beg != end) {
		printf("%d", *beg++);
	}
	printf("\n");
}

void reverse(int* beg, int* end) {
	if (beg == end) return;
	
	for (;;) {
		if (--end == beg) break;
		
		int t = *beg;
		*beg = *end;
		*end = t;
		
		if (++beg == end) break;
	}
}

int main(void) {
	
	int* a = NULL;
	int sz = 0;
	int cp = 0;
	
	int x;
	while (scanf("%d", &x) == 1) {
		if (sz == cp) {
			
			cp = (cp  == 0) ? 1: 2 * cp;
			int* p = malloc(cp * sizeof(int));
			for (int i = 0; i<sz; ++i) {
				p[i] = a[i];
			}
			
			free(a);
			a = p;
		}
		
		a[sz] = x;
		++sz;
	}
	
	reverse(a, a + sz);
	printArray(a, a + sz);
	
	free(a);
	
	return 0;
}