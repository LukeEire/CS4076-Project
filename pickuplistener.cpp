#include "pickuplistener.h"

#include "game.h"

PickupListener::PickupListener(Game* game)
{
    this->game = game;
}

void PickupListener::run(void*)
{
    game->pickup();
}
