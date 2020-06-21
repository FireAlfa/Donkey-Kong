#include "ModulePlayer.h"

#include "Application.h"

#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"

#include "SceneLevel1.h"
#include "SceneLevel2.h"
#include "SceneLevel4.h"

#include "ModuleRender.h"


#include "SDL/include/SDL_scancode.h"
#include <stdio.h>



ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	name = "player";



	//
	//Animation pushbacks
	//
	//IdleAnims
	idleAnim_Left.PushBack({ 51, 17, 12, 16 });
	idleAnim_Right.PushBack({ 68, 17, 12, 16 });



	//Running Anims
	//   Left
	runningAnim_Left.PushBack({ 0, 0, 15, 16 });
	runningAnim_Left.PushBack({ 24, 0, 15, 16 });
	//	Right
	runningAnim_Right.PushBack({ 68, 0, 15, 16});
	runningAnim_Right.PushBack({ 44, 0, 15, 16});

	runningAnim_Left.speed = runningAnim_Right.speed = 0.1f;



	//	Jumping Left
	jumpAnim_Left.PushBack({ 34, 17, 15, 16 });
	jumpAnim_Left.PushBack({ 17, 17, 16, 15 });
	//	Jumping Right
	jumpAnim_Right.PushBack({ 85, 17, 15, 16 });
	jumpAnim_Right.PushBack({ 102, 17, 16, 15 });

	jumpAnim_Left.speed = jumpAnim_Right.speed = 0.1f;
	jumpAnim_Left.loop = jumpAnim_Right.loop = false;



	//Climb
	climb.PushBack({ 51, 34, 13, 16 });
	climb.PushBack({ 68, 34, 13, 16 });
	climb.speed = 0.14f;

	//ClimbUp
	climb_Up.PushBack({ 85, 34, 14, 15 }); 
	climb_Up.PushBack({ 102, 34, 16, 12 });
	climb_Up.PushBack({ 119, 34, 16, 15 });
	climb_Up.speed = 0.1f;

	//ClimbDown
	climb_Down.PushBack({ 0, 34, 16, 15 });
	climb_Down.PushBack({ 17, 34, 16, 12 });
	climb_Down.PushBack({ 34, 34, 14, 15 });
	climb_Down.speed = 0.1f;



	//	Hammer Idle
	//		Left
	hammerIdleAnim_Left.PushBack({ 142, 0, 25, 26 });
	hammerIdleAnim_Left.PushBack({ 116, 68, 25, 26 });

	//		Right
	hammerIdleAnim_Right.PushBack({ 142, 34, 25, 26 });
	hammerIdleAnim_Right.PushBack({ 142, 68, 25, 26 });

	hammerIdleAnim_Left.speed = hammerIdleAnim_Right.speed = 0.1f;


	//	HammerRunning
	//		Left
	hammerRunAnim_Left.PushBack({ 0, 68, 29, 26 });
	hammerRunAnim_Left.PushBack({ 29, 68, 29, 26 });
	hammerRunAnim_Left.PushBack({ 58, 68, 29, 26 });     
	hammerRunAnim_Left.PushBack({ 87, 68, 29, 26 });

	//		Right
	hammerRunAnim_Right.PushBack({ 87, 94, 29, 26 });
	hammerRunAnim_Right.PushBack({ 58, 94, 29, 26 });
	hammerRunAnim_Right.PushBack({ 29, 94, 29, 26 });
	hammerRunAnim_Right.PushBack({ 0, 94, 29, 26 });
	hammerRunAnim_Left.speed = hammerRunAnim_Right.speed = 0.1f;



	//Dying
	dyingAnim.PushBack({ 85, 51, 16, 16 });
	dyingAnim.PushBack({ 102, 51, 16, 16 });
	dyingAnim.PushBack({ 118, 51, 16, 16 });
	dyingAnim.PushBack({ 68, 51, 16, 16 });
	dyingAnim.PushBack({ 85, 51, 16, 16 });
	dyingAnim.PushBack({ 102, 51, 16, 16 });
	dyingAnim.PushBack({ 118, 51, 16, 16 });
	dyingAnim.PushBack({ 68, 51, 16, 16 });
	dyingAnim.PushBack({ 85, 51, 16, 16 });
	dyingAnim.PushBack({ 102, 51, 16, 16 });
	dyingAnim.PushBack({ 118, 51, 16, 16 });
	dyingAnim.PushBack({ 68, 51, 16, 16 });
	dyingAnim.PushBack({ 85, 51, 16, 16 });
	dyingAnim.PushBack({ 0, 17, 16, 16 }); //Angel
	dyingAnim.PushBack({ 0, 17, 16, 16 }); //Angel
	dyingAnim.PushBack({ 0, 17, 16, 16 }); //Angel
	dyingAnim.PushBack({ 0, 17, 16, 16 }); //Angel
	dyingAnim.speed = 0.1f;

	deadMario.PushBack({ 0, 17, 16, 16 });
}

ModulePlayer::~ModulePlayer()
{

}

//Load the player textures
bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	//
	//Know what level the player is in & Set initial position
	//
	if ((Module*)App->sceneLevel1->IsEnabled())
	{
		currentLevel = "level 1";
		position.x = 34.0f;
		position.y = 232.0f;
		char lookupTableB[] = { "0123456789" };
		bonusFont = App->fonts->Load("Assets/Fonts/fontBlue.png", lookupTableB, 1);
	}

	if ((Module*)App->sceneLevel2->IsEnabled())
	{
		currentLevel = "level 2";
		position.x = 41.0f;
		position.y = 232.0f;
		char lookupTableB[] = { "0123456789" };
		bonusFont = App->fonts->Load("Assets/Fonts/fontWhite.png", lookupTableB, 1);
	}

	if ((Module*)App->sceneLevel4->IsEnabled())
	{
		currentLevel = "level 4";
		position.x = 45.0f;
		position.y = 232.0f;
		//Bonus
		char lookupTableB[] = { "0123456789" };
		bonusFont = App->fonts->Load("Assets/Fonts/fontYellow.png", lookupTableB, 1);
	}



	//
	//Load Player textures files & set currentAnimation
	//
	playerTexture = App->textures->Load("Assets/Sprites/Mario_Sprites.png");
	lifesTexture = App->textures->Load("Assets/GUI/Scores + Mario.png");
	gameOverTexture = App->textures->Load("Assets/GUI/GameOver.png");
	currentAnimation = &idleAnim_Right;


	//
	//Load Player FX files
	//
	jumpFx = App->audio->LoadFx("Assets/Audio/Fx/jump.ogg");
	hammerFx = App->audio->LoadFx("Assets/Audio/Fx/Hammer.ogg");

	//
	//Create Player collider
	//
	float x, y;
	x = position.x;
	y = position.y;
	playerCollider = App->collisions->AddCollider({ (int)x, (int)y, 12, 16 }, Collider::Type::PLAYER, this);
	x = position.x + 5.0f;
	playerCenterCollider = App->collisions->AddCollider({ (int)x ,(int)y, 3, 16 }, Collider::Type::PLAYER_CENTER, this);
	y = position.y + 14.0f;
	playerFeetCollider = App->collisions->AddCollider({ (int)x ,(int)y, 3, 2 }, Collider::Type::PLAYER_FEET, this);
	x = position.x + 2.0f;
	y = position.y + 15.0f;
	playerWideFeetCollider = App->collisions->AddCollider({ (int)x, (int)y, 8, 1 }, Collider::Type::PLAYER_WIDE_FEET, this);



	//
	//Player flags
	//
	if (lifes == 0)
	{
		lifes = 3;
		for (int i = 0; i < 3; ++i)
		{
			lifesDrawingArray[i] = true;
		}
	}
	facingDirection = 1;
	destroyed = false;
	canClimb = false;
	canGoDownStairs = false;
	feetTopStairs = false;
	substractLife = false;
	died = false;
	falling = false;
	bonus = 5000;
	time = TIME_PERIOD;
	conveyerRight = false;
	conveyerLeft = false;
	ChangeState(state, IDLE);


	


	//Font
	//Debugging
	char lookupTableD[] = { "! @,_./0123456789$;< ?abcdefghijklmnopqrstuvwxyz" };
	debuggingFont = App->fonts->Load("Assets/Fonts/rtype_font.png", lookupTableD, 2); 
	//Score & Highscore
	char lookupTableS[] = { "0123456789" };
	scoreFont = App->fonts->Load("Assets/Fonts/fontWhite.png", lookupTableS, 1);



	return ret;
}

//Main player Update
Update_Status ModulePlayer::Update()
{
	time--;

	//
	//State updates
	//
	UpdateState();
	UpdateLogic();

	//
	//Score system
	//

	//Update Highscore
	if (score >= highscore) { highscore = score; }
	
	//Only allow Positive Bonus
	if (bonus <= 0 && died == false)
	{
		bonus = 0;
		ChangeState(state, DYING);
		died = true;
	}
	
	//Reduce Bonus by time
		if (time == 0 && bonus > 0) {
		time = TIME_PERIOD;
		bonus -= 100;
	}
	//TODO Score Hurry up



	return Update_Status::UPDATE_CONTINUE;
}

//Control input and states
void ModulePlayer::UpdateState()
{
	//Gamepad support
	GamePad& pad = App->input->pads[0];

	switch (state)
	{

	case IDLE:
	{
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT || pad.l_x < 0.0f ||
			App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT || pad.l_x > 0.0f)
			ChangeState(state, RUNNING);

		if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN || pad.a == true)
			ChangeState(state, JUMPING);

		if (canClimb == true &&
			(App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN || pad.l_y < 0.0f ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN || pad.l_y > 0.0f))
			ChangeState(state, CLIMBING_IDLE);

		if (canGoDownStairs == true &&
			(App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN || pad.l_y > 0.0f))
			ChangeState(state, CLIMBING_DOWN);

		if (App->input->keys[SDL_SCANCODE_H] == Key_State::KEY_DOWN || pad.x == true)
			ChangeState(state, HAMMER_IDLE);

		if (App->input->keys[SDL_SCANCODE_J] == KEY_DOWN || pad.y == true)
		{
			App->collisions->RemoveCollider(playerCollider);
			App->collisions->RemoveCollider(playerCenterCollider);
			App->collisions->RemoveCollider(playerFeetCollider);
			App->collisions->RemoveCollider(playerWideFeetCollider);
			
			ChangeState(state, GOD_MODE);	

		}

		break;
	}

	case GOD_MODE:

		if (App->input->keys[SDL_SCANCODE_J] == KEY_DOWN || pad.y == true)
		{
			float x, y;
			x = position.x;
			y = position.y;
			playerCollider = App->collisions->AddCollider({ (int)x, (int)y, 12, 16 }, Collider::Type::PLAYER, this);
			x = position.x + 5.0f;
			playerCenterCollider = App->collisions->AddCollider({ (int)x ,(int)y, 3, 16 }, Collider::Type::PLAYER_CENTER, this);
			y = position.y + 14.0f;
			playerFeetCollider = App->collisions->AddCollider({ (int)x ,(int)y, 3, 2 }, Collider::Type::PLAYER_FEET, this);
			x = position.x + 2.0f;
			y = position.y + 15.0f;
			playerWideFeetCollider = App->collisions->AddCollider({ (int)x, (int)y, 8, 1 }, Collider::Type::PLAYER_WIDE_FEET, this);



			ChangeState(state, IDLE);

		}

		break;


	case RUNNING:
	{
		if (App->input->keys[SDL_SCANCODE_A] != Key_State::KEY_REPEAT &&
			App->input->keys[SDL_SCANCODE_D] != Key_State::KEY_REPEAT &&
			pad.l_x == 0.0f)
		{
			ChangeState(state, IDLE);
		}

		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT || pad.l_x < 0.0f ||
			App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT || pad.l_x > 0.0f)
			ChangeState(state, RUNNING);

		if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN ||
			/*App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_REPEAT ||*/ pad.a == true)
			ChangeState(state, JUMPING);

		if (canClimb == true && 
			(App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN || pad.l_y < 0.0f ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN || pad.l_y > 0.0f))
			ChangeState(state, CLIMBING_IDLE);

		if (App->input->keys[SDL_SCANCODE_H] == Key_State::KEY_DOWN || pad.x == true)
			ChangeState(state, HAMMER_RUNNING);

		break;
	}

	case JUMPING:
	{
		if (lastCollider == Collider::Type::WALL || feetTopStairs == true || wideWallContact == true)
		{
			jumpCountdown = 30;
			if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT || pad.l_x < 0.0f ||
				App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT || pad.l_x > 0.0f)
			{
				lastCollider = -2;
				ChangeState(state, RUNNING);
			}
			else
			{
				lastCollider = -2;
				ChangeState(state, IDLE);
			}
			feetTopStairs = false;
		}
		if (eraseHammer == true)
		{  
			ChangeState(state, HAMMER_RUNNING);
		}

		break;
	}

	case CLIMBING_DOWN:
	{
		if (canGoDownStairs == false)
			ChangeState(state, CLIMBING_IDLE);

		if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN || pad.l_y < 0.0f)
			ChangeState(state, CLIMBING_UP);

		break;
	}

	case CLIMBING_UP:
	{
		if (canGoDownStairs == false)
		{
			position.y += speed;
			ChangeState(state, IDLE);
		}


		if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN || pad.l_y > 0.0f)
			ChangeState(state, CLIMBING_DOWN);

		break;
	}

	case CLIMBING_IDLE:
	{
		if (canClimb == true &&
			App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT ||
			pad.l_y < 0.0f || pad.l_y > 0.0f)
			ChangeState(state, CLIMBING_RUNNING);

		if (canGoDownStairs == true && upDownDirection == 1 &&
			(App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN ||
				App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN ||
				App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT ||
				App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT ||
				pad.l_y < 0.0f || pad.l_y > 0.0f))
			ChangeState(state, CLIMBING_DOWN);

		if (canGoDownStairs == true && upDownDirection == -1 &&
			(App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN ||
				App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN ||
				App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT ||
				App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT ||
				pad.l_y < 0.0f || pad.l_y > 0.0f))
			ChangeState(state, CLIMBING_UP);


		if (canClimb == false)
			ChangeState(state, IDLE);


		break;
	}

	case CLIMBING_RUNNING:
	{
		if (canGoDownStairs == true)
		{
			if (upDownDirection == -1) {
				ChangeState(state, CLIMBING_UP);
			}
			else
			{
				ChangeState(state, CLIMBING_DOWN);
			}
			break;
		}

		if (App->input->keys[SDL_SCANCODE_W] != Key_State::KEY_REPEAT &&
			App->input->keys[SDL_SCANCODE_S] != Key_State::KEY_REPEAT && pad.l_y == 0)
			ChangeState(state, CLIMBING_IDLE);

		if (canClimb == false)
			ChangeState(state, IDLE);

		break;
	}

	case HAMMER_IDLE:
	{
		if (App->input->keys[SDL_SCANCODE_H] == Key_State::KEY_DOWN || pad.x == true)
			ChangeState(state, IDLE);


		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_DOWN || pad.l_x < 0.0f ||
			App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_DOWN || pad.l_x > 0.0f)
		{
			ChangeState(state, HAMMER_RUNNING);
		}


		break;
	}

	case HAMMER_RUNNING:
	{
		if (App->input->keys[SDL_SCANCODE_H] == Key_State::KEY_DOWN || pad.x == true)
			ChangeState(state, RUNNING);

		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT || pad.l_x < 0.0f ||
			App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT || pad.l_x > 0.0f)
			ChangeState(state, HAMMER_RUNNING);

		if (App->input->keys[SDL_SCANCODE_A] != Key_State::KEY_REPEAT &&
			App->input->keys[SDL_SCANCODE_D] != Key_State::KEY_REPEAT && pad.l_x==0)
		{
			ChangeState(state, HAMMER_IDLE);
		}

		break;
	}

	case FALLING:
	{
		if ((lastCollider == Collider::Type::WALL) || (lastCollider == Collider::Type::RAMP_LEFT) || (lastCollider == Collider::Type::RAMP_RIGHT))
		{
			ChangeState(state, DYING);
		}
		break;
	}

	case DYING:
	{
		if (currentAnimation->getLoopCount() != 0)
		{
			ChangeState(state, SUBSTRACT_LIFE);
		}
		break;
	}

	case SUBSTRACT_LIFE:
	{
		if (destroyed == true)
		{
			ChangeState(state, NO_LIFES);
		}
		break;
	}

	case NO_LIFES:
	{
		break;
	}

	default:
		break;
	}

}

//Control what each state does
void ModulePlayer::UpdateLogic()
{
	//Gamepad support
	GamePad& pad = App->input->pads[0];


	switch (state)
	{

	case IDLE:
	{
		// Nothing to do here :)
		if (conveyerRight == true)
		{
			position.x += speed;
		}

		if (conveyerLeft == true)
		{
			position.x -= speed;
		}

		break;
	}

	case GOD_MODE:
		if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN || App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT || pad.l_y < 0.0f)
			position.y -= speed;

		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_DOWN || App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT || pad.l_x > 0.0f)
			position.x -= speed;

		if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN || App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT || pad.l_y > 0.0f)
			position.y += speed;

		if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_DOWN || App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT || pad.l_x > 0.0f)
			position.x += speed;

		break;

	case RUNNING:
	{
		if (rampRight == true)
		{
			//Right
			if (facingDirection == 1)
			{
				if (playerCenterCollider->rect.y >= aux.y - 14 && playerCenterCollider->rect.x == aux.x) //Go Up Looking Right//
				{
					position.y -= speed;
				}
			}

			//Left
			if (facingDirection == -1)
			{
				if (playerCenterCollider->rect.y <= aux.y - 15 && playerCenterCollider->rect.x + 2 == aux.x) //Go Down Looking Left//
				{
					position.y += speed;
				}
			}
		}

		if (rampLeft == true)
		{
			//Right
			if (facingDirection == 1)
			{
				if (playerCenterCollider->rect.y < aux.y - 14 && playerCenterCollider->rect.x == aux.x) //Go Down Looking Right
				{
					position.y += speed;
				}
			}

			//Left
			if (facingDirection == -1)
			{
				if (playerCenterCollider->rect.y >= aux.y - 14 && playerCenterCollider->rect.x + 2 == aux.x) //Go Up Looking Left//
				{
					position.y -= speed;
				}
			}
		}

		if (conveyerRight == true)
		{
			position.x += 0.5f;
		}

		if (conveyerLeft == true)
		{
			position.x -= 0.5f;
		}

		position.x += speed * facingDirection;
		currentAnimation->Update();

		break;
	}

	case JUMPING:
	{
		--jumpCountdown;
		if (jumpCountdown < 15)
		{
			++position.y;
		}
		else if (jumpCountdown < 30)
		{
			--position.y;
		}
		position.x += speed * jumpDirection;
		currentAnimation->Update();

		break;
	}

	case HAMMER_IDLE:
	{

		ishammerOn = true;
		currentAnimation->Update();

		break;
	}

	case HAMMER_RUNNING:
	{
		if (rampRight == true)
		{
			//Right
			if (facingDirection == 1)
			{
				if (playerCenterCollider->rect.y >= aux.y - 14 && playerCenterCollider->rect.x == aux.x) //Go Up Looking Right//
				{
					position.y -= speed;
				}
			}

			//Left
			if (facingDirection == -1)
			{
				if (playerCenterCollider->rect.y <= aux.y - 15 && playerCenterCollider->rect.x + 2 == aux.x) //Go Down Looking Left//
				{
					position.y += speed;
				}
			}
		}

		if (rampLeft == true)
		{
			//Right
			if (facingDirection == 1)
			{
				if (playerCenterCollider->rect.y < aux.y - 14 && playerCenterCollider->rect.x == aux.x) //Go Down Looking Right
				{
					position.y += speed;
				}
			}

			//Left
			if (facingDirection == -1)
			{
				if (playerCenterCollider->rect.y >= aux.y - 14 && playerCenterCollider->rect.x + 2 == aux.x) //Go Up Looking Left//
				{
					position.y -= speed;
				}
			}
		}

		ishammerOn = true;
		position.x += speed * facingDirection;
		currentAnimation->Update();

		break;
	}

	case CLIMBING_DOWN:
	{
		if (canGoDownStairs == true)
		{
			position.y += speed * upDownDirection;
			currentAnimation->Update();
		}

		break;
	}

	case CLIMBING_UP:
	{
		if (canGoDownStairs == true)
		{
			position.y += speed * upDownDirection;
			currentAnimation->Update();
		}

		break;
	}

	case CLIMBING_IDLE:
	{
		//currentAnimation->Update();

		break;
	}

	case CLIMBING_RUNNING:
	{
		if (canClimb == true)
		{
			position.y += speed * upDownDirection;
			currentAnimation->Update();
		}
		break;
	}

	case FALLING:
	{
		if ((lastCollider != Collider::Type::WALL) || (lastCollider != Collider::Type::RAMP_LEFT) || (lastCollider != Collider::Type::RAMP_RIGHT) || (lastCollider != Collider::Type::TOP_STAIR))
		{
			position.y += speed * 2;
		}

		break;
	}

	case DYING:
	{
		if (currentAnimation->getLoopCount() == 0)
		{
			currentAnimation->Update();
		}
		
		break;
	}

	case SUBSTRACT_LIFE:
		//Reset level
		if (substractLife == true)
		{
			--lifes;
			lifesDrawingArray[lifes] = false;

			if (lifes == 0) {
				destroyed = true;
				break;
			}

			if (currentLevel == "level 1")
			{
				CleanUp();
				App->fade->FadeToBlack((Module*)App->sceneLevel1, (Module*)App->sceneLevel1, 60);
			}
			if (currentLevel == "level 2")
			{
				CleanUp();
				App->fade->FadeToBlack((Module*)App->sceneLevel2, (Module*)App->sceneLevel2, 60);
			}
			if (currentLevel == "level 4")
			{
				CleanUp();
				App->fade->FadeToBlack((Module*)App->sceneLevel4, (Module*)App->sceneLevel4, 60);
			}
		}
		break;

	case NO_LIFES:
	{
		--gameOverCountdown;
		if (gameOverCountdown == 0)
		{
			drawGameOver = false;

			if (currentLevel == "level 1")
			{
				CleanUp();
				App->fade->FadeToBlack((Module*)App->sceneLevel1, (Module*)App->sceneIntro, 60);
			}
			if (currentLevel == "level 2")
			{
				CleanUp();
				App->fade->FadeToBlack((Module*)App->sceneLevel2, (Module*)App->sceneIntro, 60);
			}
			if (currentLevel == "level 4")
			{
				CleanUp();
				App->fade->FadeToBlack((Module*)App->sceneLevel4, (Module*)App->sceneIntro, 60);
			}
		}

		break;
	}
	}


	switch (lastCollider)
	{
	case Collider::Type::NONE:
		break;
	case Collider::Type::WALL:
		position.y -= speed;
		lastCollider = Collider::Type::NONE;
		break;
	case Collider::Type::RAMP_RIGHT:
	case Collider::Type::RAMP_LEFT:
	case Collider::Type::PLAYER:
	case Collider::Type::PLAYER_CENTER:
	case Collider::Type::PLAYER_WIDE_FEET:
	case Collider::Type::ENEMY:
	case Collider::Type::STAIR:
	case Collider::Type::TOP_STAIR:
	case Collider::Type::BUTTON:
	case Collider::Type::TOPWALL:
	case Collider::Type::LEFTWALL:
	case Collider::Type::RIGHTWALL:
	case Collider::Type::GRAVITYWALLS:
	case Collider::Type::PEACH:
	case Collider::Type::DK:
	case Collider::HAMMER:
		break;
	default:
		position.y += speed;
		break;
	}


	//Erasing button if it collider
	if (eraseButton == true)
	{
		App->sceneLevel4->eraseButton(button);
		eraseButton = false;
		button = nullptr;
		lastCollider = Collider::Type::NONE;
		score += 100;
	}

	//Erasing hammer if i collide
	if (eraseHammer == true)
	{
		App->sceneLevel1->eraseHammer(hammer);
		eraseHammer = false;
		hammer = nullptr;
		lastCollider = Collider::Type::NONE;
	}


	// Simply updating the collider position to match our current position
	playerCollider->SetPos(position.x, position.y);
	playerCenterCollider->SetPos(position.x + 5, position.y);
	playerFeetCollider->SetPos(position.x + 5, position.y + 14);
	playerWideFeetCollider->SetPos(position.x + 2, position.y + 15);


	//Flag update
	canClimb = false;
	canGoDownStairs = false;
	feetTopStairs = false;
	rampRight = false;
	rampLeft = false;
	wideWallContact = false;
	substractLife = false;
	eraseButton = false;
	eraseHammer = false;
	conveyerRight = false;
	conveyerLeft = false;


	if (App->input->keys[SDL_SCANCODE_L] == KEY_DOWN || pad.l1 == true)
		ChangeState(state, DYING);

	if (App->input->keys[SDL_SCANCODE_G] == KEY_DOWN || pad.back == true)
		debugGamepadInfo = !debugGamepadInfo;
	
}

//Change the State
void ModulePlayer::ChangeState(Player_State previousState, Player_State newState)
{
	//Gamepad support
	GamePad& pad = App->input->pads[0];

	switch (newState)
	{

	case IDLE:
	{
		currentAnimation = &(facingDirection == -1 ? idleAnim_Left : idleAnim_Right);
		break;
	}

	case RUNNING:
	{
		if (lastCollider == Collider::Type::WALL)
			position.y -= speed;

		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT || pad.l_x < 0.0f)
			facingDirection = -1;
		else
			facingDirection = 1;
		currentAnimation = &(facingDirection == -1 ? runningAnim_Left : runningAnim_Right);
		break;
	}

	case JUMPING:
	{
		App->audio->PlayFx(jumpFx);

		if (previousState == IDLE)
			jumpDirection = 0;
		else
			jumpDirection = facingDirection;

		currentAnimation = &(facingDirection == -1 ? jumpAnim_Left : jumpAnim_Right);
		break;
	}

	case HAMMER_IDLE:
	{
		currentAnimation = &(facingDirection == -1 ? hammerIdleAnim_Left : hammerIdleAnim_Right);
		break;
	}

	case HAMMER_RUNNING:
	{
//		App->audio->PlayFx(hammerFx);
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT || pad.l_x < 0.0f)
			facingDirection = -1;
		else
			facingDirection = 1;

		currentAnimation = &(facingDirection == -1 ? hammerRunAnim_Left : hammerRunAnim_Right);
		break;
	}

	case CLIMBING_DOWN:
	{
		position.x = topStairCollider.x - 5;

		if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT || pad.l_y > 0.0f)
			upDownDirection = 1;
		else
			upDownDirection = -1;

		currentAnimation = &climb_Down;
		break;
	}

	case CLIMBING_UP:
	{
		position.x = topStairCollider.x - 5;

		if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT || pad.l_y < 0.0f)
			upDownDirection = -1;
		else
			upDownDirection = 1;

		currentAnimation = &climb_Up;
		break;
	}

	case CLIMBING_IDLE:
	{
		//Nothing to do here
		break;
	}

	case CLIMBING_RUNNING:
	{
		position.x = topStairCollider.x - 5;

		if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT || pad.l_y < 0.0f)
			upDownDirection = -1;
		else if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT || pad.l_y > 0.0f)
			upDownDirection = 1;

		currentAnimation = &climb;
		break;

	}

	case FALLING:
	{

		break;
	}

	case DYING:
	{
		currentAnimation = &dyingAnim;

		break;
	}

	case SUBSTRACT_LIFE:
	{
		currentAnimation->Reset();
		currentAnimation = &deadMario;
		currentAnimation->Update();

		substractLife = true;

		break;
	}

	case NO_LIFES:
	{
		drawGameOver = true;
		break;
	}
	}

	if (ishammerOn)
	{
		App->audio->PlayFx(hammerFx);
	}
	else
	{
		App->audio->UnloadFx(hammerFx);
	}

	lastCollider = Collider::Type::NONE;

	state = newState;
}

//Post Update
Update_Status ModulePlayer::PostUpdate()
{
	//
	//Draw Player
	//
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		if (state == HAMMER_IDLE || state == HAMMER_RUNNING)
		{
			if (facingDirection == -1)
			{
				App->render->Blit(playerTexture, position.x - 13, position.y - 10, &rect);
			}
			else {
				App->render->Blit(playerTexture, position.x, position.y - 10, &rect);
			}
		}
		else
		{
			App->render->Blit(playerTexture, position.x, position.y, &rect);
		}
	}

	//
	//Draw Lifes
	//
	for (int i = 0; i < NUM_LIFES; ++i)
	{
		if (lifesDrawingArray[i] == true)
		{
			SDL_Rect rect = { 95, 0, 8, 8 };
			App->render->Blit(lifesTexture, 8 * (i + 1), 24, &rect);
		}
	}

	//
	//Draw Game Over screen
	//
	if (drawGameOver == true)
	{
		App->render->Blit(gameOverTexture, 55, 161, nullptr);
	}
	
	//
	//Draw Score
	//
	sprintf_s(scoreText, 8, "%6d", score);
	sprintf_s(highscoreText, 8, "%6d", score);
	sprintf_s(bonusText, 5, "%4d", bonus);

	//Score Blits
	App->fonts->BlitText(8, 8, scoreFont, scoreText);
	App->fonts->BlitText(88, 8, scoreFont, highscoreText);
	App->fonts->BlitText(175, 47, bonusFont, bonusText);



	//Debug Gamepad
	if (debugGamepadInfo == true)
		DebugDrawGamepadInfo();
	else
		App->fonts->BlitText(5, 10, debuggingFont, "press g to display gamepad debug info");

	return Update_Status::UPDATE_CONTINUE;
}

//Controls what the player does when it collides with another collider
void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	//
	//Collision control
	//

	//Fall to death collision
	if (c1 == playerCenterCollider && c2->type == Collider::Type::GRAVITYWALLS)
	{
		falling = true;
		ChangeState(state, FALLING);
	}

	//Wall collision
	if (c1 == playerFeetCollider && c2->type == Collider::Type::WALL)
	{
		canClimb = false;
		lastCollider = Collider::Type::WALL;
	}

	if (falling == false)
	{
		if (c1 == playerWideFeetCollider && c2->type == Collider::Type::WALL)
		{
			wideWallContact = true;
			lastCollider = Collider::Type::WALL;
		}
	}


	//Mid stair collision
	if (c1 == playerCenterCollider && c2->type == Collider::Type::STAIR)
	{
		canClimb = true;
		topStairCollider = c2->GetRect();
		lastCollider = Collider::Type::STAIR;
	}
	//Top stair collision
	if (c1 == playerCenterCollider && c2->type == Collider::Type::TOP_STAIR)
	{
		canClimb = true;
		canGoDownStairs = true;
		canGoUpStairs = true;
		topStairCollider = c2->GetRect();
		lastCollider = Collider::Type::TOP_STAIR;
	}
	if (c1 == playerFeetCollider && c2->type == Collider::Type::TOP_STAIR)
	{
		feetTopStairs = true;
		
	}



	//Ramp right collision
	if (c1 == playerFeetCollider && c2->type == Collider::Type::RAMP_RIGHT)
	{
		rampRight = true;
		aux = c2->GetRect();
		lastCollider = Collider::Type::RAMP_RIGHT;
	}
	//Ramp left collision
	if (c1 == playerFeetCollider && c2->type == Collider::Type::RAMP_LEFT)
	{
		rampLeft = true;
		aux = c2->GetRect();
		lastCollider = Collider::Type::RAMP_LEFT;
	}




	//Top limit collison
	if (c1 == playerCollider && c2->type == Collider::Type::TOPWALL)
	{
		position.y += speed;
		lastCollider = Collider::Type::TOPWALL;
	}
	//Left limit collision
	if (c1 == playerCollider && c2->type == Collider::Type::LEFTWALL)
	{
		position.x += speed;
		lastCollider = Collider::Type::LEFTWALL;
	}
	//Right limit collision
	if (c1 == playerCollider && c2->type == Collider::Type::RIGHTWALL)
	{
		position.x -= speed;
		lastCollider = Collider::Type::RIGHTWALL;
	}


	//Button collision
	if (c1 == playerCenterCollider && c2->type == Collider::Type::BUTTON)
	{
		eraseButton = true;
		button = c2;
	}
	//Hammer collision
	if (c1 == playerCenterCollider && c2->type == Collider::Type::HAMMER)
	{
		eraseHammer = true;
		hammer = c2;
	}


	if (c1 == playerFeetCollider && c2->type == Collider::Type::CONVEYER_RIGHT)
	{
		conveyerRight = true;
	}
	if (c1 == playerFeetCollider && c2->type == Collider::Type::CONVEYER_LEFT)
	{
		conveyerLeft = true;
	}


}

//Draw GamePad Debug
void ModulePlayer::DebugDrawGamepadInfo()
{
	GamePad& pad = App->input->pads[0];

	sprintf_s(debuggingText, 150, "pad 0 %s, press 1/2/3 for rumble", (pad.enabled) ? "plugged" : "not detected");
	App->fonts->BlitText(5, 10, debuggingFont, debuggingText);

	sprintf_s(debuggingText, 150, "buttons %s %s %s %s %s %s %s %s %s %s %s",
		(pad.a) ? "a" : "",
		(pad.b) ? "b" : "",
		(pad.x) ? "x" : "",
		(pad.y) ? "y" : "",
		(pad.start) ? "start" : "",
		(pad.back) ? "back" : "",
		(pad.guide) ? "guide" : "",
		(pad.l1) ? "lb" : "",
		(pad.r1) ? "rb" : "",
		(pad.l3) ? "l3" : "",
		(pad.r3) ? "r3" : ""
	);
	App->fonts->BlitText(5, 20, debuggingFont, debuggingText);

	sprintf_s(debuggingText, 150, "dpad %s %s %s %s",
		(pad.up) ? "up" : "",
		(pad.down) ? "down" : "",
		(pad.left) ? "left" : "",
		(pad.right) ? "right" : ""
	);
	App->fonts->BlitText(5, 30, debuggingFont, debuggingText);

	sprintf_s(debuggingText, 150, "left trigger  %0.2f", pad.l2);
	App->fonts->BlitText(5, 40, debuggingFont, debuggingText);
	sprintf_s(debuggingText, 150, "right trigger %0.2f", pad.r2);
	App->fonts->BlitText(5, 50, debuggingFont, debuggingText);

	sprintf_s(debuggingText, 150, "left thumb    %.2fx, %0.2fy", pad.l_x, pad.l_y);
	App->fonts->BlitText(5, 60, debuggingFont, debuggingText);

	sprintf_s(debuggingText, 150, "   deadzone   %0.2f", pad.l_dz);
	App->fonts->BlitText(5, 70, debuggingFont, debuggingText);

	sprintf_s(debuggingText, 150, "right thumb   %.2fx, %0.2fy", pad.r_x, pad.r_y);
	App->fonts->BlitText(5, 80, debuggingFont, debuggingText);

	sprintf_s(debuggingText, 150, "   deadzone   %0.2f", pad.r_dz);
	App->fonts->BlitText(5, 90, debuggingFont, debuggingText);
}