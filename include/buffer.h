#ifndef LIBFB_BUFFER 
#define LIBFB_BUFFER
#include <stdio.h>
typedef struct {
	int buffer;
	int width;
	int height;
	int stride;
	FILE *fp;
	int w_bytes_written;
} libfb_buffer;

libfb_buffer libfb_init_buffer(int buffer);

void libfb_close_buffer(libfb_buffer *buffer);
#endif
