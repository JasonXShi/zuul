//header guards and includes stuff
#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <vector>
#include <map>
#include "Items.h"
using namespace std;

class Room {
 public:
 //defines methods and constructer
  Room(char* newName, char* newDescription);
  char* getDescription();
  char* getName();
  void setExit(char* direction, Room* room );
  void addItem(Items* item);
  void removeItem(Items* item);
  void printInfo();
  Room* setRoom(char* direction);
  bool checkDirection(char* direction);
  vector<Items*> getItems();
  ~Room();
 private:
 //initializes variables
  char* description;
  char* name;
  vector<Items*> items;
  map<char*, Room*> exits;
};

#endif
