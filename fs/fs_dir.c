#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <assert.h>
#include "fs_dir.h"
#include "metadata.h"
#include "fs_main.h"

int fs_opendir (const char *path, struct fuse_file_info *fi) {
	fi->keep_cache = 1;

	return 0;
}

int fs_mkdir (const char *path, mode_t mode) {
	struct metadata *meta = NULL;
	init_metadata(meta, mode);
	meta->size = 4096;

	if (strcmp(path, "/") == 0) { //root directory
	
	}
	else {
		
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
