#include "Module.h"

//Constructors looks if the Module is enabled
Module::Module(bool startEnabled) : isEnabled(startEnabled)
{

}

//Initialize the Module
bool Module::Init()
{
	return true;
}

//Start the Module (make it "visible/work")
bool Module::Start()
{
	return true;
}


//Does the Pre Update routines of the Module
Update_Status Module::PreUpdate()
{
	return Update_Status::UPDATE_CONTINUE;
}

//Does the Update routines of the Module
Update_Status Module::Update()
{
	return Update_Status::UPDATE_CONTINUE;
}

//Does the Post Update routines of the Module
Update_Status Module::PostUpdate()
{
	return Update_Status::UPDATE_CONTINUE;
}


//Deletes memory of the Module
bool Module::CleanUp()
{
	return true;
}

//Controls the collisions of a Module
void Module::OnCollision(Collider* c1, Collider* c2)
{

}

//Enables the Module
void Module::Enable()
{
	if (!isEnabled)
	{
		isEnabled = true;
		Start();
	}
}

//Disables the Module
void Module::Disable()
{
	//Call CleanUp() for disabling a module
	if (isEnabled)
	{
		isEnabled = false;
		CleanUp();
	}
}
