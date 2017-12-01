#include <cstring>
#include <iterator>
#include <vector>
#include <iostream>
#include "room.h"

using namespace std;

int main(){
    vector<room*> rooms;
    room* bSite = new room("at B Site, the second site where the bomb can be planted");
   /*
    room* upperTuns = new room("at the Upper Tunnels");
    room* outsideTuns = new room("Outside Upper Tunnels");
    room* tRamp = new room("at T Ramp, the ramp connecting tunnels to T Spawn");
    room* lowerTuns = new room("at Lower tunnels");
    room* ctSpawn = new room("at CT Spawn, where the counterterrorists spawn");
    room* mid = new room("at mid, the middle of the map");
    room* suicide = new room("at suicide, a tunnel connecting T Spawn to mid");
    room* tSpawn = new room("at T Spawn, the place where terrorists spawn");
    room* Short = new room("at Short, the walkway connecting Cat to A Site");
    room* cat = new room("at Catwalk, the walkway connecting mid to Short");
    room* longDoors = new room("at Long Doors, the doorway connecting Long");
    room* outsideLong = new room("at the section of the map outside of Long");
    room* aSite = new room("at A Site, the first site where the bomb can be planted");
    room* cross = new room("at cross, the intersection connecting Long, CT Spawn, and A Site");
    room* Long = new room("at Long, the long walkway connecting A Site to T Spawn");
    room* pit = new room("at pit, the pit at the end of long");
*/
    rooms.push_back(bSite);
}

