#include "ModuleWindow.h"

#include "Application.h"
#include "Globals.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib")


ModuleWindow::ModuleWindow(bool startEnabled) : Module(startEnabled)
{
	name = "window";
}

ModuleWindow::~ModuleWindow()
{

}

//Initialize the Window
bool ModuleWindow::Init()
{
	LOG("Init SDL window & surface-------\n");
	bool ret = true;

	//Init the library and check for possible errors using SDL_GetError()
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		LOG("SDL_VIDEO could not initialize! SDL_Error:\n");
		LOG(SDL_GetError());
		ret = false;
	}
	else
	{
		//Choose flag for the window
		Uint32 flags = SDL_WINDOW_SHOWN;

		if (WIN_FULLSCREEN == true)
			flags |= SDL_WINDOW_FULLSCREEN;

		if (WIN_BORDERLESS == true)
			flags |= SDL_WINDOW_BORDERLESS;

		if (WIN_RESIZABLE == true)
			flags |= SDL_WINDOW_RESIZABLE;

		if (WIN_FULLSCREEN_DESKTOP == true)
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

		//Creates the Window
		window = SDL_CreateWindow("OCIM Studios - Donkey Kong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH * SCREEN_SIZE, SCREEN_HEIGHT * SCREEN_SIZE, flags);

		//Window Error control
		LOG("Window created successfully--------\n");

		//Error control
		if (window == nullptr)
		{
			LOG("----- Window could not be created! SDL_Error: \n");
			LOG(SDL_GetError());
			ret = false;
		}
		else
		{
			//Creates the surface
			screenSurface = SDL_GetWindowSurface(window);

			//Surface Error control
			LOG("Surface created successfully--------\n");
		}
	}

	return ret;
}

//Destroy Window subsystem
bool ModuleWindow::CleanUp()
{
	LOG("Destroying SDL window and quitting all SDL systems--------\n");

	//Destroy window
	if (window != NULL)
		SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return true;
}