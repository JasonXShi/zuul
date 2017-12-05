#ifndef Items_H
#define Items_H

#include <iostream>
using namespace std;

class Items {
 public:
  Items(char* newDescription);
  char* getDescription();
  ~Items();
 private:
  char* description;
};

#endif
