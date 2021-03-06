#include "game.h"

#include<ctime>
#include<iostream>

#include "eventmanager.h"
#include "room.h"
#include "item.h"
#include "weapons.h"
#include "dagger.h"
#include "sword.h"
#include "potion.h"
#include "healthpotion.h"
#include "staminapotion.h"

#include "golistener.h"
#include "maplistener.h"
#include "infolistener.h"
#include "attacklistener.h"
#include "pickuplistener.h"
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
    EventManager::getInstance().listen("pickup",    new PickupListener(this));

    // State changes
    EventManager::getInstance().listen("characterDeath", new CharacterDeathListener(this));
   //Finish implementing enemy death listener
    EventManager::getInstance().listen("enemyDeath",     new EnemyDeathListener(this));
    EventManager::getInstance().listen("enterRoom",      new EnterRoomListener(this));
    EventManager::getInstance().listen("victory",        new VictoryListener(this));
    EventManager::getInstance().listen("defeat",         new DefeatListener(this));

    int gateflag = 0;

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

    //                 N         E         S         W
    rooms[0]->setExits(rooms[4], rooms[2], rooms[7], rooms[1]);

    rooms[1]->setExits(nullptr,  rooms[0], nullptr,  nullptr);
    
    rooms[2]->setExits(nullptr,  nullptr,  nullptr,  rooms[0]);
    //Example of polymorphism as Dagger is given to method that takes a parent type
    rooms[2]->setItem(new Dagger("Small Dagger"));

    rooms[3]->setExits(nullptr,  rooms[4], nullptr,  nullptr);
    rooms[3]->setItem(new HealthPotion("Health Potion"));

    rooms[4]->setExits(nullptr,  rooms[5], rooms[0], rooms[3]);
    rooms[4]->addEnemy(new Minion("Minion"));
    rooms[4]->setItem(new StaminaPotion("Stamina Potion"));
    
    rooms[5]->setExits(nullptr,  nullptr,  nullptr,  rooms[4]);
    
    rooms[6]->setExits(nullptr,  rooms[7], nullptr,  nullptr);
    rooms[6]->setItem(new Sword("Slicer"));

    rooms[7]->setExits(rooms[0], rooms[8], nullptr, rooms[6]);
    rooms[7]->addEnemy(new Boss("Mega Zork Boss"));
    
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
    player.emptyInventory();

    if (gameOver == true)
    {
        rooms[7]->addEnemy(new Boss("Mega Zork Boss"));
        rooms[4]->addEnemy(new Minion("Minion"));
        rooms[6]->setItem(new Sword("Slicer"));
        rooms[2]->setItem(new Dagger("Small Dagger"));
        rooms[4]->setItem(new StaminaPotion("Stamina Potion"));
        rooms[3]->setItem(new HealthPotion("Health Potion"));
    }

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
    cout << " - pickup"           << endl;
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
int Game::openGate()
{
    int gateFlag = 0;
    if(rooms[7]->enemiesInRoom.size() == 0)
    { 
        rooms[7]->setExits(rooms[0], rooms[8], rooms[9], rooms[6]); 
        int gateFlag = 1;
    }
    return gateFlag;
}

void Game::attack()
{ 
    if (player.getCurrentRoom()->isEnemyHere() == true)
    {
        player.getCurrentRoom()->enemiesInRoom[0]->health = (player.getCurrentRoom()->enemiesInRoom[0]->getHealth() - player.getDamage());
        player.setHealth(player.getHealth() - (player.getCurrentRoom()->enemiesInRoom[0]->getDamage()));
        cout << "Enemy did " << player.getCurrentRoom()->enemiesInRoom[0]->getDamage() << " points of damage" << endl;
        if (player.getCurrentRoom()->enemiesInRoom[0]->getHealth() < 0)
        {
            cout << player.getCurrentRoom()->enemiesInRoom[0]->getName() << " has been slain" << endl;
            player.getCurrentRoom()->enemiesInRoom.erase(player.getCurrentRoom()->enemiesInRoom.begin());
            openGate();
        }
    }
    else
    {
        cout << "Nothing here to attack" << endl;
    }
}

void operator++(Character& player)
{
    player.setHealth(player.getHealth() + 50);
}

void Game::pickup()
{   //Need to remove old system of code but currently does reduce enemy health
    string hPotionString = "Health Potion";
    string sPotionString = "Stamina Potion";
    string swordString = "Slicer";
    string daggerString = "Small Dagger";

    if (player.getCurrentRoom()->isItemHere() == true)
    {
        player.giveItem(player.getCurrentRoom()->itemsInRoom[0]);
        player.getCurrentRoom()->itemsInRoom.erase(player.getCurrentRoom()->itemsInRoom.begin());
    }
    else {
        cout << "Nothing here to pick up" << endl;
    }

    if ((player.getInventory().find(hPotionString) != std::string::npos) && player.getHPotionCount() < 1) {
        ++player;
        player.setHPotionCount(1);
    }

    if ((player.getInventory().find(sPotionString) != std::string::npos) && player.getSPotionCount() < 1) {
        player.setSPotionCount(1);
        player.setStamina(player.getStamina() + 50);
    }

    if ((player.getInventory().find(daggerString) != std::string::npos) && player.getDaggerCount() < 1) {
        player.setDaggerCount(1);
        player.setDamage(player.getDamage() + 10);
    }

    if ((player.getInventory().find(swordString) != std::string::npos) && player.getSwordCount() < 1) {
        player.setSwordCount(1);
        player.setDamage(player.getDamage() + 20);
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

        cout << endl;
        cout << "You are in " << currentRoom->getName() << endl;
        cout << "HP: " << player.getHealth() << " ST: " << player.getStamina() << endl;
        cout << "Inventory: " << player.getInventory() << endl;
        
        if (currentRoom->isItemHere() == true) 
        {
            cout <<"Items in room: " << currentRoom->displayItem() << endl;
        }

        if (currentRoom->isEnemyHere() == true)
        {
            cout << currentRoom->displayEnemy() << endl;
        }

        if (openGate() == 1) {
            cout << "A hidden door behind the boss has opened" << endl;
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

