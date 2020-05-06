#include "boss.h"
#include "enemy.h"
#include "eventmanager.h"

Boss::Boss(string name)
{
    this->name = name; // We need to use "this->" to differentiate between the "name" argument and the "name" from the class.
    health = 100;
    damage = 25;
    currentRoom = nullptr;
}

Boss::~Boss() 
{

}

void Boss::setHealth(int health)
{
    if (health <= 0) {
        health = 0;
        EventManager::getInstance().trigger("characterDeath", this);
    }

    this->health = health;
}

void Boss::setRoom(Room* bossR)
{ 
    currentRoom = bossR;
}

Room* Boss::getRoom()
{
    return currentRoom;
}

void Boss::killBoss()
{
    this->~Boss();
}
