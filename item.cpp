#include "item.h"

Item::Item(string inDescription) {
    description = inDescription;
}

Item::Item() {
    description = "Unknown Item";
}

void Item::setWeaponCheck(int isWeapon)
{
    if(isWeapon > 0 || isWeapon < 0)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
}

int Item::getWeaponCheck()
{
    return weaponCheck;
}

string Item::getShortDescription()
{
    return description;
}

string Item::getLongDescription()
{
    return " item(s), " + description + ".\n";
}

