#include "GamePlatform.h"

void GamePlatform::swapGames(Game& g1, Game& g2) {
	Game temp = g1;
	g1 = g2;
	g2 = temp;
}

void GamePlatform::addGame(const Game& toAdd) {
	if (currCount + 1 < 100) {
		games[currCount++] = toAdd;
	}
}

void GamePlatform::printGameByInd(unsigned index) const {
	if (index > 0 && index < currCount) {
		games[index].print();
	}
}

void GamePlatform::printAll() const {
	for (unsigned i = 0; i < currCount; i++) {
		games[i].print();
	}
}

void GamePlatform::printFree() const {
	for (unsigned i = 0; i < currCount; i++) {
		if (games[i].isFree()) {
			games[i].print();
		}
	}
}

void GamePlatform::remove(unsigned index) {
	swapGames(games[index], games[currCount - 1]);
	currCount--;
}

void GamePlatform::saveToFile(const char* fileName)  const {
	if (!fileName) {
		return;
	}
	std::ofstream ofs(fileName);

	if (!ofs.is_open()) {
		return;
	}

	for (unsigned i = 0; i < currCount; i++) {
		games[i].save(ofs);
	}
}
void GamePlatform::readFromFile(const char* fileName) {
	if (!fileName) {
		return;
	}

	std::ifstream ifs(fileName);
	if (!ifs.is_open()) {
		return;
	}

	unsigned i = 0;
	while (!ifs.eof()) {
		char titleBuff[64];
		ifs.getline(titleBuff, 64, ' ');
		games[i].setTitle(titleBuff);

		double priceBuff;
		ifs >> priceBuff;
		games[i].setPrice(priceBuff);

		ifs.ignore();

		bool isAvailBuff;
		ifs >> isAvailBuff;
		games[i].setIsAvailable(isAvailBuff);

		ifs.ignore();
		i++;
	}

	currCount = i;

	/*currCount = sizeof(Game) / fileSize - 1;

	for (unsigned i = 0; i < currCount; i++) {
		char titleBuff[64];
		ifs.getline(titleBuff, 64, ' ');
		games[i].setTitle(titleBuff);

		double priceBuff;
		ifs >> priceBuff;
		games[i].setPrice(priceBuff);

		ifs.ignore();

		bool isAvailBuff;
		ifs >> isAvailBuff;
		games[i].setIsAvailable(isAvailBuff);

		ifs.ignore();
	}*/
}