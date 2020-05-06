#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include <string>
#include "potion.h"
#include "character.h"

using namespace std;

class HealthPotion : public Potion {
private:

public:

	HealthPotion(string name);
	HealthPotion();
	~HealthPotion();

	int getValue();
	string getShortDescription() override;

};
#endif // HEALTHPOTION_H