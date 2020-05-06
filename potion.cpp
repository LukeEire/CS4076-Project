//extends item

#include "item.h"
#include "potion.h"
#include<string>
using namespace std;

Potion::Potion(string potionName)
{
	description = potionName;
	value = 20;
}

Potion::Potion()
{
	description = "Unknown Potion";
	value = 5;
}

Potion::~Potion()
{

}


