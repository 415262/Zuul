//Created 11/28/2023
/*Main program for Zuul*/

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "room.cpp"
#include "item.cpp"
#include "item.h"

using namespace std;

bool isRunning = true;
int playerID = 0; //Player's current room
char input[20];
vector<Room*>::iterator itRoom;

int main() {

  cout << "You arrive at the stageshow you scheduled, but for some reason, the play is delayed! Figure out what happened and save the day, for the show must go on!" << endl;
  cout << "Commands are: LOOK, INVENTORY, GO <direction>, GRAB <item>, DROP <item>, and QUIT" << endl;

  
  while (isRunning) {
    vector <Room*> roomList;
    vector <Item*> inventory;

    getDescription(playerID);
    //print room description based off player ID
    //cin >> input;
    

  }
  return 0;
}

string getDescription(int i) {

  if (i == 0)

}
