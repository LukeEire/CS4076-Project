#include "room.h"

Room::Room(string name) :
    name(name)
{
    exits["north"] = nullptr;
    exits["east"]  = nullptr;
    exits["south"] = nullptr;
    exits["west"]  = nullptr;
}

string Room::getName()
{
    return name;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west)
{
    exits["north"] = north;
    exits["east"]  = east;
    exits["south"] = south;
    exits["west"]  = west;
}

Room *Room::getExit(string direction)
{
    return exits[direction];
}
