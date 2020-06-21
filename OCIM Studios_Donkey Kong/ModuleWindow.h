#ifndef __MODULE_WINDOW_H__
#define __MODULE_WINDOW_H__

#include "Module.h"

struct SDL_Window;
struct SDL_Surface;

//Window Class
class ModuleWindow : public Module
{
public:

	ModuleWindow(bool startEnabled);

	// Virtual Destructor
	virtual ~ModuleWindow();


	// Called on application start.
	// Initializes the SDL Library and creates a window.
	bool Init();

	// Called on application exit.
	// Destroys the window and uninitializes the SDL library
	bool CleanUp();


public:
	//The window we'll be rendering to
	SDL_Window* window = nullptr;

	//The window's surface
	SDL_Surface* screenSurface = nullptr;
};

#endif // !__MODULE_WINDOW_H__