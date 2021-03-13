#include "fractal.h"

void InputParse(Fractal *data)
{
	static int sineChange;
	SDLX_Input input;
	SDL_Scancode code;
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
			if (event.wheel.y > 0)
				data->cam.scale = data->cam.scale  * (1.5);
			else
				data->cam.scale = data->cam.scale  / (1.5);
			// data->zoom_step += event.wheel.y * 0.2; 
			if (data->cam.scale < 1)
			{
				data->cam.scale = 1;
				// data->zoom_step = 0.5;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
			data->colorData.mode ^= 1;
		if (event.type == SDL_KEYDOWN)
		{
			// SDL_Log("", data->paused);
			code = event.key.keysym.scancode;
			SDL_Log("Keynum %d Fac no %d, Mode %d | RGB %d , Grad Index %d", code, data->fractal, data->colorData.mode, data->colorData.rgb, data->colorData.index);
			if (code == SDL_SCANCODE_RETURN)
				data->paused ^= 1;
			if (code == SDL_SCANCODE_SPACE)
				sineChange = (sineChange + 1) % 3;
			if (code >= SDL_SCANCODE_1 && code <= SDL_SCANCODE_9)
			{
				int keynum;

				keynum = code - 29;
				if (keynum <= data->nfractal)
					data->fractal = keynum - 1;
			}
			if (code == SDL_SCANCODE_LEFT)
			{
				// 1 = sinwave coloring, 0 = gradient coloring
				if (data->colorData.mode == 1)
					data->colorData.rgb = (data->colorData.rgb - 1) % 3;
				else
					data->colorData.index = (data->colorData.index - 1) % data->colorData.ncolors;
			}
			if (code == SDL_SCANCODE_RIGHT)
			{
				if (data->colorData.mode == 1)
					data->colorData.rgb = (data->colorData.rgb + 1) % 3;
				else
					data->colorData.index = (data->colorData.index + 1) % data->colorData.ncolors;
			}
			(data->colorData.rgb < 0) ? (data->colorData.rgb = 0) : (0);
			(data->colorData.index < 0) ? (data->colorData.index = 0) : (0);
		}
	}
	SDLX_InputUpdate(event);
	input = SDLX_InputGet();
	if (sineChange == 0)
	{
		data->colorData.waveData[data->colorData.rgb].frequency += keyboard[SDL_SCANCODE_UP] / 10;
		data->colorData.waveData[data->colorData.rgb].frequency -= keyboard[SDL_SCANCODE_DOWN] / 10;
	}
	if (sineChange == 1)
	{
		data->colorData.waveData[data->colorData.rgb].add += keyboard[SDL_SCANCODE_UP] * 2;
		data->colorData.waveData[data->colorData.rgb].add -= keyboard[SDL_SCANCODE_DOWN] * 2;
	}
	if (sineChange == 2)
	{
		data->colorData.waveData[data->colorData.rgb].mid += keyboard[SDL_SCANCODE_UP] * 10;
		data->colorData.waveData[data->colorData.rgb].mid -= keyboard[SDL_SCANCODE_DOWN] * 10;
		if (data->colorData.waveData[data->colorData.rgb].mid < 0)
			data->colorData.waveData[data->colorData.rgb].mid = 0;
		if (data->colorData.waveData[data->colorData.rgb].mid > 255)
			data->colorData.waveData[data->colorData.rgb].mid = 255;
	}

	data->cam.position.x -= input.input[SDLX_LEFT]  * (WIN_W / data->cam.scale) / WIN_W * 20;
	data->cam.position.x += input.input[SDLX_RIGHT]  * (WIN_W / data->cam.scale) / WIN_W * 20;
	data->cam.position.y -= input.input[SDLX_UP]  * (WIN_W / data->cam.scale) / WIN_W * 20;
	data->cam.position.y += input.input[SDLX_DOWN]  * (WIN_W / data->cam.scale) / WIN_W * 20;
}