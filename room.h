#ifndef ROOM_H
#define ROOM_H
#include <cstring>
#include <vector>

using namespace std;

class room {
    private:
        //ADD MAP THING
        const char* description;
        //vector<item*> items;
    public:
        room(const char* newDescription);
        //void setExit(/*direction and neighbor*/);
        //char* getDescription();
        //getInfo, getItem, getExit, removeItem, setItem, getRoomItems
};          

#endif
