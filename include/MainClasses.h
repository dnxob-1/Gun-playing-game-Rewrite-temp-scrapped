#ifndef MAINCLASSES_H
#define MAINCLASSES_H

#include <fstream>
#include <iostream>
#include <string>

class player1 {
private:
  int health = 100;
  int attack = 10;
  int coins = 0;

public:
  int accessToAtk();

  int accessToHealth();

  void killPlayer();

  int damage();

  void hpCountDown();

  int increaseCoinCountForPlayer(int waveNum);
};

class player2 {
private:
  int health = 100;
  int attack = 10;
  int coins = 0;

public:
  int accessToAtk();

  int accessToHealth();

  int killPlayer();

  int damage();

  int hpCountDown();

  int increaseCoinCountForPlayer(int waveNum);
};

class brutus {
private:
  int health = 250;
  int attack = 15;

public:
  int bruteCount = 0;
  void findBruteHpBasedOnCount();
  void findBruteAtkBasedOnCount();
  int getBruteCount(int waveNum);
  void increaseCoinCountByBKill(int waveNum);
  void damagePlayerOne();
  void damagePlayerTwo();
  void takeDamageOne();
  void takeDamageTwo();
  // add an ult
};

class zombies {
private:
  int health = 100;
  int attack = 5;

public:
  int zombCount = 0;
  void findZombHpBasedOnCount();
  void findZombAtkBasedOnCount();
  int getZombCount(int waveNum);
  void increaseCoinCountByZKill(int waveNum);
  void damagePlayerOne();
  void damagePlayerTwo();
  void takeDamageOne();
  void takeDamageTwo();
  // add an ult
};

class ghosts {
private:
  int health = 150;
  int attack = 15;

public:
  int ghostCount = 0;
  void findGhostHpBasedOnCount();
  void findGhostAtkBasedOnCount();
  int getGhostCount(int waveNum);
  void increaseCoinCountByGKill(int waveNum);
  void damagePlayerOne();
  void damagePlayerTwo();
  void takeDamageOne();
  void takeDamageTwo();
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
