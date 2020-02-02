#ifndef __FS_CONTROLLER__
#define __FS_CONTROLLER__

#include "fs_main.h"
#include <fuse3/fuse.h>
#include <fcntl.h>
#include "metadata.h"
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include "queue.h"
#include "global_types.h"

struct ino_allocator {
	struct queue *queue;
	uint64_t cur_ino;
	pthread_mutex_t *mutex;
};

uint64_t ino_get();
void allocator_init();
void allocator_destroy();

void init_metadata(struct inode *ino, mode_t mode);



#endif
