#include "findLog.h"
#include "wavePlayer1.h"
#include "wavePlayer2.h"
#include <iostream>
using namespace std;

int wave(int players) {

  string line1;

  int run;

  // make it to so that the player(s) can load their pre-built configure.
  if (players == 2) {
    wavePlayer2(line1);
    run++;
    sendToLogging(line1, players, run);
  } else {
    wavePlayer1(line1);
    run++;
    sendToLogging(line1, players, run);
  }

  return players;
}
