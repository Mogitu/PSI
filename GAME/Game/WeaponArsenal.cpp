#include "WeaponArsenal.h"

void WeaponArsenal::addWeapon(Weapon* w)
{
	if(!getWeaponOfElementalType(w->getWeaponElementalType()))
		weapons.push_back(w);
}

void WeaponArsenal::removeWeapon(Weapon* w)
{
	bool isFound = false;

	core::list<Weapon *>::Iterator Iterator = weapons.begin();

	for (; Iterator != weapons.end(); ++Iterator)
	{
		Weapon* wap = *Iterator;

		if (wap->getWeaponElementalType() == w->getWeaponElementalType())
		{
			isFound = true;
			break;
		}	
	}

	if (isFound)
		weapons.erase(Iterator);
}

Weapon* WeaponArsenal::getWeaponOfElementalType(ElementalType element)
{
	for (core::list<Weapon *>::Iterator Iterator = weapons.begin(); Iterator != weapons.end(); ++Iterator)
	{
		Weapon* w = *Iterator;

		if (w->getWeaponElementalType() == element)
			return w;
	}

	return nullptr;
}