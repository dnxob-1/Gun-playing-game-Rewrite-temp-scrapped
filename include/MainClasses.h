#ifndef MAINCLASSES_H
#define MAINCLASSES_H

#include <fstream>
#include <iostream>
#include <string>

class player1 {
private:
  int health = 150;
  int attack = 15;
  int coins = 0;

public:
  int &accessToAtk();
  int &accessToHealth();
  int setHpToZero();
  int damage(int enemeyHealth, int enemeyCount);
  int increaseCoinCountForPlayer(int waveNum);
};

class player2 {
private:
  int health = 100;
  int attack = 10;
  int coins = 0;

public:
  int &accessToAtk();
  int &accessToHealth();
  int setHpToZero();
  int damage(int enemeyHealth);
  int increaseCoinCountForPlayer(int waveNum);
};

class brutus {
private:
  int health = 150;
  int attack = 5;

public:
  int bruteCount = 0;
  void killBrute();
  void takeDamage(int healthReturnFromEnemy);
  int accessToAtk();
  int accessToHealth();
  void findBruteHpBasedOnCount();
  void findBruteAtkBasedOnCount();
  int getBruteCount(int waveNum);
  void increaseCoinCountByBKill(int waveNum);
  int damagePlayerOne(player1 &Player1);
  int damagePlayerTwo(player2 &Player2);
  void takeDamageOne(player1 &Player1);
  void takeDamageTwo(player2 &Player2);
  // add an ult
};

class zombies {
private:
  int health = 30;
  int attack = 5;

public:
  int zombCount = 0;
  int killZomb();
  void takeDamage(int healthReturnFromEnemy);
  int accessToAtk();
  int accessToHealth();
  void findZombHpBasedOnCount();
  void findZombAtkBasedOnCount();
  int getZombCount(int waveNum);
  void increaseCoinCountByZKill(int waveNum);
  int damagePlayerOne(player1 &Player1);
  int damagePlayerTwo(player2 &Player2);
  void takeDamageOne(player1 &Player1);
  void takeDamageTwo(player2 &Player2);
  // add an ult
};

class ghosts {
private:
  int health = 100;
  int attack = 10;

public:
  int ghostCount = 0;
  void killGhosts();
  void takeDamage(int healthReturnFromEnemy);
  int accessToAtk();
  int accessToHealth();
  void findGhostHpBasedOnCount();
  void findGhostAtkBasedOnCount();
  int getGhostCount(int waveNum);
  void increaseCoinCountByGKill(int waveNum);
  int damagePlayerOne(player1 &Player1);
  int damagePlayerTwo(player2 &Player2);
  void takeDamageOne(player1 &Player1);
  void takeDamageTwo(player2 &Player2);
  // add an ult
};

class RoboRabbit {
private:
  int health = 500;
  int attack = 25;

public:
  int roboCount = 0;

  // add an ult
};

#endif
