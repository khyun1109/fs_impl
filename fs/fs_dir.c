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

	char *buf1 = -128;
	char *buf2 = ".";
	if (strcmp(path, "/") == 0) { //root directory
		ino->pointer = DO/1024; 
		pwrite(fd,  buf1, 1, 4); //correcting inode bitmap
		pwrite(fd, (char *)ino, 4, IO/1024); //writing inode 
		pwrite(fd, buf2, 1, DO/1024);//writing data
	}
	else {
		char *ptr = strtok(path, "/");
		while(1){
			char buffer[4096];
			pread(fd, buffer, )
			if(){
			}
			else{ //
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
	
	return 0;
}

int fs_releasedir (const char *path, struct fuse_file_info *fi) {
	return 0;
}

int fs_fsyncdir (const char *path, int datasync, struct fuse_file_info *fi) {
	return 0;
}
