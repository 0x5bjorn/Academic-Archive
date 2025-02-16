#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv) {
/*	for (int i = 1; i < argc-1; ++i) {
		printf("%s ", argv[i]);
	}
	printf("s\n", argv[argc-1]);
	*/
	
	if (argc > 1) {
		for (int i = 1; i < argc; ++i) {
			write(1, argv[i], strlen(argv[i]));
			if (i < argc - 1) {
				write(1, " ", 1);
			} else {
				write(1, "\n", 1);
			}
		}
	} else { 
		write(1, "\n", 1);
	}
	
	return 0;
}	
