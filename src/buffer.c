#include "../include/buffer.h"
#include <stdio.h>
#include <stdlib.h>

// Find the comma separating length and width
int split_ind(char str[]) {
	for(int i = 0; i < *(&str + 1) - str; i++) {
		if(str[i] == ',') {
			return i;
		}
	}
	return -1;
}

// Initialize buffer struct
libfb_buffer libfb_init_buffer(int buffer) {
	char base_dirname[25];
	char dimensions_fname[37];
	char stride_fname[31];
	char fbuf_fname[9];

	// Filenames based on buffer being opened
	sprintf(base_dirname, "/sys/class/graphics/fb%d/", buffer);
	sprintf(dimensions_fname, "%svirtual_size", base_dirname);
	sprintf(stride_fname, "%sstride", base_dirname);
	sprintf(fbuf_fname, "/dev/fb%d", buffer);

	FILE *dim_f = fopen(dimensions_fname, "r");
	FILE *stri_f = fopen(stride_fname, "r");

	char dimensions[10];
	char stride[6];
	char width[10];
	char height[10];

	// Read dimensions and stride
	fgets(dimensions, 10, dim_f);
	fgets(stride, 5, stri_f);

	// Separate dimensions into width and height
	for(int i = 0; i < split_ind(dimensions); i++) {
		width[i] = dimensions[i];
	}
	for(int i = split_ind(dimensions) + 1; i < *(&dimensions + 1) - dimensions; i++) {
		height[i-(split_ind(dimensions)+1)] = dimensions[i];
	}

	// Close files
	fclose(dim_f);
	fclose(stri_f);

	libfb_buffer buf = {.fp = fopen(fbuf_fname, "wb"), .stride = atoi(stride), .width = atoi(width), .height = atoi(height), .buffer = buffer, .w_bytes_written = 0};
	return buf;
}

void libfb_close_buffer(libfb_buffer *buffer) {
	fclose(buffer->fp);
}
