#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SZ 1024
char res[BUFF_SZ];

int main(int argc, char** argv) {
	if (argc > 1) {
		for (int i = 1; i < argc; ++i) {
			int fd = open(argv[i], O_RDONLY);
			if (-1 != fd) {
				ssize_t bytes_read;
				while (0 < (bytes_read = read(fd, res, BUFF_SZ))) {
					write(1, res, bytes_read);
				}
			}
			close(fd);
		}
	} else {
		while (read(0, res, BUFF_SZ) >= 0) {
			write(1, res, BUFF_SZ);
		}
	}
	return 0;
}
