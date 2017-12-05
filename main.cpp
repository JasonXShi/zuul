#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <iterator>
#include "Room.h"
#include "Items.h"

int main() {
  vector<Room*> Rooms;
  vector<Items*> inventory;

  //create items
  Items* AK47 = new Items("AK47");
  Items* Bomb = new Items("Bomb");
  Items* DefuseKit = new Items("DefuseKit");
  Items* Flashbang = new Items("Flashbang");
  Items* Grenade = new Items("Grenade");

  //create rooms and add the items to the rooms
  Room* current;
  Room* bSite = new Room("bSite", "at B Site, the second site where the bomb can be planted");
  Room* upperTuns = new Room("upperTuns", "at the Upper Tunnels");
  upperTuns->addItem(Grenade);
  Room* outsideTuns = new Room("outsideTuns","Outside Upper Tunnels");
  Room* tRamp = new Room("tRamp","at T Ramp, the ramp connecting tunnels to T Spawn");
  Room* lowerTuns = new Room("lowerTuns", "at Lower tunnels");
  Room* ctSpawn = new Room("ctSpawn", "at CT Spawn, where the counterterrorists spawn");
  ctSpawn->addItem(DefuseKit);
  Room* mid = new Room("mid", "at mid, the middle of the map");
  Room* suicide = new Room("suicide", "at suicide, a tunnel connecting T Spawn to mid");
  Room* tSpawn = new Room("tSpawn", "at T Spawn, the place where terrorists spawn");
  tSpawn->addItem(AK47);
  tSpawn->addItem(Bomb);
  Room* Short = new Room("Short", "at Short, the walkway connecting Cat to A Site");
  Room* cat = new Room("cat", "at Catwalk, the walkway connecting mid to Short");
  Room* longDoors = new Room("longDoors", "at Long Doors, the doorway connecting Long");
  Room* outsideLong = new Room("outsideLong", "at the section of the map outside of Long");
  Room* aSite = new Room("aSite", "at A Site, the first site where the bomb can be planted");
  Room* cross = new Room("cross", "at cross, the intersection connecting Long, CT Spawn, and A Site");
  Room* Long = new Room("Long", "at Long, the long walkway connecting A Site to T Spawn");
  Room* pit = new Room("pit", "at pit, the pit at the end of long");
  pit->addItem(Flashbang);

  //add exits
  bSite->setExit("SOUTH", upperTuns);
	bSite->setExit("EAST", ctSpawn);
	upperTuns->setExit("NORTH", bSite);
	upperTuns->setExit("EAST", lowerTuns);
  upperTuns->setExit("SOUTH", outsideTuns);

	outsideTuns->setExit("NORTH", upperTuns);
	outsideTuns->setExit("SOUTH", tRamp);

	tRamp->setExit("NORTH", outsideTuns);
	tRamp->setExit("EAST", tSpawn);

	lowerTuns->setExit("EAST", mid);
	lowerTuns->setExit("WEST", upperTuns);

	ctSpawn->setExit("EAST", cross);
	ctSpawn->setExit("WEST", bSite);
	ctSpawn->setExit("SOUTH", mid);

	mid->setExit("NORTH", ctSpawn);
	mid->setExit("EAST", cat);
	mid->setExit("WEST", lowerTuns);
	mid->setExit("SOUTH", suicide);

	suicide->setExit("NORTH", mid);
	suicide->setExit("SOUTH", tSpawn);

	tSpawn->setExit("NORTH", suicide);
	tSpawn->setExit("EAST", outsideLong);
	tSpawn->setExit("WEST", tRamp);

	Short->setExit("EAST", aSite);
	Short->setExit("SOUTH", cat);

	cat->setExit("NORTH", Short);
	cat->setExit("WEST", mid);

	longDoors->setExit("SOUTH", outsideLong);
	longDoors->setExit("EAST", pit);

	outsideLong->setExit("NORTH", longDoors);
	outsideLong->setExit("WEST", tSpawn);

	aSite->setExit("SOUTH", cross);
	aSite->setExit("WEST", Short);

	cross->setExit("NORTH", aSite);
	cross->setExit("WEST", ctSpawn);
	cross->setExit("SOUTH", Long);

	Long->setExit("NORTH", cross);
	Long->setExit("SOUTH", pit);

	pit->setExit("NORTH", Long);
	pit->setExit("WEST", longDoors);

	current = tSpawn; // start game at mid

  //add rooms to vector
  Rooms.push_back(bSite);
  Rooms.push_back(upperTuns);
  Rooms.push_back(outsideTuns);
  Rooms.push_back(tRamp);
  Rooms.push_back(lowerTuns);
  Rooms.push_back(ctSpawn);
  Rooms.push_back(mid);
  Rooms.push_back(suicide);
  Rooms.push_back(tSpawn);
  Rooms.push_back(Short);
  Rooms.push_back(cat);
  Rooms.push_back(longDoors);
  Rooms.push_back(outsideLong);
  Rooms.push_back(aSite);
  Rooms.push_back(cross);
  Rooms.push_back(Long);
  Rooms.push_back(pit);

  cout << "Welcome to CSGO!" << endl;
  cout << "You are a Counterterrorist- " << endl;
  cout << "In order to win, you need to travel to CT Spawn and pick up a defuse kit." << endl;
  cout << endl;
  cout << "Type GO to go to another room" << endl;
  cout << "Type GET to pick up an item" << endl;
  cout << "Type DROP to drop an item" << endl;
  cout << "Type QUIT to leave the game" << endl;
  cout << "Type HELP to view items and exits" << endl;

  cout << endl;
  while(true){
    //check win condition
    //iterate through the inventory and check if there is an item with description of defusekit
    vector<Items*>::iterator it;
    for(it = inventory.begin(); it != inventory.end(); it++) {
      if (strcmp((*it)->getDescription(), DefuseKit->getDescription())==0) {
        cout << "Congradulations, you have picked up the defuse kit and won the game!!" << endl;
        cout <<"exiting...";
        exit(0);
      }
    }
    cout<< "You are " << current->getDescription() <<"." << endl;
    current->printInfo();
    cout << endl;
    cout << "You have these items: " << endl;
    for(it = inventory.begin(); it != inventory.end(); it++) {
      cout<< (*it)->getDescription() << endl;
    }
    char input[40];
    cout << endl;
    cout << "Please Enter a command: "<<endl;
    cin.getline(input, 40);
      if (strcmp(input, "GO") == 0){
        cout<< "Input the direction where you want to go: (NORTH, SOUTH, EAST, WEST)" << endl;
        cin.getline(input, 40);
        //current room name
        //iterate through until the right name is matched
        //check if the direction inputted has a value
        // if it does, set the current to the
        vector<Room*>::iterator iter;
        for(iter = Rooms.begin(); iter != Rooms.end(); iter++) {
          if (strcmp((*iter)->getName(), current->getName())==0) {
            if((*iter)->checkDirection(input)){
              current = (*iter)->setRoom(input);
            }
          }
        }
      }else if(strcmp(input, "GET") == 0){
        cout << "Enter the name of the item you want to pick up:";
        cin.getline(input, 40);
        for(it = current->getItems().begin(); it != current->getItems().end(); it++) {
          if (strcmp((*it)->getDescription(), input)==0) {
            inventory.push_back(new Items(input));
            vector<Room*>::iterator iter;
            for(iter = Rooms.begin(); iter != Rooms.end(); iter++) {
              if (strcmp((*iter)->getName(), current->getName())==0) {
                (*iter)->removeItem(*it);
              }
            }
            delete * it;
            it = current->getItems().erase(it);
            it--;
          }
        }
      } else if(strcmp(input, "DROP") == 0){
        cout<< "Enter the name of the item you want to drop:" <<endl;
        cin.getline(input, 40);
        for(it = inventory.begin(); it != inventory.end(); it++) {
          if (strcmp((*it)->getDescription(), input)==0) {
            //add to room (current and actual)
            current->addItem(new Items(input));
            vector<Room*>::iterator iter;
            for(iter = Rooms.begin(); iter != Rooms.end(); iter++) {
              if (strcmp((*iter)->getName(), current->getName())==0) {
                (*iter)->addItem(new Items(input));
              }
            }
            //delete from inventory
            delete * it;
            it = inventory.erase(it);
            it--;
          }
        }
      }else if(strcmp(input, "HELP") == 0){
        //just loops back through, because I tell all the items and exits at the beginning of the while loop
      }
      else if(strcmp(input, "QUIT") == 0){
        cout << "Exiting..."<< endl;
        exit(0);
      }else{
        cout << "Not a valid command" << endl;
      }
    }
  }
