#include <stdio.h>
#include <stdlib.h>

struct Vec {
	int* a;
	int sz;
	int cp;
};

void init(struct Vec* this) {
	this->a = NULL;
	this->sz = 0;
	this->cp = 0;
}

void pushBack(struct Vec* this, int x) {
	
	if (this->sz == this->cp) {
		this->cp = (this->cp  == 0) ? 1: 2 * this->cp;
		int* p = malloc(this->cp * sizeof(int));
		for (int i = 0; i < this->sz; ++i) {
			p[i] = this->a[i];
		}
		
		free(this->a);
		this->a = p;
	}
	
	this->a[this->sz] = x;
	++this->sz;
}

void destroy(struct Vec* this) {
	free(this->a);
}

void printArray(int* beg, int* end) {
	
	while (beg != end) {
		printf("%d ", *beg++);
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
	
	struct Vec v;
	init(&v);
	
	int x;
	while (scanf("%d", &x) == 1) {
		pushBack(&v, x);
	}
	
	reverse(v.a, v.a + v.sz);
	printArray(v.a, v.a + v.sz);
	
	destroy(&v);
	
	return 0;
}