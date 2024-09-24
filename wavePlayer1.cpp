#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int wavePlayer1() {

  srand(time(NULL));
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

  ofstream writeToLog("logger.txt");

  writeToLog << "Player has played at [0:1]" << "\n";
  writeToLog << coins;

  writeToLog.close();

  ifstream readFromLog("logger.txt");

  int value;

  string line1;
  string line2;
  if (getline(readFromLog, line1)) {
    cout << line1;
  }

  // fix
  if (getline(readFromLog, line1)) {
    cout << line2 << "\n";
    readFromLog >> value;
  }

  if (!value) {
    std::cerr << "file err: failed to read int" << std::endl;
  }

  cout << "Something: " << value;

  readFromLog.close();

  return coins;
  return bullets;
}
