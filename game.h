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
    void pickup();

    void update_screen();
    int openGate();

    Character &getPlayer();
    void setOver(bool over);
    bool is_over();
    vector<Item*> items;
    vector<Room*> rooms;

    friend void operator ++(Character& player);

private:
    Character      player;
    //vector<Room*> rooms;
    bool           gameOver;
};
#endif // GAME_H
