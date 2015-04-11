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
	btRigidBody *createBody(ISceneNode* n, Shape_Type type,btScalar mass);
	void updatePhysics(btRigidBody *body);	
	void clearObjects();
	void buildIrrLevel(Level *level);		
	btDiscreteDynamicsWorld *getWorld();
	btVector3 extractForwardVector(const btRigidBody *body);
	btVector3 extractRightVector(const btRigidBody *body);
	btRigidBody *createCube(ISceneNode* node, btScalar mass);
	btRigidBody *createSphere(ISceneNode* node, btScalar mass);
	btRigidBody *createTriangleBody(ISceneNode *node);
	btRigidBody *createConvexTriangleBody(ISceneNode *node);
	btRigidBody *createCapsule(ISceneNode *node, btScalar mass);
	btTriangleMesh *ConvertIrrMeshToBulletTriangleMesh(IMesh* mesh, const vector3df& scaling);

private:
	const float GRAVITY = -9.8f;
	//constants for objects in a level
	const std::string DYNAMIC_SPHERE = "DS";
	const std::string DYNAMIC_CUBE = "DB";
	const std::string STATIC_SPHERE = "SS";
	const std::string STATIC_CUBE = "SB";
	const std::string WORLD = "WB";
	const std::string PARTICLE = "PS";
	const std::string ENEMY = "EN";
	
	list<btRigidBody *> objects;
	btDiscreteDynamicsWorld *world;
	btDefaultCollisionConfiguration *collisionConfiguration;
	btBroadphaseInterface *broadPhase;
	btCollisionDispatcher *dispatcher;
	btSequentialImpulseConstraintSolver *solver;	

	IMesh* getMesh(ISceneNode* node);
};

#endif BULLETHELPER_H