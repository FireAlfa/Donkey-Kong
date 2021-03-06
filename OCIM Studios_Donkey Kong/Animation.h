#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "SDL/include/SDL_rect.h"
#define MAX_FRAMES 240


//Animation Class
class Animation
{
public:
	bool loop = true;
	float speed = 1.0f;
	SDL_Rect frames[MAX_FRAMES];

	// Allows the animation to keep going back and forth
	bool pingpong = false;

private:
	float currentFrame = 0.0f;
	int totalFrames = 0;
	int loopCount = 0;
	int pingpongDirection = 1;

public:

	//Add frame to animation
	void PushBack(const SDL_Rect& rect)
	{
		frames[totalFrames++] = rect;
	}

	//Restart animation
	void Reset()
	{
		currentFrame = 0;
		loopCount = 0;
	}

	//Controls whether a loop has finished or not
	bool HasFinished()
	{
		return !loop && !pingpong && loopCount > 0;
	}

	//Update the animation to change sprite
	void Update()
	{
		currentFrame += speed;
		if (currentFrame >= totalFrames)
		{
			currentFrame = (loop || pingpong) ? 0.0f : totalFrames - 1;
			++loopCount;

			if (pingpong)
				pingpongDirection = -pingpongDirection;
		}
	}

	//Returns the square of the current frame
	SDL_Rect& GetCurrentFrame()
	{
		int actualFrame = currentFrame;
		if (pingpongDirection == -1)
			actualFrame = totalFrames - currentFrame;

		return frames[actualFrame];
	}
	
	//Loop Count getter
	int getLoopCount()
	{
		return loopCount;
	}

	bool animationEnded()
	{
		if((int)currentFrame == totalFrames)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

#endif