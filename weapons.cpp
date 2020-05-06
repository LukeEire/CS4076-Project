#include "weapons.h"
#include "item.h"

Weapon::Weapon(string weaponName)
{
	description = weaponName;
}

Weapon::Weapon()
{
	weaponName = "Unknown Weapon";
}

Weapon::~Weapon()
{
}
