#include "findLog.h"
#include "main.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int writePlayerToFile(int players) {
  ofstream numPlayers("data/numPlayers.txt");

  numPlayers << players;

  numPlayers.close();

  return players;
}

string readFromPlayerFile(string wildPlayer) {

  ifstream readDatFile("data/numPlayers.txt");

  getline(readDatFile, wildPlayer);

  readDatFile.close();

  return wildPlayer;
}

int givePlayers(int players) {

  string wildPlayer;

  cout << wildPlayer;

  readFromPlayerFile(wildPlayer);

  // players = stoi(wildPlayer);

  // sendToLogging(players);

  cout << "Number of players (1-2): ";
  cin >> players;

  writePlayerToFile(players);

  if (players == 1) {
    cout << "1 player selected\n";
  } else if (players == 2) {
    cout << "2 player selected\n";
  } else {
    cout << "Error:  selected more or less than the required amount of "
            "players. Please retry.\n";
    main();
  }

  return players;
}
