#include "Enemy_Cement.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

Enemy_Cement::Enemy_Cement(int x, int y, int direction) : Enemy(x, y)
{

	//TODO: Pushbacks

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}


Enemy_Cement::~Enemy_Cement()
{

}

void Enemy_Cement::Update()
{
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}

void Enemy_Cement::OnCollision(Collider* c1, Collider* c2)
{

}