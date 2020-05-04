#ifndef MINION_H
#define MINION_H

#include<string>
#include "enemy.h"

using namespace std;

class Room;


class Minion : public Enemy
{
public:
	Minion(string name);
	~Minion();

	void setRoom(Room* inRoom) override;
	void setHealth(int health) override;
	Room* getCurrentRoom() override;
	void killMinion();
private:
};

#endif // MINION_H

