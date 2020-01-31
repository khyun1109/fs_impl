#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <assert.h>
#include <sys/time.h>
#include <unistd.h>
#include "metadata.h"
#include "fs_controller.h"

static struct ino_allocator *ino_queue;

uint64_t ino_get(){
	uint64_t ino;
	pthread_mutex_lock(ino_queue->mutex);
	if ((ino = (uint64_t) queue_pop(ino_queue->queue)) != 0){
		pthread_mutex_unlock(ino_queue->mutex);
		return ino;
	}
	ino = ino_queue->cur_ino++;
	pthread_mutex_unlock(ino_queue->mutex);

	return ino;
}

void init_metadata(struct metadata *meta, mode_t mode) {
		
	meta->mode = mode;
	meta->nlink = 1;
	meta->uid = fuse_get_context()->uid;
	meta->gid = fuse_get_context()->gid;
	meta->size = 0;
	meta->atime = time(NULL);
	meta->ctime = time(NULL);
	meta->mtime = time(NULL);
	meta->ino = ino_get();
}	
	
	
	
