#ifndef WEAPONS_H
#define WEAPONS_H

#include <string>
#include "item.h"
using namespace std;

class Weapon : public Item
{
public:
	Weapon(string weaponName);
	Weapon();
	~Weapon();

	string weaponName;
	int weaponDmg;
	virtual int getWeaponDmg() = 0;
	virtual string getWeaponName() = 0;

private:

};
#endif //WEAPONS_H