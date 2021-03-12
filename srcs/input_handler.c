#include "fractal.h"

void InputParse(Fractal *data)
{
	SDLX_Input input;
	SDL_Event event;
	Uint8 *keyboard;

	keyboard = SDL_GetKeyboardState(NULL);
	SDL_GetMouseState(&data->mouse_x, &data->mouse_y);
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit(0);
		if (event.type == SDL_MOUSEWHEEL)
		{
			data->cam.scale += event.wheel.y * data->zoom_step;
			data->zoom_step += event.wheel.y * 0.2; 
			if (data->cam.scale < 1)
			{
				data->cam.scale = 1;
				data->zoom_step = 0.5;
			}
		}
	}
	SDLX_InputUpdate(event);
	input = SDLX_InputGet();
	if (keyboard[SDL_SCANCODE_SPACE])
		data->paused ^= 1;
	data->cam.position.x -= input.input[SDLX_LEFT]  * (WIN_W / data->cam.scale) / WIN_W * 20;
	data->cam.position.x += input.input[SDLX_RIGHT]  * (WIN_W / data->cam.scale) / WIN_W * 20;
	data->cam.position.y -= input.input[SDLX_UP]  * (WIN_W / data->cam.scale) / WIN_W * 20;
	data->cam.position.y += input.input[SDLX_DOWN]  * (WIN_W / data->cam.scale) / WIN_W * 20;
	SDL_Log("PAUSE %d", data->paused);
}