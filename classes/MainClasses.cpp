#include "MainClasses.h"
#include <fstream>
#include <iostream>
#include <string>

int &player1::accessToAtk() { return this->attack; }
int &player1::accessToHealth() { return this->health; }

int &player2::accessToAtk() { return this->attack; }
int &player2::accessToHealth() { return this->health; }

int player1::setHpToZero() { return this->health = 0; }
int player2::setHpToZero() { return this->health = 0; }

int brutus::accessToAtk() { return this->attack; }
int brutus::accessToHealth() { return this->health; }

int zombies::accessToAtk() { return this->attack; }
int zombies::accessToHealth() { return this->health; }

int ghosts::accessToAtk() { return this->attack; }
int ghosts::accessToHealth() { return this->health; }

int player1::damage(int enemeyHealth, int enemeyCount) {
  enemeyHealth *= enemeyCount;
  enemeyHealth -= attack;
  return enemeyHealth;
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

int player2::damage(int enemeyHealth) {
  enemeyHealth -= attack;
  std::cout << enemeyHealth << '\n';
  return enemeyHealth;
}

// brutus related
void brutus::killBrute() {
  std::cout << "health of brute: " << health << '\n';
  if (health <= 0) {
    bruteCount--;
    health = 200;
    std::cout << "dead\n";
    std::cout << "health after " << health << '\n';
  }
}

void brutus::takeDamage(int healthReturnFromEnemy) {
  health = healthReturnFromEnemy;
}

void brutus::findBruteHpBasedOnCount() { health *= bruteCount; }
void brutus::findBruteAtkBasedOnCount() { attack *= bruteCount; }

int brutus::getBruteCount(int waveNum) {
  if (waveNum == 1) {
    bruteCount = 1;
    brutus::findBruteHpBasedOnCount();
    brutus::findBruteAtkBasedOnCount();
  }

  for (int i = 1; i < waveNum; i++) {
    bruteCount++;
    brutus::findBruteHpBasedOnCount();
    brutus::findBruteAtkBasedOnCount();
  }

  return waveNum;
}

int brutus::damagePlayerOne(player1 &Player1) {
  if (Player1.accessToHealth() <= 0) {
    Player1.setHpToZero();
    std::cout << "Player health has reached 0 : " << Player1.accessToHealth()
              << '\n';
    return 0;
  } else {
    Player1.accessToHealth() -= attack;
    std::cout << "Player health has not reached 0 : "
              << Player1.accessToHealth() << '\n';
    return 1;
  }
}

int brutus::damagePlayerTwo(player2 &Player2) {
  if (Player2.accessToHealth() <= 0) {
    Player2.setHpToZero();
    return 0;
  } else {
    Player2.accessToHealth() -= attack;
    return 1;
  }
}

void brutus::takeDamageOne(player1 &Player1) {
  health -= Player1.accessToAtk();
}

void brutus::takeDamageTwo(player2 &Player2) {
  health -= Player2.accessToAtk();
}

// zombies related
int zombies::killZomb() {
  if (health <= 0) {
    zombCount--;
    health = 50;
    return health;
    std::cout << "dead\n";
    std::cout << "health after " << health << '\n';
  }
  std::cout << "health of zombs: " << health << '\n';
}

void zombies::takeDamage(int healthReturnFromEnemy) {
  health = healthReturnFromEnemy;
}

void zombies::findZombHpBasedOnCount() { health *= zombCount; }
void zombies::findZombAtkBasedOnCount() { attack *= zombCount; }

int zombies::getZombCount(int waveNum) {
  if (waveNum == 1) {
    zombCount = 4;
    zombies::findZombHpBasedOnCount();
    zombies::findZombAtkBasedOnCount();
  }

  for (int i = 1; i < waveNum; i++) {
    zombCount++;
    zombies::findZombHpBasedOnCount();
    zombies::findZombAtkBasedOnCount();
  }

  return waveNum;
}

int zombies::damagePlayerOne(player1 &Player1) {
  if (Player1.accessToHealth() <= 0) {
    Player1.setHpToZero();
    std::cout << "Player health has reached 0 : " << Player1.accessToHealth()
              << '\n';
    return 0;
  } else {
    std::cout << "Player health has not reached 0 : "
              << Player1.accessToHealth() << '\n';
    Player1.accessToHealth() -= attack;
    std::cout << "Player health has not reached 0 : "
              << Player1.accessToHealth() << '\n';
    return 1;
  }
}

int zombies::damagePlayerTwo(player2 &Player2) {
  if (Player2.accessToHealth() <= 0) {
    Player2.setHpToZero();
    return 0;
  } else {
    Player2.accessToHealth() -= attack;
    return 1;
  }
}

void zombies::takeDamageOne(player1 &Player1) {
  health -= Player1.accessToAtk();
}

void zombies::takeDamageTwo(player2 &Player2) {
  health -= Player2.accessToAtk();
}

// ghosts related
void ghosts::killGhosts() {
  if (health <= 0) {
    ghostCount--;
    health = 120;
  }
}

void ghosts::takeDamage(int healthReturnFromEnemy) {
  health = healthReturnFromEnemy;
}

void ghosts::findGhostHpBasedOnCount() { health *= ghostCount; }
void ghosts::findGhostAtkBasedOnCount() { attack *= ghostCount; }

int ghosts::getGhostCount(int waveNum) {
  if (waveNum == 1) {
    ghostCount = 2;
    ghosts::findGhostHpBasedOnCount();
    ghosts::findGhostAtkBasedOnCount();
  }

  for (int i = 1; i < waveNum; i++) {
    ghostCount++;
    ghosts::findGhostHpBasedOnCount();
    ghosts::findGhostAtkBasedOnCount();
  }

  return waveNum;
}

int ghosts::damagePlayerOne(player1 &Player1) {
  if (Player1.accessToHealth() <= 0) {
    Player1.setHpToZero();
    return 0;
  } else {
    Player1.accessToHealth() -= attack;
    return 1;
  }
}

int ghosts::damagePlayerTwo(player2 &Player2) {
  if (Player2.accessToHealth() <= 0) {
    Player2.setHpToZero();
    return 0;
  } else {
    Player2.accessToHealth() -= attack;
    return 1;
  }
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
