#include "Player.h"

int Player::getID() const {
	return id;
}

unsigned Player::getPoints() const {
	return points;
}

const Stars& Player::getStars() const {
	return stars;
}

void Player::setID(int newId) {
	id = newId;
}

void Player::setPoints(unsigned newPoints) {
	points = newPoints;
}

void Player::setStars(const Stars& newStars) {
	stars = newStars;
}

bool Player::levelUpBasedOnPoints(unsigned currentPoints, unsigned neededPointsToLevelUp, const Stars& stars) {
	if (currentPoints >= neededPointsToLevelUp) {
		unsigned diff = currentPoints - neededPointsToLevelUp;
		setPoints(diff);
		setStars(stars);
		return true;
	}
}
