#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

string logWriter3(string line1) {

  ofstream writeToLog("data/logger.txt");

  writeToLog << "Player has played at [0:1]" << "\n";

  writeToLog.close();

  return line1;
}

int numWriter4(int coins) {

  int value;

  ofstream writeToNum2("data/nums.txt");

  writeToNum2 << coins;

  writeToNum2.close();

  ifstream readFromNum2("data/nums.txt");

  string line2;

  getline(readFromNum2, line2);

  value = stoi(line2);

  if (!value) {
    cerr << "file err: failed to read int" << endl;
  }

  readFromNum2.close();

  return coins;
}

int runWave() {
  int coins = 0;
  int monsters = 0;
  int bullets = 20;

  monsters = rand() % 20 + 1;

  for (int i = 0; i < monsters; i++) {
    bullets--;
    monsters--;
    coins++;
    if (bullets == 0) {
      std::cout << "0 bullets left.";
      break;
    }
  }

  cout << "Monsters killed: " << monsters << "\n";
  cout << "Coins earned: " << coins << "\n";
  cout << "Bullets left: " << bullets << "\n";

  numWriter4(coins);

  return coins;
  return bullets;
}

string wavePlayer1(string line1) {

  srand(time(NULL));

  runWave();

  logWriter3(line1);

  return line1;
}
