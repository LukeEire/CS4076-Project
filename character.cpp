#include "character.h"
#include "eventmanager.h"
#include "item.h"

Character::Character(string name)
//initializer list
    :health(100), stamina(100), damage(10), hPotionCount(0), sPotionCount(0), daggerCount(0), swordCount(0), currentRoom(nullptr)
{
    this->name = name; // We need to use "this->" to differentiate between the "name" argument and the "name" from the class.
}

string Character::getName()
{
    return name;
}

int Character::getHealth()
{
    return health;
}

int Character::getStamina()
{
    return stamina;
}

string Character::getInventory()
{
    string temp = "";
    if(inventory.size() > 0)
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            temp = temp + (this->inventory[i]->getShortDescription()) + ", ";
        }
        return temp;
    }
    else 
    {
        return temp;
    }
}

void Character::emptyInventory()
{
    this->inventory.clear();
}

void Character::giveItem(Item* inItem) {
    this->inventory.push_back(inItem);
}

int Character::getDamage() {
    return damage;
}

Room* Character::getCurrentRoom()
{
    return currentRoom;
}

void Character::setName(string name)
{
    this->name = name;
}

void Character::setHealth(int health)
{
    if (health <= 0) {
        health = 0;
        EventManager::getInstance().trigger("characterDeath", this);
    }

    this->health = health;
}

void Character::setStamina(int stamina)
{
    if (stamina <= 0) {
        stamina = 0;
        EventManager::getInstance().trigger("characterDeath", this);
    }

    this->stamina = stamina;
}

void Character::setDamage(int damage)
{
    this->damage = damage;
}

void Character::setCurrentRoom(Room* next)
{
    currentRoom = next;
}

int Character::getHPotionCount()
{
    return hPotionCount;
}

void Character::setHPotionCount(int set)
{
    hPotionCount = set;
}

int Character::getSPotionCount()
{
    return sPotionCount;
}

void Character::setSPotionCount(int set)
{
    sPotionCount = set;
}

int Character::getDaggerCount()
{
    return daggerCount;
}

void Character::setDaggerCount(int set)
{
    daggerCount = set;
}

int Character::getSwordCount()
{
    return swordCount;
}

void Character::setSwordCount(int set)
{
    swordCount = set;
}