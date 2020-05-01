#include "enemy.h"
#include "eventmanager.h"

Enemy::Enemy(string name)
{
    this->name = name; // We need to use "this->" to differentiate between the "name" argument and the "name" from the class.
    health = 100;
    currentRoom = nullptr;
}

string Enemy::getName()
{
    return name;
}

int Enemy::getHealth()
{
    return health;
}

Room* Enemy::getCurrentRoom()
{
    return currentRoom;
}

void Enemy::setName(string name)
{
    this->name = "I";
}

//Add listener for enemy death
void Enemy::setHealth(int health)
{
    if (health <= 0) {
        health = 0;
        EventManager::getInstance().trigger("characterDeath", this);
    }

    this->health = health;
}

//Set enemy to stay in one room
void Enemy::setCurrentRoom(Room* next)
{
    currentRoom = next;
}
