/*
Zuul - a text based adventure game where you can go around the map "dust 2" in CSGO
Written By Jason Shi
12/7/2017
*/

//import stuff
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
  Items* BOMB = new Items("BOMB");
  Items* DEFUSEKIT = new Items("DEFUSEKIT");
  Items* FLASHBANG = new Items("FLASHBANG");
  Items* GRENADE = new Items("GRENADE");

  //create rooms and add the items to the rooms
  Room* current;
  Room* bSite = new Room("bSite", "at B Site, the second site where the bomb can be planted");
  Room* upperTuns = new Room("upperTuns", "at the Upper Tunnels");
  upperTuns->addItem(GRENADE);
  Room* outsideTuns = new Room("outsideTuns","Outside Upper Tunnels");
  Room* tRamp = new Room("tRamp","at T Ramp, the ramp connecting tunnels to T Spawn");
  Room* lowerTuns = new Room("lowerTuns", "at Lower tunnels");
  Room* ctSpawn = new Room("ctSpawn", "at CT Spawn, where the counterterrorists spawn");
  ctSpawn->addItem(DEFUSEKIT);
  Room* mid = new Room("mid", "at mid, the middle of the map");
  Room* suicide = new Room("suicide", "at suicide, a tunnel connecting T Spawn to mid");
  Room* tSpawn = new Room("tSpawn", "at T Spawn, the place where terrorists spawn");
  tSpawn->addItem(AK47);
  tSpawn->addItem(BOMB);
  Room* Short = new Room("Short", "at Short, the walkway connecting Cat to A Site");
  Room* cat = new Room("cat", "at Catwalk, the walkway connecting mid to Short");
  Room* longDoors = new Room("longDoors", "at Long Doors, the doorway connecting Long");
  Room* outsideLong = new Room("outsideLong", "at the section of the map outside of Long");
  Room* aSite = new Room("aSite", "at A Site, the first site where the bomb can be planted");
  Room* cross = new Room("cross", "at cross, the intersection connecting Long, CT Spawn, and A Site");
  Room* Long = new Room("Long", "at Long, the long walkway connecting A Site to T Spawn");
  Room* pit = new Room("pit", "at pit, the pit at the end of long");
  pit->addItem(FLASHBANG);

  //add exits to each room
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

	current = mid; // start game at mid

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
//tell instructions
  cout << "Welcome to CSGO!" << endl;
  cout << "You are a Counterterrorist- " << endl;
  cout << "In order to win, you need to travel to CT Spawn and pick up a defuse kit." << endl;
  cout << "Do not go to tSpawn and pick up the bomb...or you will die" << endl;
  cout << endl;
  cout << "Type GO to go to another room" << endl;
  cout << "Type GET to pick up an item" << endl;
  cout << "Type DROP to drop an item" << endl;
  cout << "Type QUIT to leave the game" << endl;
  cout << "Type HELP to view items and exits" << endl;
  cout << endl;
	
  while(true){
    //check win and lose condition
    //iterate through the inventory and check if there is an item with description of defusekit/bomb
    vector<Items*>::iterator it;
    for(it = inventory.begin(); it != inventory.end(); it++) {
      if (strcmp((*it)->getDescription(), DEFUSEKIT->getDescription())==0) {
        cout << "Congradulations, you have picked up the defuse kit and won the game!!" << endl;
        cout <<"exiting...";
        return 0;
      }else if(strcmp((*it)->getDescription(), BOMB->getDescription())==0){
      cout << "You picked up the bomb and it exploded... Game Over." << endl;
      cout<< "exiting...";
      return 0;
      }
    }
//displays current room and the exits and items
    cout<< "You are " << current->getDescription() <<"." << endl;
    current->printInfo();
    cout << endl;
     //displays inventory
    cout << "You have these items: " << endl;
    for(it = inventory.begin(); it != inventory.end(); it++) {
      cout<< (*it)->getDescription() << endl;
    }
	  //gets user input
    char input[40];
    cout << endl;
    cout << "Please Enter a command: "<<endl;
    cin.getline(input, 40);
      if (strcmp(input, "GO") == 0){
        cout<< "Input the direction where you want to go: (NORTH, SOUTH, EAST, WEST)" << endl;
        cin.getline(input, 40);
        //iterate through until the right room is found
        //check if the direction inputted has a exit
        // if it does, set the current to that room
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
	 //iterate through all items and if its the input, remove it from the room and add it to the inventory
        vector<Items*>::iterator ite;
        for(ite = current->getItems().begin(); ite != current->getItems().end(); ++ite) {   
            if (strcmp((*ite)->getDescription(), input)==0) {
            inventory.push_back(*ite);
            current->removeItem(*ite);
            break;
          }
        }
      } else if(strcmp(input, "DROP") == 0){
	//iterate through the inventory and if the input is found, remove the item from the inventory and add it to the room
        cout<< "Enter the name of the item you want to drop:" <<endl;
        cin.getline(input, 40);
        for(it = inventory.begin(); it != inventory.end(); it++) {
          if (strcmp((*it)->getDescription(), input)==0) {
            current->addItem(*it); 
            it = inventory.erase(it);
            break;
          }
        }
      }else if(strcmp(input, "HELP") == 0){
        //just loops back through, because it displays all the items and exits at the beginning of the while loop
      }
      else if(strcmp(input, "QUIT") == 0){
	//exits
        cout << "Exiting..."<< endl;
        return 0;
      }else{
        cout << "Not a valid command" << endl;
      }
    }
  }
