#include <iostream>
#include <assert.h>

struct Rational {
	int nom;
	int denom;
};

bool isValid(const Rational& rat) {
	return rat.denom != 0;
}

void printRat(const Rational& rat) {
	std::cout << rat.nom << "/" << rat.denom << std::endl;
}

unsigned getGcd(unsigned a, unsigned b) {
	if (a < b) {
		std::swap(a, b);
	}

	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

void rationalize(Rational& rat) {
	assert(isValid(rat));

	unsigned gcd = getGcd(rat.nom, rat.denom);
	rat.denom /= gcd;
	rat.nom /= gcd;

	if ((rat.nom < 0 && rat.denom < 0) || (rat.nom > 0 && rat.denom < 0)) {
		rat.nom *= -1;
		rat.denom *= -1;
	}
}

Rational& plusEq(Rational& lhs, const Rational& rhs) {
	assert(isValid(lhs) && isValid(rhs));
	lhs.nom *= rhs.denom;
	lhs.nom += rhs.nom * lhs.denom;
	lhs.denom *= rhs.denom;

	rationalize(lhs);
	return lhs;
}

Rational plus(const Rational& lhs, const Rational& rhs) {
	assert(isValid(lhs), isValid(rhs));
	Rational lhsCpy = lhs;
	plusEq(lhsCpy, rhs);
	return lhsCpy;
}

int main() {
	Rational r1{ 1,4 };
	Rational r2{ 1,3 };

	Rational r3 = plus(r1, r2);

	printRat(r3);

	plusEq(r3, r1);

	printRat(r3);
}