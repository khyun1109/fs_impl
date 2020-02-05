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
	if ((ino = (uint64_t) queue_pop(ino_queue->queue)) != 0){
		return ino;
	}
	ino = ino_queue->cur_ino++;

	return ino;
}

uint64_t data_get(){
	uint64_t dat;
	if ((dat = (uint64_t) map_pop(dat_map->map)) != 0){
		return dat;
	}
	data = dat_map->cur_dat++;

	return dat;
}

uint64_t ibit_get(){
	uint64_t ret;
	if (i_cycle == 0){
		ret = ib_off;
		return ret;
	}	
	else {
	}
}

uint64_t dbit_get(){
	uint64_t ret;
	if (d_cycle == 0){
		ret = db_off;
		return ret;
	}
	else{
	}
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

void bitmap_add(){
	int iboff = ibit_get();
	int dboff = dbit_get():
	pread(fd,	);
	pwrite(fd,	)
}

void bitmap_del(uint32_t t_blknum){

}
	

