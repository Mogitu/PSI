#include "BulletHelper.h"

BulletHelper::BulletHelper()
{
	// Initialize bullet
	btDefaultCollisionConfiguration *collisionConfiguration = new btDefaultCollisionConfiguration();
	btBroadphaseInterface *broadPhase = new btAxisSweep3(btVector3(-1000, -1000, -1000), btVector3(1000, 1000, 1000));
	btCollisionDispatcher *dispatcher = new btCollisionDispatcher(collisionConfiguration);
	btSequentialImpulseConstraintSolver *Solver = new btSequentialImpulseConstraintSolver();
	world = new btDiscreteDynamicsWorld(dispatcher, broadPhase, Solver, collisionConfiguration);
}

BulletHelper::~BulletHelper()
{
	delete world;
	delete solver;
	delete dispatcher;
	delete broadPhase;
	delete collisionConfiguration;
	clearObjects();
}


// Removes all objects from the world
void BulletHelper::clearObjects() {

	for (list<btRigidBody *>::Iterator Iterator = objects.begin(); Iterator != objects.end(); ++Iterator) {
		btRigidBody *Object = *Iterator;

		// Delete irrlicht node
		ISceneNode *Node = static_cast<ISceneNode *>(Object->getUserPointer());
		Node->remove();

		// Remove the object from the world
		world->removeRigidBody(Object);

		// Free memory
		delete Object->getMotionState();
		delete Object->getCollisionShape();
		delete Object;
	}
	objects.clear();
}

// Passes bullet's orientation to irrlicht
void BulletHelper::updateRender(btRigidBody *TObject) {
	ISceneNode *Node = static_cast<ISceneNode *>(TObject->getUserPointer());

	// Set position
	btVector3 Point = TObject->getCenterOfMassPosition();
	Node->setPosition(vector3df((f32)Point[0], (f32)Point[1], (f32)Point[2]));

	// Set rotation
	vector3df Euler;
	const btQuaternion& TQuat = TObject->getOrientation();
	quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
	q.toEuler(Euler);
	Euler *= RADTODEG;
	Node->setRotation(Euler);
}

// Create a box rigid body
btRigidBody *BulletHelper::createBody(IMeshSceneNode* Node, btScalar TMass) {	
	btRigidBody *b = 0;	

	b = createCube(Node, TMass);

	return b;
	
}

btRigidBody *BulletHelper::createCube(IMeshSceneNode* Node, btScalar TMass)
{
	// Set the initial position of the object
	btTransform Transform;
	Transform.setIdentity();
	Transform.setOrigin(btVector3(Node->getAbsolutePosition().X, Node->getAbsolutePosition().Y, Node->getAbsolutePosition().Z));
	btDefaultMotionState *MotionState = new btDefaultMotionState(Transform);
	// Create the shape
	btVector3 HalfExtents(Node->getTransformedBoundingBox().getExtent().X*0.5, Node->getTransformedBoundingBox().getExtent().Y*0.5, Node->getTransformedBoundingBox().getExtent().Z*0.5);

	btCollisionShape *Shape = new btBoxShape(HalfExtents);
	// Add mass
	btVector3 LocalInertia;
	Shape->calculateLocalInertia(TMass, LocalInertia);
	// Create the rigid body object
	btRigidBody *RigidBody = new btRigidBody(TMass, MotionState, Shape, LocalInertia);
	// Store a pointer to the irrlicht node so we can update it later
	RigidBody->setUserPointer((void *)(Node));
	// Add it to the world
	world->addRigidBody(RigidBody);
	objects.push_back(RigidBody);

	return RigidBody;
}

btRigidBody *BulletHelper::createSphere(IMeshSceneNode* Node, btScalar TMass)
{
	// Set the initial position of the object
	btTransform Transform;
	Transform.setIdentity();
	Transform.setOrigin(btVector3(Node->getAbsolutePosition().X, Node->getAbsolutePosition().Y, Node->getAbsolutePosition().Z));
	btDefaultMotionState *MotionState = new btDefaultMotionState(Transform);
	// Create the shape	
	btVector3 HalfExtents(Node->getTransformedBoundingBox().getExtent().X*0.5, Node->getTransformedBoundingBox().getExtent().Y*0.5, Node->getTransformedBoundingBox().getExtent().Z*0.5);
	btCollisionShape *Shape = new btSphereShape(HalfExtents.getX());
	// Add mass
	btVector3 LocalInertia;
	Shape->calculateLocalInertia(TMass, LocalInertia);
	// Create the rigid body object
	btRigidBody *RigidBody = new btRigidBody(TMass, MotionState, Shape, LocalInertia);
	// Store a pointer to the irrlicht node so we can update it later
	RigidBody->setUserPointer((void *)(Node));
	// Add it to the world
	world->addRigidBody(RigidBody);
	objects.push_back(RigidBody);
	return RigidBody;
}

// Runs the physics simulation.
// - TDeltaTime tells the simulation how much time has passed since the last frame so the simulation can run independently of the frame rate.
void BulletHelper::updatePhysics(u32 TDeltaTime) {

	world->stepSimulation(TDeltaTime * 0.001f, 60);

	// Relay the object's orientation to irrlicht
	for (list<btRigidBody *>::Iterator Iterator = objects.begin(); Iterator != objects.end(); ++Iterator) {

		updateRender(*Iterator);
	}
}

void BulletHelper::buildIrrLevel(Level *level)
{
	
	for (int i = 0; i < level->getNodes().size(); i++)
	{
		btRigidBody *tmp = 0;
		std::string name = level->getNodes()[i]->getName();

		ISceneNode *node = level->getNamedNode(name);

		std::string b = name.substr(0, 2);		

		if (b == DYNAMIC_CUBE)
		{
			IMeshSceneNode *p = (IMeshSceneNode*)level->getNamedNode(name);			
			tmp=createCube(p, 1);
		}
		else if (b == STATIC_CUBE)
		{
			IMeshSceneNode *p = (IMeshSceneNode*)level->getNamedNode(name);
			tmp=createCube(p, 0);
		}
		else if (b ==DYNAMIC_SPHERE)
		{
			IMeshSceneNode *p = (IMeshSceneNode*)level->getNamedNode(name);
			tmp = createSphere(p, 1);
		}
		tmp = 0;
	}	
}