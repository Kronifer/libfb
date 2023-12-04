#include "../include/px.h"

// Convert libfb_px to format needed for writing to framebuffer
void libfb_convert_px(char arr[], libfb_px *px) {
	arr[0] = px->B;
	arr[1] = px->G;
	arr[2] = px->R;
	arr[3] = (char)0;
}
