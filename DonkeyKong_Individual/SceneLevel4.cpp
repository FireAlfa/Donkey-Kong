#include "SceneLevel4.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

#include "ModuleEnemies.h"
#include "Enemy_DonkeyKong.h"
#include "ModulePlayer.h"


SceneLevel4::SceneLevel4(bool startEnabled) : Module(startEnabled)
{
	name = "level_4";

	
	//
	//Set position for textures
	//
	lvl4Rect = { 0, 0, 224, 256 };
	buttonRect = { 0, 0, 8, 9 };


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

SceneLevel4::~SceneLevel4()
{

}

// Load assets
bool SceneLevel4::Start()
{
	LOG("Loading Level 4 assets--------\n");

	bool ret = true;


	//Enable modules
	App->player->Enable();
	App->enemies->Enable();
	App->collisions->Enable();


	//
	//Flags reset
	//
	for (int i = 0; i < 8; ++i)
	{
		buttonDrawingArray[i] = true;
	}
	totalButtons = 8;
	lvl4win = false;
	spawnGravityWall = false;
	spawnGravityWallCountdown = BUTTON_REPLACE_COUNTDOWN;



	//
	//Load the files of each texture & audio
	//
	lvl4Texture = App->textures->Load("Assets/Maps/level4.png");
	buttonTexture = App->textures->Load("Assets/GUI/Button.png");

	princessTexture = App->textures->Load("Assets/Sprites/Peach_Sprites.png");



	//
	//Place colliders
	//
	//Floor 0 colliders
	App->collisions->AddCollider({ 0, 248, 227, 4 }, Collider::Type::WALL);

	//Floor 1 colliders
	App->collisions->AddCollider({ 16, 208, 40, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 64, 208, 39, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 112, 208, 47, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 168, 208, 39, 4 }, Collider::Type::WALL);

	//Floor 2 colliders
	App->collisions->AddCollider({ 24, 168, 32, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 64, 168, 7, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 80, 168, 63, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 152, 168, 7, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 168, 168, 31, 4 }, Collider::Type::WALL);

	//Floor 3 colliders
	App->collisions->AddCollider({ 32, 128, 24, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 64, 128, 39, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 112, 128, 47, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 168, 128, 24, 4 }, Collider::Type::WALL);

	//Floor 4 colliders
	App->collisions->AddCollider({ 40, 88, 16, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 72, 88, 80, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 168, 88, 16, 4 }, Collider::Type::WALL);



	//Stairs Set 1
	//App->collisions->AddCollider({ 11, 208, 2, 26 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 11, 223, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 11, 207, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 107, 223, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 107, 207, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 211, 223, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 211, 207, 2, 2 }, Collider::Type::TOP_STAIR);

	//Stairs Set 2
	App->collisions->AddCollider({ 19, 183, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 19, 167, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 75, 183, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 75, 167, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 147, 183, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 147, 167, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 203, 183, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 203, 167, 2, 2 }, Collider::Type::TOP_STAIR);

	//Stairs Set 3
	App->collisions->AddCollider({ 27, 143, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 27, 127, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 107, 143, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 107, 127, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 195, 143, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 195, 127, 2, 2 }, Collider::Type::TOP_STAIR);

	//Stairs Set 4
	App->collisions->AddCollider({ 35, 103, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 35, 87, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 67, 103, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 67, 87, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 155, 103, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 155, 87, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 187, 103, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 187, 87, 2, 2 }, Collider::Type::TOP_STAIR);
	



	//Buttons Floor 1
	buttonColliders[0] = App->collisions->AddCollider({ 58, 193, 4, 14 }, Collider::Type::BUTTON);
	buttonColliders[1] = App->collisions->AddCollider({ 162, 193, 4, 14 }, Collider::Type::BUTTON);

	//Buttons Floor 2
	buttonColliders[2] = App->collisions->AddCollider({ 58, 153, 4, 14 }, Collider::Type::BUTTON);
	buttonColliders[3] = App->collisions->AddCollider({ 162, 153, 4, 14 }, Collider::Type::BUTTON);

	//Buttons Floor 3
	buttonColliders[4] = App->collisions->AddCollider({ 58, 113, 4, 14 }, Collider::Type::BUTTON);
	buttonColliders[5] = App->collisions->AddCollider({ 162, 113, 4, 14 }, Collider::Type::BUTTON);

	//Buttons Floor 4
	buttonColliders[6] = App->collisions->AddCollider({ 58, 73, 4, 14 }, Collider::Type::BUTTON);
	buttonColliders[7] = App->collisions->AddCollider({ 162, 73, 4, 14 }, Collider::Type::BUTTON);



	//Gravity Walls 1
	App->collisions->AddCollider({ 0, 168, 5, 40 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 218, 168, 5, 40 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 2
	App->collisions->AddCollider({ 0, 128, 13, 40 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 210, 128, 13, 40 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 3
	App->collisions->AddCollider({ 0, 88, 21, 40 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 203, 88, 21, 40 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 4
	App->collisions->AddCollider({ 0, 48, 29, 40 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 195, 48, 29, 40 }, Collider::Type::GRAVITYWALLS);




	//Top Wall
	App->collisions->AddCollider({ 0, 0, 254, 1 }, Collider::Type::TOPWALL);
	//Left Wall
	App->collisions->AddCollider({ 0, 208, 1, 48 }, Collider::Type::LEFTWALL);
	//RightWall
	App->collisions->AddCollider({ 223, 208, 1, 48 }, Collider::Type::RIGHTWALL);

	


	//
	//Add enemies
	//
	App->enemies->AddEnemy(Enemy_Type::DONKEYKONG, 92, 56, 0);




	

	return ret;
}

//Draw the animations
Update_Status SceneLevel4::Update()
{
	//Gamepad support
	GamePad& pad = App->input->pads[0];

	//
	//Update animations
	//
	Princess.Update();

	//
	//Change Level
	//
	//Intro screen
	if (App->input->keys[SDL_SCANCODE_0] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 10);
	}
	//Level 1 screen
	if (App->input->keys[SDL_SCANCODE_1] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel1, 10);
	}
	//Level 2 screen
	if (App->input->keys[SDL_SCANCODE_2] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel2, 10);
	}
	//Reload Level 4
	if (App->input->keys[SDL_SCANCODE_R] == Key_State::KEY_DOWN || pad.start == true)
	{
		CleanUp();
		App->fade->FadeToBlack(this, this, 10);
	}

	//Instant win
	if (App->input->keys[SDL_SCANCODE_V] == Key_State::KEY_DOWN || pad.l2 == true)
	{
		lvl4win = true;
	}


	//Gravity wall under button
	if (spawnGravityWall == true)
	{
		--spawnGravityWallCountdown;
		if (spawnGravityWallCountdown == 0)
		{
			App->collisions->AddCollider(aux, Collider::Type::GRAVITYWALLS);
			spawnGravityWall = false;
			spawnGravityWallCountdown = BUTTON_REPLACE_COUNTDOWN;
		}
	}



	//
	//Win condition
	//
	if (lvl4win == true)
	{
		App->player->lifes = 3;
		for (int i = 0; i < 3; ++i)
		{
			App->player->lifesDrawingArray[i] = true;
		}
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneVictory, 0);
	}

	return Update_Status::UPDATE_CONTINUE;
}


// Update: draw background
Update_Status SceneLevel4::PostUpdate()
{
	// Draw everything --------------------------------------

	//
	//Draw the background
	//
	App->render->Blit(lvl4Texture, 0, 0, &lvl4Rect, NULL, false);


	//
	//Draw Princess animation
	//
	App->render->Blit(princessTexture, 105, 26, &(Princess.GetCurrentFrame()), 0.1f);


	//
	//Draw the buttons
	//
	for (int i = 0; i < 8; ++i)
	{
		if (buttonDrawingArray[0] == true)
		{
			App->render->Blit(buttonTexture, 56, 207, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[1] == true)
		{
			App->render->Blit(buttonTexture, 160, 207, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[2] == true)
		{
			App->render->Blit(buttonTexture, 56, 167, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[3] == true)
		{
			App->render->Blit(buttonTexture, 160, 167, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[4] == true)
		{
			App->render->Blit(buttonTexture, 56, 127, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[5] == true)
		{
			App->render->Blit(buttonTexture, 160, 127, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[6] == true)
		{
			App->render->Blit(buttonTexture, 56, 87, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[7] == true)
		{
			App->render->Blit(buttonTexture, 160, 87, &buttonRect, NULL, false);
		}
	}


	return Update_Status::UPDATE_CONTINUE;
}

//Disable modules related to the Scene
bool SceneLevel4::CleanUp()
{
	//Disable modules
	App->player->Disable();
	App->enemies->Disable();
	App->collisions->Disable();
	
	return true;
}


//Erase button
void SceneLevel4::eraseButton(Collider* c)
{
	int index = -1;

	aux = c->GetRect();
	aux.y += 14;
	aux.h -= 13;
	spawnGravityWall = true;

	for (int i = 0; i < 8; ++i)
	{
		if (buttonColliders[i] == c)
		{
			index = i;
			break;
		}
	}

	if (index != -1)
	{
		App->collisions->RemoveCollider(buttonColliders[index]);
		buttonDrawingArray[index] = false;
		--totalButtons;
	}

	


	if (totalButtons == 0)
	{
		lvl4win = true;
	}
}