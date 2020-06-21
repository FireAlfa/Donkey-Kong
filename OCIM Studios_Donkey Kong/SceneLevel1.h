#ifndef __SCENE_LVL1_H__
#define __SCENE_LVL1_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class SceneLevel1 : public Module
{
public:
	//Constructor
	SceneLevel1(bool startEnabled);

	//Destructor
	~SceneLevel1();

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

	//erase hammer
	void eraseHammer(Collider* c);

	//Score functions

	void score100() { score += 100; }

	void score300() { score += 300; }

	//
	//Texture variables
	//
		SDL_Texture* lvl1Texture = nullptr;
		SDL_Texture* lvl1Barrels = nullptr;
		SDL_Texture* lvl1fireBarrels = nullptr;
		SDL_Texture* lvl1dkAnimation = nullptr;
		SDL_Texture* hammerTexture = nullptr;


	//
	//
	//
	//Collider arrays
	//
	//
	//
	Collider* ladderColliders[4];

	Collider* hammerColliders[2];

	SDL_Texture* dkBarrels = nullptr;
	SDL_Texture* lvl1LeftdkAnimation = nullptr;



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
	SDL_Rect hammerRect;

	//SDL_Rect buttonRect;

	//Hammer array
	bool hammerDrawingArray[2] = { true, true };

	//
	//Win condition
	//
	bool lvl1win = false;

	int initialY = 217;
	int animCont0 = 0;
	int animCont1 = 0;


private:
	uint score = 000000;
	uint highscore = 000000;
	uint bonus = 5000;

	char scoreText[7] = { "\0" };
	char highscoreText[7] = { "\0" };
	char bonusText[5] = { "\0" };

};

#endif