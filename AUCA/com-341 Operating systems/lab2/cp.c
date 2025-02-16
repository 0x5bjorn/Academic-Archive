#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 131072
char BUF[BUF_SIZE];

int main(int argc, char** argv) {
	
	if (argc == 3) {
		int fFD = openat(AT_FDCWD, argv[1], O_RDONLY);
		int sFD = openat(AT_FDCWD, argv[2], O_WRONLY|O_CREAT|O_EXCL, 0664);
		int rBytes = read(fFD, BUF, BUF_SIZE);
		write(sFD, BUF, rBytes);
	} else if (argc > 3) {
		int dirFD = openat(AT_FDCWD, argv[argc-1], O_DIRECTORY);
		for (int i = 1; i < (argc-1); ++i) {
			int fFD = openat(AT_FDCWD, argv[i], O_RDONLY);
			int sFD = openat(dirFD, argv[i], O_WRONLY|O_CREAT|O_EXCL, 0664);
			int rBytes = read(fFD, BUF, BUF_SIZE);
			write(sFD, BUF, rBytes);		
		}
	} else {
		write(1, "Error\n", 6);
	}
	
	return 0;
}
