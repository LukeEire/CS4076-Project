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
    Enemy();
    ~Enemy();

    string getName();
    int    getHealth();
    Room* getCurrentRoom();

    string name;
    int health;
    Room* currentRoom;

    void setName(string name);
    virtual void setHealth(int setHealth);
    virtual void setRoom(Room* next);

private:
};

#endif // ENEMY_H