#include "minion.h"
#include "enemy.h"
#include "eventmanager.h"

Minion::Minion(string name)
{
    this->name = name; // We need to use "this->" to differentiate between the "name" argument and the "name" from the class.
    health = 15;
    currentRoom = nullptr;
}

Minion::~Minion()
{
}

void Minion::setHealth(int health)
{
    if (health <= 0) {
        health = 0;
        EventManager::getInstance().trigger("characterDeath", this);
    }

    this->health = health;
}

void Minion::setRoom(Room* bossR)
{
    currentRoom = bossR;
}

Room* Minion::getRoom()
{
    return currentRoom;
}

void Minion::killMinion()
{
    this->~Minion();
}
