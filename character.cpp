#include "character.h"
#include "eventmanager.h"
#include "item.h"

Character::Character(string name)
{
    this->name = name; // We need to use "this->" to differentiate between the "name" argument and the "name" from the class.
    health = 100;
    stamina = 100;
    damage = 50;
    currentRoom = nullptr;
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

void Character::setCurrentRoom(Room* next)
{
    currentRoom = next;
}
