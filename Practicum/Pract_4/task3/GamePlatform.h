#include "Game.h"

class GamePlatform {
	Game games[100];
	unsigned currCount = 0;

	void swapGames(Game& g1, Game& g2);

public:
	void addGame(const Game& toAdd);

	void printGameByInd(unsigned index) const;

	void printAll() const;

	void printFree() const;

	void remove(unsigned index);

	void saveToFile(const char* fileName) const;
	void readFromFile(const char* fileName);
};