#ifndef __GLOBAL_TYPES__
#define __GLOBAL_TYPES__

#include <stdint.h> 

#define BLOCK_SIZE	4096
#define PAGESIZE	4096
#define DEVSIZE 1024L * 1024L * 1024L * 10L
#define IBO 4096
#define DBO 6 * 4096
#define IO 81 * 4096
#define DO 154277L * 4096L

int fd;
uint64_t db_off;
uint64_t ib_off;
uint64_t i_off;
uint64_t d_off;
uint64_t i_cycle;
uint64_t d_cycle;
#endif
