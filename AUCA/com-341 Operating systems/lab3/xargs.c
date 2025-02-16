#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define BUFF_SZ 255
char input[BUFF_SZ];

int main(int argc, char **argv) {

	read(0, input, BUFF_SZ);
	input[strlen(input)-1] = NULL;                //?????????????????????????
	char *arguments[] = {argv[1], input, NULL};
	// char **arguments = {argv[1], input, NULL}; ?????????????????????????

	int pid = fork();

	if (pid == 0){
		execv(argv[1], arguments);
		exit(-1);
	} else if (pid > 0) {
		int child_status;
		waitpid(pid, &child_status, 0);
	} else {
		write(2, "error\n", 6);
	}

	return 0;
}
