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

enum Shape_Type
{
	BOX,
	CAPSULE, 
	SPHERE,
	TRIANGLE
};

class BulletHelper
{
public:

	BulletHelper();
	~BulletHelper();

	float gravityMultiplier;
	btRigidBody *createBody(IMeshSceneNode* n, Shape_Type type,btScalar mass);
	void updatePhysics(u32 deltaTime);
	void updateRender(btRigidBody *object);
	void clearObjects();
	void buildIrrLevel(Level *level);		
	btDiscreteDynamicsWorld *getWorld();
	btVector3 extractForwardVector(const btRigidBody *body);
	void deactivateObject(btRigidBody *body);

private:

	const float GRAVITY = -9.8f;
	//constants for objects in a level
	const std::string DYNAMIC_SPHERE = "DS";
	const std::string DYNAMIC_CUBE = "DB";
	const std::string STATIC_SPHERE = "SS";
	const std::string STATIC_CUBE = "SB";
	const std::string WORLD = "WB";
	
	list<btRigidBody *> objects;
	btDiscreteDynamicsWorld *world;
	btDefaultCollisionConfiguration *collisionConfiguration;
	btBroadphaseInterface *broadPhase;
	btCollisionDispatcher *dispatcher;
	btSequentialImpulseConstraintSolver *solver;	
	btRigidBody *createCube(IMeshSceneNode* node, btScalar mass);
	btRigidBody *createSphere(IMeshSceneNode* node, btScalar mass);
	btRigidBody *createTriangleBody(IMeshSceneNode *node);
	btRigidBody *createConvexTriangleBody(IMeshSceneNode *node);
	btRigidBody *createCapsule(IMeshSceneNode *node, btScalar mass);
	btTriangleMesh *ConvertIrrMeshToBulletTriangleMesh(IMesh* mesh, const vector3df& scaling);
};

class CustomContactResultCallback : public btCollisionWorld::ContactResultCallback
{
public:
	//An idea is to pass the constructor a context object where all required variables etc are located.
	CustomContactResultCallback();

	btScalar addSingleResult(btManifoldPoint& cp,
		const btCollisionObjectWrapper* colObj0Wrap,
		int partId0,
		int index0,
		const btCollisionObjectWrapper* colObj1Wrap,
		int partId1,
		int index1);

};


#endif BULLETHELPER_H