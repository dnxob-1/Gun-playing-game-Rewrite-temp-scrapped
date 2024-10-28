

// this was a part of the original code

/*#include "wave.h"
#include "wavePlayer1.h"
#include "wavePlayer2.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int ask() {

  char asker;

  cout << asker;

  cout << "Do you wish to load to the previous position? (Y/n): ";
  cin >> asker;

  if (asker == 'Y' || asker == 'y') {
    return 0;
  } else if (asker == 'N' || asker == 'n') {
    return 1;
  } else {
    cout << "Invalid" << '\n';
    ask();
  }
}

string readFromLogFile(char count) {

  ifstream reader("data/logger.txt");

  if (!reader && count == '1') {
    cerr << "Error: logger.txt does not exist. Did you delete it?" << '\n';
    exit(1);
  }

  string lineGrab;

  getline(reader, lineGrab);

  reader.close();

  return lineGrab;
}

char readFromPlayerFile(char wildPlayer, char count) {

  ifstream readDatFile("data/numPlayers.txt");

  if (!readDatFile && count == '1') {
    cerr << "Error: numPlayers.txt does not exist. Did you delete it?" << '\n';
    exit(1);
  }

  string tempL;

  getline(readDatFile, tempL);

  wildPlayer = tempL[0];

  readDatFile.close();

  return wildPlayer;
}

int sendToLogging(char count) {

  string c01;
  string subc01 = readFromLogFile(count);
  c01 = subc01;

  char wildPlayer;
  int outsideReturner;

  wildPlayer = readFromPlayerFile(wildPlayer, count);

  if (c01 == subc01 && wildPlayer == '2') {
    outsideReturner = ask();
    if (outsideReturner == 1) {
      cout << "Leaving..." << '\n';
      exit(1);
    }
  } else if (c01 == subc01 && wildPlayer == '1') {
    outsideReturner = ask();
    if (outsideReturner == 1) {
      cout << "Leaving..." << '\n';
      exit(1);
    }
  }
  return 1;
}*/
