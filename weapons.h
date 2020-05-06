#ifndef WEAPONS_H
#define WEAPONS_H

#include <string>
#include "item.h"
using namespace std;

//Example of Inheritance
class Weapon : public Item
{
public:
	Weapon(string weaponName);
	Weapon();
	~Weapon();

	string weaponName;
	int weaponDmg;

	//Example of virtual function and dynamic dispatch
	virtual int getWeaponDmg();

private:
	
};
#endif //WEAPONS_H