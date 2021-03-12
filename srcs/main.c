#include "fractal.h"

Fractal *Fractal_Init()
{
	Fractal *data;
	
	data = calloc(1, sizeof(*data));
	data->colorData.colors = init_colors();
	data->colorData.index = 0;
	data->colorData.ncolors = 1;
	data->cam.scale = 1;
	data->zoom_step = 0.5;
	data->cam.position.x = WIN_H / 2;
	data->cam.position.y = WIN_W / 2;

	SDLX_InputMap(SDL_SCANCODE_UP,	  1, SDLX_UP, 0);
	SDLX_InputMap(SDL_SCANCODE_LEFT,  1, SDLX_LEFT, 0);
	SDLX_InputMap(SDL_SCANCODE_DOWN,  1, SDLX_DOWN, 0);
	SDLX_InputMap(SDL_SCANCODE_RIGHT, 1, SDLX_RIGHT, 0);
	
	SDLX_InputMap(SDL_SCANCODE_W, 1, SDLX_UP, 0);
	SDLX_InputMap(SDL_SCANCODE_A, 1, SDLX_LEFT, 0);
	SDLX_InputMap(SDL_SCANCODE_S, 1, SDLX_DOWN, 0);
	SDLX_InputMap(SDL_SCANCODE_D, 1, SDLX_RIGHT, 0);

	SDLX_InputMap(SDL_SCANCODE_SPACE, 1, SDLX_PAUSE, 0);
	return data;
}

int main(void)
{
	int i;
	Fractal *data;
	SDLX_Display *display;

	i = 1;
	SDLX_DisplaySet();
	display = SDLX_DisplayGet();
	data = Fractal_Init();
	while (1)
	{
		SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 255);
		SDL_RenderClear(display->renderer);
		InputParse(data);
		RenderToScreen(data);
		SDL_RenderPresent(display->renderer);
	}
	return 0;
}