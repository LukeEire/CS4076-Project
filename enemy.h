#ifndef ENEMY_H
#define ENEMY_H

#include<string>

using namespace std;

// No need to include room since we're only working with pointers.
// This is how we tell the compiler "there will be a room eventually".
// This is called a "forward declaration".
class Room;

class Enemy
{
public:
    Enemy(string name);

    string getName();
    int    getHealth();
    Room* getCurrentRoom();

    void setName(string name);
    void setHealth(int setHealth);
    void setCurrentRoom(Room* next);

private:
    string name;
    int health;
    Room* currentRoom;
};

#endif // ENEMY_H
#pragma once
