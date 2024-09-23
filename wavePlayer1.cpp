#include <iostream>

int wavePlayer1() {
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

  std::cout << "Monsters killed: " << monsters << "\n";
  std::cout << "Coins earned: " << coins << "\n";
  std::cout << "Bullets left: " << bullets << "\n";

  return coins;
  return bullets;
}
