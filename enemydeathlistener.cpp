#include "enemydeathlistener.h"

#include "eventmanager.h"
#include "game.h"

EnemyDeathListener::EnemyDeathListener(Game* game)
{
    this->game = game;
}

void EnemyDeathListener::run(void* args)
{
    if (game->is_over()) {
        return;
    }

    Character* character = (Character*)args;

    if (character->getName() == game->getPlayer().getName()) {
        EventManager::getInstance().trigger("defeat");
    }
}
