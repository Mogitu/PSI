#include "BulletHelper.h"

BulletHelper::BulletHelper(IrrlichtDevice *device) :device(device)
{
	// Initialize bullet
	btDefaultCollisionConfiguration *CollisionConfiguration = new btDefaultCollisionConfiguration();
	btBroadphaseInterface *BroadPhase = new btAxisSweep3(btVector3(-1000, -1000, -1000), btVector3(1000, 1000, 1000));
	btCollisionDispatcher *Dispatcher = new btCollisionDispatcher(CollisionConfiguration);
	btSequentialImpulseConstraintSolver *Solver = new btSequentialImpulseConstraintSolver();
	World = new btDiscreteDynamicsWorld(Dispatcher, BroadPhase, Solver, CollisionConfiguration);
}

BulletHelper::~BulletHelper()
{
	delete World;
	delete Solver;
	delete Dispatcher;
	delete BroadPhase;
	delete CollisionConfiguration;
	ClearObjects();
}


// Removes all objects from the world
void BulletHelper::ClearObjects() {

	for (list<btRigidBody *>::Iterator Iterator = Objects.begin(); Iterator != Objects.end(); ++Iterator) {
		btRigidBody *Object = *Iterator;

		// Delete irrlicht node
		ISceneNode *Node = static_cast<ISceneNode *>(Object->getUserPointer());
		Node->remove();

		// Remove the object from the world
		World->removeRigidBody(Object);

		// Free memory
		delete Object->getMotionState();
		delete Object->getCollisionShape();
		delete Object;
	}
	Objects.clear();
}

// Passes bullet's orientation to irrlicht
void BulletHelper::UpdateRender(btRigidBody *TObject) {
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
void BulletHelper::MAKEBODY(IMeshSceneNode* n, btScalar TMass) {
	IMeshSceneNode *Node = n;
	Node->setMaterialFlag(EMF_LIGHTING, 1);
	Node->setMaterialFlag(EMF_NORMALIZE_NORMALS, true);
	Node->setMaterialTexture(0, device->getVideoDriver()->getTexture("../Assets/Sydney.bmp"));
	Node->setDebugDataVisible(EDS_BBOX);

	// Set the initial position of the object
	btTransform Transform;
	Transform.setIdentity();
	Transform.setOrigin(btVector3(Node->getPosition().X, Node->getPosition().Y, Node->getPosition().Z));

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
	World->addRigidBody(RigidBody);
	Objects.push_back(RigidBody);
}

// Runs the physics simulation.
// - TDeltaTime tells the simulation how much time has passed since the last frame so the simulation can run independently of the frame rate.
void BulletHelper::UpdatePhysics(u32 TDeltaTime) {

	World->stepSimulation(TDeltaTime * 0.001f, 60);

	// Relay the object's orientation to irrlicht
	for (list<btRigidBody *>::Iterator Iterator = Objects.begin(); Iterator != Objects.end(); ++Iterator) {

		UpdateRender(*Iterator);
	}
}

void BulletHelper::buildIrrLevel(Level *level)
{
	for (int i = 0; i < level->getNodes().size(); i++)
	{
		std::string name = level->getNodes()[i]->getName();

		ISceneNode *node = level->getNamedNode(name);

		std::string b = name.substr(0, 3);
		std::cout << b << std::endl;

		if (b == "BOX")
		{
			IMeshSceneNode *p = (IMeshSceneNode*)level->getNamedNode(name);
			MAKEBODY(p, 1);
		}
		else if (b == "WAL")
		{
			IMeshSceneNode *p = (IMeshSceneNode*)level->getNamedNode(name);
			MAKEBODY(p, 0);
		}
	}
}