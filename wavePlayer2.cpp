#include <iostream>

int wavePlayer2() {
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

  std::cout << "True runner";
  std::cout << "Monsters killed: " << monsters << "\n";
  std::cout << "Coins earned: " << coins << "\n";
  std::cout << "Bullets left: " << bullets << "\n";

  return coins;
  return bullets;
}
