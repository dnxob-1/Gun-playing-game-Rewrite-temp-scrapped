#include "MainClasses.h"
#include "findLog.h"
#include "wavePlayer1.h"
#include "wavePlayer2.h"
#include <iostream>

int wave_init(int waveNum) {
  waveNum++;
  return waveNum;
}

void waveRunner(int waveNum, int holder) {

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

  for (int i = 0; i < Brutus.bruteCount; i++) {
    Brutus.killBrute();
    if (holder == 2) {
      Player2.damage(Brutus.bruteCount, bruteHealth);
      Brutus.damagePlayerTwo(Player2);
    } else {
      Player1.damage(Brutus.bruteCount, bruteHealth);
      Brutus.damagePlayerOne(Player1);
    }
    Brutus.damagePlayerTwo(Player2);
    for (int j = 0; i < Zombies.zombCount; j++) {
      Zombies.killZomb();
      if (holder == 2) {
        Player2.damage(Zombies.zombCount, zombHealth);
        Zombies.damagePlayerTwo(Player2);
      } else {
        Zombies.damagePlayerOne(Player1);
        Player1.damage(Zombies.zombCount, zombHealth);
      }
      Zombies.damagePlayerTwo(Player2);
      for (int p = 0; p < Ghosts.ghostCount; p++) {
        Ghosts.killGhosts();
        if (holder == 2) {
          Ghosts.damagePlayerTwo(Player2);
          Player2.damage(Ghosts.ghostCount, ghostHealth);
        } else {
          Player1.damage(Ghosts.ghostCount, ghostHealth);
          Ghosts.damagePlayerOne(Player1);
        }
        Ghosts.damagePlayerTwo(Player2);
      }
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
    waveRunner(waveNum, Holder);

  } else if (Holder == 1) {

    std::cout << "Player " << Holder << " has been chosen, who currently has "
              << Player1.accessToHealth() << " health Points" << '\n';

    waveRunner(waveNum, Holder);
  } else {
    // make it so that the player count matters here
    std::cout << "An error has occured!" << '\n';
  }
}
