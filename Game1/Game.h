#pragma once
#include <iostream>

class Game {
private:
	int position;
	const int worldSize;
	bool isRunning;

public:
	Game(int worldSize = 20);

	void run();
	void clear() const;
	void update(char input);
	void draw() const;
};
