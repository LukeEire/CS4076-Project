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

void Room::addItem(Item* inItem) {
    itemInRoom.push_back(*inItem);
}

/*void Room::removeBoss(Boss* inBoss){
    bossInRoom.erase(std::remove(bossInRoom.begin(), bossInRoom.end(), inBoss), bossInRoom.end());
}
*/

string Room::displayItem() {
    string temp = "Enemy Spotted! \nEnemies present = ";
    int itemCount = (itemInRoom.size());
    if (itemInRoom.size() < 1) {
        temp = "";
    }
    else if (itemInRoom.size() > 0) {
        int x = 0;
        string tempName = itemInRoom[x].getShortDescription() + ", ";
        for (int y = itemCount; y > 0; y--) {
            temp = temp + tempName;
            x++;
        }
    }
    return temp;
}

int Room::numberOfItems() {
    return itemInRoom.size();
}

int Room::isItemInRoom(string inString) {
    int itemCount = (itemInRoom.size());
    if (itemInRoom.size() < 1) {
        return false;
    }
    else if (itemInRoom.size() > 0) {
        int x = 0;
        for (int n = itemCount; n > 0; n--) {
            int itemFlag = inString.compare(itemInRoom[x].getShortDescription());
            if (itemFlag == 0) {
                itemInRoom.erase(itemInRoom.begin() + x);
                return x;
            }
            x++;
        }
        return -1;
    }
}
