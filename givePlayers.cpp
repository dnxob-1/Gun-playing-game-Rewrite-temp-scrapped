#include "findLog.h"
#include "main.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// this was a part of the original code
/*int writePlayerToFile(int players) {
  ofstream numPlayers("data/numPlayers.txt");

  numPlayers << players;

  numPlayers.close();

  return players;
}*/

int givePlayers(int players) {

  cout << "Number of players (1-2): ";
  cin >> players;

  writePlayerToFile(players);

  // make it so that it parses the string of players into int
  if (players == 1) {
    cout << "1 player selected\n";
  } else if (players == 2) {
    cout << "2 player selected\n";
  } else {
    cout << "Error:  selected more or less than the required amount of "
            "players. Please retry.\n";
    main(); // shouldnt be called again as this does the things in main twice
  }

  return players;
}
