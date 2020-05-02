#include "room.h"
#include "enemy.h"
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

void Room::addBoss(Boss* inBoss) {
    bossInRoom.push_back(*inBoss);
}

void Room::removeBoss(Boss* inEnemy){
    bossInRoom.erase(std::remove(bossInRoom.begin(), bossInRoom.end(), inEnemy), bossInRoom.end());
}

string Room::displayBoss() {
    string temp = "Enemy Spotted! \nEnemies present = ";
    int bossCount = (bossInRoom.size());
    if (bossInRoom.size() < 1) {
        temp = "The coast is clear";
    }
    else if(bossInRoom.size() > 0) {
        int x = 0;
        for (int y = bossCount; y > 0; y--) {
            temp = temp + bossInRoom[x].getName() + " ";
            x++;
        }
    }
    return temp;
}

int Room::numberOfBoss() {
    return bossInRoom.size();
}

int Room::isBossInRoom(string inString) {
    int bossCount = (bossInRoom.size());
    if (bossInRoom.size() < 1) {
        return false;
    }
    else if (bossInRoom.size() > 0) {
        int x = 0;
        for (int n = bossCount; n > 0; n--) {
            int enemyFlag = inString.compare(bossInRoom[x].getName());
            if (enemyFlag = 0) {
                bossInRoom.erase(bossInRoom.begin() + x);
                return x;
            }
            x++;
        }
        return -1;
    }
}
    

