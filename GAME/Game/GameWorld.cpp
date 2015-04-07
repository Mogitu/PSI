#include "GameWorld.h"
#include "Enemy.h"
#include "Player.h"


GameWorld::GameWorld(BulletHelper *h, IrrlichtDevice *device) :helper(h), device(device)
{

}

GameWorld::GameWorld(BulletHelper *h, IrrlichtDevice *device, InputReceiver *playerInputReceiver) : helper(h), device(device), playerInputReceiver(playerInputReceiver)
{

}

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
		helper->updatePhysics(gameObject->body);

		stringw nodeName = gameObject->node->getName();
		
		if (!gameObject->isAlive || nodeName=="dead")
		{
			gameObject->kill();
			gameObjects.erase(Iterator);
			delete gameObject;
			return;			
		}			
	}
	
	//collision detection
	//TODO: VERY SLOPPY; in its current state this will need a lot of special case checks. Needs to be improved in later sprints.
	int numManifolds = helper->getWorld()->getDispatcher()->getNumManifolds();
	for (int i = 0; i<numManifolds; i++)
	{
		btPersistentManifold* contactManifold = helper->getWorld()->getDispatcher()->getManifoldByIndexInternal(i);
		btCollisionObject* obA = (btCollisionObject*)contactManifold->getBody0();
		btCollisionObject* obB = (btCollisionObject*)contactManifold->getBody1();

		ISceneNode *nodeA =  (ISceneNode*)contactManifold->getBody0()->getUserPointer();
		ISceneNode *nodeB = (ISceneNode*)contactManifold->getBody1()->getUserPointer();		

		std::string nameA = nodeA->getName();
		std::string nameB = nodeB->getName();
		
		//check collisions between enemies and projectiles
		if ((nameB == "Enemy"&&nameA == "Projectile") || (nameA == "Enemy"&&nameB == "Projectile"))
		{					
			int numContacts = contactManifold->getNumContacts();
			for (int j = 0; j<numContacts; j++)
			{
				btManifoldPoint& pt = contactManifold->getContactPoint(j);
				if (pt.getDistance()<0.f)
				{
					const btVector3& ptA = pt.getPositionWorldOnA();
					const btVector3& ptB = pt.getPositionWorldOnB();
					const btVector3& normalOnB = pt.m_normalWorldOnB;
					//std::cout << "Hit" << std::endl;
				}
				ParticleManager::createFullParticleEffect("../Assets/killEnemyEffect.xml", nodeB->getPosition());
				ParticleManager::createFullParticleEffect("../Assets/killEnemyEffect.xml", nodeA->getPosition());
				nodeA->setName("dead");
				nodeB->setName("dead");
				Common::soundEngine->play2D("../Assets/Sounds/explosion.wav");
			}
		}		

		//check collisions between player and enemy
		if ((nameB == "Enemy"&&nameA == "Player") || (nameA == "Enemy"&&nameB == "Player"))
		{
			ParticleManager::createFullParticleEffect("../Assets/playerGotHitEffect.xml", nodeA->getPosition());
			ParticleManager::createFullParticleEffect("../Assets/playerGotHitEffect.xml", nodeB->getPosition());
		}

		//check collisions between player and projectiles
		if ((nameB == "Projectile"&&nameA == "Player") || (nameA == "Projectile"&&nameB == "Player"))
		{
			if (nameA == "Projectile")
			{
				nodeA->setName("dead");

			}
			else if (nameB == "Projectile")
			{
				nodeB->setName("dead");
			}
		}
	}
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

void GameWorld::setPlayer(IGameObject *p)
{
	player = p;
}

IGameObject *GameWorld::getPlayer()
{
	return player;
}

void GameWorld::buildIrrLevel(Level *level)
{
	for (u32 i = 0; i < level->getNodes().size(); i++)
	{
		btRigidBody *tmp = 0;
		std::string name = level->getNodes()[i]->getName();

		ISceneNode *node = level->getNamedNode(name);

		std::string namePrefix = name.substr(0, 2);

		if (namePrefix == DYNAMIC_CUBE)
		{
			ISceneNode *p = (ISceneNode*)level->getNamedNode(name);
			tmp = helper->createCube(p, 50);
			tmp->setRestitution(0.8);
			tmp->setFriction(0.6);
		}
		else if (namePrefix == STATIC_CUBE)
		{
			ISceneNode *p = (ISceneNode*)level->getNamedNode(name);
			tmp = helper->createCube(p, 0);
			tmp->setRestitution(0.2);
			tmp->setFriction(0.3);
		}
		else if (namePrefix == DYNAMIC_SPHERE)
		{
			ISceneNode *p = (ISceneNode*)level->getNamedNode(name);
			tmp = helper->createSphere(p, 50);
			tmp->setRestitution(0.8);
			tmp->setFriction(0.6);
		}
		else if (namePrefix == WORLD)
		{
			ISceneNode *p = (ISceneNode*)level->getNamedNode(name);
			tmp = helper->createTriangleBody(p);
			tmp->setRestitution(0.8);
			tmp->setFriction(0.6);
		}
		else if (namePrefix == PARTICLE)
		{
			ISceneNode *p = (ISceneNode*)level->getNamedNode(name);
			stringw last = core::stringw(name.c_str());
			stringw path = "../Assets/";
			ParticleManager::createFullParticleEffect(path.append(last.subString(4, last.size()).append(".xml")), p->getPosition());
		}		
		else if (namePrefix == ENEMY)
		{		
			IAnimatedMeshSceneNode *p = (IAnimatedMeshSceneNode*)level->getNamedNode(name);
			Enemy* enemy = new Enemy(Common::smgr, Common::irrDriver, helper, this, p, Shape_Type::CAPSULE, 300, p->getPosition(), vector3df(0, 0, 0), vector3df(1, 1, 1));
		}
		else if (namePrefix == PLAYER)
		{
			//This part bugs out, probably a problem in memory allocation in the player class.
			//IAnimatedMeshSceneNode *p = (IAnimatedMeshSceneNode*)level->getNamedNode(name);
			//Player* player = new Player(Common::smgr, Common::irrDriver, helper, this, playerInputReceiver, "../Assets/sydney.md2", "../Assets/sydney.bmp", Shape_Type::CAPSULE, 80, p->getPosition());
		}
		tmp = 0;
	}
}