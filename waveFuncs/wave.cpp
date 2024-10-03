#include "findLog.h"
#include "wavePlayer1.h"
#include "wavePlayer2.h"
#include <iostream>
using namespace std;

int wave(int players, char count) {

  string line;

  // make it to so that the player(s) can load their pre-built configure.
  if (players == 2) {
    wavePlayer2(line, count);
  } else {
    wavePlayer1(line, count);
  }

  return players;
}
