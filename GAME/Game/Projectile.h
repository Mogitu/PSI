#include "GameWorld.h"
#include "BulletHelper.h"
#include "ParticleManager.h"
#include "IGameObject.h"


#ifndef PROJECTILE_H
#define PROJECTILE_H
class Projectile: public IGameObject
{
public:
	Projectile();
	Projectile(ISceneManager *smgr, BulletHelper *h,stringw projectileName);
	~Projectile();	
	void fire(btVector3 &pos, btVector3 &direction);
	virtual void kill();
	virtual void Initialize();	
	virtual void Initialize(ISceneManager *smgr, BulletHelper *h, stringw projectileName, btVector3 &pos, btVector3 &dir);
	virtual void Update(u32 deltaTime);	
	virtual void revive();
	ParticleManager::ParticleSystem *a;
	ParticleManager::ParticleSystem *b;
	ParticleManager::ParticleSystem *c;
	GameObjectType getType() const;
	bool warmedUp;
private:
	ISceneManager *smgr;

	//IMeshSceneNode *node;
	IMesh *mesh;
	BulletHelper *h;		
	float aliveTime;
	u32 speed;
	float maxLifeTime;
	stringw projectileName;
	ParticleManager::ParticleSystem *particleEffect;
};
#endif // !PROJECTILE_H


