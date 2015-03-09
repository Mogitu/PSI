#include "BulletHelper.h"

BulletHelper::BulletHelper()
{
	gravityMultiplier = 10;
	// Initialize bullet
	btDefaultCollisionConfiguration *collisionConfiguration = new btDefaultCollisionConfiguration();
	btBroadphaseInterface *broadPhase = new btAxisSweep3(btVector3(-1000, -1000, -1000), btVector3(1000, 1000, 1000));
	btCollisionDispatcher *dispatcher = new btCollisionDispatcher(collisionConfiguration);
	btSequentialImpulseConstraintSolver *Solver = new btSequentialImpulseConstraintSolver();
	world = new btDiscreteDynamicsWorld(dispatcher, broadPhase, Solver, collisionConfiguration);
	world->setGravity(btVector3(0,GRAVITY*gravityMultiplier,0));
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

void BulletHelper::deactivateObject(btRigidBody *b)
{
	for (list<btRigidBody *>::Iterator Iterator = objects.begin(); Iterator != objects.end(); ++Iterator) {
		btRigidBody *object = *Iterator;
		if (object==b)
		{					
			ISceneNode *node = static_cast<ISceneNode *>(object->getUserPointer());
			node->setVisible(false);
			object->setActivationState(0);
			object->setCollisionFlags(object->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
		}
	}
}


btDiscreteDynamicsWorld *BulletHelper::getWorld()
{
	return world;
}

// Passes bullet's orientation to irrlicht
void BulletHelper::updateRender(btRigidBody *object) {
	ISceneNode *node = static_cast<ISceneNode *>(object->getUserPointer());	

	// Set position
	btVector3 point = object->getCenterOfMassPosition();
	node->setPosition(vector3df((f32)point[0], (f32)point[1], (f32)point[2]));

	// Set rotation
	vector3df euler;
	const btQuaternion& btQuat = object->getOrientation();
	quaternion irrQuat(btQuat.getX(), btQuat.getY(), btQuat.getZ(), btQuat.getW());
	irrQuat.toEuler(euler);
	euler *= RADTODEG;
	node->setRotation(euler);
}

btRigidBody *BulletHelper::createBody(ISceneNode* node,Shape_Type type, btScalar mass) {	
	btRigidBody *body = 0;
	
	switch (type)
	{
		case CAPSULE:
			body = createCapsule(node, mass);
			break;
		case SPHERE:
			body = createSphere(node, mass);
			break;
		case TRIANGLE:
			body = createTriangleBody(node);
			break;
		case BOX:
		default:
			body = createCube(node, mass);
			break;
	}
	
	body->setRestitution(0.8);
	body->setFriction(0.6);
	return body;	
}

// Create a box rigid body
btRigidBody *BulletHelper::createCube(ISceneNode* node, btScalar mass)
{		
	// Set the initial position of the object	
	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(btVector3(node->getPosition().X, node->getPosition().Y, node->getPosition().Z));
	btQuaternion q;
	q.setEulerZYX(node->getRotation().Z*DEGTORAD, node->getRotation().Y*DEGTORAD, node->getRotation().X*DEGTORAD);
	transform.setRotation(q);

	btDefaultMotionState *motionState = new btDefaultMotionState(transform);
	
	// Create the shape	
	btVector3 halfExtents(node->getTransformedBoundingBox().getExtent().X*0.5, node->getTransformedBoundingBox().getExtent().Y*0.5, node->getTransformedBoundingBox().getExtent().Z*0.5);	
	btCollisionShape *shape = new btBoxShape(halfExtents);
	
	// Add mass
	btVector3 localInertia;
	shape->calculateLocalInertia(mass, localInertia);
	// Create the rigid body object
	btRigidBody *rigidBody = new btRigidBody(mass, motionState, shape, localInertia);		
	
	// Store a pointer to the irrlicht node so we can update it later
	rigidBody->setUserPointer((void *)(node));
	// Add it to the world

	world->addRigidBody(rigidBody);
	objects.push_back(rigidBody);

	return rigidBody;
}

btRigidBody *BulletHelper::createCapsule(ISceneNode *node, btScalar mass)
{	
	// Set the initial position of the object	
	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(btVector3(node->getPosition().X, node->getPosition().Y, node->getPosition().Z));
	btQuaternion q;
	q.setEulerZYX(node->getRotation().Z*DEGTORAD, node->getRotation().Y*DEGTORAD, node->getRotation().X*DEGTORAD);
	transform.setRotation(q);

	btDefaultMotionState *motionState = new btDefaultMotionState(transform);

	// Create the shape	
	btScalar radius = node->getTransformedBoundingBox().getExtent().X*0.5;
	btScalar height = node->getTransformedBoundingBox().getExtent().Y*0.5;
	btCapsuleShape *shape = new btCapsuleShape(radius,height);

	// Add mass
	btVector3 localInertia;
	shape->calculateLocalInertia(mass, localInertia);
	// Create the rigid body object
	btRigidBody *rigidBody = new btRigidBody(mass, motionState, shape, localInertia);

	// Store a pointer to the irrlicht node so we can update it later
	rigidBody->setUserPointer((void *)(node));
	// Add it to the world

	world->addRigidBody(rigidBody);
	objects.push_back(rigidBody);
	//std::cout << HalfExtents.getX() << "  " << HalfExtents.getY() << " " << HalfExtents.getZ()<< " "<<  Node->getName() << std::endl;
	std::cout << node->getScale().Y << std::endl;
	return rigidBody;
}


btRigidBody *BulletHelper::createTriangleBody(ISceneNode *node)
{	
	btTriangleMesh* triMesh = ConvertIrrMeshToBulletTriangleMesh(getMesh(node), node->getScale());

	btBvhTriangleMeshShape* shape = new btBvhTriangleMeshShape(triMesh,true);	

	btQuaternion quat;
	quat.setEulerZYX(node->getRotation().Z*DEGTORAD, node->getRotation().Y*DEGTORAD, node->getRotation().X*DEGTORAD);

	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(btVector3(node->getAbsolutePosition().X, node->getAbsolutePosition().Y, node->getAbsolutePosition().Z));
	transform.setRotation(quat);

	btDefaultMotionState *motionState = new btDefaultMotionState(transform);	

	btRigidBody* rigidBody = new btRigidBody(0, motionState, shape);
	
	rigidBody->setUserPointer((void *)(node));
	rigidBody->setActivationState(DISABLE_DEACTIVATION);

	world->addRigidBody(rigidBody);
	objects.push_back(rigidBody);

	return rigidBody;
}

btRigidBody *BulletHelper::createConvexTriangleBody(ISceneNode *node)
{	
	// Set the initial position of the object
	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(btVector3(node->getAbsolutePosition().X, node->getAbsolutePosition().Y, node->getAbsolutePosition().Z));
	btQuaternion btQuat;
	btQuat.setEulerZYX(node->getRotation().Z*DEGTORAD, node->getRotation().Y*DEGTORAD, node->getRotation().X*DEGTORAD);
	transform.setRotation(btQuat);

	btDefaultMotionState *motionState = new btDefaultMotionState(transform);
	// Create the shape
	btVector3 HalfExtents(node->getTransformedBoundingBox().getExtent().X*0.5, node->getTransformedBoundingBox().getExtent().Y*0.5, node->getTransformedBoundingBox().getExtent().Z*0.5);

	btTriangleMesh* trimesh = ConvertIrrMeshToBulletTriangleMesh(getMesh(node), node->getScale());
	btConvexShape* shape = new btConvexTriangleMeshShape(trimesh);
	// Add mass
	btVector3 localInertia;
	shape->calculateLocalInertia(0, localInertia);
	// Create the rigid body object
	btRigidBody *RigidBody = new btRigidBody(0, motionState, shape, localInertia);

	// Store a pointer to the irrlicht node so we can update it later
	RigidBody->setUserPointer((void *)(node));
	// Add it to the world
	world->addRigidBody(RigidBody);
	objects.push_back(RigidBody);	
	return RigidBody;	
}

btTriangleMesh *BulletHelper::ConvertIrrMeshToBulletTriangleMesh(IMesh* mesh, const vector3df& scaling)
{
	btTriangleMesh* tMesh = new btTriangleMesh();

	irr::u32 MBCount = mesh->getMeshBufferCount();

	for (irr::u32 m = 0; m < MBCount; m++)
	{
		irr::scene::IMeshBuffer* MB = mesh->getMeshBuffer(m);

		irr::video::S3DVertex* Vertices = (irr::video::S3DVertex*)MB->getVertices();
		irr::u16* Indices = MB->getIndices();

		for (irr::u32 i = 0; i < MB->getIndexCount(); i += 3)
		{
			irr::core::vector3df Tri1Pos = Vertices[Indices[i]].Pos;
			irr::core::vector3df Tri2Pos = Vertices[Indices[i + 1]].Pos;
			irr::core::vector3df Tri3Pos = Vertices[Indices[i + 2]].Pos;

			tMesh->addTriangle(btVector3(Tri1Pos.X*scaling.X, Tri1Pos.Y*scaling.Y, Tri1Pos.Z*scaling.Z), btVector3(Tri2Pos.X*scaling.X, Tri2Pos.Y*scaling.Y, Tri2Pos.Z*scaling.Z), btVector3(Tri3Pos.X*scaling.X, Tri3Pos.Y*scaling.Y, Tri3Pos.Z*scaling.Z));
		}
	}
	return tMesh;
};


btRigidBody *BulletHelper::createSphere(ISceneNode* node, btScalar mass)
{
	// Set the initial position of the object
	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(btVector3(node->getAbsolutePosition().X, node->getAbsolutePosition().Y, node->getAbsolutePosition().Z));

	btDefaultMotionState *motionState = new btDefaultMotionState(transform);
	// Create the shape	
	btVector3 halfExtents(node->getTransformedBoundingBox().getExtent().X*0.5, node->getTransformedBoundingBox().getExtent().Y*0.5, node->getTransformedBoundingBox().getExtent().Z*0.5);
	btCollisionShape *shape = new btSphereShape(halfExtents.getX());
	// Add mass
	btVector3 localInertia;
	shape->calculateLocalInertia(mass, localInertia);
	// Create the rigid body object
	btRigidBody *rigidBody = new btRigidBody(mass, motionState, shape, localInertia);	

	// Store a pointer to the irrlicht node so we can update it later
	rigidBody->setUserPointer((void *)(node));
	// Add it to the world
	world->addRigidBody(rigidBody);
	objects.push_back(rigidBody);
	return rigidBody;
}

// Runs the physics simulation.
// - TDeltaTime tells the simulation how much time has passed since the last frame so the simulation can run independently of the frame rate.
void BulletHelper::updatePhysics(u32 TDeltaTime) {

	world->stepSimulation(TDeltaTime * 0.001f, 60);

	// Relay the object's orientation to irrlicht
	for (list<btRigidBody *>::Iterator Iterator = objects.begin(); Iterator != objects.end(); ++Iterator) 
	{ 
		//updateRender(*Iterator);	
	}
}

void BulletHelper::buildIrrLevel(Level *level)
{	
	for (int i = 0; i < level->getNodes().size(); i++)
	{
		btRigidBody *tmp = 0;
		std::string name = level->getNodes()[i]->getName();

		ISceneNode *node = level->getNamedNode(name);

		std::string namePrefix = name.substr(0, 2);		
		
		if (namePrefix == DYNAMIC_CUBE)
		{
			ISceneNode *p = (ISceneNode*)level->getNamedNode(name);			
			tmp=createCube(p, 50);			
			tmp->setRestitution(0.8);
			tmp->setFriction(0.6);
		}
		else if (namePrefix == STATIC_CUBE)
		{
			ISceneNode *p = (ISceneNode*)level->getNamedNode(name);
			tmp=createCube(p, 0);
			tmp->setRestitution(0.2);
			tmp->setFriction(0.3);
		}
		else if (namePrefix == DYNAMIC_SPHERE)
		{
			ISceneNode *p = (ISceneNode*)level->getNamedNode(name);
			tmp = createSphere(p, 50);		
			tmp->setRestitution(0.8);
			tmp->setFriction(0.6);
		}
		else if (namePrefix == WORLD)
		{
			ISceneNode *p = (ISceneNode*)level->getNamedNode(name);
			tmp = createTriangleBody(p);		
			tmp->setRestitution(0.8);
			tmp->setFriction(0.6);
		}
		tmp = 0;
	}
}

IMesh* BulletHelper::getMesh(ISceneNode* node)
{
	if (node->getType() == ESCENE_NODE_TYPE::ESNT_MESH)
		return static_cast<IMeshSceneNode*>(node)->getMesh();
	else
		return static_cast<IAnimatedMeshSceneNode*>(node)->getMesh();
}

btVector3 BulletHelper::extractForwardVector(const btRigidBody *b)
{
	btScalar matrix[16];
	b->getWorldTransform().getOpenGLMatrix(matrix);
	btVector3 forward = btVector3(matrix[0], matrix[1], matrix[2]);
	return forward;
}

CustomContactResultCallback::CustomContactResultCallback()
{

}

btScalar CustomContactResultCallback::addSingleResult(btManifoldPoint& cp,
	const btCollisionObjectWrapper* colObj0Wrap,
	int partId0,
	int index0,
	const btCollisionObjectWrapper* colObj1Wrap,
	int partId1,
	int index1)
{			
	
	//Response handling will be done in here.
	return 1;
}