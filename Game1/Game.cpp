#include "Game.h"
#include <thread>
#include <chrono>

Game::Game(int size)
    : position(size / 2),   // стартуем примерно из середины
    worldSize(size),      // инициализация const-поля
    isRunning(true),
    stepCount(0)
{
    std::cout << "Game created. World size = " << worldSize << "\n";
}

Game::~Game() {
    std::cout << "Game destroyed. Total steps = " << stepCount << "\n";
}

void Game::clearScreen() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Game::draw() const {
    clearScreen();

    // Рамка сверху
    std::cout << '+';
    for (int i = 0; i < worldSize; ++i) {
        std::cout << '-';
    }
    std::cout << "+\n";

    // Линия с игроком
    std::cout << '|';
    for (int i = 0; i < worldSize; ++i) {
        if (i == position) {
            std::cout << '@';
        }
        else {
            std::cout << '.';
        }
    }
    std::cout << "|\n";

    // Рамка снизу
    std::cout << '+';
    for (int i = 0; i < worldSize; ++i) {
        std::cout << '-';
    }
    std::cout << "+\n";

    std::cout << "Controls: a - left, d - right, q - quit\n";
    std::cout << "Position: " << position + 1 << "/" << worldSize
        << " | Steps: " << stepCount << "\n";
}

void Game::update(char input) {
    if (input == 'a') {
        if (position > 0) {
            position -= 1;
            ++stepCount;
        }
    }
    else if (input == 'd') {
        if (position < worldSize - 1) {
            position += 1;
            ++stepCount;
        }
    }
    else if (input == 'q') {
        isRunning = false;
    }
}

void Game::run() {
    while (isRunning) {
        draw();

        char command;
        std::cin >> command;

        update(command);

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    std::cout << "Game Over!\n";
}

// ----- Геттеры (const-методы) -----

int Game::getPosition() const {
    return position;
}

int Game::getWorldSize() const {
    return worldSize;
}

int Game::getStepCount() const {
    return stepCount;
}
