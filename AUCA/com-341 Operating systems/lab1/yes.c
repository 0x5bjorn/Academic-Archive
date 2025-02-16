#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
	
/*	while (true) {
		if (argc > 1) {
			for (int i = 1; i < argc; ++i) {
				printf(i < argc - 1 ? "%s " : "%s\n", argv[i]);
			}
		} else {
			puts("y");
		}
	} */
	
	while (true) {
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
			write(1, "y\n", 2);
		}
	}

	return 0;
}
