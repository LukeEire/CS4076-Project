#ifndef PICKUPLISTENER_H
#define PICKUPLISTENER_H

#include "eventlistener.h"

class Game;

class PickupListener : public EventListener
{
public:
    PickupListener(Game* game);
    void run(void* args) override;
private:
    Game* game;
};

#endif // PICKUPLISTENER_H
