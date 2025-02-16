#include <unistd.h>
#include <string.h>

#define BUF_SIZE 4096
char BUF[BUF_SIZE];

int main() {
	if (getcwd(BUF, BUF_SIZE) != NULL) {
		write(STDOUT_FILENO, BUF, strlen(BUF));
		write(STDOUT_FILENO, "\n", 1);
	}
	
	return 0;
}
