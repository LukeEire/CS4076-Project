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

    void addEnemy(Enemy* inEnemy);
    string displayEnemy();
    bool isEnemyHere();

    void setItem(Item* inItem);
    string displayItem();
    bool isItemHere();

    vector <Enemy*> enemiesInRoom;
    vector <Item*> itemsInRoom;

private:
    string name;
    map<string, Room *> exits;
};

#endif // ROOM_H
