#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void logWriter1() {

  ofstream writeToLog("data/logger.txt");

  writeToLog << "Player has played at [0:1]" << "\n";

  writeToLog.close();

  ifstream readFromLog("data/logger.txt");

  string line1;

  readFromLog.close();
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

  cout << value << "\n";

  if (!value) {
    std::cerr << "file err: failed to read int" << std::endl;
  }

  readFromLog2.close();

  return coins;
}

int wavePlayer2() {

  srand(time(NULL));
  int coins = 0;
  int monsters;
  int bullets = 40;

  monsters = rand() % 40 + 1;

  for (int i = 0; i < monsters; i++) {
    bullets--;
    if (monsters <= 25) {
      bullets += 2;
    } else {
      coins++;
    }
    monsters--;
    if (bullets == 0) {
      cout << "0 bullets left.";
      break;
      exit(1);
    }
  }

  cout << "Monsters killed: " << monsters << "\n";
  cout << "Coins earned: " << coins << "\n";
  cout << "Bullets left: " << bullets << "\n";

  logWriter2(coins);

  return coins;
  return bullets;
}
