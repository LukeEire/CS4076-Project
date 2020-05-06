#include "item.h"

Item::Item(string inDescription) {
    description = inDescription;
}

Item::Item() {
    description = "Unknown Item";
}

//Example of deconstructors used in most classes
Item::~Item()
{

}

