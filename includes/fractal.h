#ifndef FRACTAL_H
# define FRACTAL_H

# include "SDLX/SDLX.h"
# include "MT/MT.h"
# include "Gradient/gradient.h"

# define LOD 100

typedef struct Imaginary
{
	double r;
	double i;
} Imaginary;

typedef struct Color_data
{
	int ncolors;
	int index;
	Uint32 **colors;
}				Color_data;

typedef struct Fractal
{
	int index;
	double zoom;
	double zoom_step;

	Color_data colorData;
	MT_Vector2 mousePos;
	MT_Vector2 offset;
} Fractal;

int Julia(double x, double y, Fractal *data);
int Mandelbrot(double x, double y, Fractal *data);

void RenderToScreen(Fractal *data);
void InputParse(Fractal *data);
Uint32 **init_colors();

#endif