#ifndef LIBFB_PX
#define LIBFB_PX
typedef struct {
	char R; 
	char G; 
	char B;
} libfb_px;

void libfb_convert_px(char arr[], libfb_px *px);
#endif
