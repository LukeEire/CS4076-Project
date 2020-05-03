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

	void setRoom(Room* next) override;
	void setHealth(int health) override;
private:
};

#endif // MINION_H

