#ifndef __SCENE_LVL4_H__
#define __SCENE_LVL4_H__

#include "Module.h"
#include "Animation.h"



#define BUTTON_REPLACE_COUNTDOWN 25

struct SDL_Texture;

class SceneLevel4 : public Module
{
public:
	//Constructor
	SceneLevel4(bool startEnabled);

	//Destructor
	~SceneLevel4();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	Update_Status Update();

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	Update_Status PostUpdate();

	// Disables the player and the enemies
	bool CleanUp();


	//Erase button
	void eraseButton(Collider* c);

public:

	//
	//Texture variables
	//
	SDL_Texture* lvl4Texture = nullptr;
	SDL_Texture* buttonTexture = nullptr;
	SDL_Texture* princessTexture = nullptr;

	//
	//Collider arrays
	//
	Collider* buttonColliders[8];

	//
	//Srite rectangles
	//
	SDL_Rect lvl4Rect;
	SDL_Rect buttonRect;
	SDL_Rect aux;

	//
	//Animations
	//
	Animation Princess;
	
	

	//
	//Level 4 win condition
	//
	//Button array
	bool buttonDrawingArray[8] = { true, true, true, true, true, true, true, true };
	uint totalButtons = 8;
	bool lvl4win = false;
	bool spawnGravityWall = false;
	int spawnGravityWallCountdown = BUTTON_REPLACE_COUNTDOWN;

};

#endif