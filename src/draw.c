#include "../include/px.h"
#include "../include/buffer.h"
#include <stdio.h>

void libfb_draw_px(libfb_buffer *buf, libfb_px *px) {
	FILE *fp = buf->fp;
	char bytes[4];
	libfb_convert_px(bytes, px);
	fwrite(bytes, 4, sizeof(char), fp);
	buf->w_bytes_written += 4;
	if(buf->w_bytes_written == 5504) {
		buf->w_bytes_written = 0;
	}
}

void libfb_next_line(libfb_buffer *buf) {
	fseek(buf->fp, 5504-buf->w_bytes_written, SEEK_CUR);
	buf->w_bytes_written = 0;
}
