#ifndef SINGLESHOTBEHAVIOUR_H
#define SINGLESHOTBEHAVIOUR_H

#include "WeaponBehaviour.h"

class SingleShotBehaviour : public WeaponBehaviour
{
public:
	void setUpWeaponBehaviour(GameWorld* w) override;
	void doWeaponBehaviour(btVector3 &offset, btVector3 &direction, stringw name, ElementalType eType, float damagePerProjectile) override;
};

#endif