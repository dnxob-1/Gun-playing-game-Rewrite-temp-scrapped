#include "MainClasses.h"
#include <fstream>
#include <iostream>
#include <string>

int MainPlayers::setPlayerCount() {
  std::ifstream readFromNumFile("data/numPlayers.txt");

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
  std::cout << "Attack: " << attack << "\n";
  return attack;
}

int MainPlayers::increasePlayerHealthBasedOnCount() {

  if (playerCount == 2) {
    health *= 2;
  }

  std::cout << "Health: " << health << "\n";
  return health;
}

int MainPlayers::killPlayer() {

  if (health == 0) {
    playerCount--;
  }

  std::cout << health;
  return playerCount;
}

/*
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

  std::cout << health;
  return health;
}

int brutus::findBruteHpBasedOnCount() { return health *= bruteCount; }
int brutus::findBruteAtkBasedOnCount() { return attack *= bruteCount; }

int zombies::findZombHpBasedOnCount() { return health *= zombCount; }
int zombies::findZombAtkBasedOnCount() { return attack *= zombCount; }

int ghosts::findGhostHpBasedOnCount() { return health *= ghostCount; }
int ghosts::findGhostAtkBasedOnCount() { return attack *= ghostCount; }*/
