#define _GNU_SOURCE

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <dirent.h>

struct linux_dirent {
	long           d_ino;
	off_t          d_off;
	unsigned short d_reclen;
	char           d_name[];
};

#define BUF_SIZE 32768
char BUF[BUF_SIZE];

int main(int argc, char** argv) {
	struct linux_dirent* d;

	int fd = openat(AT_FDCWD, argc > 1 ? argv[1] : ".", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY);
	int readBytes = syscall(SYS_getdents, fd, BUF, BUF_SIZE);
	
	for (int i = 0; i < readBytes;) {
		d = (struct linux_dirent*) (BUF + i);
		write(STDOUT_FILENO, d->d_name, strlen(d->d_name));
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, BUF+i, d->d_reclen);
		write(STDOUT_FILENO, "\n", 1);
		i += d->d_reclen;		
	}
	
	return 0;
}
