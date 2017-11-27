#ifndef ROOM_H
#define ROOM_H
#include <cstring>

struct item{
    char item = char[50];
};
class room{
public:
    room(char* newDescription);
    void setExit(/*direction and neighbor*/);
    char* getDescription();
    //getInfo, getItem, getExit, removeItem, setItem, getRoomItems
private:
    //ADD MAP THING
    char description = char[50];
    vector<item*> items;
};          

#endif
