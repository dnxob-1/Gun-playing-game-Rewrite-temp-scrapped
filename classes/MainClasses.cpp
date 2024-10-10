#include "MainClasses.h"
#include <fstream>
#include <iostream>
#include <string>

// to do: please add a method that increases coins and there is a shop

int MainPlayers::setPlayerCount() {
  std::ifstream readFromNumFile("data/numPlayers.txt");

  if (!readFromNumFile) {
    std::cerr << "File could not be read. Does it exist?";
  }

  std::string tempP;

  std::getline(readFromNumFile, tempP);

  playerCount = std::stoi(tempP);

  readFromNumFile.close();

  return playerCount;
}

int MainPlayers::increasePlayerAtkBasedOnCount() {

  if (playerCount == 2) {
    attack *= 2;
  }
  return attack;
}

int MainPlayers::increasePlayerHealthBasedOnCount() {

  if (playerCount == 2) {
    health *= 2;
  }

  return health;
}

/*int MainPlayers::killPlayer() {

  if (health == 0) {
    playerCount--;
  }

  return playerCount;
}

int mainPlayers::damage(int enemeyHealth, int enemeyCount) {
  enemeyHealth -= attack;

  if (enemeyHealth == 0) {
    enemeyCount--;
    return enemeyCount;
  }

  return enemeyHealth;
}

int mainPlayers::hpCountDown(int enemeyAtk, int enemeyCount) {
  for (int i = 0; i < enemeyCount; i++) {
    health -= enemeyAtk;
  }

  return health;
}

int mainPlayers::increaseCoinCountForPlayer(waveNum) {
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
    conis++;
    break;
  }
  return waveNum;
}

// brutus related
int brutus::findBruteHpBasedOnCount() { return health *= bruteCount; }
int brutus::findBruteAtkBasedOnCount() { return attack *= bruteCount; }

int brutus::getBruteCount(waveNum) {
  if (waveNum == 1) {
    bruteCount = 10;
    findBruteHpBasedOnCount();
    findBruteAtkBasedOnCount();
  }

  for (int i = 0; i < waveNum; i++) {
    bruteCount++;
    findBruteHpBasedOnCount();
    findBruteAtkBasedOnCount();
  }

  return waveNum;
}

// zombies related
int zombies::findZombHpBasedOnCount() { return health *= zombCount; }
int zombies::findZombAtkBasedOnCount() { return attack *= zombCount; }

int zombies::getZombCount(waveNum) {
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

// ghosts related
int ghosts::findGhostHpBasedOnCount() { return health *= ghostCount; }
int ghosts::findGhostAtkBasedOnCount() { return attack *= ghostCount; }

int ghosts::getGhostCount(waveNum) {
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

void brutus::increaseCoinCountByBKill(int waveNum) {
  for (int i = 0; i < bruteCount; i++) {
    mainPlayers::increaseCoinCountForPlayer(); // take in the parameter of
                                               // monstType
  }
}

void zombies::increaseCoinCountByZKill(int waveNum) {
  for (int i = 0; i < ghostCount; i++) {
    mainPlayers::increaseCoinCountForPlayer();
  }
}

void ghosts::increaseCoinCountByGKill(int waveNum) {
  for (int i = 0; i < ghostCount; i++) {
    mainPlayers::increaseCoinCountForPlayer();
  }
}*/
