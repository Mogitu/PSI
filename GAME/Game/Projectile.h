#include "BulletHelper.h"

class Projectile
{
public:
	Projectile();
	Projectile(ISceneManager *smgr, BulletHelper *h);
	~Projectile();
	void fire(btVector3 &pos, btVector3 &direction);
	void kill();
	void resurrect();
	bool alive;
	void update(u32 duration);	

private:
	ISceneManager *smgr;
	IMeshSceneNode *node;
	IMesh *mesh;
	BulletHelper *h;
	void init();
	btRigidBody *body;
	u32 aliveTime;
};