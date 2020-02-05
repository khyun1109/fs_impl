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
		char *ptr;
		pread(fd, ptr, 1, ib_off);
		if(ptr == -1){
			ib_off += 1;
			ret = ib_off;
		}
		else{
			ret = ib_off;
		}
		return ret;
	}	
	else { //i_cycle >= 1
	}
}

uint64_t dbit_get(){
	uint64_t ret;
	if (d_cycle == 0){
		char *ptr;
		pread(fd, ptr, 1, db_off);
		if(ptr == -1){
			db_off += 1;
			ret = db_off;
		}	
		else{
			ret = db_off;
		}
		return ret;
	}
	else{ //d_cycle >= 1
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
	char *iptr;
	char *dptr;
	pread(fd, iptr, 1, iboff);
	pread(fd, dptr, 1, dboff);

	unsigned char x = *iptr;
	unsigned char y = *dptr;;
	int a = 0;
	int b = 0;
	for(int i = 0; i < 8; i++){
		if(x & (1 << (7-i)) == 0){
			break;
		}
		else{
			a++;
		}
	}
	for(int j = 0; j < 8; j++){
		if(x & (1 << (7-j)) == 0){
			break;
		}
		else{
			b++;
		}
	}
	
	int k = 1;
	if (a == 0){
		*iptr -= 128;
	}
	else{
		for(int i = 0; i < 7-a; i++){
			k *= 2;
		}
		*iptr += k;
	}
	k = 1;
	if (b == 0){
		*dptr -= 128;
	}
	else{
		for(int i = 0; i < 7-b; i++){
			k *= 2;
		}
		*dptr += k;
	}
	pwrite(fd, iptr, 1, iboff);
	pwrite(fd, dptr, 1, dboff);
}

void bitmap_del(uint32_t i_blknum){
	
}
	

