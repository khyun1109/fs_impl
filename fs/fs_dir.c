#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <assert.h>
#include "fs_dir.h"
#include "metadata.h"
#include "fs_main.h"
#include "fs_controller.h"

int fs_opendir (const char *path, struct fuse_file_info *fi) {
	fi->keep_cache = 1;

	return 0;
}

int fs_mkdir (const char *path, mode_t mode) {
	struct inode *ino = NULL;
	init_metadata(ino->md, mode);
	ino->md.size = 4096;

	if (strcmp(path, "/") == 0) { //root directory
		ino->pointer = DO; 
		char *buf1 = 1;
		char *buf2 = " . ";
		char *buf3 = 0;
		bitmap_addi(); //correcting bitmap 
		pwrite(fd, (char *)ino, PAGE_SIZE, ino->md.ino); //writing inode 
		pwrite(fd, buf1, 1, DO); //writing num of file;
		pwrite(fd, buf2, 3, DO+1);//writing data
		pwrite(fd, buf3, 1, DO+4);//writing inode block num;
	}
	else { //orinary directory
		char *ptr = strtok(path, "/");
		int level = 0;
		while (ptr != NULL){
			level++;
			ptr = strtok(ptr, "/");
		}
		ptr = strtok(path, "/");
		char buffer[PAGE_SIZE];
		pread(fd, buffer, PAGE_SIZE, DO);
		char *ptr2 = strtok(buffer, " ");
		int dir_num = atoi(ptr2);
		for(int i = 1; i < level+1; i++){
			if(i == level){ //The place that dir will be located.
				if( ){
					printf("directory already exists!!\n");
				}
				else{
					bitmap_add(ino->md.ino);
					pwrite(fd, (char *)ino, PAGE_SIZE, ino->md.ino);
					pwrite(fd, , , );
				}
			}
			else{ //Parent dir of target dir
				
			}
		}
	}
	return 0;
}

int fs_readdir (const char *path, void *buf, fuse_fill_dir_t filler, off_t off, struct fuse_file_info *fi, enum fuse_readdir_flags flags) {

	filler(buf, ".", NULL, 0, (enum fuse_fill_dir_flags)0);
	filler(buf, "..", NULL, 0, (enum fuse_fill_dir_flags)0);

	return 0;
}

int fs_rmdir (const char *path) {
	char buffer[PAGE_SIZE];
	pread(fd, buffer, PAGE_SIZE, DO);
	char *ptr = strtok(buffer, " "):
	char *ptr2 = strtok(buffer, " ");

	bitmap_del();
	return 0;
}

int fs_releasedir (const char *path, struct fuse_file_info *fi) {
	return 0;
}

int fs_fsyncdir (const char *path, int datasync, struct fuse_file_info *fi) {
	return 0;
}
