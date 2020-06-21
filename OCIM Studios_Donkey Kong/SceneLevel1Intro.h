#ifndef __SCENE_LEVEL1INTRO_H__
#define ___SCENE_LEVEL1INTRO_H__

#include "Module.h"
#include "Animation.h"



#define SPACE_BLINK 40

struct SDL_Texture;

//Class for the First screen of the game
class SceneLevel1Intro : public Module
{
public:
	//Constructor
	SceneLevel1Intro(bool startEnabled);

	//Destructor
	~SceneLevel1Intro();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	Update_Status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	Update_Status PostUpdate() override;


	bool CleanUp();


	SDL_Texture* lvl1Texture = nullptr;
	SDL_Texture* lvl1dkAnimation = nullptr;

	SDL_Texture* dkBarrels;
	SDL_Texture* lvl1LeftdkAnimation;



	Animation DK;
	Animation fireBarrel;
	Animation dkAnim;

	//
	//Srite rectangles
	//
	SDL_Rect lvl1Rect;
	SDL_Rect Barrels;
	SDL_Rect lvl1B;
	SDL_Rect dkLeftAnim;




	bool lvl1win = false;

	int initialY = 217;
	int animCont0 = 0;
	int animCont1 = 0;


	bool topReached = false;

	int jumpY = 52;

	int time1 = 0;

	int contX1 = 0;

	int contX2 = 0;

	int contX = 90;

	int totalJumps = 0;

	int animController0 = 0;

public:
	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* spaceToStartTexture = nullptr;

	//Square for texture
	SDL_Rect spaceToStartRect;

	//Counter to know when to print the Space to Start text
	int cont = 0;

};

#endif
