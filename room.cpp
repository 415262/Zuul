#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"
#include <vector>

using namespace std;

Room::Room() {
  description = new char[100];
  id = 0;
}

char* Room::getDescription() {
  return description;
}

int Room::getID() {
  return id;
}

Item* Room::getItem() {
  return itemList;
}
