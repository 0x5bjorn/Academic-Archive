#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
	
	for (int i = 1; i<argc; ++i) {
		int fd = openat(AT_FDCWD, argv[i], O_WRONLY|O_CREAT|O_NOCTTY|O_NONBLOCK, 0666);
		utimensat(AT_FDCWD, argv[i], NULL, 0);
	}
	
	return 0;
}
