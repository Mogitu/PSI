#ifndef I_GAME_OBJECT_H
#define I_GAME_OBJECT_H

#include <irrlicht.h>
#include "BulletHelper.h"
#include "GameWorld.h"

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
protected:
	GameWorld *world;
	BulletHelper *helper;
public:
	bool isAlive;
	btRigidBody *body;
	ISceneNode *node;

	virtual ~IGameObject()
	{
		std::cout << "REMOVING IGAMEOBJECT\n";

		if (node)
			node->remove();

		if (body)
		{
			delete body->getMotionState();
			delete body->getCollisionShape();

			helper->getWorld()->removeCollisionObject(body);

			delete body;
		}
		
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
