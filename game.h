#ifndef GAME_H
#define GAME_H

#include<string>
#include<vector>

#include "character.h"
#include "enemy.h"
#include "room.h"

using namespace std;

class Game
{
public:
    Game();
    void reset(bool show_update = true);

    void map();
    void info();
    void go(string direction);
    void teleport();
    void attack();

    void update_screen();

    Character &getPlayer();
    void setOver(bool over);
    bool is_over();
    //Dont know if this is needed
    //void setCurrentRoom(Room *next);

private:
    Character      player;
    vector<Room*> rooms;
    vector<Minion*> minions;
    vector<Room*> minionRooms;
    vector<Boss*> bossS;
    vector<Room*> bossRooms;
    vector<Item*> playerInventory;
    vector<Room*> itemRooms;
    bool           gameOver;
};
#endif // GAME_H
