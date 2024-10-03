#include "wave.h"
#include "wavePlayer1.h"
#include "wavePlayer2.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int ask() {

  char asker;

  cout << "Do you wish to load to the previous position? (Y/n): ";
  cin >> asker;

  if (asker == 'Y' || asker == 'y') {
    return 0;
  } else if (asker == 'N' || asker == 'n') {
    return 1;
  } else {
    cout << "Invalid" << '\n';
    ask();
    return 1;
  }
}

string readFromLogFile() {

  string line2;
  ifstream reader("data/logger.txt");

  getline(reader, line2);

  reader.close();

  return line2;
}

char readFromPlayerFile(char wildPlayer) {

  ifstream readDatFile("data/numPlayers.txt");

  string tempL;

  getline(readDatFile, tempL);

  wildPlayer = tempL[0];

  readDatFile.close();

  return wildPlayer;
}

int sendToLogging() {

  string c01;
  string subc01 = readFromLogFile();
  char wildPlayer;
  int outsideReturner;
  c01 = subc01;

  wildPlayer = readFromPlayerFile(wildPlayer);

  if (c01 == subc01 && wildPlayer == '2') {
    outsideReturner = ask();
    cout << outsideReturner;
    if (outsideReturner == 0) {
      wavePlayer2(c01);
    } else if (outsideReturner == 1) {
      exit(1);
    }
  } else if (c01 == subc01 && wildPlayer == '1') {
    outsideReturner = ask();
    if (outsideReturner == 0) {
      wavePlayer1(c01);
    } else if (outsideReturner == 1) {
      exit(1);
    }
  }

  return 1;
}
