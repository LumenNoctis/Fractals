#include "fractal.h"
int Mandelbrot(double x, double y, Fractal *data)
{
	int i;
	Imaginary c;
	Imaginary z;
	Imaginary tmp;

	c.r = MT_ScaleNumberf(x, (MT_Vector2){0, WIN_W}, (MT_Vector2){-2, 2});
	c.i = MT_ScaleNumberf(y, (MT_Vector2){0, WIN_H}, (MT_Vector2){-2, 2});
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
		return i + 1 - (log(2) / sqrt(z.r * z.r + z.i * z.i)) / log(2);
}

int Julia(double x, double y, Fractal *data)
{
	int i;
	Imaginary c;
	Imaginary z;
	Imaginary tmp;

	c.r = MT_ScaleNumberf(data->c.r, (MT_Vector2){0, WIN_W}, (MT_Vector2){-2, 2});
	c.i = MT_ScaleNumberf(data->c.i, (MT_Vector2){0, WIN_H}, (MT_Vector2){-2, 2});
	z.r = MT_ScaleNumberf(x, (MT_Vector2){0, WIN_W}, (MT_Vector2){-2, 2});
	z.i = MT_ScaleNumberf(y, (MT_Vector2){0, WIN_H}, (MT_Vector2){-2, 2});
	// z.r = MT_ScaleNumberf(x + data->offset.x, (MT_Vector2){0, WIN_W}, (MT_Vector2){-2, 2});
	// z.i = MT_ScaleNumberf(y + data->offset.y, (MT_Vector2){0, WIN_H}, (MT_Vector2){-2, 2});
// 
	double mod;
	i = 0;
	while (i < 20 - 1 && mod < 3)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) + c.r;
		z.i = 2 * (tmp.r * tmp.i) + c.i;
		mod = sqrt(z.r * z.r + z.i * z.i);
		i++;
	}
	return i + 1 - (log(mod) / log(2.0));
	// return data->colorData.colors[0][i];
}

int Burninship(double x, double y, Fractal *data)
{

}

int Newton(double x, double y, Fractal *data)
{

}

int Owo(double x, double y, Fractal *data)
{

}