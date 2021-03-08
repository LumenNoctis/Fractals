#include "fractal.h"
int Mandelbrot(double x, double y, Fractal *data)
{
	int i;
	Imaginary c;
	Imaginary z;
	Imaginary tmp;

	//c.r = MT_ScaleNumberf(x / data->zoom + data->offset.x, (MT_Vector2){0, WIN_W}, (MT_Vector2){-2, 2});
	//c.i = MT_ScaleNumberf(y / data->zoom + data->offset.y, (MT_Vector2){0, WIN_H}, (MT_Vector2){-2, 2});
	//c.r = (x + data->offset.x) / data->zoom;// + data->offset.x;
	//c.i = (y + data->offset.y) / data->zoom;// + data->offset.y;
	c.r = (x - WIN_W / 2) / (0.5 * data->zoom * WIN_W) - data->offset.x;
	c.i = (y - WIN_W / 2) / (0.5 * data->zoom * WIN_H) - data->offset.y;
	z.r = c.r;
	z.i = c.i;
	i = 0;
	while (i < LOD - 1 && (z.r * z.r + z.i * z.i) <= 4)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) + c.r;
		z.i = 2 * (tmp.r * tmp.i) + c.i;
		i++;
	}
	return data->colorData.colors[0][i];
}

int Julia(double x, double y, Fractal *data)
{
	int i;
	Imaginary c;
	Imaginary z;
	Imaginary tmp;

	c.r = MT_ScaleNumberf((double)data->mouse_x, (MT_Vector2){0, WIN_W}, (MT_Vector2){-2, 2});
	c.i = MT_ScaleNumberf((double)data->mouse_y, (MT_Vector2){0, WIN_H}, (MT_Vector2){-2, 2});
	z.r = MT_ScaleNumberf(x + data->offset.x, (MT_Vector2){0, WIN_W}, (MT_Vector2){-2, 2});
	z.i = MT_ScaleNumberf(y + data->offset.y, (MT_Vector2){0, WIN_H}, (MT_Vector2){-2, 2});


	i = 0;
	while (i < LOD - 1 && (z.r * z.r + z.i * z.i) <= 4)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) + c.r;
		z.i = 2 * (tmp.r * tmp.i) + c.i;
		i++;
	}
	return data->colorData.colors[0][i];
}