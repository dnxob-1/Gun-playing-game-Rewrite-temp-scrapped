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
    Brutus.killBrute();
    std::cout << "current bruteCount: " << Brutus.bruteCount << '\n';
    Player2.damage(Brutus.bruteCount, bruteHealth);
    std::cout << "current brute health: " << bruteHealth << '\n';
    Brutus.damagePlayerTwo(Player2);
    for (int j = 0; i < Zombies.zombCount; j++) {
      Zombies.killZomb();
      Player2.damage(Zombies.zombCount, zombHealth);
      Zombies.damagePlayerTwo(Player2);
    }
    Zombies.damagePlayerTwo(Player2);
    for (int p = 0; p < Ghosts.ghostCount; p++) {
      Ghosts.killGhosts();
      Ghosts.damagePlayerTwo(Player2);
      Player2.damage(Ghosts.ghostCount, ghostHealth);
    }
    Ghosts.damagePlayerTwo(Player2);
  }
  std::cout << ghostHealth << '\n';
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
    Brutus.killBrute();
    std::cout << "current bruteCount: " << Brutus.bruteCount << '\n';
    Player1.damage(Brutus.bruteCount, bruteHealth);
    std::cout << "current brute health: " << bruteHealth << '\n';
    Brutus.damagePlayerOne(Player1);
    for (int j = 0; i < Zombies.zombCount; j++) {
      Zombies.killZomb();
      Zombies.damagePlayerOne(Player1);
      Player1.damage(Zombies.zombCount, zombHealth);
    }
    Zombies.damagePlayerTwo(Player2);
    for (int p = 0; p < Ghosts.ghostCount; p++) {
      Ghosts.killGhosts();
      Player1.damage(Ghosts.ghostCount, ghostHealth);
      Ghosts.damagePlayerOne(Player1);
    }
  }
  std::cout << ghostHealth << '\n';
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
