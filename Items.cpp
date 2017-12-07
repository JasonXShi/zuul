#include <iostream>
#include "Items.h"

using namespace std;
//constructor updates the description of the item
Items::Items(char* newDescription) {
  description = newDescription;
}
//returns description
char* Items::getDescription() {
  return description;
}
//deconstructor for items (deletes the description)
Items::~Items(){
  delete[] description;
}
