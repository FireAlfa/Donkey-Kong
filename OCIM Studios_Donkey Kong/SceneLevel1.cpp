#include "SceneLevel1.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"


SceneLevel1::SceneLevel1(bool startEnabled) : Module(startEnabled)
{
	name = "level_1";


	//
	//Set position for textures
	//
	lvl1Rect = { 0, 0, 224, 256 };
	Barrels = { 0,0, 21,32 };
	dkLeftAnim = { 0, 0,41,32 };
	hammerRect = { 157,0,9,10 };


	//
	//Scene 1 Animation pushbacks
	//
	{
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });
		fireBarrel.PushBack({ 84,67,16,31 });




		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });
		fireBarrel.PushBack({ 103,67,16,31 });





		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });
		fireBarrel.PushBack({ 122,67,16,31 });


		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });
		fireBarrel.PushBack({ 141,67,16,31 });




		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });
		DK.PushBack({ 0,0,40,32 });



		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });
		DK.PushBack({ 41,0,43,32 });

		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });
		DK.PushBack({ 85,0,40,32 });


		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
		DK.PushBack({ 126,0,43,32 });
	}

	
}

SceneLevel1::~SceneLevel1()
{

}

// Load assets
bool SceneLevel1::Start()
{
	LOG("Loading Level 1 assets--------\n");

	bool ret = true;



	//Enable modules
	App->player->Enable();
	App->enemies->Enable();
	App->collisions->Enable();


	//
	//Flags reset
	//
	for (int i = 0; i < 2; ++i)
	{
		hammerDrawingArray[i] = true;
	}

	lvl1win = false;


	//
	//Load the files of each texture & audio
	//
	lvl1Texture = App->textures->Load("Assets/Maps/level1.png");
	dkBarrels = App->textures->Load("Assets/Sprites/DonkeyKong_Sprites.png");
	lvl1Barrels = App->textures->Load("Assets/Sprites/Barrells_Sprites.png");
	lvl1fireBarrels = App->textures->Load("Assets/Sprites/Enemies_Sprites.png");
	lvl1LeftdkAnimation = App->textures->Load("Assets/Sprites/Enemies_Sprites.png");
	hammerTexture = App->textures->Load("Assets/Sprites/Mario_Sprites.png");

	{
	// ===================== WALLS ==================== //


		//
		//Walls with ramps
		//

		//Floor 1 colliders
	App->collisions->AddCollider({ 0, 248, 112, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 111, 246, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 114, 247, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 127, 245, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 130, 246, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 143, 244, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 146, 245, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 159, 243, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 162, 244, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 175, 242, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 178, 243, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 191, 241, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 194, 242, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 207, 240, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 210, 241, 14, 1 }, Collider::Type::WALL);

	//Floor 2 colliders
	App->collisions->AddCollider({ 0, 208, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 16, 207, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 16, 209, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 32, 208, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 32, 210, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 48, 209, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 48, 211, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 64, 210, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 64, 212, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 80, 211, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 80, 213, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 96, 212, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 96, 214, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 112, 213, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 112, 215, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 128, 214, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 128, 216, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 144, 215, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 144, 217, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 160, 216, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 160, 218, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 176, 217, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 176, 219, 8, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 192, 218, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 192, 220, 16, 1 }, Collider::Type::WALL);

	//Floor 3 colliders
	App->collisions->AddCollider({ 16, 187, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 31, 185, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 40, 186, 8, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 47, 184, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 50, 185, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 63, 183, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 66, 184, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 79, 182, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 82, 183, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 95, 181, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 104, 182, 8, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 111, 180, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 114, 181, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 127, 179, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 130, 180, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 143, 178, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 146, 179, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 159, 177, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 162, 178, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 175, 176, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 178, 177, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 191, 175, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 194, 176, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 207, 174, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 210, 175, 14, 1 }, Collider::Type::WALL);

	//Floor 4 colliders
	App->collisions->AddCollider({ 0, 142, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 16, 141, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 16, 143, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 32, 142, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 32, 144, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 48, 143, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 48, 145, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 64, 144, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 64, 146, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 80, 145, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 80, 147, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 96, 146, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 96, 148, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 112, 147, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 120, 149, 6, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 128, 148, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 128, 150, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 144, 149, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 144, 151, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 160, 150, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 160, 152, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 176, 151, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 176, 153, 8, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 192, 152, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 192, 154, 16, 1 }, Collider::Type::WALL);

	//Floor 5 colliders
	App->collisions->AddCollider({ 16, 121, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 31, 119, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 40, 120, 8, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 47, 118, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 50, 119, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 63, 117, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 66, 118, 6, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 79, 116, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 82, 117, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 95, 115, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 98, 116, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 111, 114, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 114, 115, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 127, 113, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 130, 114, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 143, 112, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 146, 113, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 159, 111, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 162, 112, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 175, 110, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 178, 111, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 191, 109, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 194, 110, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 207, 108, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 210, 109, 14, 1 }, Collider::Type::WALL);

	//Floor 6 colliders
	App->collisions->AddCollider({ 0, 84, 142, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 144, 83, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 144, 85, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 160, 84, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 160, 86, 14, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 176, 85, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 176, 87, 8, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 192, 86, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 192, 88, 16, 1 }, Collider::Type::WALL);

	//Floor 7 colliders
	App->collisions->AddCollider({ 88, 56, 40, 1 }, Collider::Type::WALL);





	// ================== STAIR ================= //

	// Stairs set 1
	App->collisions->AddCollider({ 187, 228, 2, 1 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 187, 218, 2, 2 }, Collider::Type::TOP_STAIR);

	// Stairs set 2
	App->collisions->AddCollider({ 35, 194, 2, 1 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 35, 185, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 99, 198, 2, 2 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 99, 181, 2, 2 }, Collider::Type::TOP_STAIR);
	// Stairs set 3

	App->collisions->AddCollider({ 115, 165, 2, 1 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 187, 152, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 187, 161, 2, 1 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 115, 148, 2, 2 }, Collider::Type::TOP_STAIR);

	// Stairs set 4
	App->collisions->AddCollider({ 75, 131, 2, 1 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 35, 119, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 35, 129, 2, 1 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 75, 117, 2, 2 }, Collider::Type::TOP_STAIR);

	// Stairs set 5
	App->collisions->AddCollider({ 187, 95, 2, 1 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 187, 86, 2, 2 }, Collider::Type::TOP_STAIR);

	// Stairs set 6
	App->collisions->AddCollider({ 131, 68, 2, 1 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 131, 55, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 67, 32, 2, 37 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 83, 32, 2, 37 }, Collider::Type::STAIR);




	// ===================== GRAVITY WALLS ==================== //

	//Gravity Walls 1
	App->collisions->AddCollider({ 209, 190, 7, 20 }, Collider::Type::GRAVITYWALLS);
	//Gravity Walls 2
	App->collisions->AddCollider({ 8, 157, 7, 20 }, Collider::Type::GRAVITYWALLS);
	//Gravity Walls 3
	App->collisions->AddCollider({ 209, 124, 7, 20 }, Collider::Type::GRAVITYWALLS);
	//Gravity Walls 4
	App->collisions->AddCollider({ 8, 92, 7, 20 }, Collider::Type::GRAVITYWALLS);
	//Gravity Walls 5
	App->collisions->AddCollider({ 209, 58, 7, 20 }, Collider::Type::GRAVITYWALLS);
	//Gravity Walls 6
	App->collisions->AddCollider({ 138, 26, 1, 20 }, Collider::Type::GRAVITYWALLS);



	// ================== Border Walls ================ //

	//TOP WALL
	App->collisions->AddCollider({ 0, 0, 224, 5 }, Collider::Type::TOPWALL);
	//LEFT WALL
	App->collisions->AddCollider({ 0, 0, 1, 256 }, Collider::Type::LEFTWALL);
	//RIGHT WALL
	App->collisions->AddCollider({ 223, 1, 1, 255 }, Collider::Type::RIGHTWALL);

	//Hammer
	hammerColliders[0] = App->collisions->AddCollider({ 167, 192, 8, 8 }, Collider::Type::HAMMER);
	hammerColliders[1] = App->collisions->AddCollider({ 20, 97, 8, 8 }, Collider::Type::HAMMER);




	//Test
	App->collisions->AddCollider({ 211, 86, 13, 5 }, Collider::Type::PLAYER_FEET);
	App->collisions->AddCollider({ 211, 152, 13, 5 }, Collider::Type::PLAYER_FEET);
	App->collisions->AddCollider({ 0, 119, 13, 5 }, Collider::Type::PLAYER_FEET);
	App->collisions->AddCollider({ 0, 185, 13, 5 }, Collider::Type::PLAYER_FEET);
	}




	//
	//Add enemies
	//
	App->enemies->AddEnemy(Enemy_Type::BARREL, 62, 75, 1);

	

	return ret;
}

//Draw the animations
Update_Status SceneLevel1::Update()
{
	//Gamepad support
	GamePad& pad = App->input->pads[0];

	//
	//Update animations
	//
	DK.Update();
	fireBarrel.Update();

	//
	//Enemies
	//
	








	//
	//Change Level
	//
	//Intro screen
	if (App->input->keys[SDL_SCANCODE_0] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 10);
	}
	//Level 2 screen
	if (App->input->keys[SDL_SCANCODE_2] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel2, 10);
	}
	//Level 4 screen
	if (App->input->keys[SDL_SCANCODE_4] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel4, 10);
	}
	//Reload Level 1 screen
	if (App->input->keys[SDL_SCANCODE_R] == Key_State::KEY_DOWN || pad.start == true)
	{
		CleanUp();
		App->fade->FadeToBlack(this, this, 10);
	}

	//Instant win
	if (App->input->keys[SDL_SCANCODE_V] == Key_State::KEY_DOWN || pad.l1 == true)
	{
		lvl1win = true;
	}







	//
	//Win condition
	//
	if (App->player->position.y <= 41)
	{
		lvl1win = true;
	}

	if (lvl1win == true)
	{

		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel2, 60);
	}


	return Update_Status::UPDATE_CONTINUE;
}


// Update: draw background
Update_Status SceneLevel1::PostUpdate()
{
	// Draw everything --------------------------------------

	//
	//Draw the background
	//
	//App->render->Blit(lvl1Barrels, 2, 55, &lvl1B, NULL, false);

	App->render->Blit(lvl1Texture, 0, 0, &lvl1Rect, NULL, false);
	App->render->Blit(dkBarrels, 21, 52, &(DK.GetCurrentFrame()), 0.1f);
	App->render->Blit(lvl1Barrels, 1, 51, &Barrels,NULL,false);
	App->render->Blit(lvl1fireBarrels, 10, 217, &(fireBarrel.GetCurrentFrame()), 0.1f);

	for (int i = 0; i < 2; ++i)
	{
		if (hammerDrawingArray[0] == true)
		{
			App->render->Blit(hammerTexture, 167, 190, &hammerRect, NULL, false);
		}
		if (hammerDrawingArray[1] == true)
		{
			App->render->Blit(hammerTexture, 20, 95, &hammerRect, NULL, false);
		}
	}


	return Update_Status::UPDATE_CONTINUE;
}

//Disable modules related to the Scene
bool SceneLevel1::CleanUp()
{

	//Disable modules
	App->player->Disable();
	App->enemies->Disable();
	App->collisions->Disable();


	return true;
}

void SceneLevel1::eraseHammer(Collider* c)
{
	int index = -1;
	for (int i = 0; i < 2; ++i)
	{
		if (hammerColliders[i] == c)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		App->collisions->RemoveCollider(hammerColliders[index]);
		hammerDrawingArray[index] = false;
	}
}