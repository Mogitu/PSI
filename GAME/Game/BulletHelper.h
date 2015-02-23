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
const std::string WORLD = "WB";

class BulletHelper
{
public:
	BulletHelper();
	~BulletHelper();

	btRigidBody *createBody(IMeshSceneNode* n, btScalar mass);
	void updatePhysics(u32 deltaTime);
	void updateRender(btRigidBody *object);
	void clearObjects();
	void buildIrrLevel(Level *level);		

private:
	list<btRigidBody *> objects;
	btDiscreteDynamicsWorld *world;
	btDefaultCollisionConfiguration *collisionConfiguration;
	btBroadphaseInterface *broadPhase;
	btCollisionDispatcher *dispatcher;
	btSequentialImpulseConstraintSolver *solver;	
	btRigidBody *createCube(IMeshSceneNode* node, btScalar mass);
	btRigidBody *createSphere(IMeshSceneNode* node, btScalar mass);
	btRigidBody *createTriangleBody(IMeshSceneNode *node);
	btTriangleMesh *ConvertIrrMeshToBulletTriangleMesh(IMesh* mesh, const vector3df& scaling);
};


#endif BULLETHELPER_H