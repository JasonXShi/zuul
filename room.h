#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <vector>
#include <map>
#include "Items.h"
using namespace std;

class Room {
 public:
  Room(char* newName, char* newDescription);
  char* getDescription();
  char* getName();
  void setExit(char* direction, Room* room );
  void addItem(Items* item);
  void removeItem(Items* item);
  void printInfo();
  Room* setRoom(char* direction);
  //void deleteItem(char* itemName, vector<Items*> &inventory);
  bool checkDirection(char* direction);
  vector<Items*> getItems();
 private:
  char* description;
  char* name;
  vector<Items*> items;
  map<char*, Room*> exits;
};

#endif
