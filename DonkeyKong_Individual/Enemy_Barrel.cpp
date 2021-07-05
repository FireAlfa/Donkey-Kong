#include "Enemy_Barrel.h"

#include "Application.h"
#include "Collider.h"
#include "ModuleCollisions.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "Enemy.h"
#include "ModulePlayer.h"


Enemy_Barrel::Enemy_Barrel(int x, int y, int _direction) : Enemy(x, y)
{
	direction = _direction;
	
	BarrelAnim.PushBack({ 103, 136, 12, 10 });
	BarrelAnim.PushBack({ 116, 136, 12, 10 });
	BarrelAnim.PushBack({ 129, 136, 12, 10 });
	BarrelAnim.PushBack({ 142, 136, 12, 10 });
	BarrelAnim.loop = true;
	BarrelAnim.speed = 0.1f;

	BarrelFall.PushBack({ 92, 153, 16, 11 });
	BarrelFall.PushBack({ 92, 153, 16, 11 });
	BarrelFall.loop = true;
	BarrelFall.speed = 0.1f;

	currentAnim = &BarrelAnim;



	rampRight = false;
	rampLeft = false;
	touchedWall = false;
	canGoDownStairs = false;
	bounceWall = false;
	destroy = false;


	collider = App->collisions->AddCollider({ position.x + 3, position.y + 4, 6, 6 }, Collider::Type::ENEMY, (Module*)App->enemies);
	tallCollider = App->collisions->AddCollider({ position.x + 5, position.y - 8, 2, 2 }, Collider::Type::TALLENEMY, (Module*)App->enemies);
}

Enemy_Barrel::~Enemy_Barrel()
{

}

void Enemy_Barrel::Update()
{
	UpdateState();
	UpdateLogic();
}


// Call to the base class. It must be called at the end
// It will update the collider depending on the position
void Enemy_Barrel::UpdateState()
{
	switch (barrelState)
	{
	case BARREL_MOVING:
		if (canGoDownStairs == true)
		{
			random = rand() % 10 + 1;
			if (random <= 3)
			{
				ChangeState(barrelState, BARREL_FALLING);
			}
			canGoDownStairs = false;
		}
		break;

	case BARREL_FALLING:
		if (touchedWall == true)
		{
			position.y -= speed;
			position.x += speed * direction;
			touchedWall = false;
			ChangeState(barrelState, BARREL_MOVING);
			
		}
		break;

	default:
		break;
	}

	Enemy::Update();
}

void Enemy_Barrel::UpdateLogic()
{
	switch (barrelState)
	{
	case BARREL_MOVING:

		if (falling == true)
		{
			position.y += speed;
		}

		if (bounceWall == true)
		{
			direction *= -1;
			bounceWall = false;
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

		if (destroy == true)
		{
			App->collisions->RemoveCollider(auxCollider);
		}



		currentAnim->Update();

		break;

	case BARREL_FALLING:
		if (touchedWall == false)
		{
			position.y += speed;
		}

		currentAnim->Update();

		break;

	default:
		break;
	}

	if (touchedWall == true)
	{
		position.y -= speed;
		falling = false;
	}




	rampRight = false;
	rampLeft = false;
	touchedWall = false;
	canGoDownStairs = false;
	bounceWall = false;
	destroy = false;


	collider->SetPos(position.x + 3, position.y + 4);
	tallCollider->SetPos(position.x + 5, position.y - 8);
}

void Enemy_Barrel::ChangeState(Barrel_State prevState, Barrel_State newState)
{
	switch (newState)
	{
	case BARREL_MOVING:
		if (prevState == BARREL_FALLING)
		{
			touchedWall = false;
			direction *= -1;
			prevState = BARREL_MOVING;
		}
		currentAnim = &BarrelAnim;

		break;

	case BARREL_FALLING:
		if (direction == 1)
		{
			position.x = aux.x - 6;
		}
		if (direction == -1)
		{
			position.x = aux.x - 5;
		}
		

		currentAnim = &BarrelFall;

		break;

	default:
		break;
	}


	barrelState = newState;
}

void Enemy_Barrel::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == tallCollider && c2->type == Collider::Type::GRAVITYWALLS)
	{
		falling = true;
	}

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

	if (c1 == collider && c2->type == Collider::Type::RIGHTWALL || c1 == collider && c2->type == Collider::Type::LEFTWALL)
	{
		SDL_Rect auxrect = c1->GetRect();

		if (aux.y - 10 < App->player->position.y)
		{
			bounceWall = true;
		}
		else
		{
			auxCollider = c1;
			destroy = true;
		}
	}


	if (c1 == collider && c2->type == Collider::Type::PLAYER_FEET) //Fall
	{
		falling = true;
	}


}