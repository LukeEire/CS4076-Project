#ifndef ENEMYDEATHLISTENER_H
#define ENEMYDEATHLISTENER_H

#include "eventlistener.h"

class Game;

// A listener for the bad ending
class EnemyDeathListener : public EventListener
{
public:
    EnemyDeathListener(Game* game);
    void run(void* args) override;
private:
    Game* game;
};
#endif // ENEMYDEATHLISTENER_H
