#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "InputReceiver.h"
#include "BulletHelper.h"
#include "Character.h"
#include "GameWorld.h"
#include "WeaponArsenal.h"

class Hud; //Defining HUD; Forward declaring because we can't include each others headers

class Player : public Character
{
private:
	InputReceiver* input;
	BulletHelper* helper;
	ISceneManager* smgr;
	vector2di centerScreenPosition;
	GameWorld *world;	
	bool justJumped;
	bool isGrounded();
	int score;
	float restriction = 1; //1 = no restriction; 0 = stop movement
	WeaponArsenal* weaponArsenal;
	ElementalType currentTypeWeapon;
	Hud* hud;
public:
	Player(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, GameWorld* world, InputReceiver* input, io::path meshName, io::path textureName, LevelProgress* level, int XP, LevelAttribute* attribute, Shape_Type bodyType, btScalar bodyMass = 1, vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1));
	void Initialize();
	void Initialize(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, GameWorld* world, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass, vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1));
	void Update(u32 frameDeltaTime);
	void PlayerMovement(u32 frameDeltaTime);
	void WeaponSelect();
	void Fire();
	virtual void kill();
	virtual void revive();
	virtual void takeDamage(int damage, ElementalType eType = ElementalType::NONE) override;
	const vector3df& getNodePosition() const;
	const vector3df& getNodeAbsolutePosition() const;
	scene::IAnimatedMeshSceneNode* getNode();
	GameObjectType getType() const;
	void increaseScore(int amount);
	int getScore();
	void addWeaponToArsenal(Weapon* w);
	void attachHUD(Hud* h);
	ElementalType &getCurrentTypeWeapon();
};

#endif // !__PLAYER_H__
