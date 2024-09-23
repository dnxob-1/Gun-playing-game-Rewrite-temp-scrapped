#include "main.h"
#include <iostream>
using namespace std;

int givePlayers(int players) {

  cout << "Number of players (1-2): ";
  cin >> players;

  if (players == 1) {
    cout << "1 player selected\n";
  } else if (players == 2) {
    cout << "2 player selected\n";
  } else {
    cout << "Error:  selected more or less than the required amount of "
            "players. Please retry.\n";
    main();
  }

  return players;
}
