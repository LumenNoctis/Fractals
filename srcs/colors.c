#include "fractal.h"

Uint32 **init_colors()
{
	Uint32 **colors;
	Grad_data red[4];
	Grad_data blue[2];
	Grad_data green[2];

	colors = calloc(1, sizeof(int *));
	// red[0].color = 0xF0000000;
	// red[1].color = 0xF0FF00FF;
	// red[2].color = 0x000FFFFF;
	// red[3].color = 0xFFFFFFFF;
	red[0].location = 0;
	red[1].location = 0.3;
	red[2].location = 0.6;
	red[3].location = 1;

	colors[0] = GradArray_Get(LOD, create_gradient(red, 4));

	return colors;
}