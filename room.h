#ifndef ROOM_H
#define ROOM_H

#include<map>
#include<string>
#include<vector>
#include "enemy.h"
#include "boss.h"
#include "minion.h"
#include "item.h"

using namespace std;
using std::vector;

class Room
{
public:
    Room(string name);
    string getName();
    void setExits(Room *north, Room *east, Room *south, Room *west);
    Room *getExit(string direction);

    string displayBoss();
    int numberOfBoss();
    void addBoss(Boss* inBoss);
    int isBossInRoom(string inString);

    string displayMinion();
    int numberOfMinion();
    void addMinion(Minion* inMinion);
    int isMinionInRoom(string inString);

    string displayItem();
    int numberOfItems();
    void addItem(Item* inItem);
    int isItemInRoom(string inString);

private:
    string name;
    map<string, Room *> exits;
    vector <Boss> bossInRoom;
    vector <Minion> minionInRoom;
    vector <Item> itemInRoom;
};

#endif // ROOM_H
