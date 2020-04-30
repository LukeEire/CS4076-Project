#ifndef ROOM_H
#define ROOM_H

#include<map>
#include<string>

using namespace std;

class Room
{
public:
    Room(string name);
    string getName();
    void setExits(Room *north, Room *east, Room *south, Room *west);
    Room *getExit(string direction);

private:
    string name;
    map<string, Room *> exits;
};

#endif // ROOM_H
