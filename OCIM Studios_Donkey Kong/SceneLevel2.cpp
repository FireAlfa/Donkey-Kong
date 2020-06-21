#include "SceneLevel2.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"

#include "ModuleEnemies.h"
#include "Enemy_DonkeyKong.h"
#include "ModulePlayer.h"
#include <time.h>


SceneLevel2::SceneLevel2(bool startEnabled) : Module(startEnabled)
{
	name = "level_2";


	//
	//Set position for textures
	//
	lvl2Rect = { 0, 0, 224, 256 };


	//
	//Scene 4 Animation pushbacks
	//
	/*DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 217, 0, 46, 32 });
	DonkeyKong.PushBack({ 170, 0, 46, 32 });
	DonkeyKong.pingpong = true;
	DonkeyKong.loop = true;*/


	leftKnob.PushBack({ 12, 0, 11, 10 });
	leftKnob.PushBack({ 25, 0, 11, 10 });
	leftKnob.PushBack({ 38, 0, 11, 10 });
	leftKnob.speed = 0.1f;

	rightKnob.PushBack({ 12, 11, 11, 10 });
	rightKnob.PushBack({ 25, 11, 11, 10 });
	rightKnob.PushBack({ 38, 11, 11, 10 });
	rightKnob.speed = 0.1f;


	//
	//Scene 4 Animation pushbacks
	//
	//Princess Animation pushbacks
	{
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 16, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 16, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 16, 0, 15, 22 }); //Face right + wiggle 1
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 16, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 16, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 16, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 16, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 16, 0, 15, 22 }); // Face right + wiggle 2
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });
		Princess.PushBack({ 0, 0, 15, 22 });  //Wait before turning left
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 66, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 66, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 66, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 66, 0, 15, 22 }); // Turn left + wiggle 1
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 66, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 66, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 66, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 66, 0, 15, 22 }); //Face left + wiggle 2
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });
		Princess.PushBack({ 82, 0, 15, 22 });// Wait
	}
	Princess.speed = 0.2f;
}

SceneLevel2::~SceneLevel2()
{

}

// Load assets
bool SceneLevel2::Start()
{
	LOG("Loading Level 2 assets--------\n");

	bool ret = true;


	//Enable modules
	App->player->Enable();
	App->enemies->Enable();
	App->collisions->Enable();


	//
	//Flags reset
	//
	lvl2win = false;

	//
	//Initialize Knob direction array for the colliders
	//
	for (int i = 0; i < 4; i++)
	{
		int random = rand() % 2;
		knobDirectionArray[i] = random;
	}

	//Animation for each knob
	knobAnimationArray[0] = &leftKnob;
	knobAnimationArray[1] = &rightKnob;
	knobAnimationArray[2] = &rightKnob;
	knobAnimationArray[3] = &leftKnob;
	knobAnimationArray[4] = &leftKnob;
	knobAnimationArray[5] = &rightKnob;

	for (int i = 0; i < 6; ++i)
	{
		knobAnimationArray[i]->speed = 0.02f;
	}




	//
	//Load the files of each texture & audio
	//
	lvl2Texture = App->textures->Load("Assets/Maps/level2.png");
	movingObjects = App->textures->Load("Assets/GUI/MovingObjects_Level2.png");
	princessTexture = App->textures->Load("Assets/Sprites/Peach_Sprites.png");
	
	
	
	//
	//Place colliders
	//
	{
		//Floor 0 colliders
		App->collisions->AddCollider({ 0, 248, 227, 1 }, Collider::Type::WALL);
		//Floor 1 colliders
		App->collisions->AddCollider({ 8, 208, 16, 1 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 32, 208, 48, 1 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 88, 208, 48, 1 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 144, 208, 48, 1 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 200, 208, 15, 1 }, Collider::Type::WALL);
		//Floor 2 colliders
		App->collisions->AddCollider({ 8, 168, 40, 1 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 72, 168, 72, 1 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 168, 168, 48, 1 }, Collider::Type::WALL);
		//Floor 3 colliders
		App->collisions->AddCollider({ 0, 128, 24, 1 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 32, 128, 48, 1 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 88, 128, 8, 1 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 128, 128, 8, 1 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 144, 128, 48, 1 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 200, 128, 24, 1 }, Collider::Type::WALL);
		//Floor 4 colliders
		App->collisions->AddCollider({ 8, 88, 8, 1 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 24, 88, 176, 1 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 208, 88, 8, 1 }, Collider::Type::WALL);




		//Stairs Set 1
		//App->collisions->AddCollider({ 11, 208, 2, 26 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 27, 223, 2, 10 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 27, 207, 2, 2 }, Collider::Type::TOP_STAIR);
		App->collisions->AddCollider({ 83, 223, 2, 10 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 83, 207, 2, 2 }, Collider::Type::TOP_STAIR);
		App->collisions->AddCollider({ 139, 223, 2, 10 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 139, 207, 2, 2 }, Collider::Type::TOP_STAIR);
		App->collisions->AddCollider({ 195, 223, 2, 10 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 195, 207, 2, 2 }, Collider::Type::TOP_STAIR);
		//Stairs Set 2
		App->collisions->AddCollider({ 67, 183, 2, 10 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 67, 167, 2, 2 }, Collider::Type::TOP_STAIR);
		App->collisions->AddCollider({ 147, 183, 2, 10 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 147, 167, 2, 2 }, Collider::Type::TOP_STAIR);
		//Stairs Set 3
		App->collisions->AddCollider({ 27, 143, 2, 10 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 27, 127, 2, 2 }, Collider::Type::TOP_STAIR);
		App->collisions->AddCollider({ 83, 143, 2, 10 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 83, 127, 2, 2 }, Collider::Type::TOP_STAIR);
		App->collisions->AddCollider({ 139, 143, 2, 10 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 139, 127, 2, 2 }, Collider::Type::TOP_STAIR);
		App->collisions->AddCollider({ 195, 143, 2, 10 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 195, 127, 2, 2 }, Collider::Type::TOP_STAIR);
		//Stairs Set 4
		App->collisions->AddCollider({ 19, 103, 2, 10 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 19, 87, 2, 2 }, Collider::Type::TOP_STAIR);
		App->collisions->AddCollider({ 203, 103, 2, 10 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 203, 87, 2, 2 }, Collider::Type::TOP_STAIR);
		//Stairs Set 5
		App->collisions->AddCollider({ 131, 71, 2, 2 }, Collider::Type::STAIR);
		App->collisions->AddCollider({ 131, 55, 2, 2 }, Collider::Type::TOP_STAIR);




		//Gravity Walls 1
		App->collisions->AddCollider({ 0, 207, 5, 5 }, Collider::Type::GRAVITYWALLS);
		App->collisions->AddCollider({ 219, 207, 5, 5 }, Collider::Type::GRAVITYWALLS);
		//Gravity Walls 2
		App->collisions->AddCollider({ 0, 167, 5, 5 }, Collider::Type::GRAVITYWALLS);
		App->collisions->AddCollider({ 51, 167, 10, 5 }, Collider::Type::GRAVITYWALLS);
		App->collisions->AddCollider({ 155, 167, 10, 5 }, Collider::Type::GRAVITYWALLS);
		App->collisions->AddCollider({ 219, 167, 5, 5 }, Collider::Type::GRAVITYWALLS);
		//Gravity Walls 3
		App->collisions->AddCollider({ 101, 113, 23, 18 }, Collider::Type::GRAVITYWALLS);
		//Gravity Walls 4
		App->collisions->AddCollider({ 0, 87, 5, 5 }, Collider::Type::GRAVITYWALLS);
		App->collisions->AddCollider({ 219, 87, 5, 5 }, Collider::Type::GRAVITYWALLS);



		//
		//Limits
		//
		//Top Wall
		App->collisions->AddCollider({ 0, 0, 254, 1 }, Collider::Type::TOPWALL);
		//Left Wall
		App->collisions->AddCollider({ 0, 0, 1, 256 }, Collider::Type::LEFTWALL);
		//RightWall
		App->collisions->AddCollider({ 223, 0, 1, 256 }, Collider::Type::RIGHTWALL);


		for (int i = 0; i < 4; ++i)
		{
			//
			if (knobDirectionArray[0] == 1)
			{
				conveyerColliders[0] = App->collisions->AddCollider({ 8, 207, 208, 1 }, Collider::Type::CONVEYER_RIGHT);
			}
			else if (knobDirectionArray[0] == 1)
			{
				conveyerColliders[0] = App->collisions->AddCollider({ 8, 207, 208, 1 }, Collider::Type::CONVEYER_LEFT);
			}
			//
			if (knobDirectionArray[1] == 1)
			{
				conveyerColliders[1] = App->collisions->AddCollider({ 0, 127, 102, 1 }, Collider::Type::CONVEYER_RIGHT);
			}
			else if (knobDirectionArray[1] == 1)
			{
				conveyerColliders[1] = App->collisions->AddCollider({ 0, 127, 102, 1 }, Collider::Type::CONVEYER_LEFT);
			}
			//
			if (knobDirectionArray[2] == 1)
			{
				conveyerColliders[2] = App->collisions->AddCollider({ 122, 127, 102, 1 }, Collider::Type::CONVEYER_RIGHT);
			}
			else if (knobDirectionArray[2] == 1)
			{
				conveyerColliders[2] = App->collisions->AddCollider({ 122, 127, 102, 1 }, Collider::Type::CONVEYER_LEFT);
			}
			//
			if (knobDirectionArray[3] == 1)
			{
				conveyerColliders[3] = App->collisions->AddCollider({ 8, 87, 208, 1 }, Collider::Type::CONVEYER_RIGHT);
			}
			else if (knobDirectionArray[3] == 1)
			{
				conveyerColliders[3] = App->collisions->AddCollider({ 8, 87, 208, 1 }, Collider::Type::CONVEYER_LEFT);
			}
		}

	}



	//
	//Add enemies
	//
	App->enemies->AddEnemy(Enemy_Type::DONKEYKONG, 23, 56, 0);




	return ret;
}

//Draw the animations
Update_Status SceneLevel2::Update()
{
	//Gamepad support
	GamePad& pad = App->input->pads[0];


	//
	//Update animations
	//
	Princess.Update();

	//
	//Change Knob conveyer direction array
	//
	for (int i = 0; i < 4; i++)
	{
		int random = rand() % 10;
		if (random <= 2)
		{
			if (knobDirectionArray[i] == 0) {
				knobDirectionArray[i] = 1;
			}
			else
			{
				knobDirectionArray[i] = 0;
			}
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		//
		if (knobDirectionArray[0] == 1)
		{
			App->collisions->RemoveCollider(conveyerColliders[0]);
			conveyerColliders[0] = App->collisions->AddCollider({ 8, 207, 208, 1 }, Collider::Type::CONVEYER_RIGHT);
		}
		else if (knobDirectionArray[0] == 1)
		{
			App->collisions->RemoveCollider(conveyerColliders[0]);
			conveyerColliders[0] = App->collisions->AddCollider({ 8, 207, 208, 1 }, Collider::Type::CONVEYER_LEFT);
		}
		//
		if (knobDirectionArray[1] == 1)
		{
			App->collisions->RemoveCollider(conveyerColliders[1]);
			conveyerColliders[1] = App->collisions->AddCollider({ 0, 127, 102, 1 }, Collider::Type::CONVEYER_RIGHT);
		}
		else if (knobDirectionArray[1] == 1)
		{
			App->collisions->RemoveCollider(conveyerColliders[1]);
			conveyerColliders[1] = App->collisions->AddCollider({ 0, 127, 102, 1 }, Collider::Type::CONVEYER_LEFT);
		}
		//
		if (knobDirectionArray[2] == 1)
		{
			App->collisions->RemoveCollider(conveyerColliders[2]);
			conveyerColliders[2] = App->collisions->AddCollider({ 122, 127, 102, 1 }, Collider::Type::CONVEYER_RIGHT);
		}
		else if (knobDirectionArray[2] == 1)
		{
			App->collisions->RemoveCollider(conveyerColliders[2]);
			conveyerColliders[2] = App->collisions->AddCollider({ 122, 127, 102, 1 }, Collider::Type::CONVEYER_LEFT);
		}
		//
		if (knobDirectionArray[3] == 1)
		{
			App->collisions->RemoveCollider(conveyerColliders[3]);
			conveyerColliders[3] = App->collisions->AddCollider({ 8, 87, 208, 1 }, Collider::Type::CONVEYER_RIGHT);
		}
		else if (knobDirectionArray[3] == 1)
		{
			App->collisions->RemoveCollider(conveyerColliders[3]);
			conveyerColliders[3] = App->collisions->AddCollider({ 8, 87, 208, 1 }, Collider::Type::CONVEYER_LEFT);
		}
	}

	
	//Knobs animation array
	for (int i = 0; i < 6; ++i)
	{
		knobAnimationArray[i]->Update();
	}


	//
	//Change Level
	//
	if (App->input->keys[SDL_SCANCODE_0] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 10);
	}

	if (App->input->keys[SDL_SCANCODE_1] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel1, 10);
	}

	if (App->input->keys[SDL_SCANCODE_4] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel4, 10);
	}
	if (App->input->keys[SDL_SCANCODE_R] == Key_State::KEY_DOWN || pad.start == true)
	{
		CleanUp();
		App->fade->FadeToBlack(this, this, 10);
	}
	if (App->input->keys[SDL_SCANCODE_V] == Key_State::KEY_DOWN || pad.l2 == true)
	{
		lvl2win = true;
	}


	//Win condition
	if (App->player->position.y <= 41)
	{
		lvl2win = true;
	}
	if (lvl2win == true)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel4, 60);
	}

	return Update_Status::UPDATE_CONTINUE;
}


// Update: draw background
Update_Status SceneLevel2::PostUpdate()
{
	// Draw everything --------------------------------------

	//
	//Draw the background
	//
	App->render->Blit(lvl2Texture, 0, 0, &lvl2Rect, NULL, false);

	
	//
	//Draw Princess animation
	//
	App->render->Blit(princessTexture, 105, 34, &(Princess.GetCurrentFrame()), 0.1f);


	//
	//Draw knobs animation
	//
	App->render->Blit(movingObjects, 2, 207, &(knobAnimationArray[0]->GetCurrentFrame()), NULL);
	App->render->Blit(movingObjects, 211, 207, &(knobAnimationArray[1]->GetCurrentFrame()), NULL);
	App->render->Blit(movingObjects, 94, 127, &(knobAnimationArray[2]->GetCurrentFrame()), NULL);
	App->render->Blit(movingObjects, 119, 127, &(knobAnimationArray[3]->GetCurrentFrame()), NULL);
	App->render->Blit(movingObjects, 2, 87, &(knobAnimationArray[4]->GetCurrentFrame()), NULL);
	App->render->Blit(movingObjects, 211, 87, &(knobAnimationArray[5]->GetCurrentFrame()), NULL);


	return Update_Status::UPDATE_CONTINUE;
}

//Disable modules related to the Scene
bool SceneLevel2::CleanUp()
{
	for (int i = 0; i < 4; ++i)
	{
		App->collisions->RemoveCollider(conveyerColliders[i]);
	}




	//Disable modules
	App->player->Disable();
	App->enemies->Disable();
	App->collisions->Disable();

	return true;
}