#include "MainClasses.h"
#include <fstream>
#include <iostream>
#include <string>

// to do: please add a method that increases coins and there is a shop

// create more access points to things
int player1::accessToAtk() { return this->attack; }

int player1::accessToHealth() { return this->health; }

int player2::accessToAtk() { return this->attack; }

int player2::accessToHealth() { return this->health; }

int brutus::accessToHealth() { this->attack; }

int brutus::accessToHealth() { this->attack; }

int zombies::accessToAtk() { return this->attack; }

int zombies::accessToHealth() { return this->health; }

int ghosts::accessToAtk() { return this->attack; }

int ghosts::accessToHealth() { return this->health; }

void player1::killPlayer() {
  if (health == 0) {
    playerCount--;
  }
}

int player1::damage() {

  // replace with the gets-= attack;

  if (enemeyHealth == 0) {
    enemeyCount--; // replace with the gets
    return enemeyCount;
  }

  return enemeyHealth;
}

void player1::hpCountDown() {
  for (int i = 0; i < enemeyCount; i++) { // replace with gets
    health -= enemeyAtk;
  }
}

int player1::increaseCoinCountForPlayer(int waveNum) {
  switch (waveNum) {
  case 1:
    coins++;
  case 2:
    coins++;
  case 3:
    coins += 2;
  case 6:
    coins += 3;
  case 9:
    coins += 4;
  default:
    coins++;
    break;
  }
  return waveNum;
}

void player2::killPlayer() {
  if (health == 0) {
    playerCount--;
  }
}

int player2::damage(int enemeyHealth, int enemeyCount) {

  enemeyHealth -= attack;

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
void brutus::findBruteHpBasedOnCount() { health *= bruteCount; }
void brutus::findBruteAtkBasedOnCount() { attack *= bruteCount; }

int brutus::getBruteCount(int waveNum) {
  if (waveNum == 1) {
    bruteCount = 10;
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

void brutus::damagePlayerOne() { player1::accessToHealth() -= attack; }

void brutus::damagePlayerTwo() { player2::accessToHealth() -= attack; }

void brutus::takeDamageOne() { health -= player1::accessToAtk; }

void brutus::takeDamageTwo() { health -= player2::accessToAtk; }

// zombies related
void zombies::findZombHpBasedOnCount() { health *= zombCount; }
void zombies::findZombAtkBasedOnCount() { attack *= zombCount; }

int zombies::getZombCount(int waveNum) {
  if (waveNum == 1) {
    zombCount = 10;
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

void zombies::damagePlayerOne() { player1::accessToHealth() -= attack; }

void zombies::damagePlayerTwo() { player2::accessToHealth() -= attack; }

void zombies::takeDamageOne() { health -= player1::accessToAtk; }

void zombies::takeDamageTwo() { health -= player2::accessToAtk; }

// ghosts related
void ghosts::findGhostHpBasedOnCount() { health *= ghostCount; }
void ghosts::findGhostAtkBasedOnCount() { attack *= ghostCount; }

int ghosts::getGhostCount(int waveNum) {
  if (waveNum == 1) {
    ghostCount = 2;
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

void ghosts::damagePlayerOne() { player1::accessToHealth() -= attack; }

void ghosts::damagePlayerTwo() { player2::accessToHealth() -= attack; }

void ghosts::takeDamageOne() { health -= player1::accessToAtk; }

void ghosts::takeDamageTwo() { health -= player2::accessToAtk; }

void brutus::increaseCoinCountByBKill(int waveNum) {
  for (int i = 0; i < bruteCount; i++) {
    player1::increaseCoinCountForPlayer(waveNum); // take in the parameter
  }
}

void zombies::increaseCoinCountByZKill(int waveNum) {
  for (int i = 0; i < ghostCount; i++) {
    player1::increaseCoinCountForPlayer(waveNum);
  }
}

void ghosts::increaseCoinCountByGKill(int waveNum) {
  for (int i = 0; i < ghostCount; i++) {
    player1::increaseCoinCountForPlayer(waveNum);
  }
}
