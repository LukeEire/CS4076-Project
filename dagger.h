#ifndef DAGGER_H
#define DAGGER_H

#include<string>
#include "weapons.h"

using namespace std;

class Dagger : public Weapon
{
public:
	Dagger(string name);
	Dagger();
	~Dagger();

	int getWeaponDmg() override;
	string getShortDescription() override;
private:
};

#endif //DAGGER_H