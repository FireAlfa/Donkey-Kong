#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "Collider.h"


#define NUM_LIFES 3
#define TIME_PERIOD 100

struct SDL_Texture;
struct Collider;

//Different states of the player
enum Player_State
{
	IDLE,
	RUNNING,
	JUMPING,
	HAMMER_IDLE,
	HAMMER_RUNNING,
	FALLING,
	DYING,
	SUBSTRACT_LIFE,
	CLIMBING_IDLE,
	CLIMBING_RUNNING,
	CLIMBING_UP,
	CLIMBING_DOWN,
	NO_LIFES,
	GOD_MODE
};


//Player Class
class ModulePlayer : public Module
{
public:
	// Constructor
	ModulePlayer(bool startEnabled);

	// Destructor
	~ModulePlayer();


	// Called when the module is activated
	// Loads the necessary textures for the player
	bool Start() override;

	// Called at the middle of the application loop
	// Processes new input and handles player movement
	Update_Status Update() override;

	// Checks for inputs (or timers) and changes the player state accordingly
	void UpdateState();

	// Updates the logic of the player depending on the current state
	void UpdateLogic();

	// Transition from one state to a new one. Changes animations, resets variables,...
	void ChangeState(Player_State previousState, Player_State newState);

	// Called at the end of the application loop
	// Performs the render call of the player sprite
	Update_Status PostUpdate() override;



	// Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;

	// Draws gamepad debug info in the screen
	void DebugDrawGamepadInfo();

public:

	//
	//Variables ralated to the player
	//

	// Position of the player in the map
	fPoint position;
	
	// The state of the player
	Player_State state = IDLE;

	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* playerTexture = nullptr;
	//Lifes texture
	SDL_Texture* lifesTexture = nullptr;
	bool lifesDrawingArray[NUM_LIFES] = { true, true, true };
	//Game Over texture
	SDL_Texture* gameOverTexture = nullptr;

	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnimation = nullptr;

	//The Player's collider
	Collider* playerCollider = nullptr;
	Collider* playerCenterCollider = nullptr;
	Collider* playerFeetCollider = nullptr;
	Collider* playerWideFeetCollider = nullptr;

	//
	//Auxiliar variables
	//
	//Rectangle of the other collider
	SDL_Rect aux;
	SDL_Rect topStairCollider;
	//Last collider
	int lastCollider = Collider::Type::NONE;
	//Auxiliar collider for buttons
	Collider* button = nullptr;
	//Auxiliar collider for hammers
	Collider* hammer = nullptr;
	//Current level
	const char* currentLevel = "none";

	// The speed in which we move the player (pixels per frame)
	float speed = 1.0f;

	// The direction where the player is facing -> -1 for Left // 1 for Right
	int facingDirection = 1;

	//If player is climbing up or down -> -1 for Up // 1 for Down
	int upDownDirection = -1;

	// Jump handlers
	int jumpCountdown = 30;
	int jumpDirection = 1;


	///////ANIMATION SETS////////
	Animation idleAnim_Left;
	Animation idleAnim_Right;

	Animation runningAnim_Left;
	Animation runningAnim_Right;

	Animation jumpAnim_Left;
	Animation jumpAnim_Right;

	Animation climb;
	Animation climb_Up;
	Animation climb_Down;

	Animation hammerIdleAnim_Left;
	Animation hammerIdleAnim_Right;

	Animation hammerRunAnim_Left;
	Animation hammerRunAnim_Right;

	Animation dyingAnim;
	Animation deadMario;
	//////////////////////////////////////



	//
	//Player flags
	//
	//Lifes
	int lifes = 3;

	//A flag to detect when the player has been destroyed
	bool destroyed = false;

	// Flag set when the player is near a ladder
	bool canClimb = false;
	bool canGoDownStairs = false;
	bool canGoUpStairs = false;
	bool rampRight = false;
	bool rampLeft = false;
	bool eraseButton = false;
	bool eraseHammer = false;
	bool wideWallContact = false;
	bool substractLife = false;
	bool died = false;
	bool drawGameOver = false;
	bool feetTopStairs = false;
	bool falling = false;
	bool conveyerRight = false;
	bool conveyerLeft = false;


	
	//Countdown for the game over screen
	int gameOverCountdown = 300;
	


	// Sound effects indices
	uint jumpFx = 0;
	uint hammerFx = 0;

	// Font score index
	uint score = 000000;
	uint highscore = 000000;
	uint bonus = 5000;

	int debuggingFont = -1;
	int scoreFont = -1;
	int bonusFont = -1;
	char debuggingText[200] = { "\0" };
	char scoreText[7];
	char highscoreText[7];
	char bonusText[5];

	bool ishammerOn;

	// Debug flag for gamepad data drawing
	bool debugGamepadInfo = false;

	int time = TIME_PERIOD;
};

#endif //!__MODULE_PLAYER_H__