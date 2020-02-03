#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "string.h"

int main() {
	int fd = open("tmp", O_RDWR | O_CREAT, 0755);
	char *buf = "123456";
	pwrite(fd, buf, 6, 0);
	char buffer[2];
	pread(fd, buffer, 2, 5);
	if(buffer+1 == NULL){
		printf("correct!\n");
	}
	printf("%s\n", buffer+1);
}
