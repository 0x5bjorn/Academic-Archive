#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	for (int i = 1; i < argc; ++i) {
		if (!faccessat(AT_FDCWD, argv[i], W_OK, 0)) {
			unlinkat(AT_FDCWD, argv[i], 0);
			unlinkat(AT_FDCWD, argv[i], AT_REMOVEDIR);
		}
	}

	return 0;
}
