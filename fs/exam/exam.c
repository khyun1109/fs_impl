#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "string.h"

int main() {
	
	char buf[10] = "/1/2/3";
	char *ptr = strtok(buf, "/");
	printf("%s\n", ptr);
}
