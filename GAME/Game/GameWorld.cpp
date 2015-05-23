#include "GameWorld.h"
#include "Enemy.h"
#include "Player.h"
#include "WeaponPickup.h"

GameWorld::GameWorld(BulletHelper *h, IrrlichtDevice *device) :helper(h), device(device)
{
	gameState = PLAYING;
	menu = new Menu(device, "../Assets/textures/menu.png");
}

GameWorld::GameWorld(BulletHelper *h, IrrlichtDevice *device, InputReceiver *playerInputReceiver) : helper(h), device(device), playerInputReceiver(playerInputReceiver)
{
	gameState = PLAYING;
	menu = new Menu(device,"../Assets/textures/menu.png");
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
	//only update when game is in play state
	if (gameState==PLAYING)
	{
		//Loop all objects in the world and update their physics
		for (core::list<IGameObject *>::Iterator Iterator = gameObjects.begin(); Iterator != gameObjects.end(); ++Iterator)
		{
			IGameObject* gameObject = *Iterator;
			//gets the name of the node
			stringw nodeName = gameObject->node->getName();
			//if object not alive or name is dead we kill/clean it.
			if ((!gameObject->isAlive || nodeName == "dead"))
			{
				gameObject->kill();				
				//gameObjects.erase(Iterator);
				//delete gameObject;				
			}
			else
			{
				gameObject->Update(frameDeltaTime);
				helper->updatePhysics(gameObject->body);
			}

			//Flocking Separation
			if (gameObject->getType() == GameObjectType::ENEMY)
			{
				Enemy* e = dynamic_cast<Enemy*>(gameObject);
				bool isAvoiding = false;
				for (core::list<IGameObject *>::Iterator i = gameObjects.begin(); i != gameObjects.end(); ++i)
				{
					IGameObject* gb = *i;

					if (gb->getType() == GameObjectType::PROJECTILE && (std::string)gb->node->getName() == "PlayerProjectile")
					{
						Projectile* projectile = dynamic_cast<Projectile*>(gb);

						vector3df dist = projectile->node->getPosition() - e->node->getPosition();

						if (dist.getLength() <= 60)
						{
							isAvoiding = true;
							e->addAvoidance(dist);
						}					
					}
				}

				if (!isAvoiding)
					e->resetAvoidance();
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

			ISceneNode *nodeA = (ISceneNode*)contactManifold->getBody0()->getUserPointer();
			ISceneNode *nodeB = (ISceneNode*)contactManifold->getBody1()->getUserPointer();

			std::string nameA = nodeA->getName();
			std::string nameB = nodeB->getName();

			//check collisions between enemies and projectiles
			if ((nameB == "Enemy"&&nameA == "PlayerProjectile") || (nameA == "Enemy"&&nameB == "PlayerProjectile"))
			{
				Player *p = (Player*)getPlayer();				
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
					ParticleManager::createFullParticleEffect("../Assets/bloodsplat.xml", nodeB->getPosition());
					ParticleManager::createFullParticleEffect("../Assets/bloodsplat.xml", nodeA->getPosition());
					nodeA->setName("dead");
					nodeB->setName("dead");
					Common::soundEngine->play2D("../Assets/Sounds/splat.wav");
					p->increaseScore(10);
				}			
			}

			//if player reaches the end node
			if ((nameA == "SB_END"&&nameB == "Player") || (nameB == "SB_END"&&nameA == "Player"))
			{				
				int numContacts = contactManifold->getNumContacts();
				for (int j = 0; j<numContacts; j++)
				{
					btManifoldPoint& pt = contactManifold->getContactPoint(j);
					if (pt.getDistance()<=0.f)
					{
						gameState = LEVELCOMPLETE;						
					}					
				}
			}

			//check collisions between player and enemy
			if ((nameB == "Enemy" && nameA == "Player") || (nameA == "Enemy" && nameB == "Player"))
			{
				int numContacts = contactManifold->getNumContacts();
				for (int j = 0; j<numContacts; j++)
				{
					btManifoldPoint& pt = contactManifold->getContactPoint(j);
					if (pt.getDistance() <= 0.f)
					{
						ParticleManager::createFullParticleEffect("../Assets/playerGotHitEffect.xml", nodeA->getPosition());
						ParticleManager::createFullParticleEffect("../Assets/playerGotHitEffect.xml", nodeB->getPosition());
					}
				}				
			}

			//check collisions between player and projectiles
			if ((nameB == "EnemyProjectile"&&nameA == "Player") || (nameA == "EnemyProjectile"&&nameB == "Player"))
			{
				Player *p = (Player*)getPlayer();				
				
				if (nameA == "EnemyProjectile")
				{
					nodeA->setName("dead");
				}
				else if (nameB == "EnemyProjectile")
				{
					nodeB->setName("dead");
				}				
				p->takeDamage(10);								
			}				


			//check collisions between player and weapon pickups..
			if ((nameB == "IceWeapon"&&nameA == "Player") || (nameA == "IceWeapon"&&nameB == "Player"))
			{
				std::cout << "Ice weapon picked up" << std::endl;				
				if (nameB=="IceWeapon")
				{
					nodeB->setName("dead");
				}
				else{
					nodeA->setName("dead");
				}
			}

			if ((nameB == "FireWeapon"&&nameA == "Player") || (nameA == "FireWeapon"&&nameB == "Player"))
			{
				std::cout << "Fire weapon picked up" << std::endl;
				if (nameB == "FireWeapon")
				{
					nodeB->setName("dead");
				}
				else{
					nodeA->setName("dead");
				}
			}

			if ((nameB == "WindWeapon"&&nameA == "Player") || (nameA == "WindWeapon"&&nameB == "Player"))
			{
				std::cout << "Wind weapon picked up" << std::endl;
				if (nameB == "WindWeapon")
				{
					nodeB->setName("dead");
				}
				else{
					nodeA->setName("dead");
				}
			}
		}//End collision detection
	}
	else if (gameState==PAUSED)
	{
		menu->draw();		
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

//loads a level into the world 
void GameWorld::buildIrrLevel(Level *level)
{
	//Loop all nodes in the scene 
	for (u32 i = 0; i < level->getNodes().size(); i++)
	{
		//create a temporary body
		btRigidBody *tmp = 0;
		//retreive the full name of the current node
		std::string name = level->getNodes()[i]->getName();		

		//get the prefix to check against
		std::string namePrefix = name.substr(0, 2);

		//create a suitable rigid body  depending on the prefix
		if (namePrefix == DYNAMIC_CUBE)
		{
			//We know the prefix, so now we can create a scene node 
			ISceneNode *node = (ISceneNode*)level->getNamedNode(name);
			//create the body from the node and a given mass
			tmp = helper->createCube(node, 50);
			//set some defaults
			tmp->setRestitution(0.8);
			tmp->setFriction(0.6);
		}
		else if (namePrefix == STATIC_CUBE)
		{
			ISceneNode *node = (ISceneNode*)level->getNamedNode(name);
			tmp = helper->createCube(node, 0);
			tmp->setRestitution(0.2);
			tmp->setFriction(0.3);
		}
		else if (namePrefix == DYNAMIC_SPHERE)
		{
			ISceneNode *node = (ISceneNode*)level->getNamedNode(name);
			tmp = helper->createSphere(node, 50);
			tmp->setRestitution(0.8);
			tmp->setFriction(0.6);
		}
		//Create world geometry, simple boxes are often not enough for more complex scenes so we create a convex shape.
		else if (namePrefix == WORLD)
		{
			ISceneNode *node = (ISceneNode*)level->getNamedNode(name);
			tmp = helper->createConvexTriangleBody(node);
			tmp->setRestitution(0.2);
			tmp->setFriction(0.3);
		}
		//Create a particle
		else if (namePrefix == PARTICLE)
		{
			ISceneNode *node = (ISceneNode*)level->getNamedNode(name);
			stringw last = core::stringw(name.c_str());
			stringw path = "../Assets/";			
			ParticleManager::createFullParticleEffect(path.append(last.subString(3, last.size()).append(".xml")), node->getPosition());
		}	
		//The enemy alreay knows how to construct its rigidbody so we only create a new instance of the enemy from the current node.
		else if (namePrefix == ENEMY)
		{		
			IAnimatedMeshSceneNode *node = (IAnimatedMeshSceneNode*)level->getNamedNode(name);
			Enemy* enemy = new Enemy(Common::smgr, Common::irrDriver, helper, this, node, Shape_Type::CAPSULE, 300, node->getPosition(), vector3df(0, 0, 0), vector3df(1, 1, 1));
			//enemy->node->setName("EN");
		}	
		else if (namePrefix == FIREENEMY)
		{
			IAnimatedMeshSceneNode *node = (IAnimatedMeshSceneNode*)level->getNamedNode(name);
			Enemy* enemy = new Enemy(Common::smgr, Common::irrDriver, helper, this, node, Shape_Type::CAPSULE, 300, node->getPosition(), vector3df(0, 0, 0), vector3df(1, 1, 1));
			//enemy->node->setName("EN");
		}
		else if (namePrefix == WINDENEMY)
		{
			IAnimatedMeshSceneNode *node = (IAnimatedMeshSceneNode*)level->getNamedNode(name);
			Enemy* enemy = new Enemy(Common::smgr, Common::irrDriver, helper, this, node, Shape_Type::CAPSULE, 300, node->getPosition(), vector3df(0, 0, 0), vector3df(1, 1, 1));
			//enemy->node->setName("EN");
		}
		else if (namePrefix == ICEENEMY)
		{
			IAnimatedMeshSceneNode *node = (IAnimatedMeshSceneNode*)level->getNamedNode(name);
			Enemy* enemy = new Enemy(Common::smgr, Common::irrDriver, helper, this, node, Shape_Type::CAPSULE, 300, node->getPosition(), vector3df(0, 0, 0), vector3df(1, 1, 1));
			//enemy->node->setName("EN");
		}
		else if (namePrefix ==FIREWEAPON)
		{
			//spawn fire weapon
			ISceneNode *node = (ISceneNode*)level->getNamedNode(name);
			WeaponPickup *pickUp = new WeaponPickup("FireWeapon", helper,node);
			this->addGameObject(pickUp);

		}
		else if (namePrefix == ICEWEAPON)
		{
			//spawn ice weapon
			ISceneNode *node = (ISceneNode*)level->getNamedNode(name);
			WeaponPickup *pickUp = new WeaponPickup("IceWeapon",helper, node);
			this->addGameObject(pickUp);
		}
		else if (namePrefix == WINDWEAPON)
		{
			//spawn windweapon
			ISceneNode *node = (ISceneNode*)level->getNamedNode(name);
			WeaponPickup *pickUp = new WeaponPickup("WindWeapon",helper, node);
			this->addGameObject(pickUp);
		}
		//Done with the tempory body
		tmp = 0;
		delete tmp;
	}
}

void GameWorld::restart(Level *level)
{
	/*
	for (int i = 0; i < level->getNodes().size(); i++)
	{
		ISceneNode *node = level->getNodes()[i];
		//retreive the full name of the current node
		std::string name = node->getName();
		
		if (name=="Enemy")
		{
			std::cout << name << std::endl;
			node->setName("dead");
		}
		//get the prefix to check against
		
	}
	*/
	/*
	for (core::list<IGameObject *>::Iterator Iterator = gameObjects.begin(); Iterator != gameObjects.end(); ++Iterator)
	{
		IGameObject* gameObject = *Iterator;
		std::string name = gameObject->node->getName();

	
		if (name== "Enemy")
		{				
		
			//gameObject->node->setName("dead");
			gameObject->node->setName("dead");
		}		
	}

	//std::cout << "enee" << std::endl;
	for (core::list<IGameObject *>::Iterator Iterator = gameObjects.begin(); Iterator != gameObjects.end(); ++Iterator)
	{
		IGameObject* gameObject = *Iterator;
		std::string name = gameObject->node->getName();		
		if (name== "dead")
		{		
			//gameObject->node->setName("Enemy");
			
		}
	}

	*/
	gameState == PLAYING;
}