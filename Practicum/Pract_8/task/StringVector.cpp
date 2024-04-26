#include "StringVector.h"

StringVector::StringVector() {
    //TO DO
}
StringVector::StringVector(size_t size) {
    //TO DO
}

StringVector::StringVector(const StringVector& other) {
	copyFrom(other);
}
StringVector::StringVector(StringVector&& other) noexcept {
	moveFrom(std::move(other));
}

StringVector& StringVector::operator=(const StringVector& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
StringVector& StringVector::operator=(StringVector&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

StringVector::~StringVector() {
	free();
}

void StringVector::push_back(const MyString& toAdd) {
	if (size + 1 >= capacity) {
		resize(capacity * 2);
	}
	stringVector[size++] = toAdd;
}
void StringVector::push_back(MyString&& toAdd) {
	if (size + 1 >= capacity) {
		resize(capacity * 2);
	}
	stringVector[size++] = std::move(toAdd);
}

void StringVector::pop_back() {
	stringVector[size--] = nullptr;
}

void StringVector::insert(const MyString& toInsert) {
    //TO DO
}
void StringVector::insert(MyString&& toInsert) {
    //TO DO
}

void StringVector::erase(size_t atIndex) {
    //TO DO
}

void StringVector::clear() {
	for (size_t i = 0; i < size; i++) {
		stringVector[i] = nullptr;
	}
	size = 0;
}

MyString& StringVector::operator[](size_t index) {
	if (index >= size) {
		throw std::out_of_range("Index not valid!");
	}
	return stringVector[index];
}
const MyString& StringVector::operator[](size_t index) const {
	if (index >= size) {
		throw std::out_of_range("Index not valid!");
	}
	return stringVector[index];
}

bool StringVector::empty() const {
	return (size == 0);
}

size_t StringVector::getSize() const {
	return size;
}

std::ostream& operator<<(std::ostream& os, const StringVector& vector) {
	for (size_t i = 0; i < vector.capacity; i++) {
		os << vector[i] << " ";
	}
	return os;
}
std::istream& operator>>(std::istream& is, StringVector& vector) {
	for (size_t i = 0; i < vector.capacity; i++) {
		is >> vector[i];
	}
	return is;
}

void StringVector::copyFrom(const StringVector& other) {
	size = other.size;
	capacity = other.capacity;

	stringVector = new MyString[capacity];

	for (size_t i = 0; i < size; i++) {
		stringVector[i] = other.stringVector[i];
	}
}
void StringVector::moveFrom(StringVector&& other) {
	stringVector = other.stringVector;
	other.stringVector = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;
}
void StringVector::free() {
	for (size_t i = 0; i < capacity; i++) {
		stringVector[i].~MyString();
	}
	delete[] stringVector;
}

void StringVector::resize(size_t newCapacity) {
    //TO DO
}