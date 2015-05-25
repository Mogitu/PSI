#ifndef GAMEOBJECTPLACEHOLDER_H
#define GAMEOBJECTPLACEHOLDER_H

#include "IGameObject.h"

class GameObjectPlaceHolder : public IGameObject
{
public:
	GameObjectPlaceHolder(ISceneNode* node)
	{
		this->node = node;
	}

	void Initialize() override { };
	void Update(irr::u32 frameDeltaTime) override { };
	void kill() override { };
	void revive() override { };

	GameObjectType getType() const
	{
		return GameObjectType::PLACEHOLDER;
	}
};

#endif