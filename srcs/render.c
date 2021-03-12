#include "fractal.h"

typedef int (*Frac_func)(double x, double y, Fractal *frac);

void RenderToScreen(Fractal *data)
{
	static Frac_func fractals[2];
	int x;
	int y;
	Uint8 r;
	Uint8 g;
	Uint8 b;
	double pixelX;
	double pixelY;
	int color;

	SDLX_Display *display;

	display = SDLX_DisplayGet();
	fractals[0] = Mandelbrot;
	// fractals[0] = Julia;
	y = 0;
	if (data->paused != 0)
	{
		data->c.r = data->mouse_x;
		data->c.i = data->mouse_y;
	}
	pixelY = data->cam.position.y - ((WIN_H / data->cam.scale) * 0.5);
	while (y < WIN_H)
	{
		x  = 0;
		pixelX = data->cam.position.x - ((WIN_W / data->cam.scale) * 0.5);
		while (x < WIN_W)
		{
			color = fractals[data->index](pixelX, pixelY, data);
			r = sin(0.33 * color + 10) * 127.5 + 127.5;
			g = sin(0.1 * color + 1) * 127.5 + 127.5;
			b = sin(40 * color + 4) * 127.5 + 127.5;
			// color = data->colorData.colors[0][color];
			// r = color >> 24;
			// g = color >> 16;
			// b = color >> 8;
			SDL_SetRenderDrawColor(display->renderer, r, g, b, 255);
			SDL_RenderDrawPoint(display->renderer,  x, y);
			x++;
			pixelX += (WIN_W / data->cam.scale) / WIN_W;
		}
		pixelY += (WIN_H / data->cam.scale ) / WIN_H;
		y++;
	}
}