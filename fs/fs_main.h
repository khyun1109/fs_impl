#ifndef __FS_MAIN__
#define __FS_MAIN__

#define FUSE_USE_VERSION 31
#include "global_types.h"
#include "metadata.h"
#ifdef MONITOR
#include "monitor.h"
//extern struct monitor *global_monitor;
#endif

FILE *fp;

struct superblock {
	int num_of_inode;
	uint32_t ib_beginning;
	uint32_t db_beginning;
	uint32_t ir_beginning;
	uint32_t dr_beginning;
	
};

struct inode {
	struct metadata md;
	uint32_t pointer[50];
	int con_num[50];
};

struct bitmap {
	char i_b[5][BLOCK_SIZE];
	char d_b[75][BLOCK_SIZE];
};

#endif
