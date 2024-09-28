#include "wave.h"
#include "wavePlayer1.h"
#include "wavePlayer2.h"
#include <iostream>
using namespace std;

void sendToLogging(string line1, int players, int run) {

  string c01;
  c01 = line1;
  // unset vars, set later

  /*string c02;
  string c03;
  string c1;
  string c2;
  string c3;
  string c4;*/

  if (c01 == line1 && run == 1 && players == 2) {
    wavePlayer2(line1);
  } else if (c01 == line1 && run == 1 && players == 1) {
    wavePlayer1(line1);
  }
}
