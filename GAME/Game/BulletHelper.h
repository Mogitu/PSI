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

class BulletHelper
{
public:
	BulletHelper(IrrlichtDevice *device);
	~BulletHelper();

	void MAKEBODY(IMeshSceneNode* n, btScalar TMass);
	void UpdatePhysics(u32 TDeltaTime);
	void UpdateRender(btRigidBody *TObject);
	void ClearObjects();
	void buildIrrLevel(Level *level);	
	

private:
	list<btRigidBody *> Objects;
	btDiscreteDynamicsWorld *World;
	btDefaultCollisionConfiguration *CollisionConfiguration;
	btBroadphaseInterface *BroadPhase;
	btCollisionDispatcher *Dispatcher;
	btSequentialImpulseConstraintSolver *Solver;
	IrrlichtDevice *device;	
};


#endif BULLETHELPER_H