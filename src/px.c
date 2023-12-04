#include "../include/px.h"

void libfb_convert_px(char arr[], libfb_px *px) {
	arr[0] = px->B;
	arr[1] = px->G;
	arr[2] = px->R;
	arr[3] = (char)0;
}
