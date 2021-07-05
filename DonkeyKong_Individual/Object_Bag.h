#ifndef __BAG_H__
#define __BAG_H__

#include "Object.h"
#include "Collider.h"
#include "ModuleCollisions.h"



class Object_Bag : public Object
{
public:

	Object_Bag(int x, int y);
	~Object_Bag();


	void Update() override;
	
	//Control barrel collisions
	void OnCollision(Collider* c1, Collider* c2) override;

	

private:

	bool destroyed = false;

	Animation bagAnim;

};

#endif // !__BAG_H__
