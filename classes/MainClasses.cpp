#include "MainClasses.h"
#include <fstream>
#include <iostream>
#include <string>

// to do: please add a method that increases coins and there is a shop

int &player1::accessToAtk() { return this->attack; }

int &player1::accessToHealth() { return this->health; }

int &player2::accessToAtk() { return this->attack; }

int &player2::accessToHealth() { return this->health; }

int brutus::accessToAtk() { return this->attack; }

int brutus::accessToHealth() { return this->attack; }

int zombies::accessToAtk() { return this->attack; }

int zombies::accessToHealth() { return this->health; }

int ghosts::accessToAtk() { return this->attack; }

int ghosts::accessToHealth() { return this->health; }

int player1::damage(int enemeyCount, int enemeyHealth) {

  enemeyHealth -= attack;
  std::cout << "Health Of enemey: " << enemeyHealth << '\n';

  if (enemeyHealth == 0) {
    enemeyCount--;
    return enemeyCount;
  }

  return enemeyHealth;
}

void player1::hpCountDown(int enemeyAtk, int enemeyCount) {
  for (int i = 0; i < enemeyCount; i++) { // replace with gets
    health -= enemeyAtk;
  }
}

int player1::increaseCoinCountForPlayer(int waveNum) {
  switch (waveNum) {
  case 1:
    coins++;
    break;
  case 2:
    coins++;
    break;
  case 3:
    coins += 2;
    break;
  case 6:
    coins += 3;
    break;
  case 9:
    coins += 4;
    break;
  default:
    coins++;
    break;
  }
  return waveNum;
}

int player2::damage(int enemeyHealth, int enemeyCount) {

  enemeyHealth -= attack;
  std::cout << "Health Of enemey: " << enemeyHealth << '\n';

  if (enemeyHealth == 0) {
    enemeyCount--;
    return enemeyCount;
  }

  return enemeyHealth;
}

void player2::hpCountDown(int enemeyAtk, int enemeyCount) {
  for (int i = 0; i < enemeyCount; i++) {
    health -= enemeyAtk;
  }
}

// brutus related
void brutus::killBrute() {
  if (health == 0) {
    bruteCount--;
    health = 250;
  }
}

void brutus::findBruteHpBasedOnCount() { health *= bruteCount; }
void brutus::findBruteAtkBasedOnCount() { attack *= bruteCount; }

int brutus::getBruteCount(int waveNum) {
  if (waveNum == 1) {
    bruteCount = 2;
    brutus::findBruteHpBasedOnCount();
    brutus::findBruteAtkBasedOnCount();
  }

  for (int i = 0; i < waveNum; i++) {
    bruteCount++;
    brutus::findBruteHpBasedOnCount();
    brutus::findBruteAtkBasedOnCount();
  }

  return waveNum;
}

void brutus::damagePlayerOne(player1 &Player1) {
  Player1.accessToHealth() -= attack;
  std::cout << "health of player1: " << Player1.accessToHealth();
}

void brutus::damagePlayerTwo(player2 &Player2) {
  Player2.accessToHealth() -= attack;
  std::cout << "health of player2: " << Player2.accessToHealth() << '\n';
}

void brutus::takeDamageOne(player1 &Player1) {
  health -= Player1.accessToAtk();
}

void brutus::takeDamageTwo(player2 &Player2) {
  health -= Player2.accessToAtk();
}

// zombies related
void zombies::killZomb() {
  while (true) {
    if (health == 0) {
      zombCount--;
      health = 100;
      break;
    }
  }
}
void zombies::findZombHpBasedOnCount() { health *= zombCount; }
void zombies::findZombAtkBasedOnCount() { attack *= zombCount; }

int zombies::getZombCount(int waveNum) {
  if (waveNum == 1) {
    zombCount = 7;
    zombies::findZombHpBasedOnCount();
    zombies::findZombAtkBasedOnCount();
  }

  for (int i = 0; i < waveNum; i++) {
    zombCount++;
    zombies::findZombHpBasedOnCount();
    zombies::findZombAtkBasedOnCount();
  }

  return waveNum;
}

void zombies::damagePlayerOne(player1 &Player1) {
  Player1.accessToHealth() -= attack;
}

void zombies::damagePlayerTwo(player2 &Player2) {
  Player2.accessToHealth() -= attack;
}

void zombies::takeDamageOne(player1 &Player1) {
  health -= Player1.accessToAtk();
}

void zombies::takeDamageTwo(player2 &Player2) {
  health -= Player2.accessToAtk();
}

// ghosts related
void ghosts::killGhosts() {
  while (true) {
    if (health == 0) {
      ghostCount--;
      health = 150;
      break;
    }
  }
}
void ghosts::findGhostHpBasedOnCount() { health *= ghostCount; }
void ghosts::findGhostAtkBasedOnCount() { attack *= ghostCount; }

int ghosts::getGhostCount(int waveNum) {
  if (waveNum == 1) {
    ghostCount = 3;
    ghosts::findGhostHpBasedOnCount();
    ghosts::findGhostAtkBasedOnCount();
  }

  for (int i = 0; i < waveNum; i++) {
    ghostCount++;
    ghosts::findGhostHpBasedOnCount();
    ghosts::findGhostAtkBasedOnCount();
  }

  return waveNum;
}

void ghosts::damagePlayerOne(player1 &Player1) {
  Player1.accessToHealth() -= attack;
}

void ghosts::damagePlayerTwo(player2 &Player2) {
  Player2.accessToHealth() -= attack;
}

void ghosts::takeDamageOne(player1 &Player1) {
  health -= Player1.accessToAtk();
}

void ghosts::takeDamageTwo(player2 &Player2) {
  health -= Player2.accessToAtk();
}

void brutus::increaseCoinCountByBKill(int waveNum) {
  player1 Player1;
  for (int i = 0; i < bruteCount; i++) {
    Player1.increaseCoinCountForPlayer(waveNum); // take in the parameter
  }
}

void zombies::increaseCoinCountByZKill(int waveNum) {
  player1 Player1;
  for (int i = 0; i < zombCount; i++) {
    Player1.increaseCoinCountForPlayer(waveNum); // take in the parameter
  }
}

void ghosts::increaseCoinCountByGKill(int waveNum) {
  player1 Player1;
  for (int i = 0; i < ghostCount; i++) {
    Player1.increaseCoinCountForPlayer(waveNum); // take in the parameter
  }
}
