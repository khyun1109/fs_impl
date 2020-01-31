#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	
	int fd = open("tmp", O_RDWR | O_CREAT, 0755);
	char *buf;
	pread(fd, buf, 1, 1);
	buf = "5";
	pwrite(fd, buf, 1, 1);
}
