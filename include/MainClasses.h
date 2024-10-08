#ifndef MAINCLASSES_H
#define MAINCLASSES_H

#include <fstream>
#include <iostream>
#include <string>

class MainPlayers {
private:
  int health = 100;
  int attack = 10;
  int playerCount = 0;
  int coins = 0;

public:
  int setPlayerCount();

  int increasePlayerAtkBasedOnCount();

  int increasePlayerHealthBasedOnCount();

  int killPlayer();

  int damage(int enemeyHealth, int enemeyCount);

  int hpCountDown(int enemeyAtk, int enemeyCount);

  int increaseCoinCountForPlayer(int waveNum);
};

class brutus {
private:
  int health = 250;
  int attack = 15;

public:
  int bruteCount = 0;
  int findBruteHpBasedOnCount();
  int findBruteAtkBasedOnCount();
  int getBruteCount(int waveNum);
  void increaseCoinCountByBKill(int waveNum) {
    // add an ult
  };

  class zombies {
  private:
    int health = 100;
    int attack = 5;

  public:
    int zombCount = 0;
    int findZombHpBasedOnCount();
    int findZombAtkBasedOnCount();
    int getZombCount(int waveNum);
    void increaseCoinCountByZKill(int waveNum) {
      // add an ult
    };

    class ghosts {
    private:
      int health = 150;
      int attack = 15;

    public:
      int ghostCount = 0;
      int findGhostHpBasedOnCount();
      int findGhostAtkBasedOnCount();
      int getGhostCount(int waveNum);
      void increaseCoinCountByGKill(int waveNum);
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
