//***************************************************************
// Bullet/irrlicht demo by Alan Witkowski
// http://www.cs.utah.edu/~witkowsk
// http://code.google.com/p/irrlamb/
//***************************************************************
#include <irrlicht.h>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <cstdlib>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

// Functions
static void CreateStartScene();
static void CreateBox(const btVector3 &TPosition, const vector3df &TScale, btScalar TMass);
static void CreateSphere(const btVector3 &TPosition, btScalar TRadius, btScalar TMass);
static void UpdatePhysics(u32 TDeltaTime);
static void UpdateRender(btRigidBody *TObject);
static void ClearObjects();
static int GetRandInt(int TMax) { return rand() % TMax; }

// Globals
static bool Done = false;
static btDiscreteDynamicsWorld *World;
static IrrlichtDevice *irrDevice;
static IVideoDriver *irrDriver;
static ISceneManager *irrScene;
static IGUIEnvironment *irrGUI;
static IFileSystem *irrFile;
static ITimer *irrTimer;
static ILogger *irrLog;
static list<btRigidBody *> Objects;

// Event receiver
class EventReceiverClass : public IEventReceiver  {

public:

	virtual bool OnEvent(const SEvent &TEvent) {

		if (TEvent.EventType == EET_KEY_INPUT_EVENT && !TEvent.KeyInput.PressedDown) {
			switch (TEvent.KeyInput.Key) {
			case KEY_ESCAPE:
				Done = true;
				break;
			case KEY_KEY_1:
				CreateBox(btVector3(GetRandInt(10) - 5.0f, 7.0f, GetRandInt(10) - 5.0f), vector3df(GetRandInt(3) + 0.5f, GetRandInt(3) + 0.5f, GetRandInt(3) + 0.5f), 1.0f);
				break;
			case KEY_KEY_2:
				CreateSphere(btVector3(GetRandInt(10) - 5.0f, 7.0f, GetRandInt(10) - 5.0f), GetRandInt(5) / 5.0f + 0.2f, 1.0f);
				break;
			case KEY_KEY_X:
				CreateStartScene();
				break;
			default:
				return false;
				break;
			}

			return true;
		}

		return false;
	}
};

int main() {

	// Initialize irrlicht
	EventReceiverClass Receiver;
	irrDevice = createDevice(video::EDT_OPENGL, dimension2d<u32>(800, 600), 32, false, false, false, &Receiver);
	irrGUI = irrDevice->getGUIEnvironment();
	irrTimer = irrDevice->getTimer();
	irrScene = irrDevice->getSceneManager();
	irrDriver = irrDevice->getVideoDriver();

	irrDevice->getCursorControl()->setVisible(0);

	// Initialize bullet
	btDefaultCollisionConfiguration *CollisionConfiguration = new btDefaultCollisionConfiguration();
	btBroadphaseInterface *BroadPhase = new btAxisSweep3(btVector3(-1000, -1000, -1000), btVector3(1000, 1000, 1000));
	btCollisionDispatcher *Dispatcher = new btCollisionDispatcher(CollisionConfiguration);
	btSequentialImpulseConstraintSolver *Solver = new btSequentialImpulseConstraintSolver();
	World = new btDiscreteDynamicsWorld(Dispatcher, BroadPhase, Solver, CollisionConfiguration);

	// Add camera
	ICameraSceneNode *Camera = irrScene->addCameraSceneNodeFPS(0, 100, 10);
	Camera->setPosition(vector3df(0, 5, -5));
	Camera->setTarget(vector3df(0, 0, 0));

	// Preload textures
	irrDriver->getTexture("../Assets/bricks.png");
	irrDriver->getTexture("../Assets/bricks.png");

	// Create text
	IGUISkin *Skin = irrGUI->getSkin();
	Skin->setColor(EGDC_BUTTON_TEXT, SColor(255, 255, 255, 255));
	irrGUI->addStaticText(L"Hit 1 to create a box\nHit 2 to create a sphere\nHit x to reset", rect<s32>(0, 0, 200, 100), false);

	// Create the initial scene
	irrScene->addLightSceneNode(0, core::vector3df(2, 5, -2), SColorf(4, 4, 4, 1));
	CreateStartScene();

	// Main loop
	u32 TimeStamp = irrTimer->getTime(), DeltaTime = 0;
	while (!Done) {

		DeltaTime = irrTimer->getTime() - TimeStamp;
		TimeStamp = irrTimer->getTime();

		UpdatePhysics(DeltaTime);

		irrDriver->beginScene(true, true, SColor(255, 20, 0, 0));
		irrScene->drawAll();
		irrGUI->drawAll();
		irrDriver->endScene();
		irrDevice->run();
	}

	ClearObjects();
	delete World;
	delete Solver;
	delete Dispatcher;
	delete BroadPhase;
	delete CollisionConfiguration;

	irrDevice->drop();

	return 0;
}

// Runs the physics simulation.
// - TDeltaTime tells the simulation how much time has passed since the last frame so the simulation can run independently of the frame rate.
void UpdatePhysics(u32 TDeltaTime) {

	World->stepSimulation(TDeltaTime * 0.001f, 60);

	// Relay the object's orientation to irrlicht
	for (list<btRigidBody *>::Iterator Iterator = Objects.begin(); Iterator != Objects.end(); ++Iterator) {

		UpdateRender(*Iterator);
	}
}

// Creates a base box
void CreateStartScene() {

	ClearObjects();
	CreateBox(btVector3(0.0f, 0.0f, 0.0f), vector3df(10.0f, 0.5f, 10.0f), 0.0f);
}

// Create a box rigid body
void CreateBox(const btVector3 &TPosition, const vector3df &TScale, btScalar TMass) {

	ISceneNode *Node = irrScene->addCubeSceneNode(1.0f);
	Node->setScale(TScale);
	Node->setMaterialFlag(EMF_LIGHTING, 1);
	Node->setMaterialFlag(EMF_NORMALIZE_NORMALS, true);
	Node->setMaterialTexture(0, irrDriver->getTexture("../Assets/bricks.png"));

	// Set the initial position of the object
	btTransform Transform;
	Transform.setIdentity();
	Transform.setOrigin(TPosition);

	btDefaultMotionState *MotionState = new btDefaultMotionState(Transform);

	// Create the shape
	btVector3 HalfExtents(TScale.X * 0.5f, TScale.Y * 0.5f, TScale.Z * 0.5f);
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

// Create a sphere rigid body
void CreateSphere(const btVector3 &TPosition, btScalar TRadius, btScalar TMass) {

	ISceneNode *Node = irrScene->addSphereSceneNode(TRadius, 32);
	Node->setMaterialFlag(EMF_LIGHTING, 1);
	Node->setMaterialFlag(EMF_NORMALIZE_NORMALS, true);
	Node->setMaterialTexture(0, irrDriver->getTexture("../Assets/bricks.png"));

	// Set the initial position of the object
	btTransform Transform;
	Transform.setIdentity();
	Transform.setOrigin(TPosition);

	btDefaultMotionState *MotionState = new btDefaultMotionState(Transform);

	// Create the shape
	btCollisionShape *Shape = new btSphereShape(TRadius);

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

// Passes bullet's orientation to irrlicht
void UpdateRender(btRigidBody *TObject) {
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

// Removes all objects from the world
void ClearObjects() {

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





















/*#include <irrlicht.h>
#include <iostream>
#include "Level.h"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main()
{
	
	IrrlichtDevice *device =
		createDevice(video::EDT_OPENGL, dimension2d<u32>(640, 480), 16,
		false, false, false, 0);

	if (!device)
		return 1;	

	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");	

	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

	guienv->addStaticText(L"Hello World! This is the Irrlicht OPENGL renderer!",
		rect<s32>(10, 10, 260, 22), true);

	scene::ICameraSceneNode * camera = smgr->addCameraSceneNodeFPS(0, 50.f, 0.1f);
	camera->setPosition(core::vector3df(0, 50, 0));

	Level level(smgr,camera,"../Assets/level.irr");	
	
	scene::ISceneNode *pl = level.getNamedNode("BOX");		
	scene::ISceneNode *pl2 = level.getNamedNode("BOX2");

	//*************	
	scene::ITriangleSelector* selector = smgr->createTriangleSelector(((scene::IMeshSceneNode*)pl)->getMesh(),pl);
	pl->setTriangleSelector(selector);

	scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
		selector,pl, core::vector3df(60, 100, 60),
		core::vector3df(0, -1, 0),
		core::vector3df(0, 50, 0));
	selector->drop();
	pl->addAnimator(anim);
	anim->drop();
	//*********************	

	pl->setPosition(vector3df(0, 20, 0));
	pl2->setPosition(vector3df(0, 100, 0));
	pl->updateAbsolutePosition();
	pl2->updateAbsolutePosition();

	aabbox3d<irr::f32> boxA = pl->getTransformedBoundingBox();
	aabbox3d<irr::f32> boxB = pl2->getTransformedBoundingBox();	
	
	if (boxA.intersectsWithBox(boxB))
	{
		std::cout << "BOXES INTERSECT!" << std::endl;
	}

	u32 then = device->getTimer()->getTime();
	while (device->run())
	{	
		// Work out a frame delta time.
		const u32 now = device->getTimer()->getTime();
		const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
		then = now;		
		pl->updateAbsolutePosition();
		driver->beginScene(true, true, SColor(255, 100, 101, 140));
		smgr->drawAll();

		guienv->drawAll();

		driver->endScene();
	}
	
	device->drop();
	return 0;
}



*/