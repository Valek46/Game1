#include "Game.h"

Game::Game()
    : window(sf::VideoMode(800, 600), "My SFML Game"),
    speed(200.f)
{
    window.setFramerateLimit(60);

    player.setSize(sf::Vector2f(50.f, 50.f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(400 - 25, 300 - 25);
}

void Game::run() {
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time dt = clock.restart();

        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(sf::Time dt) {
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= speed * dt.asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += speed * dt.asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= speed * dt.asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += speed * dt.asSeconds();

    player.move(movement);
}

void Game::render() {
    window.clear(sf::Color::Black);
    window.draw(player);
    window.display();
}
