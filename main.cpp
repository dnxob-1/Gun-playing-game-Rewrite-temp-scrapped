#include "MainClasses.h"
#include "findLog.h"
#include "givePlayers.h"
#include "wave.h"
#include <fstream>
#include <iostream>
#include <string>

int main() {

  int players = 0;
  int waveNum = 0;

  // players = givePlayers(players);
  // this was a part of the original code

  waveNum = wave_init(waveNum);
  wave(waveNum);

  return 0;
}
