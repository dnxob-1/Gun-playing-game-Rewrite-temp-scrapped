#include "wavePlayer1.h"
#include "wavePlayer2.h"

int wave(int players) {

  if (players == 2) {
    wavePlayer2();
  } else {
    wavePlayer1();
  }

  return players;
}
