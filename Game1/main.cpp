#include "Game.h"

void printGameSummary(const Game& game) {
    std::cout << "=== Game summary ===\n";
    std::cout << "World size: " << game.getWorldSize() << "\n";
    std::cout << "Final position: " << game.getPosition() + 1
        << " / " << game.getWorldSize() << "\n";
    std::cout << "Total steps: " << game.getStepCount() << "\n";
}

int main() {
    Game game(20);   

    game.run();    
    
    printGameSummary(game);

    return 0;
}
