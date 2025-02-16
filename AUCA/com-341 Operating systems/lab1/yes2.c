#include <stdio.h>

int main(int argc, char** argv) {

	while (1) {
		if (argv[1] == NULL) printf("y\n");
		else {
			for (int i = 1; i < argc; ++i) {
				printf("%s ", argv[i]);
			}
			printf("\n");
		}
	}

	return 0;
}	
