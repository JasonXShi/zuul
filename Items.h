//includes stuff and header guards
#ifndef Items_H
#define Items_H
#include <iostream>
using namespace std;

class Items {
 public:
//defines constructer, destructer, and method of getting the description
 Items(char* newDescription);
  char* getDescription();
  ~Items();
 private:
 //initializes the description (char*)
  char* description;
};

#endif
