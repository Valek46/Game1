#include "Game.h"
#include <thread>
#include <chrono>

Game::Game(int size)
    : position(size / 2), worldSize(size), isRunning(true)
{
}

void Game::draw() const {
    for (int i = 0; i < worldSize; ++i) {
        if (i == position)
            std::cout << '@';
        else
            std::cout << '.';
    }
    std::cout << "\n";
}

void Game::update(char input) {
    if (input == 'a' && position > 0) {
        position -= 1;
    }
    else if (input == 'd' && position < worldSize - 1) {
        position += 1;
    }
    else if (input == 'q') {
        isRunning = false;
    }
}

void Game::clear() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Game::run() {
    while (isRunning) {
        clear();

        draw();

        std::cout << "Controls: a - left, d - right, q - quit\n";
        char command;
        std::cin >> command;

        update(command);

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    std::cout << "Game Over!\n";
}
