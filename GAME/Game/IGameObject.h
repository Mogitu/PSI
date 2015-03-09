#ifndef I_GAME_OBJECT_H
#define I_GAME_OBJECT_H

#include <irrlicht.h>

enum GameObjectType
{
	UNKNOWN = 0,
	PLAYER
};

class IGameObject
{
public:
	virtual ~IGameObject(){}
	virtual void Initialize() = 0;
	virtual void Update(irr::u32 frameDeltaTime) = 0;
	virtual GameObjectType getType() const
	{
		return GameObjectType::UNKNOWN;
	}
};

#endif // !I_GAME_OBJECT_H
