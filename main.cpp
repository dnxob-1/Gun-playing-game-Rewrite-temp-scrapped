#include "findLog.h"
#include "givePlayers.h"
#include "wave.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {

  int players = 0;

  // write it so that it writes that the player has played before and then at
  // what stage has the player played.
  players = givePlayers(players);

  // make line1 appear before this

  wave(players);

  return 0;
}
