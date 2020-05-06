#ifndef POTION_H
#define POTION_H

#include<string>
#include "item.h"

using namespace std;
class Potion : public Item
{
private:

public:
	//Abstract Class
	Potion();
	~Potion();

	int value;
	string description;
	virtual string getShortDescription() = 0;
};
#endif //POTION_H