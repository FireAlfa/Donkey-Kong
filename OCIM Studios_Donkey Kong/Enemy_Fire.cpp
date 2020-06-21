#include "Enemy_Fire.h"

#include "Application.h"
#include "Collider.h"
#include "ModuleCollisions.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "Enemy.h"
#include "ModulePlayer.h"



Enemy_Fire::Enemy_Fire(int x, int y, int _direction) :Enemy(x, y)
{
	direction = _direction;

	FireAnim.PushBack({ 0, 134, 13, 15, });
	FireAnim.PushBack({ 17, 134, 13, 15, });
	FireAnim.speed = 0.1f;


	rampRight = false;
	rampLeft = false;
	canGoDownStairs = false;
	canGoUpStairs = false;
	touchedWall = false;
	destroy = false;

	currentAnim = &FireAnim;

	collider = App->collisions->AddCollider({position.x + 3, position.y + 7, 6, 7 }, Collider::Type::ENEMY, (Module*)App->enemies);
}



Enemy_Fire::~Enemy_Fire()
{

}


void Enemy_Fire::Update()
{
	UpdateState();
	UpdateLogic();
}

// Checks for inputs (or timers) and changes the player state accordingly
void Enemy_Fire::UpdateState()
{
	switch (fireState)
	{
	case FIRE_MOVING:
		if (canGoDownStairs == true)
		{
			random = rand() % 10 + 1;
			if (random <= 3)
			{
				ChangeState(fireState, FIRE_CLIMBING_DOWN);
			}
			canGoDownStairs = false;
		}
		if (canGoUpStairs == true)
		{
			random = rand() % 10 + 1;
			if (random <= 3)
			{
				ChangeState(fireState, FIRE_CLIMBING_UP);
			}
			canGoDownStairs = false;
		}
		break;
	case FIRE_CLIMBING:
		break;

	case FIRE_CLIMBING_DOWN:
		if (touchedWall == true)
		{
			ChangeState(fireState, FIRE_MOVING);
		}
		break;

	case FIRE_CLIMBING_UP:
		break;

	default:
		break;
	}
}

// Updates the logic of the player depending on the current state
void Enemy_Fire::UpdateLogic()
{
	switch (fireState)
	{
	case FIRE_MOVING:
		--faceCountdown;
		if (faceCountdown == 0)
		{
			int random = rand() % 2;
			if (random == 0) {
				direction *= -1;
			}
		}



		if (direction == 1)
		{
			position.x += speed;
		}

		if (direction == -1)
		{
			position.x -= speed;
		}

		//Going Right
		if (rampLeft == true)
		{
			if (collider->rect.y < aux.y - 8 && collider->rect.x + 4 == aux.x) //Go Down Looking Right
			{
				position.y += speed;
			}
		}

		//Going Left
		if (rampRight == true)
		{
			if (collider->rect.y <= aux.y - 8 && collider->rect.x + 5 == aux.x) //Go Down Looking Left//
			{
				position.y += speed;
			}
		}



		break;
	case FIRE_CLIMBING:
		break;
	case FIRE_CLIMBING_DOWN:
		position.y += speed;
		break;
	case FIRE_CLIMBING_UP:
		position.y -= speed;
		break;
	default:
		break;
	}

	rampRight = false;
	rampLeft = false;
	canGoDownStairs = false;
	canGoUpStairs = false;
	touchedWall = false;
	destroy = false;


	collider->SetPos(position.x + 3, position.y + 7);
}

// Transition from one state to a new one. Changes animations, resets variables,...
void Enemy_Fire::ChangeState(Fire_State previousState, Fire_State newState)
{
	switch (fireState)
	{
	case FIRE_MOVING:
		if (previousState == FIRE_CLIMBING_DOWN)
		{
			touchedWall = false;
			direction *= -1;
			previousState = FIRE_CLIMBING_DOWN;
		}
		break;
	case FIRE_CLIMBING:
		break;
	case FIRE_CLIMBING_DOWN:
		if (direction == 1)
		{
			position.x = aux.x - 4;
		}
		if (direction == -1)
		{
			position.x = aux.x - 3;
		}
		break;
	case FIRE_CLIMBING_UP:
		if (direction == 1)
		{
			position.x = aux.x - 4;
		}
		if (direction == -1)
		{
			position.x = aux.x - 3;
		}
		break;

	default:
		break;
	}
}


//Control barrel collisions
void Enemy_Fire::OnCollision(Collider* c1, Collider* c2)
{
	//Rolling on the floor collisions
	if (c1 == collider && c2->type == Collider::Type::RAMP_RIGHT)
	{
		rampRight = true;
		aux = c2->GetRect();
	}

	if (c1 == collider && c2->type == Collider::Type::RAMP_LEFT)
	{
		rampLeft = true;
		aux = c2->GetRect();
	}

	//Going down stairs collisions
	if (c1 == collider && c2->type == Collider::Type::TOP_STAIR)
	{
		SDL_Rect c1Rect = c1->GetRect();
		aux = c2->GetRect();

		if (aux.y - 8 <= c1Rect.y) {
			if (direction == 1 && aux.x - 5 == c1Rect.x) {
				canGoDownStairs = true;
			}
			else if (direction == -1 && aux.x - 5 != c1Rect.x)
			{
				canGoDownStairs = true;
			}
			else {
				canGoDownStairs = false;
			}

		}


	}

	if (c1 == collider && c2->type == Collider::Type::WALL)
	{
		touchedWall = true;
		lastCollider = Collider::Type::WALL;
	}

}