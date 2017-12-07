#include <iostream>
#include "Room.h"
#include <vector>
#include <map>
#include <string.h>
#include "Items.h"
#include <iterator>

//constructor
Room::Room(char* newName, char* newDescription) {
  description = newDescription;
  name = newName;
}

char* Room::getDescription(){
  return description;
}
char* Room::getName(){
  return name;
}
void Room::addItem(Items* item){
  items.push_back(item);
}

void Room::removeItem(Items* item){
    for(vector<Items*>::iterator it = items.begin(); it!=items.end(); ++it){
        if(strcmp((*it)->getDescription(), item->getDescription()) == 0){  
            items.erase(it); 
            break;
        }
    }
}
Room::~Room() {
	delete []description;
	delete []name;
}
void Room::setExit( char* direction, Room* room ){
  exits.insert(make_pair(direction, room));
}

void Room::printInfo(){
  //print all Items in the room
  cout <<  endl;
  cout << "The items in this room:" << endl;
  vector<Items*>::iterator it;
  for(it = items.begin(); it != items.end(); it++) {
    cout << (*it)->getDescription() << endl;
  }
  //print all exits and directions
  cout <<  endl;
  cout << "Here are the exits:" << endl;
  map<char*, Room*>::iterator iter; exits.begin();
  for(iter = exits.begin(); iter != exits.end(); iter++){
    cout<< (iter->second)->getName() << " is in the "<< iter->first << " direction" << endl;
  }
}

bool Room::checkDirection(char* direction){
  map<char*, Room*>::iterator it; exits.begin();
  for(it = exits.begin(); it != exits.end(); it++){
    if (strcmp(it->first, direction)==0) {
        return true;
    }
  }
  return false;
}
Room* Room::setRoom(char* direction){
  map<char*, Room*>::iterator it; exits.begin();
  for(it = exits.begin(); it != exits.end(); it++){
    if (strcmp(it->first, direction)==0) {
      return it->second;
    }
  }
}

vector<Items*> Room::getItems(){
    return items;
}

