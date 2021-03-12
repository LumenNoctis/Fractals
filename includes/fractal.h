#ifndef FRACTAL_H
# define FRACTAL_H

# include "SDLX/SDLX.h"
# include "MT/MT.h"
# include "Gradient/gradient.h"

# define LOD 125

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

typedef struct Camera
{
	MT_Vector2 position;
	double scale;
}				Camera;

typedef struct Fractal
{
	int index;
	int paused;
	double zoom_step;

	int mouse_x;
	int mouse_y;

	Imaginary c;
	Color_data colorData;
	Camera cam;
} Fractal;

int Julia(double x, double y, Fractal *data);
int Mandelbrot(double x, double y, Fractal *data);

void RenderToScreen(Fractal *data);
void InputParse(Fractal *data);
Uint32 **init_colors();

#endif