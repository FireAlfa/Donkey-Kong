#include "Enemy_DonkeyKong.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

Enemy_DonkeyKong::Enemy_DonkeyKong(int x, int y) : Enemy(x, y)
{

	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 217, 0, 46, 32 });
	DonkeyKong.PushBack({ 170, 0, 46, 32 });
	DonkeyKong.PushBack({ 217, 0, 46, 32 });
	DonkeyKong.speed = 0.03f;

	currentAnim = &DonkeyKong;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_DonkeyKong::Update()
{
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}