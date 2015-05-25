#ifndef WEAPONARSENAL_H
#define WEAPONARSENAL_H

#include <irrlicht.h>
#include "Weapon.h"
#include "Elementals.h"


using namespace irr;

class WeaponArsenal
{
private:
	core::list<Weapon*> weapons;
public:
	~WeaponArsenal()
	{
		weapons.clear();
	}

	void addWeapon(Weapon* w);
	void removeWeapon(Weapon* w);
	Weapon* getWeaponOfElementalType(ElementalType element);
};


#endif