#ifndef BULLETHELPER_H
#define BULLETHELPER_H

#include <irrlicht.h>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Level.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

const std::string DYNAMIC_SPHERE = "DS";
const std::string DYNAMIC_CUBE ="DB";
const std::string STATIC_SPHERE ="SS";
const std::string STATIC_CUBE = "SB";

class BulletHelper
{
public:
	BulletHelper();
	~BulletHelper();

	btRigidBody *createBody(IMeshSceneNode* n, btScalar TMass);
	void updatePhysics(u32 TDeltaTime);
	void updateRender(btRigidBody *TObject);
	void clearObjects();
	void buildIrrLevel(Level *level);		

private:
	list<btRigidBody *> objects;
	btDiscreteDynamicsWorld *world;
	btDefaultCollisionConfiguration *collisionConfiguration;
	btBroadphaseInterface *broadPhase;
	btCollisionDispatcher *dispatcher;
	btSequentialImpulseConstraintSolver *solver;	
	btRigidBody *createCube(IMeshSceneNode* n, btScalar TMass);
	btRigidBody *createSphere(IMeshSceneNode* n, btScalar TMass);
};


#endif BULLETHELPER_H