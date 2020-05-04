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

void Room::addBoss(Boss* inBoss) {
    bossInRoom.push_back(*inBoss);
}

/*void Room::removeBoss(Boss* inBoss){
    bossInRoom.erase(std::remove(bossInRoom.begin(), bossInRoom.end(), inBoss), bossInRoom.end());
}
*/

string Room::displayBoss() {
    string temp = "Enemy Spotted! \nEnemies present = ";
    int bossCount = (bossInRoom.size());
    if (bossInRoom.size() < 1) {
        temp = "The coast is clear";
    }
    else if(bossInRoom.size() > 0) {
        int x = 0;
        string tempName = bossInRoom[x].getName() + "\n";
        for (int y = bossCount; y > 0; y--) {
            temp = temp + tempName;
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
            if (enemyFlag == 0) {
                bossInRoom.erase(bossInRoom.begin() + x);
                return x;
            }
            x++;
        }
        return -1;
    }
}
    
void Room::addMinion(Minion* inMinion) {
    minionInRoom.push_back(*inMinion);
}

/*void Room::removeBoss(Boss* inBoss){
    bossInRoom.erase(std::remove(bossInRoom.begin(), bossInRoom.end(), inBoss), bossInRoom.end());
}
*/

string Room::displayMinion() {
    string temp = "Enemy Spotted! \nEnemies present = ";
    int minionCount = (minionInRoom.size());
    if (minionInRoom.size() < 1) {
        temp = "The coast is clear";
    }
    else if (minionInRoom.size() > 0) {
        int x = 0;
        string tempName = minionInRoom[x].getName() + "\n";
        for (int y = minionCount; y > 0; y--) {
            temp = temp + tempName;
            x++;
        }
    }
    return temp;
}

int Room::numberOfMinion() {
    return minionInRoom.size();
}

int Room::isMinionInRoom(string inString) {
    int minionCount = (minionInRoom.size());
    if (minionInRoom.size() < 1) {
        return false;
    }
    else if (minionInRoom.size() > 0) {
        int x = 0;
        for (int n = minionCount; n > 0; n--) {
            int enemyFlag = inString.compare(minionInRoom[x].getName());
            if (enemyFlag == 0) {
                minionInRoom.erase(minionInRoom.begin() + x);
                return x;
            }
            x++;
        }
        return -1;
    }
}
