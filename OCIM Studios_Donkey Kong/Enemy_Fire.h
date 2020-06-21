#ifndef __ENEMY_FIRE_H__
#define __ENEMY_FIRE_H__

#include "Enemy.h"
#include "Path.h"
#include "Animation.h"
#include "Collider.h"
#include <time.h>


enum Fire_State
{
	FIRE_MOVING,
	FIRE_CLIMBING,
	FIRE_CLIMBING_DOWN,
	FIRE_CLIMBING_UP,
};

class Enemy_Fire : public Enemy
{
public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_Fire(int x, int y, int direction);

	//Destructor
	~Enemy_Fire();



	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

	// Checks for inputs (or timers) and changes the player state accordingly
	void UpdateState();

	// Updates the logic of the player depending on the current state
	void UpdateLogic();

	// Transition from one state to a new one. Changes animations, resets variables,...
	void ChangeState(Fire_State previousState, Fire_State newState);


	//Control barrel collisions
	void OnCollision(Collider* c1, Collider* c2) override;


private:
	//
	//Fire Flags
	//
	bool rampRight = false;
	bool rampLeft = false;
	bool canGoDownStairs = false;
	bool canGoUpStairs = false;
	bool touchedWall = false;
	bool destroy = false;

	int faceCountdown = 100;


	//Auxiliar collider rectangle
	SDL_Rect aux;
	Collider* auxCollider;

	int lastCollider = Collider::Type::NONE;



	//
	//Initial variables
	//
	Fire_State fireState = FIRE_MOVING;
	int random = 0;
	int direction = 1;
	int speed = 1;

	SDL_Texture* Texture = nullptr;

	// The path that will define the position in the world
	Path path;

	// Enemy animations
	Animation FireAnim;
};

#endif // __ENEMY_DONKEYKONG_H__