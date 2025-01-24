#include "game.h"

int main() {

    std::srand(std::time(nullptr));
    Game game;
    game.play_the_game();

    return 0;
}
