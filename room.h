#ifndef ROOM_H
#define ROOM_H

#include<map>
#include<string>
#include<vector>
#include "enemy.h"
#include "boss.h"

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
    void removeBoss(Boss* inEnemy);

private:
    string name;
    map<string, Room *> exits;

    //The bitch boy problem is with the vector and dealing with the boss object being added to a room fuck yeah im gonna fuck this bitch up tomorrow
    vector <Boss> bossInRoom;
};

#endif // ROOM_H
