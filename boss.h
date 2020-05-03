#ifndef BOSS_H
#define BOSS_H

#include<string>
#include "enemy.h"

using namespace std;

class Room;


class Boss : public Enemy
{
public:
	Boss(string name);
	~Boss();

	void setRoom(Room* next) override;
	void setHealth(int health) override;
	Room* getRoom();
	void killBoss();
private:
};

#endif // BOSS_H

