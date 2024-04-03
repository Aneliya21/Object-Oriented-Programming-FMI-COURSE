#include "Nvector.h"

void Nvector::copyFrom(const Nvector& other) {
	vector = new int[other.size];
	size = other.size;

	for (size_t i = 0; i, size; i++) {
		vector[i] = other.vector[i];
	}
}
void Nvector::free() {
	delete[] vector;
	vector = nullptr;

	size = 0;
}

Nvector::Nvector(size_t size) {
	vector = new int[size];
	this->size = size;
}
Nvector::Nvector(const Nvector& other) {
	copyFrom(other);
}
Nvector& Nvector::operator=(const Nvector& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Nvector::~Nvector() {
	free();
}

size_t Nvector::getSize() const {
	return size;
}

void Nvector::setSize(size_t size) {
	this->size = size;
}

int Nvector::getElementFromVector(size_t index) {
	if (index > 0 && index < size) {
		return vector[index];
	}
	return -1;
}

Nvector operator+(const Nvector& lhs, const Nvector& rhs) {
	if (lhs.getSize() == rhs.getSize()) {
		Nvector result(lhs.getSize());

		for (size_t i = 0; i < result.getSize(); i++) {
			result.vector[i] = lhs.vector[i] + rhs.vector[i];
		}

		return result;
	}
	else {
		return Nvector();
	}
}
Nvector operator-(const Nvector& lhs, const Nvector& rhs) {
	if (lhs.getSize() == rhs.getSize()) {
		Nvector result(lhs.getSize());

		for (size_t i = 0; i < result.getSize(); i++) {
			result.vector[i] = lhs.vector[i] - rhs.vector[i];
		}

		return result;
	}
	else {
		return Nvector();
	}
}

Nvector& Nvector::operator+=(const Nvector& other) {
	if (size == other.getSize()) {
		for (size_t i = 0; i < size; i++) {
			vector[i] += other.vector[i];
		}
	}
	return *this;
}
Nvector& Nvector::operator-=(const Nvector& other) {
	if (size == other.getSize()) {
		for (size_t i = 0; i < size; i++) {
			vector[i] -= other.vector[i];
		}
	}
	return *this;
}

Nvector operator*(const Nvector& vector, size_t scalar) {
	Nvector result(vector.getSize());

	for (size_t i = 0; i < result.getSize(); i++) {
		result.vector[i] = vector.vector[i] * scalar;
	}

	return result;
}
Nvector& Nvector::operator*=(size_t scalar) {
	for (size_t i = 0; i < size; i++) {
		vector[i] *= scalar;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Nvector& vect) {
	for (size_t i = 0; i < vect.getSize(); i++) {
		os << vect.vector[i] << " ";
	}
	return os;
}
std::istream& operator>>(std::istream& is, Nvector& vect) {
	for (size_t i = 0; i < vect.getSize(); i++) {
		is >> vect.vector[i];
	}
	return is;
}

bool Nvector::operator|=(const Nvector& other) const {

}
bool Nvector::operator|(const Nvector& other) const {

}