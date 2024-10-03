#include "findLog.h"
#include "givePlayers.h"
#include "wave.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int writeToCounter(int countInt) {

  ofstream counterFile("data/counter.txt");

  counterFile << countInt;

  counterFile.close();

  return countInt;
}

char readFromCounter(char countChar) {

  ifstream counterRead("data/counter.txt");

  string tempR;

  getline(counterRead, tempR);

  countChar = tempR[0];

  counterRead.close();

  return countChar;
}

int main() {

  int players = 0;
  char countChar;
  int countInt = 0;

  // write it so that it writes that the player has played before and then at
  // what stage has the player played.

  countChar = readFromCounter(countChar);

  if (countChar != '0') {
    sendToLogging(countChar);
  }

  if (true) {
    players = givePlayers(players);
    countInt = 1;
    writeToCounter(countInt);
  }
  wave(players, countChar);

  return 0;
}
