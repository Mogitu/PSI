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


btRigidBody *BulletHelper::createBody(IMeshSceneNode* Node, btScalar TMass) {	
	btRigidBody *b = 0;	
	b = createCube(Node, TMass);
	return b;	
}

// Create a box rigid body
btRigidBody *BulletHelper::createCube(IMeshSceneNode* Node, btScalar TMass)
{	
	Node->setDebugDataVisible(EAC_BOX);
	// Set the initial position of the object	
	btTransform Transform;
	Transform.setIdentity();	
	Transform.setOrigin(btVector3(Node->getAbsolutePosition().X, Node->getAbsolutePosition().Y, Node->getAbsolutePosition().Z));		
	btQuaternion q;
	q.setEulerZYX(Node->getRotation().Z*DEGTORAD, Node->getRotation().Y*DEGTORAD, Node->getRotation().X*DEGTORAD);
	Transform.setRotation(q);

	btDefaultMotionState *MotionState = new btDefaultMotionState(Transform);	
	
	// Create the shape	
	btVector3 HalfExtents(Node->getTransformedBoundingBox().getExtent().X*0.5, Node->getTransformedBoundingBox().getExtent().Y*0.5, Node->getTransformedBoundingBox().getExtent().Z*0.5);
	HalfExtents.rotate(btVector3(0, 0, 1), Node->getRotation().Z);
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
	//std::cout << HalfExtents.getX() << "  " << HalfExtents.getY() << " " << HalfExtents.getZ()<< " "<<  Node->getName() << std::endl;
	std::cout << Node->getScale().Y << std::endl;
	return RigidBody;
}

btRigidBody *BulletHelper::createTriangleBody(IMeshSceneNode *Node)
{
	/*
	Node->setDebugDataVisible(EAC_BOX);
	// Set the initial position of the object	
	btTransform Transform;
	Transform.setIdentity();
	Transform.setOrigin(btVector3(Node->getAbsolutePosition().X, Node->getAbsolutePosition().Y, Node->getAbsolutePosition().Z));
	btQuaternion q;
	q.setEulerZYX(Node->getRotation().Z*DEGTORAD, Node->getRotation().Y*DEGTORAD, Node->getRotation().X*DEGTORAD);
	Transform.setRotation(q);

	btDefaultMotionState *MotionState = new btDefaultMotionState(Transform);

	// Create the shape	
	btVector3 HalfExtents(Node->getTransformedBoundingBox().getExtent().X*0.5, Node->getTransformedBoundingBox().getExtent().Y*0.5, Node->getTransformedBoundingBox().getExtent().Z*0.5);
	

	btTriangleMesh* trimesh = ConvertIrrMeshToBulletTriangleMesh(Node->getMesh(), Node->getScale());
	btConvexShape* Shape = new btConvexTriangleMeshShape(trimesh);

	// Add mass
	btVector3 LocalInertia;
	Shape->calculateLocalInertia(0, LocalInertia);
	// Create the rigid body object
	btRigidBody *RigidBody = new btRigidBody(0, MotionState, Shape, LocalInertia);

	// Store a pointer to the irrlicht node so we can update it later
	RigidBody->setUserPointer((void *)(Node));
	// Add it to the world

	world->addRigidBody(RigidBody);
	objects.push_back(RigidBody);	
	std::cout << Node->getScale().Y << std::endl;
	return RigidBody;
	*/
	
	btTriangleMesh* trimesh = ConvertIrrMeshToBulletTriangleMesh(Node->getMesh(), Node->getScale());

	btBvhTriangleMeshShape* hull = new btBvhTriangleMeshShape(trimesh,true);
	hull->setUserPointer(hull);

	btVector3 localInertia(0, 0, 0);
	//hull->calculateLocalInertia(0, localInertia);

	btQuaternion quat;
	quat.setEulerZYX(Node->getRotation().Z*DEGTORAD, Node->getRotation().Y*DEGTORAD, Node->getRotation().X*DEGTORAD);

	btTransform Transform2;
	Transform2.setIdentity();
	Transform2.setOrigin(btVector3(Node->getAbsolutePosition().X, Node->getAbsolutePosition().Y, Node->getAbsolutePosition().Z));
	Transform2.setRotation(quat);

	btDefaultMotionState *MotionState2 = new btDefaultMotionState(Transform2);
	

	btRigidBody* RigidBody = new btRigidBody(0, MotionState2, hull, localInertia);
	
	RigidBody->setUserPointer((void *)(Node));
	RigidBody->setActivationState(DISABLE_DEACTIVATION);

	world->addRigidBody(RigidBody);
	objects.push_back(RigidBody);

	return RigidBody;
}

btTriangleMesh *BulletHelper::ConvertIrrMeshToBulletTriangleMesh(IMesh* pMesh, const vector3df& scaling)
{/*
	btVector3 vertices[3];
	u32 i, j, k, index, numVertices, numIndices;
	u16* mb_indices;
	btTriangleMesh *pTriMesh = new btTriangleMesh();
	//this->m_triangleMeshes.push_back(pTriMesh);
	for (i = 0; i<pMesh->getMeshBufferCount(); i++)
	{
		IMeshBuffer* mb = pMesh->getMeshBuffer(i);
		if (mb->getVertexType() == EVT_STANDARD)
		{
			S3DVertex* mb_vertices = (S3DVertex*)mb->getVertices();
			mb_indices = mb->getIndices();
			numVertices = mb->getVertexCount();
			numIndices = mb->getIndexCount();
			for (j = 0; j<numIndices; j += 3)
			{
				for (k = 0; k<3; k++)
				{
					index = mb_indices[j + k];
					vertices[k] = btVector3(mb_vertices[index].Pos.X*scaling.X, mb_vertices[index].Pos.Y*scaling.Y, mb_vertices[index].Pos.Z*scaling.Z);
				}
				pTriMesh->addTriangle(vertices[0], vertices[1], vertices[2]);
			}
		}
		else if (mb->getVertexType() == EVT_2TCOORDS)
		{
			S3DVertex2TCoords* mb_vertices = (S3DVertex2TCoords*)mb->getVertices();
			mb_indices = mb->getIndices();
			numVertices = mb->getVertexCount();
			numIndices = mb->getIndexCount();
			for (j = 0; j<numIndices; j += 3)
			{
				for (k = 0; k<3; k++)
				{
					index = mb_indices[j + k];
					vertices[k] = btVector3(mb_vertices[index].Pos.X*scaling.X, mb_vertices[index].Pos.Y*scaling.Y, mb_vertices[index].Pos.Z*scaling.Z);
				}
				pTriMesh->addTriangle(vertices[0], vertices[1], vertices[2]);
			}
		}
	}
	return pTriMesh;
	*/

	btTriangleMesh* tMesh = new btTriangleMesh();

	irr::u32 MBCount = pMesh->getMeshBufferCount();

	for (irr::u32 m = 0; m < MBCount; m++)
	{
		irr::scene::IMeshBuffer* MB = pMesh->getMeshBuffer(m);

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
		else if (b== WORLD)
		{
			IMeshSceneNode *p = (IMeshSceneNode*)level->getNamedNode(name);
			tmp = createTriangleBody(p);
		}
		tmp = 0;
	}	
}