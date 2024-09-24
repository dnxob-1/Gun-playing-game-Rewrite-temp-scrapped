#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int wavePlayer2() {

  srand(time(NULL));
  int coins = 0;
  int monsters;
  int bullets = 40;

  monsters = rand() % 40 + 1;

  for (int i = 0; i < monsters; i++) {
    bullets--;
    monsters--;
    coins++;
    if (bullets == 0) {
      std::cout << "0 bullets left.";
      break;
    }
  }

  std::cout << "Monsters killed: " << monsters << "\n";
  std::cout << "Coins earned: " << coins << "\n";
  std::cout << "Bullets left: " << bullets << "\n";

  ofstream writeToLog("logger.txt");

  writeToLog << "Player has played at [0:1]" << "\n";
  writeToLog << coins;

  writeToLog.close();

  ifstream readFromLog("logger.txt");

  // int value;

  string line1;
  string line2;

  /*if (getline(readFromLog, line1)) {
    cout << line1;
  }*/

  // fix
  /*if (getline(readFromLog, line1)) {
    cout << line2 << "\n";
    readFromLog >> value;
  }*/

  while (getline(readFromLog, line1)) {

    /*if (line1 == typeid(int)) {
    }*/
    cout << line1;
  }

  /*if (!value) {
    std::cerr << "file err: failed to read int" << std::endl;
  }*/

  // cout << "Something: " << value;

  readFromLog.close();

  return coins;
  return bullets;
}
