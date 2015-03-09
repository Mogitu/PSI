#include "GameWorld.h"

GameWorld::~GameWorld()
{
	clearGameObjects();
}

//TODO: Game Objects that are being removed from the Game World now still exists in the Physics World -José
void GameWorld::clearGameObjects()
{
	for (core::list<IGameObject *>::Iterator Iterator = gameObjects.begin(); Iterator != gameObjects.end(); ++Iterator)
	{
		IGameObject* gameObject = *Iterator;

		delete gameObject;
	}

	gameObjects.clear();
}

void GameWorld::update(u32 frameDeltaTime)
{
	for (core::list<IGameObject *>::Iterator Iterator = gameObjects.begin(); Iterator != gameObjects.end(); ++Iterator)
	{
		IGameObject* gameObject = *Iterator;
		gameObject->Update(frameDeltaTime);
		updatePhysics(gameObject->body);
		if (!gameObject->isAlive)
		{
			gameObject->kill();
			gameObjects.erase(Iterator);
			delete gameObject;
			return;			
		}			
	}
}

void GameWorld::updatePhysics(btRigidBody *body)
{
	ISceneNode *node = static_cast<ISceneNode *>(body->getUserPointer());

	// Set position
	btVector3 point = body->getCenterOfMassPosition();
	node->setPosition(vector3df((f32)point[0], (f32)point[1], (f32)point[2]));

	// Set rotation
	vector3df euler;
	const btQuaternion& btQuat = body->getOrientation();
	quaternion irrQuat(btQuat.getX(), btQuat.getY(), btQuat.getZ(), btQuat.getW());
	irrQuat.toEuler(euler);
	euler *= RADTODEG;
	node->setRotation(euler);
}

void GameWorld::addGameObject(IGameObject* gameObject)
{
	this->gameObjects.push_back(gameObject);
}

//TODO: Game Objects that are being removed from the Game World now still exists in the Physics World -José
void GameWorld::removeGameObject(IGameObject* gameObject)
{
	for (core::list<IGameObject *>::Iterator Iterator = gameObjects.begin(); Iterator != gameObjects.end(); ++Iterator)
	{
		if (gameObject == *Iterator)
		{
			gameObjects.erase(Iterator);
			delete gameObject;
			break;
		}
	}
}