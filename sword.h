#ifndef SWORD_H
#define SWORD_H

#include<string>
#include "weapons.h"

using namespace std;


class Sword : public Weapon
{
public:
    Sword(string name);
    ~Sword();

    int getWeaponDmg() override;
    string getShortDescription() override;
private:
};

#endif //SWORD_H