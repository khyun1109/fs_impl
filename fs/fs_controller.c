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
#include "fs_main.h"

static struct ino_allocator *ino_queue;
static struct dat_allocator *dat_map;

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

uint64_t data_get(){
	uint64_t dat;
	pthread_mutex_lock(data_map->mutex);
	if ((dat = (uint64_t) map_pop(dat_map->map)) != 0){
		pthread_mutex_unlock(dat_map->mutex);
		return dat;
	}
	data = dat_map->cur_dat++;
	pthread_mutex_unlock(dat_map->mutex);

	return dat;
}

void init_metadata(struct inode *ino, mode_t mode) {
		
	ino->md.mode = mode;
	ino->md.nlink = 1;
	ino->md.uid = fuse_get_context()->uid;
	ino->md.gid = fuse_get_context()->gid;
	ino->md.size = 0;
	ino->md.atime = time(NULL);
	ino->md.ctime = time(NULL);
	ino->md.mtime = time(NULL);
	ino->md.ino = ino_get();
}	

void bitmap_control(uint32_t t_blknum){
	pread(fd,	);
	pwrite(fd,	)
}
	

