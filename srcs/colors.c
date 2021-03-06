#include "fractal.h"

Uint32 **init_colors()
{
	Uint32 **colors;
	Grad_data red[2];

	colors = calloc(1, sizeof(int *));
	red[0].color = 0x0000F0FF;
	red[1].color = 0xFFFFFFFF;
	red[0].location = 0;
	red[1].location = 1;

	colors[0] = GradArray_Get(LOD, create_gradient(red, 2));

	return colors;
}