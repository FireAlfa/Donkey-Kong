#include "SceneLevel1Intro.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

SceneLevel1Intro::SceneLevel1Intro(bool startEnabled) : Module(startEnabled)
{
	name = "s_level1intro";

	lvl1Rect = { 0, 0, 224, 256 };
	Barrels = { 0,0, 21,32 };
	dkLeftAnim = { 0, 0,41,32 };
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });
	dkAnim.PushBack({ 0,70,38,32 });

	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
	dkAnim.PushBack({ 39,70,43,32 });
}

SceneLevel1Intro::~SceneLevel1Intro()
{

}

// Load assets
bool SceneLevel1Intro::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Maps/lvl1Cinematic.png");
	lvl1dkAnimation = App->textures->Load("Assets/Sprites/Enemies_Sprites.png");


	//
	//
	//
	//Play start music
	//
	//
	//




	//
	lvl1dkAnimation = App->textures->Load("Assets/Sprites/Enemies_Sprites.png");
	lvl1LeftdkAnimation = App->textures->Load("Assets/Sprites/Enemies_Sprites.png");






	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status SceneLevel1Intro::Update()
{
	//Gamepad support
	GamePad& pad = App->input->pads[0];

	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN || pad.a == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel1, 60);
	}

	if (App->input->keys[SDL_SCANCODE_1] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel1, 10);
	}

	if (App->input->keys[SDL_SCANCODE_2] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel2, 10);
	}

	if (App->input->keys[SDL_SCANCODE_4] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel4, 10);
	}

	if (App->input->keys[SDL_SCANCODE_V] == Key_State::KEY_DOWN || pad.l1 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 10);
	}



	DK.Update();
	fireBarrel.Update();
	dkAnim.Update();
	if (animCont1 <= 165)
	{
		animCont0++;
	}

	if (animCont0 == 4)
	{
		animCont1++;
		animCont0 = 0;
	}



	if (topReached)
	{
		if (contX == 90)
		{
			jumpY--;
		}
		if (contX == 85)
		{
			jumpY++;
		}
		if (contX == 80)
		{
			jumpY--;

		}
		if (contX == 75)
		{
			jumpY++;
		}
		if (contX == 70)
		{
			jumpY--;
		}
		if (contX == 65)
		{
			jumpY++;
		}
		if (contX == 60)
		{
			jumpY--;
		}
		if (contX == 55)
		{
			jumpY++;
		}
		if (contX == 50)
		{
			jumpY--;
		}
		if (contX == 45)
		{
			jumpY++;
		}
	}

	if (topReached)
	{
		contX1++;
		if (contX1 % 10 == 0)
		{
			contX2++;
		}
	}
	if (contX == 40)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel1, 30);
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status SceneLevel1Intro::PostUpdate()
{
	animController0 = 217 - animCont1;
	contX = 90 - contX2;
	if (animController0 == 52)
	{
		topReached = true;
	}
	// Draw everything --------------------------------------

	App->render->Blit(lvl1Texture, 0, 0, &lvl1Rect, NULL, false);
	App->render->Blit(dkBarrels, 21, 52, &(DK.GetCurrentFrame()), 0.1f);
	App->render->Blit(bgTexture, 0, 0, NULL);

	if (topReached == false)
	{
		App->render->Blit(lvl1dkAnimation, 105, animController0, &(dkAnim.GetCurrentFrame()), 0.4f);
	}

	if (topReached && contX >= 40)
	{
		App->render->Blit(lvl1dkAnimation, contX, jumpY, &dkLeftAnim, NULL, false);
	}

	++cont;

	return Update_Status::UPDATE_CONTINUE;
}
bool SceneLevel1Intro::CleanUp()
{



	return true;
}