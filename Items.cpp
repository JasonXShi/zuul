#include <iostream>
#include "Items.h"

using namespace std;

Items::Items(char* newDescription) {
  description = newDescription;
}
char* Items::getDescription() {
  return description;
}
Items::~Items(){
  delete[] description;
}
