#include "Path.h"

#include "Animation.h"

//Creates an animation path
void Path::PushBack(fPoint speed, uint frames, Animation* animation)
{
	steps[totalSteps].animation = animation;
	steps[totalSteps].framesDuration = frames;
	steps[totalSteps].speed = speed;
	totalSteps++;
}

//Updates path
void Path::Update()
{
	currentStepFrame += 1;

	if (currentStepFrame > steps[currentStep].framesDuration)
	{
		if (currentStep < totalSteps - 1) // If it is not the last step, advance
		{
			currentStep++;
		}
		else if (loop) // Otherwise, if the path loops, go back to the beginning
		{
			currentStep = 0;
		}
		currentStepFrame = 0;
	}

	relativePosition += steps[currentStep].speed;
}

//Get the current position in the path
iPoint Path::GetRelativePosition() const
{
	return iPoint((int)relativePosition.x, (int)relativePosition.y);
}

//Get the current animation in the path
Animation* Path::GetCurrentAnimation()
{
	return steps[currentStep].animation;
}

//Restart the path
void Path::Reset()
{
	currentStepFrame = 0;
	currentStep = 0;
}