#include "room.h"
#include "enemy.h"
#include "game.h"
#include <algorithm>

Room::Room(string name) :
    name(name)
{
    exits["north"] = nullptr;
    exits["east"] = nullptr;
    exits["south"] = nullptr;
    exits["west"] = nullptr;
}

string Room::getName()
{
    return name;
}

void Room::setExits(Room* north, Room* east, Room* south, Room* west)
{
    exits["north"] = north;
    exits["east"] = east;
    exits["south"] = south;
    exits["west"] = west;
}

Room* Room::getExit(string direction)
{
    return exits[direction];
}

void Room::setItem(Item* inItem)
{
    itemsInRoom.push_back(inItem);
}

bool Room::isItemHere()
{
    if (this->itemsInRoom.size() > 0) {
        return true;
    }
    else
    {
        return false;
    }
}

string Room::displayItem() {
    string temp;
    if (itemsInRoom.size() > 0) {
        temp = itemsInRoom[0]->getShortDescription();
    }
    return temp;
}

void Room::addEnemy(Enemy* inEnemy)
{
    enemiesInRoom.push_back(inEnemy);
}

bool Room::isEnemyHere()
{
    if (enemiesInRoom.size() > 0) {
        
            return true;
        
    }
    else
    {
        return false;
    }
}

string Room::displayEnemy() {
    string temp = "Enemy Spotted! \nEnemies present = ";
    if (enemiesInRoom.size() > 0) {
        temp = temp + enemiesInRoom[0]->getName() + "\n" + "Enemy Health: " + to_string(enemiesInRoom[0]->getHealth());
    }
    return temp;
}
