#include "ModuleEnemies.h"

#include "Application.h"

#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"

//
//Include enemy files
//
#include "Enemy.h"
#include "Enemy_DonkeyKong.h"
#include "Enemy_Barrel.h"
#include "Enemy_BlueBarrel.h"
#include "Enemy_Cement.h"
#include "Enemy_Fire.h"



#define SPAWN_MARGIN 5


//Constructor inits enemy array to nullptr
ModuleEnemies::ModuleEnemies(bool startEnabled) : Module(startEnabled)
{
	name = "enemies";

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

ModuleEnemies::~ModuleEnemies()
{

}

//Set the textures and FX for the enemies
bool ModuleEnemies::Start()
{
	//
	//Load texture files used by ALL enemies
	//
	texture = App->textures->Load("Assets/Sprites/Enemies_Sprites.png");


	//
	//Load FX files used by ALL enemies
	//
	enemyDestroyedFx = App->audio->LoadFx("Assets/Audio/FX/Kill.ogg"); //General enemy death sound


	return true;
}

//Removes enemies scheduled for deletion
Update_Status ModuleEnemies::PreUpdate()
{
	// Remove all enemies scheduled for deletion
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->pendingToDelete)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

//Control spawn, update enemy, control despawn
Update_Status ModuleEnemies::Update()
{
	HandleEnemiesSpawn();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
			enemies[i]->Update();
	}

	HandleEnemiesDespawn();

	return Update_Status::UPDATE_CONTINUE;
}


//Draw the enemies
Update_Status ModuleEnemies::PostUpdate()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
			enemies[i]->Draw();
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

//Add an enemy to the queue
bool ModuleEnemies::AddEnemy(Enemy_Type type, int x, int y, int direction)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (spawnQueue[i].type == Enemy_Type::NO_TYPE)
		{
			spawnQueue[i].type = type;
			spawnQueue[i].x = x;
			spawnQueue[i].y = y;
			spawnQueue[i].direction = direction;
			ret = true;
			break;
		}
	}

	return ret;
}

//Controls the enemies spawn
void ModuleEnemies::HandleEnemiesSpawn()
{
	// Iterate all the enemies queue
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (spawnQueue[i].type != Enemy_Type::NO_TYPE)
		{
			// Spawn a new enemy if the screen has reached a spawn position
			if (spawnQueue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				LOG("Spawning enemy at %d", spawnQueue[i].x * SCREEN_SIZE);

				SpawnEnemy(spawnQueue[i]);
				spawnQueue[i].type = Enemy_Type::NO_TYPE; // Removing the newly spawned enemy from the queue
			}
		}
	}
}

//Control the enemies despawn
void ModuleEnemies::HandleEnemiesDespawn()
{
	// Iterate existing enemies
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			// Delete the enemy when it has reached the end of the screen
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);

				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}
}

//Spawn the enemies
void ModuleEnemies::SpawnEnemy(const EnemySpawnpoint& info)
{
	// Find an empty slot in the enemies array
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] == nullptr)
		{
			switch (info.type)
			{
				case Enemy_Type::DONKEYKONG:
					enemies[i] = new Enemy_DonkeyKong(info.x, info.y);

					break;
			
				case Enemy_Type::BARREL:
						enemies[i] = new Enemy_Barrel(info.x, info.y, info.direction);
						break;

				//case Enemy_Type::BLUEBARREL:
				//	enemies[i] = new Enemy_BlueBarrel(info.x, info.y);
				//	break;

				//case Enemy_Type::FIRE:
				//	enemies[i] = new Enemy_Fire(info.x, info.y);
				//	break;

				//case Enemy_Type::CEMENT:
				//	enemies[i] = new Enemy_Cement(info.x, info.y);
				//	break;
			}
			enemies[i]->texture = texture;
			enemies[i]->destroyedFx = enemyDestroyedFx;
			break;
		}
	}
}

//Control the collision between the enemies and other colliders
void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			enemies[i]->OnCollision(c1, c2); //Notify the enemy of a collision

			/*delete enemies[i];
			enemies[i] = nullptr;*/
			break;
		}
	}
}