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

  players = givePlayers(players);

  MainPlayers playerMain;

  playerMain.setPlayerCount();

  playerMain.increasePlayerAtkBasedOnCount();

  playerMain.increasePlayerHealthBasedOnCount();

  wave_init(waveNum);

  std::cout << waveNum;

  return 0;
}
