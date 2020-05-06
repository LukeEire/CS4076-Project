#include "staminapotion.h"
#include "item.h"

StaminaPotion::StaminaPotion(string name) {
	this->description = name;
};

StaminaPotion::~StaminaPotion() {
}

string StaminaPotion::getShortDescription() {
	return  this->description;
}

void StaminaPotion::usedStaminaPotion() {
	this->~StaminaPotion();
}
