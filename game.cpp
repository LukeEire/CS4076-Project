#include "game.h"

#include<ctime>
#include<iostream>

#include "eventmanager.h"
#include "room.h"
#include "item.h"
#include "weapons.h"
#include "dagger.h"
#include "sword.h"

#include "golistener.h"
#include "maplistener.h"
#include "infolistener.h"
#include "attacklistener.h"
#include "restartlistener.h"
#include "teleportlistener.h"
#include "exitlistener.h"
#include "characterdeathlistener.h"
#include "enemydeathlistener.h"
#include "enterroomlistener.h"
#include "victorylistener.h"
#include "defeatlistener.h"

Game::Game() :
    player("Hero")
{
    srand(time(nullptr
               ));

    // Commands
    EventManager::getInstance().listen("go",        new GoListener(this));
    EventManager::getInstance().listen("map",       new MapListener(this));
    EventManager::getInstance().listen("info",      new InfoListener(this));
    EventManager::getInstance().listen("restart",   new RestartListener(this));
    EventManager::getInstance().listen("teleport",  new TeleportListener(this));
    EventManager::getInstance().listen("exit",      new ExitListener(this));
    EventManager::getInstance().listen("attack",    new AttackListener(this));

    // State changes
    EventManager::getInstance().listen("characterDeath", new CharacterDeathListener(this));
   //Finish implementing enemy death listener
    EventManager::getInstance().listen("enemyDeath",     new EnemyDeathListener(this));
    EventManager::getInstance().listen("enterRoom",      new EnterRoomListener(this));
    EventManager::getInstance().listen("victory",        new VictoryListener(this));
    EventManager::getInstance().listen("defeat",         new DefeatListener(this));

    rooms.push_back(new Room("A")); // 0
    rooms.push_back(new Room("B")); // 1
    rooms.push_back(new Room("C")); // 2
    rooms.push_back(new Room("D")); // 3
    rooms.push_back(new Room("E")); // 4
    rooms.push_back(new Room("F")); // 5
    rooms.push_back(new Room("G")); // 6
    rooms.push_back(new Room("H")); // 7
    rooms.push_back(new Room("I")); // 8
    rooms.push_back(new Room("J")); // 9
    rooms.push_back(new Room("Graveyard"));

    //playerInventory.push_back(new Dagger("Knif"));

    minions.push_back(new Minion("Smol PP"));
    bossS.push_back(new Boss("Buff Bitch 9000"));

    //                 N         E         S         W
    rooms[0]->setExits(rooms[4], rooms[2], rooms[7], rooms[1]);
    rooms[1]->setExits(nullptr,  rooms[0], nullptr,  nullptr);

    //May need to create minion within game as well as boss
    rooms[1]->addMinion(minions[0]);
    minionRooms.push_back(rooms[1]);

    rooms[2]->setExits(nullptr,  nullptr,  nullptr,  rooms[0]);
    rooms[2]->setItem(new Dagger("Knif"));

    rooms[3]->setExits(nullptr,  rooms[4], nullptr,  nullptr);

    rooms[4]->setExits(nullptr,  rooms[5], rooms[0], rooms[3]);
    
    rooms[5]->setExits(nullptr,  nullptr,  nullptr,  rooms[4]);
    
    rooms[6]->setExits(nullptr,  rooms[7], nullptr,  nullptr);
    rooms[6]->setItem(new Sword("Slicer"));

    rooms[7]->setExits(rooms[0], rooms[8], rooms[9], rooms[6]);
    rooms[7]->addBoss(bossS[0]);
    bossRooms.push_back(rooms[7]);
    
    rooms[8]->setExits(nullptr,  nullptr,  nullptr,  rooms[7]);
    rooms[9]->setExits(rooms[7], nullptr,  nullptr,  nullptr);

    reset();
}

void Game::reset(bool show_update)
{
    gameOver = false;

    player.setCurrentRoom(rooms[0]);
    player.setHealth(100);
    player.setStamina(100);

    cout << "Welcome to Zork!" << endl;
    if (show_update) {
        update_screen();
    }
}

void Game::setOver(bool over)
{
    this->gameOver = over;
}

void Game::map()
{
    cout << "D-E-F" << endl;
    cout << "  |  " << endl;
    cout << "B-A-C" << endl;
    cout << "  |  " << endl;
    cout << "G-H-I" << endl;
    cout << "  |  " << endl;
    cout << "  J  " << endl;
}

void Game::info()
{
    cout << "Available commands:" << endl;
    cout << " - go <direction>"   << endl;
    cout << " - teleport"         << endl;
    cout << " - map"              << endl;
    cout << " - info"             << endl;
    //Listener yet to be implemented
    cout << " - attack"           << endl;
}

void Game::go(string direction)
{
    Room *next = player.getCurrentRoom()->getExit(direction);

    if (next != nullptr) {
        player.setCurrentRoom(next);
        player.setStamina(player.getStamina() - 1);
        EventManager::getInstance().trigger("enterRoom", next);
    } else {
        cout << "You hit a wall" << endl;
    }
}

void Game::teleport()
{   //Make sure player cant go to graveyard
    
    int selected = rand() % (rooms.size()-1);
    player.setCurrentRoom(rooms[selected]);
    player.setStamina(player.getStamina() - 5);
    EventManager::getInstance().trigger("enterRoom", rooms[selected]);
}

void Game::attack()
{
    //Needs proper event manager
    if (player.getCurrentRoom() == (minionRooms[0]))
    {
        minions[0]->health = (minions[0]->getHealth() - player.getDamage());
        if (minions[0]->getHealth() < 0)
        {
            minionRooms[0] = rooms[10];
            cout << minions[0]->getName() << " Is dEd" << endl;
        }
    }

    //Needs proper event manager
    if (player.getCurrentRoom() == (bossRooms[0]))
    {
        bossS[0]->health = (bossS[0]->getHealth() - player.getDamage());
        if (bossS[0]->getHealth() < 0)
        {
            bossRooms[0] = rooms[10];
            cout << bossS[0]->getName() << " Is dEd" << endl;
        }
    }
    
    if (((player.getCurrentRoom() != (bossRooms[0])) && (bossRooms[0] != rooms[10])) && (player.getCurrentRoom() != (minionRooms[0])) && (minionRooms[0] != rooms[10]))
    {
        cout << "Nothing here to attack" << endl;
    }
}

bool Game::is_over()
{
    return gameOver;
}

Character &Game::getPlayer()
{
    return player;
}

void Game::update_screen()
{
    if (!gameOver) {
        Room *currentRoom = player.getCurrentRoom();
        Room* enemyR = minionRooms[0];
        Room* bossR = bossRooms[0];

        cout << endl;
        cout << "You are in " << currentRoom->getName() << endl;
        cout << "HP: " << player.getHealth() << " ST: " << player.getStamina() << endl;
        cout << "Inventory: \n";
        
        if (currentRoom->isItemHere() == true) {
            cout <<"Items in room: " << currentRoom->displayItem() << endl;
        }
        
        if (currentRoom == enemyR) {
            cout << enemyR->displayMinion() << "Enemy Health: " << minions[0]->getHealth() << endl;
        }
        else if (currentRoom == bossR) {
            cout << bossR->displayBoss() << "Enemy Health: " << bossS[0]->getHealth() << endl;
        } else {
            cout << "The coast is clear" << endl;
        }

        cout << "Exits:";
        if (currentRoom->getExit("north") != nullptr) { cout << " north"; }
        if (currentRoom->getExit("east")  != nullptr) { cout << " east";  }
        if (currentRoom->getExit("south") != nullptr) { cout << " south"; }
        if (currentRoom->getExit("west")  != nullptr) { cout << " west";  }
        cout << endl;

        
    } else {
        cout << "Type \"restart\" or \"exit\"." << endl;
    }
}
