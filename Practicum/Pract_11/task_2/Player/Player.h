#pragma once

#include <iostream>


enum class Stars {
	One,
	Two,
	Three,
	Four,
	Five
};

class Player {

public:
	virtual bool levelUp() = 0;

protected:
	int getID() const;
	unsigned getPoints() const;
	const Stars& getStars() const;

	void setID(int newId);
	void setPoints(unsigned newPoints);
	void setStars(const Stars& newStars);

	virtual ~Player() = default;

	bool levelUpBasedOnPoints(unsigned currentPoints, unsigned neededPointsToLevelUp, const Stars& stars);

private:
	int id = 0;
	unsigned points = 0;
	Stars stars = Stars::One;
};

