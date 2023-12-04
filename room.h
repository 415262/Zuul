#include <iostream>
#include <cstring>
#include "item.h"
#include <vector>

using namespace std;

class Room {
 public:
  Room();
  char* getDescription();
  int getID();
  Item* getItem();
 private:
  char* description;
  int id;
  vector<Item*> itemList;
}
