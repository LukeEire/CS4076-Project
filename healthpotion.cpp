#include "healthpotion.h"

HealthPotion::HealthPotion(string name) 
{
	this->description = name;
	value = 20;
}

HealthPotion::HealthPotion()
{
	this->description = "Unknown HPotion";
	value = 5;
}

HealthPotion::~HealthPotion() 
{

}

int HealthPotion::getValue()
{
	return this->value;
}

/*Character operator+(const Character &player, const HealthPotion &hPotion)
{
	return addH(player, hPotion);
}

Character addH(Character& player, HealthPotion& hPotion)
{
	player.setHealth((player.getHealth()) + (hPotion.getValue()));
	return player;
}*/

string HealthPotion::getShortDescription() {
	return  this->description;
}