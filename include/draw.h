#ifndef LIBFB_DRAW
#define LIBFB_DRAW
void libfb_draw_px(libfb_buffer *buf, libfb_px *px);
void libfb_next_line(libfb_buffer *buf);
void libfb_top_buffer(libfb_buffer *buf);
void libfb_render_buffer(libfb_buffer *buf);
#endif
