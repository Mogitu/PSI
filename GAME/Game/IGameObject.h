#ifndef I_GAME_OBJECT_H
#define I_GAME_OBJECT_H

#include <irrlicht.h>
#include "BulletHelper.h"

enum GameObjectType
{
	UNKNOWN = 0,
	PLAYER,
	PROJECTILE,
	ENEMY,
	PLACEHOLDER
};

class IGameObject
{
public:
	bool isAlive;
	btRigidBody *body;
	ISceneNode *node;
	virtual ~IGameObject()
	{
		//Node->remove();
		//// Remove the object from the world
		//helper->getWorld()->removeRigidBody(body);
		//// Free memory
		//delete body->getMotionState();
		//delete body->getCollisionShape();
		//delete body;
		std::cout << "REMOVING IGAMEOBJECT\n";
		
		//node->removeAll();
		
		//if (body && body->getMotionState())
		//	delete body->getMotionState();

		//if (body && body->getCollisionShape())
		//	delete body->getCollisionShape();

		//delete body;		
	}
	virtual void Initialize() = 0;
	virtual void Update(irr::u32 frameDeltaTime) = 0;
	virtual void kill()=0;
	virtual void revive()=0;
	//virtual void takeDamage(int amount){};
	virtual GameObjectType getType() const
	{
		return GameObjectType::UNKNOWN;
	}
};

#endif // !I_GAME_OBJECT_H
