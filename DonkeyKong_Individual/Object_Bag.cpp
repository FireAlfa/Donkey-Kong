#include "Object_Bag.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleRender.h"
#include "ModuleObject.h"
#include "Object.h"



Object_Bag::Object_Bag(int x, int y) : Object(x, y)
{
	bagAnim.PushBack({ 17, 0, 8, 12 });

	currentAnim = &bagAnim;
	objcollider = App->collisions->AddCollider({4, 6, 8, 12}, Collider::Type::OBJECT, (Module*)App->objects);
}

Object_Bag::~Object_Bag()
{

}


void Object_Bag::Update()
{
	if (destroyed == false)
	{
		App->textures->Blit()
	}
}


void Object_Bag::OnCollision(Collider* c1, Collider* c2)
{

}