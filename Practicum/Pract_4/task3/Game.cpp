#include "Game.h"


Game::Game(const char* title, double price, bool isAvailable) {
	setTitle(title);
	setPrice(price);
	setIsAvailable(isAvailable);
}

void Game::setTitle(const char* title) {
	if (!title || strlen(title) > 64) {
		return;
	}
	strcpy(this->title, title);
}
void Game::setPrice(double price) {
	this->price = price;
}
void Game::setIsAvailable(bool isAvailable) {
	this->isAvailable = isAvailable;
}

const char* Game::getTitle() const {
	return title;
}
double Game::getPrice() const {
	return price;
}
bool Game::getIsAvailable() const {
	return isAvailable;
}

bool Game::isFree() const {
	return (price == 0.0);
}
void Game::print() const {
	std::cout << title << " " << price << " ";
	(isAvailable ? std::cout << "yes" : std::cout << "no");

	std::cout << std::endl;
}

void Game::save(std::ofstream& ofs) const {
	if (!ofs.is_open()) {
		return;
	}
	ofs << title <<" "<< price << " " << isAvailable << std::endl;
}