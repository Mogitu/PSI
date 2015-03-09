#ifndef Game_World_H
#define Game_World_H

#include "IGameObject.h"

using namespace irr;

class GameWorld
{
private:
	core::list<IGameObject*> gameObjects;
public:
	//GameWorld();
	~GameWorld();
	void clearGameObjects();
	void update(u32 frameDeltaTime);
	void addGameObject(IGameObject* gameObject);
	void removeGameObject(IGameObject* gameObject);
};

#endif // !Game_World_H
