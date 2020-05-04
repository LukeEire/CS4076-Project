#include "dagger.h"

Dagger::Dagger(string weaponName)
{
    this->weaponName = weaponName;
    weaponDmg = 25;
}

Dagger::Dagger()
{
    this->weaponName = "Standard Dagger";
}

Dagger::~Dagger()
{
}

int Dagger::getWeaponDmg()
{
    return weaponDmg;
}

string Dagger::getShortDescription()
{
    return weaponName;
}
