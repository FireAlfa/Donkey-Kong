#include "Enemy.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

//Constructor sets the initial position of enemy
Enemy::Enemy(int x, int y) : position(x, y)
{
	spawnPos = position;
	srand(time(NULL));
}

//Destroys enemy collider
Enemy::~Enemy()
{
	if (collider != nullptr)
		collider->pendingToDelete = true;
}

//Get the collider from the enemy
const Collider* Enemy::GetCollider() const
{
	return collider;
}

//Update the animation and position of the enemy
void Enemy::Update()
{
	if (currentAnim != nullptr)
		currentAnim->Update();

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);
}

//Blit the enemy on the screen
void Enemy::Draw()
{
	if (currentAnim != nullptr)
		App->render->Blit(texture, position.x, position.y, &(currentAnim->GetCurrentFrame()));
}

//Control the collisions between the enemy and other colliders
void Enemy::OnCollision(Collider* c1, Collider* c2)
{
	App->particles->AddParticle(App->particles->enemyDeath, position.x, position.y);
	App->audio->PlayFx(destroyedFx);
}

//Put the enemy in delete queue
void Enemy::SetToDelete()
{
	pendingToDelete = true;
	if (collider != nullptr)
		collider->pendingToDelete = true;
}