#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char** argv) {
	
	if (argv[1] == argv[2]) {
		write(1, "Same file\n", 10);
	} else {
		if (argc == 3) {
			int dirFD = openat(AT_FDCWD, argv[2], O_DIRECTORY);
			if (renameat(AT_FDCWD, argv[1], dirFD, argv[1])) {
				write(1, "Error\n", 6);
			}
		} else if (argc > 3) {
			int dirFD = openat(AT_FDCWD, argv[argc-1], O_DIRECTORY);
			for (int i = 1; i < (argc-1); ++i) {
				if (renameat(AT_FDCWD, argv[i], dirFD, argv[i])) {
					write(1, "Error\n", 6);
				}		
			}
		} else {
			write(1, "Error\n", 6);
		}
	}

	return 0;
}
