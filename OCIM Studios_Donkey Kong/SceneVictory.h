#ifndef __SCENE_VICTORY_H__
#define __SCENE_VICTORY_H__


#include "Module.h"
#include "Animation.h"



#define SPACE_BLINK 40

struct SDL_Texture;

//Class for the First screen of the game
class SceneVictory : public Module
{
public:
	//Constructor
	SceneVictory(bool startEnabled);

	//Destructor
	~SceneVictory();

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
	SDL_Texture* deathanim = nullptr;
	SDL_Texture* leftright = nullptr;
	SDL_Texture* heartVicotry = nullptr;


	SDL_Texture* downAnim = nullptr;
	SDL_Texture* marioT = nullptr;
	SDL_Texture* peachT = nullptr;
	SDL_Texture* heartT = nullptr; 


	SDL_Rect heart;
	SDL_Rect goDown;
	SDL_Rect Mario;
	SDL_Rect Peach;
	Animation armS;
	Animation dowN;
	Animation landr;

	int counter1 = 0;
	int counter2 = 0;

	bool dead;
	
	bool transition;

	int deathcont = 0;

	int goDownCounter1 = 0;
	int goDownCounter2 = 0;
	int yDescent;

	int lastAnim1 = 0;
	int lastAnim2 = 0;

	//
	//Srite rectangles
	//

public:
	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* spaceToStartTexture = nullptr;

	//Square for texture
	SDL_Rect vscreen;
	SDL_Rect wincond;

	//Counter to know when to print the Space to Start text
	int cont = 0;

};

#endif