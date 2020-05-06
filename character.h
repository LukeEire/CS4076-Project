#ifndef CHARACTER_H
#define CHARACTER_H

#include<string>
#include "item.h"
#include "healthpotion.h"

using namespace std;

// No need to include room since we're only working with pointers.
// This is how we tell the compiler "there will be a room eventually".
// This is called a "forward declaration".
class Room;

class Character
{
public:
    Character(string name);

    string getName();
    int    getHealth();
    int    getStamina();
    int    getDamage();
    int    getHPotionCount();
    int    getSPotionCount();
    int    getDaggerCount();
    int    getSwordCount();
    string getInventory();
    Room* getCurrentRoom();
    void giveItem(Item* inItem);

    void setName(string name);
    void setHealth(int setHealth);
    void setStamina(int stamina);
    void setDamage(int damage);
    void setCurrentRoom(Room* next);
    void setHPotionCount(int set);
    void setSPotionCount(int set);
    void setDaggerCount(int set);
    void setSwordCount(int set);

private:
    string name;
    int health;
    int stamina;
    int damage;
    int hPotionCount;
    int sPotionCount;
    int daggerCount;
    int swordCount;
    vector<Item*> inventory;
    Room* currentRoom;
};

#endif // CHARACTER_H
