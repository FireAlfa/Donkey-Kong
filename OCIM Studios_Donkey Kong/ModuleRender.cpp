#include "ModuleRender.h"

#include "Application.h"

#include "ModuleWindow.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"

#include "SDL/include/SDL_render.h"
#include "SDL/include/SDL_scancode.h"



//Constructor
ModuleRender::ModuleRender(bool startEnabled) : Module(startEnabled)
{
	name = "render";
}

//Destructor
ModuleRender::~ModuleRender()
{

}


//Initiate the Render
bool ModuleRender::Init()
{
	LOG("Creating Renderer context--------------\n");
	bool ret = true;
	Uint32 flags = 0;

	//VSYNC flag
	if (VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	//Sets the renderer to be window size
	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	//Error control
	if (renderer == nullptr)
	{
		LOG("----- Renderer could not be created! SDL_Error: \n");
		LOG(SDL_GetError());
		ret = false;
	}
	else
	{
		LOG("Renderer created succesfully--------------\n");
	}

	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	return ret;
}

// Called every draw update
Update_Status ModuleRender::PreUpdate()
{
	//Set the color used for drawing operations
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	//Clear rendering target
	SDL_RenderClear(renderer);

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleRender::Update()
{
	//Handle positive vertical movement
	if (App->input->keys[SDL_SCANCODE_UP] == KEY_REPEAT)
		camera.y -= cameraSpeed;

	//Handle negative vertical movement
	if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_REPEAT)
		camera.y += cameraSpeed;

	// Handle negative horizontal movement of the camera
	if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_REPEAT)
		camera.x -= cameraSpeed;
	if (camera.x < 0) camera.x = 0;

	// Handle positive horizontal movement of the camera
	if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_REPEAT)
		camera.x += cameraSpeed;
	if (camera.x > 1536) camera.x = 1536;


	return Update_Status::UPDATE_CONTINUE;
}

//Paints the render on screen
Update_Status ModuleRender::PostUpdate()
{
	//Update the screen
	SDL_RenderPresent(renderer);

	return Update_Status::UPDATE_CONTINUE;
}

//Destroys the render subsystem
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer--------\n");

	//Destroy the rendering context
	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);

	return true;
}


// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, const SDL_Rect* section, float speed, bool useCamera)
{
	bool ret = true;

	SDL_Rect dstRect{ x * SCREEN_SIZE, y * SCREEN_SIZE, 0, 0 };

	if (useCamera)
	{
		dstRect.x -= (camera.x * speed);
		dstRect.y -= (camera.y * speed);
	}

	if (section != nullptr)
	{
		dstRect.w = section->w;
		dstRect.h = section->h;
	}
	else
	{
		//Collect the texture size into rect.w and rect.h variables
		SDL_QueryTexture(texture, nullptr, nullptr, &dstRect.w, &dstRect.h);
	}

	dstRect.w *= SCREEN_SIZE;
	dstRect.h *= SCREEN_SIZE;

	if (SDL_RenderCopy(renderer, texture, section, &dstRect) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}

//Draws a square
bool ModuleRender::DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, float speed, bool useCamera)
{
	bool ret = true;

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	SDL_Rect dstRect{ rect.x * SCREEN_SIZE, rect.y * SCREEN_SIZE, rect.w * SCREEN_SIZE, rect.h * SCREEN_SIZE };

	if (useCamera)
	{
		dstRect.x -= (camera.x * speed);
		dstRect.y -= (camera.y * speed);
	}

	if (SDL_RenderFillRect(renderer, &dstRect) != 0)
	{
		LOG("Cannot draw quad to screen. SDL_RenderFillRect error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}