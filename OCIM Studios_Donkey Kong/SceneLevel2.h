#ifndef __SCENE_LVL2_H__
#define __SCENE_LVL2_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class SceneLevel2 : public Module
{
public:
	//Constructor
	SceneLevel2(bool startEnabled);

	//Destructor
	~SceneLevel2();

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

public:

	//
	//Texture variables
	//
	SDL_Texture* lvl2Texture = nullptr;
	SDL_Texture* princessTexture = nullptr;
	SDL_Texture* oilTexture = nullptr;
	SDL_Texture* movingObjects = nullptr;
	SDL_Texture* cementTexture = nullptr;
	SDL_Texture* hatTexture = nullptr;
	SDL_Texture* bagTexture = nullptr;
	SDL_Texture* parasolTexture = nullptr;
	SDL_Texture* hammerTexture = nullptr;


	//
	//Collider arrays
	//
	Collider* conveyerColliders[4] = { nullptr };


	//
	//Grind animation array	
	// 0 means left  and 1 means right
	// [0]=bottom bair  [1]=mid left  [2]=mid right  [3]=top pair
	//
	bool knobDirectionArray[4] = { 0 };
	Animation* knobAnimationArray[6] = { nullptr };


	//
	//Srite rectangles
	//
	SDL_Rect lvl2Rect;
	SDL_Rect knobRect;


	//
	//Animations
	//
	Animation Princess;
	Animation leftKnob;
	Animation rightKnob;





	//
	//Win condition
	//
	bool lvl2win;

};

#endif
