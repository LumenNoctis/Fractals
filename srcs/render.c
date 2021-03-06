#include "fractal.h"

typedef int (*Frac_func)(double x, double y, Fractal *frac);



void RenderToScreen(Fractal *data)
{
	static Frac_func fractals[2];
	int x;
	int y;
	int color;

	SDLX_Display *display;

	display = SDLX_DisplayGet();
	fractals[0] = Julia;
	//fractals[1] = Julia;
	y = 0;
	while (y < WIN_H)
	{
		x  = 0;
		while (x < WIN_W)
		{
			color = fractals[data->index](x, y, data);
			SDL_SetRenderDrawColor(display->renderer,
									(color >> 24) & 0xFF,
									(color >> 16) & 0xFF,
									(color >>  8) & 0xFF,
									255);
			SDL_RenderDrawPoint(display->renderer,  x, y);
			x++;
		}
		y++;
	}
}