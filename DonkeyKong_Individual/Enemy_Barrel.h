#ifndef __ENEMY_BARREL_H__
#define __ENEMY_BARREL_H__

#include "Enemy.h"
#include "Animation.h"
#include "Collider.h"
#include "ModuleCollisions.h"
#include <stdlib.h>
#include <time.h>

enum Barrel_State
{
	BARREL_MOVING,
	BARREL_FALLING,
};


class Enemy_Barrel : public Enemy
{
public:
	//Constructor
	Enemy_Barrel(int x, int y, int _direction);

	//Destructor
	~Enemy_Barrel();


	void Update() override;

	// Checks for inputs (or timers) and changes the player state accordingly
	void UpdateState();

	// Updates the logic of the player depending on the current state
	void UpdateLogic();

	// Transition from one state to a new one. Changes animations, resets variables,...
	void ChangeState(Barrel_State previousState, Barrel_State newState);


	//Control barrel collisions
	void OnCollision(Collider* c1, Collider* c2) override;



	//
	//Barrel Flags
	//
	bool rampRight = false;
	bool rampLeft = false;
	bool canGoDownStairs = false;
	bool touchedWall = false;
	bool bounceWall = false;
	bool falling = false;
	bool destroy = false;

	//
	//Initial variables
	//
	Barrel_State barrelState = BARREL_MOVING;
	int random = 0;
	int direction = 1;
	int speed = 1;

	//Auxiliar collider rectangle
	SDL_Rect aux;
	Collider* auxCollider;

	int lastCollider = Collider::Type::NONE;


private:

	Animation BarrelAnim, BarrelFall;
};
	
#endif // !__ENEMY_BARREL_H__