#ifndef STAMINAPOTION_H
#define STAMINNAPOTION_H
#include "item.h"
#include "potion.h"
#include<string>

using namespace std;

class Room;

class StaminaPotion : public Potion {
private:

public:
	
	StaminaPotion(string name);
	~StaminaPotion();
	string getShortDescription() override;
	void usedStaminaPotion();
};
#endif //STAMINAPOTION_H