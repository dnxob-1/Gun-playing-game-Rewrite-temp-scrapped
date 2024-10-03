#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

string logWriter1(string line1) {

  ofstream writeToLog("data/logger.txt");

  writeToLog << "Player has played at [0:1]" << "\n";

  writeToLog.close();

  ifstream readFromLog("data/logger.txt");

  readFromLog.close();

  return line1;
}

int logWriter2(int coins, char count) {

  int value = 0;

  ofstream writeToLog2("data/nums.txt");

  writeToLog2 << coins;

  writeToLog2.close();

  ifstream readFromLog2("data/nums.txt");

  if (!readFromLog2 && count == '1') {
    cerr << "Error: logger.txt does not exist. Did you delete it?" << '\n';
    exit(1);
  }

  string line2;

  getline(readFromLog2, line2);

  value = stoi(line2);

  if (!value) {
    cerr << "file err: failed to read int" << endl;
  }

  readFromLog2.close();

  return coins;
}

int runWave2(char count) {

  srand(time(NULL));

  int coins = 0;
  int monsters = 0;
  int bullets = 40;

  monsters = rand() % 40 + 1;

  for (int i = 0; i < monsters; i++) {
    bullets--;
    monsters--;
    coins++;
    if (bullets == 0) {
      cout << "0 bullets left.";
      break;
    }
  }

  cout << "Monsters killed: " << monsters << "\n";
  cout << "Coins earned: " << coins << "\n";
  cout << "Bullets left: " << bullets << "\n";

  logWriter2(coins, count);

  return coins;
  return bullets;
}

string wavePlayer2(string line1, char count) {

  runWave2(count);

  logWriter1(line1);

  return line1;
}
