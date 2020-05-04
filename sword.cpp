#include "sword.h"

Sword::Sword(string weaponName)
{
    this->weaponName = weaponName;
    weaponDmg = 50;
}

Sword::~Sword()
{
}

int Sword::getWeaponDmg()
{
    return weaponDmg;
}

string Sword::getShortDescription()
{
    return weaponName;
}
