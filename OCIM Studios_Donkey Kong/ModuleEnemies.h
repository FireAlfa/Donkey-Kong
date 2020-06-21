#ifndef __MODULE_ENEMIES_H__
#define __MODULE_ENEMIES_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "Collider.h"

//Ammount of enemies
#define MAX_ENEMIES 40


enum class Enemy_Type
{
	NO_TYPE,

	DONKEYKONG,
	BARREL,
	BLUEBARREL,
	FIRE,
	CEMENT
};

//struct that controls enemy spawn point
struct EnemySpawnpoint
{
	Enemy_Type type = Enemy_Type::NO_TYPE;
	int x, y, direction;
};

class Enemy;
struct SDL_Texture;

//Enemies module class
class ModuleEnemies : public Module
{
public:
	// Constructor
	ModuleEnemies(bool startEnabled);

	// Destructor
	~ModuleEnemies();


	// Called when the module is activated
	// Loads the necessary textures for the enemies
	virtual bool Start();

	// Called at the beginning of the application loop
	// Removes all enemies pending to delete
	Update_Status PreUpdate() override;

	// Called at the middle of the application loop
	// Handles all enemies logic and spawning/despawning
	Update_Status Update() override;

	// Called at the end of the application loop
	// Iterates all the enemies and draws them
	Update_Status PostUpdate() override;

	// Called on application exit
	// Destroys all active enemies left in the array
	virtual bool CleanUp();

public:
	// Called when an enemi collider hits another collider
	// The enemy is destroyed and an explosion particle is fired
	void OnCollision(Collider* c1, Collider* c2) override;

	// Add an enemy into the queue to be spawned later
	bool AddEnemy(Enemy_Type type, int x, int y, int direction);

	// Iterates the queue and checks for camera position
	void HandleEnemiesSpawn();

	// Destroys any enemies that have moved outside the camera limits
	void HandleEnemiesDespawn();

private:
	// Spawns a new enemy using the data from the queue
	void SpawnEnemy(const EnemySpawnpoint& info);

	// A queue with all spawn points information
	EnemySpawnpoint spawnQueue[MAX_ENEMIES];

	// All spawned enemies in the scene
	Enemy* enemies[MAX_ENEMIES] = { nullptr };

	Enemy* DonkeyKong = nullptr;


	// The enemies sprite sheet
	SDL_Texture* texture = nullptr;

	// The audio fx for destroying an enemy
	int enemyDestroyedFx = 0;
};

#endif // __MODULE_ENEMIES_H__