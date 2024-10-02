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

  cout << "Do you wish to load to the previous position? (Y/n)" << '\n';
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

void sendToLogging(char playersVal) {

  string c01;
  string subc01 = readFromLogFile();
  c01 = subc01;

  // unset vars, set later

  /*string c02;
  string c03;
  string c1;
  string c2;
  string c3;
  string c4;*/

  int outsideReturner = ask();

  if (c01 == subc01 && playersVal == '2' && outsideReturner == 0) {
    wavePlayer2(c01);
  } else if (c01 == subc01 && playersVal == '1' && outsideReturner == 0) {
    wavePlayer1(c01);
  }
}
