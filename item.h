#ifndef ITEM_H
#define ITEM_H

#include <map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Item {
private:
	string description;
	string longDescription;
	int weightGrams;
	float value;
	bool weaponCheck;

public:
	Item(string description);
	string getShortDescription();
	string getLongDescription();
	int getWeaponCheck();
	void setWeaponCheck(int weaponCheck);
};

#endif //ITEM_H
