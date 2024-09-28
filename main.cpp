#include "include/givePlayers.h"
#include "wave.h"
#include <iostream>
using namespace std;

int main() {

  int players = 0;

  // write it so that it writes that the player has played before and then at
  // what stage has the player played.
  players = givePlayers(players);

  wave(players);

  return 0;
}
