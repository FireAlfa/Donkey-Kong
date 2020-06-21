#include "Globals.h"
#include "MemLeaks.h"
#include "Application.h"

#include <stdlib.h>
#include <time.h>


#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#include "SDL_mixer/include/SDL_mixer.h"

#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )




//Main states for the loop
enum class Main_States {
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};

//Creation of the App (the game)
Application* App = nullptr;


//Main Function
int main(int argc, char** argv)
{

	//Calls to see if there are any memory leaks
	ReportMemoryLeaks();

	/* initialize random seed: */
	srand(time(NULL));

	//Variable to know if the programm has ended
	int main_return = EXIT_FAILURE;

	//Variable to know the current Main state
	Main_States state = Main_States::MAIN_CREATION;


	//Main loop
	while (state != Main_States::MAIN_EXIT)
	{
		switch (state)
		{

		//Creation of the Dynamic Memory for the App
		case Main_States::MAIN_CREATION:
		{
			LOG("Application Creation--------------\n");
			App = new Application();
			state = Main_States::MAIN_START;
		}	break;

		//Initialitzation of the game systems
		case Main_States::MAIN_START:
		{
			LOG("Application Start--------------\n");
			if (App->Init() == false)
			{
				LOG("----- Application Init exits with error\n");
				state = Main_States::MAIN_EXIT;
			}
			else
			{
				state = Main_States::MAIN_UPDATE;
			}
		}	break;

		//Game loop
		case Main_States::MAIN_UPDATE:
		{
			Update_Status status = App->Update();

			if (status == Update_Status::UPDATE_ERROR)
			{
				LOG("----- Application Update exits with error\n");
				state = Main_States::MAIN_EXIT;
			}
			else if (status == Update_Status::UPDATE_STOP)
			{
				state = Main_States::MAIN_FINISH;
			}
		}	break;

		//Clean up all the game systems
		case Main_States::MAIN_FINISH:
		{
			LOG("Application Finish--------------\n");
			if (App->CleanUp() == true)
			{
				main_return = EXIT_SUCCESS;
			}
			else
			{
				LOG("----- Application CleanUp exits with error\n");
			}
			state = Main_States::MAIN_EXIT;
		}
		}
	}

	LOG("\nBye :)\n");

	//Delete dynamic memory of the App
	delete App;


	return 0;
}