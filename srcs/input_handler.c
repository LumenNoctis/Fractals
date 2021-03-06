#include "fractal.h"

void InputParse(Fractal *data)
{
	SDLX_Input input;
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit(0);
		if (event.type == SDL_MOUSEWHEEL)
		{
			data->zoom += event.wheel.y;
			(data->zoom <= 0) ? (data->zoom = 1) : (0);
			SDL_Log("Zoom %f\n", data->zoom);
		}
	}
	SDLX_InputUpdate(event);
	input = SDLX_InputGet();
	data->mousePos.x = input.mouse_x;
	data->mousePos.y = input.mouse_y;
	data->offset.x -= input.input[SDLX_LEFT]  * data ->zoom;//	* (data->zoom / 10);
	data->offset.x += input.input[SDLX_RIGHT] * data ->zoom;// 	* (data->zoom / 10);
	data->offset.y -= input.input[SDLX_UP] 	  * data ->zoom;//	* (data->zoom / 10);
	data->offset.y += input.input[SDLX_DOWN]  * data ->zoom;//	* (data->zoom / 10);
}