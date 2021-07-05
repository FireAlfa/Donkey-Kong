#include "SceneIntro.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

SceneIntro::SceneIntro(bool startEnabled) : Module(startEnabled)
{
	name = "s_intro";

	spaceToStartRect = { 43, 146, 142, 52 };
}

SceneIntro::~SceneIntro()
{

}

// Load assets
bool SceneIntro::Start()
{
	LOG("Loading SceneIntro assets ---------\n");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Maps/startScreen_text.png");
	spaceToStartTexture = App->textures->Load("Assets/GUI/SpaceToStart.png");
	
	//
	//
	//
	//Play start music
	//
	//
	//

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status SceneIntro::Update()
{
	//Gamepad support
	GamePad& pad = App->input->pads[0];

	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN || pad.a == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel1Intro, 10);
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
	if (App->input->keys[SDL_SCANCODE_I] == Key_State::KEY_DOWN || pad.l1 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel1Intro, 10);
	}
	if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_DOWN || pad.l1 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneVictory, 10);
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status SceneIntro::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	++cont;

	if (cont >= SPACE_BLINK) {
		App->render->Blit(spaceToStartTexture, 43, 146, NULL);

		if (cont == (2*SPACE_BLINK)) {
			cont = 0;
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}