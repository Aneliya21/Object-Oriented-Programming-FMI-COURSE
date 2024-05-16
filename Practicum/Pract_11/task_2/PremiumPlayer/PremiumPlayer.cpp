#include "PremiumPlayer.h"

PremiumPlayer::PremiumPlayer(const char* name) {
	setName(name);
}

PremiumPlayer::PremiumPlayer(const PremiumPlayer& other) {
	copyFrom(other);
}

PremiumPlayer::PremiumPlayer(PremiumPlayer&& other) noexcept {
	moveFrom(std::move(other));
}

PremiumPlayer& PremiumPlayer::operator=(const PremiumPlayer& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

PremiumPlayer& PremiumPlayer::operator=(PremiumPlayer&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

bool PremiumPlayer::levelUp() {

	const Stars& currStars = getStars();

	while (getPoints() >= 256 || getStars() != Stars::Five) {
		const Stars& currStars = getStars();
		int nextStars = (int)currStars + 1;
		levelUpBasedOnPoints(getPoints(), 256, (Stars)nextStars);
	}

	if (currStars != getStars()) {
		return true;
	}
	else {
		return false;
	}
}

PremiumPlayer::~PremiumPlayer() {
	free();
}

void PremiumPlayer::setName(const char* newName) {
	if (!newName) {
		return;
	}
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void PremiumPlayer::copyFrom(const PremiumPlayer& other) {
	setName(other.name);
}
void PremiumPlayer::moveFrom(PremiumPlayer&& other) {
	name = other.name;
	other.name = nullptr;
}
void PremiumPlayer::free() {
	delete[] name;
}