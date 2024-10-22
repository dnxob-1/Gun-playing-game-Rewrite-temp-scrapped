#include "MainClasses.h"
#include "findLog.h"
#include "wavePlayer1.h"
#include "wavePlayer2.h"
#include <iostream>

int wave_init(int waveNum) {
  waveNum++;
  return waveNum;
}

void waveRunnerForPlayer2(int waveNum) {

  player2 Player2;
  brutus Brutus;
  zombies Zombies;
  ghosts Ghosts;

  int ghostHealth = Ghosts.accessToHealth();
  int zombHealth = Zombies.accessToHealth();
  int bruteHealth = Brutus.accessToHealth();

  Brutus.getBruteCount(waveNum);
  Zombies.getZombCount(waveNum);
  Ghosts.getGhostCount(waveNum);

  for (int i = 0; i < Brutus.bruteCount; i++) {
    Player2.damage(bruteHealth);
    Brutus.damagePlayerTwo(Player2);
    Brutus.killBrute();
  }

  for (int j = 0; j < Zombies.zombCount; j++) {
    Player2.damage(zombHealth);
    Zombies.damagePlayerTwo(Player2);
    Zombies.killZomb();
  }

  for (int p = 0; p < Ghosts.ghostCount; p++) {
    Player2.damage(ghostHealth);
    Ghosts.damagePlayerTwo(Player2);
    Ghosts.killGhosts();
  }
}

void waveRunnerForPlayer1(int waveNum) {

  player1 Player1;
  brutus Brutus;
  zombies Zombies;
  ghosts Ghosts;

  int ghostHealth = Ghosts.accessToHealth();
  int zombHealth = Zombies.accessToHealth();
  int bruteHealth = Brutus.accessToHealth();

  Brutus.getBruteCount(waveNum);
  Zombies.getZombCount(waveNum);
  Ghosts.getGhostCount(waveNum);

  std::cout << "brute health before: " << bruteHealth << '\n';

  /*for (int i = 0; i < Brutus.bruteCount; i++) {
    bruteHealth = Player1.damage(bruteHealth);
    std::cout << "brute health: " << bruteHealth << '\n';
    Brutus.damagePlayerOne(Player1);
    Brutus.killBrute();
  }*/

  while (Brutus.bruteCount != 0 && bruteHealth != 0) {
    bruteHealth = Player1.damage(bruteHealth);
    std::cout << "brute health: " << bruteHealth << '\n';
    Brutus.damagePlayerOne(Player1);
    Brutus.killBrute();
  }

  std::cout << "zomb health before: " << zombHealth << '\n';

  for (int j = 0; j < Zombies.zombCount; j++) {
    zombHealth = Player1.damage(zombHealth);
    std::cout << "zomb health: " << zombHealth << '\n';
    Zombies.damagePlayerOne(Player1);
    Zombies.killZomb();
  }

  for (int p = 0; p < Ghosts.ghostCount; p++) {
    ghostHealth = Player1.damage(ghostHealth);
    std::cout << "health of ghost: " << ghostHealth << '\n';
    Ghosts.damagePlayerOne(Player1);
    Ghosts.killGhosts();
  }
}

void wave(int waveNum) {
  int Holder = 0;

  std::cout << "Which player do you want to fend off this wave?" << '\n';
  std::cout << "> ";
  std::cin >> Holder;

  player1 Player1;
  player2 Player2;

  if (Holder == 2) {
    std::cout << "Player " << Holder << " has been chosen, who currently has "
              << Player2.accessToHealth() << " health Points" << '\n';
    waveRunnerForPlayer2(waveNum);
  } else if (Holder == 1) {

    std::cout << "Player " << Holder << " has been chosen, who currently has "
              << Player1.accessToHealth() << " health Points" << '\n';

    waveRunnerForPlayer1(waveNum);
  } else {
    // make it so that the player count matters here
    std::cout << "An error has occured!" << '\n';
  }
}
