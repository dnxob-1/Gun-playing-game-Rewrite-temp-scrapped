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

  player1 Player1;
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

  std::cout << "current ghost health: " << ghostHealth << '\n';

  std::cout << "current ghost count: " << Ghosts.ghostCount << '\n';

  for (int i = 0; i < Brutus.bruteCount; i++) {
    std::cout << "current bruteCount: " << Brutus.bruteCount << '\n';
    Player2.damage(bruteHealth, Brutus.bruteCount);
    std::cout << "current brute health: " << bruteHealth << '\n';
    Brutus.damagePlayerTwo(Player2);
    Brutus.killBrute();
    std::cout << "new brute health: " << bruteHealth << '\n';
    for (int j = 0; i < Zombies.zombCount; j++) {
      Player2.damage(zombHealth, Zombies.zombCount);
      Zombies.damagePlayerTwo(Player2);
      Zombies.killZomb();
    }
    for (int p = 0; p < Ghosts.ghostCount; p++) {
      Ghosts.damagePlayerTwo(Player2);
      Player2.damage(
          ghostHealth,
          Ghosts.ghostCount); // fix this later, switch the parameters.
      Ghosts.damagePlayerTwo(Player2);
      Ghosts.killGhosts();
    }
  }
}

void waveRunnerForPlayer1(int waveNum) {

  player1 Player1;
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

  std::cout << "current ghost health: " << ghostHealth << '\n';

  std::cout << "current ghost count: " << Ghosts.ghostCount << '\n';

  for (int i = 0; i < Brutus.bruteCount; i++) {
    std::cout << "current bruteCount: " << Brutus.bruteCount << '\n';
    Player1.damage(bruteHealth, Brutus.bruteCount);
    std::cout << "current brute health: " << bruteHealth << '\n';
    Brutus.damagePlayerOne(Player1);
    std::cout << "new brute health: " << bruteHealth << '\n';
    Brutus.killBrute();
    for (int j = 0; i < Zombies.zombCount; j++) {
      Zombies.damagePlayerOne(Player1);
      Player1.damage(zombHealth, Zombies.zombCount);
      Zombies.killZomb();
    }
    for (int p = 0; p < Ghosts.ghostCount; p++) {
      Player1.damage(ghostHealth, Ghosts.ghostCount);
      std::cout << "current ghost health: " << ghostHealth << '\n';
      Ghosts.damagePlayerOne(Player1);
      Ghosts.killGhosts();
      std::cout << "new ghost health: " << ghostHealth << '\n';
    }
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
