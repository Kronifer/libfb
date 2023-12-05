#include "../include/px.h"
#include "../include/buffer.h"
#include <stdio.h>

// Draw single pixel to buffer
void libfb_draw_px(libfb_buffer *buf, libfb_px *px) {
	FILE *fp;
	if(buf->en_dbuffer == 1) {
		fp = buf->dbuffer;
	}
	else {
		fp = buf->fp;
	}
	char bytes[4];
	libfb_convert_px(bytes, px);
	fwrite(bytes, 4, sizeof(char), fp);
	buf->w_bytes_written += 4;
	// Reset w_bytes_written if 1 line has been written
	if(buf->w_bytes_written == buf->stride) {
		buf->w_bytes_written = 0;
	}
}

// Move down 1 line
void libfb_next_line(libfb_buffer *buf) {
	if(buf->en_dbuffer == 1) {
		fseek(buf->dbuffer, 5504-buf->w_bytes_written, SEEK_CUR);
	}
	else {
		fseek(buf->fp, 5504-buf->w_bytes_written, SEEK_CUR);
	}
	buf->w_bytes_written = 0;
}

void libfb_top_buffer(libfb_buffer *buf) {
	if(buf->en_dbuffer == 1) {
		fseek(buf->dbuffer, 0, SEEK_SET);
	}
	else {
		fseek(buf->fp, 0, SEEK_SET);
	}
	buf->w_bytes_written = 0;
}

void libfb_render_buffer(libfb_buffer *buf) {
	if(buf->en_dbuffer != 1) {
		return;
	}
	fseek(buf->dbuffer, 0, SEEK_SET);
	fseek(buf->fp, 0, SEEK_SET);
	char buffer[buf->stride*buf->width];
	fread(buffer, buf->stride*buf->width, sizeof(char), buf->dbuffer);
	fwrite(buffer, buf->stride*buf->width, sizeof(char), buf->fp);
}
