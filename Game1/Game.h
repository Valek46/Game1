#pragma once
#include <iostream>

class Game {
public:
    // Конструктор: задаём размер мира, стартовую позицию и начальное состояние
    Game(int worldSize = 20);

    // Деструктор: здесь просто выведем информацию о завершении игры
    ~Game();

    // Главный игровой цикл
    void run();

    // Геттеры (const-методы, не меняют состояние объекта)
    int getPosition() const;
    int getWorldSize() const;
    int getStepCount() const;

private:
    // Внутреннее состояние (private)
    int position;         // позиция игрока
    const int worldSize;  // размер "мира" (const ? задаётся только в конструкторе)
    bool isRunning;       // флаг "игра идёт"
    int stepCount;        // счётчик шагов

    // Внутренние методы (private)

    // Отрисовка текущего состояния (ничего не меняет ? const)
    void draw() const;

    // Обновление логики игры (меняет состояние ? НЕ const)
    void update(char input);

    // Очистка экрана
    void clearScreen() const;
};

