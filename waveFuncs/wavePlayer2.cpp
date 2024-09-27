#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string logWriter1(string line1) {

  ofstream writeToLog("data/logger.txt");

  writeToLog << "Player has played at [0:1]" << "\n";

  writeToLog.close();

  ifstream readFromLog("data/logger.txt");

  readFromLog.close();

  return line1;
}

int logWriter2(int coins) {

  int value;

  ofstream writeToLog2("data/nums.txt");

  writeToLog2 << coins;

  writeToLog2.close();

  ifstream readFromLog2("data/nums.txt");

  string line2;

  getline(readFromLog2, line2);

  value = stoi(line2);

  if (!value) {
    cerr << "file err: failed to read int" << std::endl;
  }

  readFromLog2.close();

  return coins;
}

int runWave() {
  int coins = 0;
  int monsters;
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

  logWriter2(coins);

  return coins;
  return bullets;
}

string wavePlayer1(string line2) {

  srand(time(NULL));

  line2 = "NULL";

  runWave();

  logWriter1(line2);

  return line2;
}
