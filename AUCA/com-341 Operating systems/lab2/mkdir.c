#include <unistd.h>
#include <string.h>

int main(int argc, char** argv) {
	
	for (int i = 1; i < argc; ++i) {
		if (mkdir(argv[i], 0777)) {
			write(1, argv[i], strlen(argv[i]));
			write(1, " already exists.\n", 17);
		}
	}

	return 0;
}
