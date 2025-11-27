#pragma once
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void run(); // главный цикл игры

private:
    void processEvents();   // обработка событий
    void update(sf::Time dt); // логика
    void render();           // отрисовка

private:
    sf::RenderWindow window;
    sf::RectangleShape player;
    float speed;
};

