#include "DynamicSet.h"

void DynamicSet::copyFrom(const DynamicSet& other) {
	set = new unsigned char[other.bucketsCount];
	bucketsCount = other.bucketsCount;
	maxNumber = other.maxNumber;
	for (unsigned i = 0; i < bucketsCount; i++) {
		set[i] = other.set[i];
	}
}
void DynamicSet::free() {
	delete[] set;
	set = nullptr;
	maxNumber = 0;
	bucketsCount = 0;
}

DynamicSet::DynamicSet(unsigned maxNumber) {

	this->maxNumber = maxNumber;
	bucketsCount = getBucketsCount(maxNumber);
	set = new unsigned char[bucketsCount] {0};
}
DynamicSet::DynamicSet(const DynamicSet& other) {
	copyFrom(other);
}
DynamicSet& DynamicSet::operator=(const DynamicSet& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
DynamicSet::~DynamicSet() {
	free();
}

unsigned DynamicSet::getBucketsCount(unsigned maxNumber) {
	return (maxNumber / 8) + 1;
}
unsigned DynamicSet::getBucketIndex(unsigned num) const {
	return num / 8;
}

void DynamicSet::add(unsigned number) {
	if (number > maxNumber - 1) {
		return;
	}

	unsigned bucketIndex = getBucketIndex(number);
	unsigned bitIndex = number % 8;
	unsigned char mask = 1 << bitIndex;

	set[bucketIndex] |= mask;
}
void DynamicSet::remove(unsigned number) {
	if (number > maxNumber - 1) {
		return;
	}

	unsigned bucketIndex = getBucketIndex(number);
	unsigned bitIndex = number % 8;
	unsigned char mask = 1 << bitIndex;

	set[bucketIndex] &= (~mask);
}
bool DynamicSet::contains(unsigned number) const {
	if (number > maxNumber - 1) {
		return false;
	}

	unsigned bucketIndex = getBucketIndex(number);

	unsigned bitIndex = number % 8;
	unsigned char mask = 1 << bitIndex;

	return set[bucketIndex] & mask;
}

void DynamicSet::print() const {
	for (unsigned i = 0; i < maxNumber; i++) {
		if (contains(i)) {
			std::cout << i << " ";
		}
	}
}

DynamicSet DynamicSet::Union(const DynamicSet& other) {

	DynamicSet result = (maxNumber > other.maxNumber) ? *this : other;

	unsigned minLen = std::min(bucketsCount, other.bucketsCount);

	for (unsigned i = 0; i < minLen; i++) {
		result.set[i] = set[i] | other.set[i];
	}

	return result;
}
DynamicSet DynamicSet::Intersection(const DynamicSet& other) {
	DynamicSet result(std::min(maxNumber, other.maxNumber));
	for (unsigned i = 0; i < result.bucketsCount; i++) {
		result.set[i] = set[i] & other.set[i];
	}
	return result;
}