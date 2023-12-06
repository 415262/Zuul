//Created 11/28/2023
/*Main program for Zuul*/
/*TO-DO: 
"You can't go that way" for false exits, "<Item> is on the ground"
The only vector is the player inventory, the only class are the Items

Because I am behind in the class right now, I am prioritizing speed over functionality
You cannot drop any item, only GIVE the required one
You cannot grab specific items, only PICKUP required ones.


 */

#include <iostream>
#include <cstring>
//#include <vector>
//#include "room.h"
//#include "room.cpp"
//#include "item.cpp"
//#include "item.h"

using namespace std;

//Major Events
bool isRunning = true;
//bool boughtTicket = false;
//bool boughtSnacks = false;
bool gotMoney1 = false;//Tracks if items have been taken
bool gotMoney2 = false;//even if already spent on other items
bool gotMask = false;
bool gaveMask = false;

//Items
bool hasMoney1 = false;
bool hasMoney2 = false;
bool hasSnacks = false;
bool hasPass = false;
bool hasMask = false;
bool hasTicket = false;

int playerID = 0; //Player's current room
string input;
//vector<Room*>::iterator itRoom;
void getDescription(int i);

int main() {

  cout << "You arrive at the stageshow you scheduled, but for some reason, the play is delayed! Figure out what happened and save the day, for the show must go on!" << endl;
  cout << "Commands are: INVENTORY, NORTH/SOUTH/EAST/WEST, PICKUP, GIVE, and QUIT" << endl;

  //Save on time: You can only grab items on floor, you're only able to drop what you need to.
  
  while (isRunning) {
    //vector <Room*> roomList;
    //vector <Item*> inventory;
    if (playerID == 8 && gaveMask == true && hasTicket == true) {
      cout << "Returning to your seat, you feel satisfied with what you accomplished. You got your ticket. You used the backstage pass to find the actor. You returned the mask.";
      if (hasSnacks == true) {
	cout << " And hey, you even found time to get some snacks!";
      }
      cout << " You saved the show!." << endl;
      if (hasSnacks == true) {
	cout << "Afterwards, you had some popcorn left over, and shared some the lead actor. Over time you two got closer and came to be great friends." << endl;
	  }
      cout << "This game was brought to you by Ethan Larson, hope you enjoyed it!";
      return 0;
    }
    getDescription(playerID);
    //print room description based off player ID
    cin >> input;
    if (input == "NORTH") {// Directions for going North
      if (playerID == 0) {
	playerID = 1;
	continue;
      }
      if (playerID == 1) {
	playerID = 2;
	continue;
      }
      if (playerID == 2) {
	playerID = 8;
	continue;
      }
      if (playerID == 4) {
	playerID = 3;
	continue;
      }
      if (playerID == 7) {
	playerID = 6;
	continue;
      }
      if (playerID == 9) {
	playerID = 10;
	continue;
      }
      if (playerID == 11) {
	playerID = 13;
	continue;
      }
      if (playerID == 13) {
	playerID = 14;
	continue;
      }
      else {
	cout << "You can't go that way." << endl;
      }
    }
    if (input == "EAST") {// Directions for going East
      if (playerID == 2) {
	playerID = 6;
	continue;
      }
      if (playerID == 3) {
	playerID = 2;
	continue;
      }
      if (playerID == 5) {
	playerID = 3;
	continue;
      }
      if (playerID == 9) {
	playerID = 8;
	continue;
      }
      if (playerID == 10) {
	playerID = 11;
	continue;
      }
      if (playerID == 11) {
	playerID = 12;
	continue;
      }
      else {
	cout << "You can't go that way." << endl;
      }
    }
    if (input == "SOUTH") {// Directions for going South
      if (playerID == 1) {
	playerID = 0;
	continue;
      }
      if (playerID == 2) {
	playerID = 1;
	continue;
      }
      if (playerID == 3) {
	playerID = 4;
	continue;
      }
      if (playerID == 6) {
	playerID = 7;
	continue;
      }
      if (playerID == 8) {
	playerID = 2;
	continue;
      }
      if (playerID == 10) {
	playerID = 9;
	continue;
      }
      if (playerID == 13) {
	playerID = 11;
	continue;
      }
      if (playerID == 14) {
	playerID = 13;
	continue;
      }
      else {
	cout << "You can't go that way." << endl;
      }
    }
    if (input == "WEST") {// Directions for going West
      if (playerID == 2) {
	playerID = 3;
	continue;
      }
      if (playerID == 3) {
	playerID = 5;
	continue;
      }
      if (playerID == 6) {
	playerID = 2;
	continue;
      }
      if (playerID == 8 && hasPass == true) {
	playerID = 9;
	continue;
      }
      if (playerID == 11) {
	playerID = 10;
	continue;
      }
      if (playerID == 12) {
	playerID = 11;
	continue;
      }
    }
    if (input == "INVENTORY") {// Prints Inventory
      cout << "Current inventory." << endl;
      if (hasMoney1) {
	cout << "Some money" << endl;
      }
      if (hasMoney2) {
	cout << "Some money" << endl;
      }
      if (hasPass) {
	cout << "A backstage pass" << endl;
      }
      if (hasSnacks) {
	cout << "A bucket of popcorn." << endl;
      }
      continue;
    }
    if (input == "PICKUP") {//Picks up item from ground
      if (playerID == 0 && gotMoney1 == false) {
	cout << "You picked up the money from the ground." << endl;
	gotMoney1 = true;
	hasMoney1 = true;
	continue;
      }
      if (playerID == 4 && gotMask == false) {
	cout << "You picked up the mask by the sinks." << endl;
	gotMask = true;
	hasMask = true;
	continue;
      }
      if (playerID == 7 && hasPass == false) {
	cout << "You picked up the backstage pass from the ground." << endl;
	hasPass = true;
	continue;
      }
      if (playerID == 14) {
	cout << "You picked up the money from the ground." << endl;
	gotMoney2 = true;
	hasMoney2 = true;
	continue;
      }
      else {
	cout << "There is nothing here to pickup." << endl;
	continue;
      }
    }
    if (input == "GIVE") {
      if (playerID == 1 && hasPass == false) {
	if (hasMoney1 == false && hasMoney2 == false) {
	  cout << "You have no money to exchange." << endl;
	  continue;
	}
	else if (hasMoney1 == true) {
	  cout << "You exchanged some money for a ticket." << endl;
	  hasMoney1 = false;
	  hasPass = true;
	  continue;
	}
	else {
	  cout<< "You exchanged some money for a ticket." << endl;
	  hasMoney2 = false;
	  hasPass = true;
	  continue;
	}
      }
      if (playerID == 6 && hasSnacks == false) {
	if (hasMoney1 == false && hasMoney2 == false) {
	  cout << "You have no money to exchange." << endl;
	  continue;
	}
	else if (hasMoney1 == true) {
	  cout << "You exchanged some money for a bucket of popcorn." << endl;
	  hasMoney1 = false;
	  hasSnacks = true;
	  continue;
	}
	else {
	  cout<< "You exchanged some money for a bueckt of popcorn." << endl;
	  hasMoney2 = false;
	  hasSnacks = true;
	  continue;
	}
      }
      if (playerID == 12 && gaveMask == false) {
	if (hasMask == true) {
	  cout << "You give the mask to the actor. 'Thanks a million! Now the show can continue!" << endl;
	  cout << "'Make your way back to your seat, and if you will, enjoy the show!'" << endl;
	  hasMask = false;
	  gaveMask = true;
	  continue;
	}
	else {
	  cout << "The actor looks at you confused. 'I appreciate the sentiment, but you don't seem to have my mask." << endl;
	  cout << "'Do please find it quickly, the audience is waiting...'" << endl;
	  continue;
	}
      }
      else {
	cout << "There is nothing to give here." << endl;
	continue;
      }
    }
    if (input == "QUIT") {
      return 0;
    }
    else {
      cout << "Not a valid command." << endl;
    }

  }
  return 0;
}

void getDescription(int i) {

  if (i == 0) {
    cout << "You are outside on the street. The only thing in between you and the theater is a ticket booth." << endl;
    if (hasMoney1 == false) {
      cout << "There is some money on the ground to PICKUP." << endl;
    }
    cout << "NORTH to go to the ticket booth" << endl;
  }
  if (i == 1) {
    cout << "You are at the ticket booth.";
    if (hasTicket) {
      cout << "You can no longer buy a ticket." << endl;
    }
    else {
      cout << "Here you can GIVE money for a ticket" << endl;
    }
    cout << "NORTH to go inside, SOUTH to go back to the street." << endl;
  }
  if (i == 2) {
    cout << "You are inside the lobby. There is a general sense of confusion among the people." << endl;
    cout << "NORTH is the house seating, EAST is the consession stand, SOUTH to the ticket booth, and WEST to the bathrooms." << endl; 
  }
  if (i == 3) {
    cout << "You are in the bathroom enterance. You're pretty sure no one else is here right now. Maybe." << endl;
    cout << "You can check the stalls in the WEST, or the sinks to the SOUTH." << endl;
  }
  if (i == 4) {
    cout << "The sinks are pristine, made of white cermaic and marble. They're shockingly clean." << endl;
    if (hasMask == false) {
      cout << "There is a MASK by the sinks to PICKUP" << endl;
    }
    else {
      cout << "This is where you found the MASK." << endl;
    }
    cout << "NORTH to leave the sinks." << endl;
  }
  if (i == 5) {
    cout << "Thankfully, all of the stalls are empty. And the toilets too." << endl;
    cout << "EAST to leave the stalls." << endl;
  }
  if (i == 6) {
    cout << "You are at the consession stand.";
    if (hasSnacks) {
      cout << " They are sold out on snacks." << endl;
    }
    else {
      cout << " Here, you can GIVE money for a snack." << endl;
    }
    cout << "To the SOUTH there is a storage closet, and WEST is the lobby" << endl;
  }
  if (i == 7) {
    cout << "It's very dark and messy in here. You have a feeling this place isn't supposed to be accessible to the public." << endl;
    if (hasPass == false) {
      cout << "There is a Backstage Pass on the ground to PICKUP" << endl;
    }
    else {
      cout << "This is where you found the Backstage Pass." << endl;
    }
    cout << "Go NORTH to return to the consession stand." << endl;
  }
  if (i == 8) {
    cout << "You are in the main house seating. The seats are velvet red. There is a commotion, why isn't the show starting?" << endl;
    cout << "To the SOUTH is the Lobby, to the WEST you see a side path for cast & crew, but you need a BACKSTAGE PASS to go there." << endl;
  }
  if (i == 9) {
    cout <<  "You are in a dark hallway. A single lightbulb lights the path. It's a wonder how anyone navigates this." << endl;
    cout << "NORTH to continue up the hallway, or EAST to go back to house seating." << endl;
  }
  if (i == 10) {
    cout <<"You find yourself Stage Right. People with headphones and props are running around, none of them pay notice to you." << endl;
    cout << "SOUTH to go back in the hallway, EAST to get on stage." << endl;
  }
  if (i == 11) {
    cout << "On the stage of the theater, the lights point right at you. They're so bright that you can't see the audience." << endl;
    cout << "NORTH to go Backstage, EAST to go to Stage Right, WEST to go to Stage Left." << endl;
  }
  if (i == 12) {
    cout << "Here actors are doing their makeup, getting their costumes, rehearsing lines, and doing vocal warm-ups." << endl;
    if (gaveMask == false) {
      cout << "An actor walks up to you. 'Hi, I can't find the MASK for my costume. Can you help me find it?'" << endl;
    }
    else {
      cout << "The actor walks up to you. 'Thank you for finding my MASK, now the show must go on!'" << endl;
    }
    cout << "WEST to return to the main stage." << endl;
  }
  if (i == 13) {
    cout << "Backstage you see the director pacing back and forth, then eye you. 'Are you here to help? Help us find our lead's costume.'" << endl;
    cout << "NORTH to go to the back alley, or SOUTH to return to the stage." << endl;
  }
  if (i == 14) {
    cout << "You are back outside behind the theater. You hear cars in the distance, and there's a faint smell of smoke." << endl;
    cout << "Go SOUTH to return inside." << endl;
  }
  return;
}

