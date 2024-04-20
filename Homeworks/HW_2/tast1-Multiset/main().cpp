
#pragma once
#include <iostream>
#include <fstream>
#include "Multiset.h"
//SOURCES: https://github.com/desiish/OOP_Pract_2023_2024/blob/main/Pract06/Multiset/Multiset.cpp
//         KAMELIA TODOROVA, GROUP 4, COURSE 2 and ROSITSA ILIEVA, GROUP 4, COURSE 2
/*
namespace MultisetConstants {
	const unsigned MAX_K_BITS = 8;
	const unsigned MIN_K_BITS = 1;

	const unsigned MAX_INDEX_IN_BUCKET = 7;
	const unsigned MIN_INDEX_IN_BUCKET = 0;

	const unsigned DEF_VALUE = 0;
}

class Multiset {

    uint8_t* buckets = nullptr;

    unsigned maxNumber = MultisetConstants::DEF_VALUE; //0

    unsigned bucketsCount = MultisetConstants::DEF_VALUE; //0

    unsigned maxOccurrences = MultisetConstants::DEF_VALUE; //0

	unsigned kBits = MultisetConstants::DEF_VALUE; //0


    void free();
    void copyFrom(const Multiset& other);
	void moveFrom(Multiset&& other);

    void printNumber(unsigned num, unsigned occurrences) const;
	void printBits(uint8_t current) const;

	/*unsigned getBucketIndex(unsigned number) const;
	unsigned getNumberIndexInBucket(unsigned number) const;*/

/*	void setBucketsCount();
	void setMaxOccurences();
	void set_kBits(unsigned kBits);

	bool areValidBits(unsigned kBits) const;

	void incrementOccurences(unsigned number, unsigned occurrences);

	uint8_t getMask(unsigned toShift) const;
	unsigned getIndex(unsigned bitPositionInBuckets, unsigned currentBit) const;
	unsigned toShiftWith(unsigned bitPositionInBuckets, unsigned currentBit) const;

	void addNumberMultipleTimes(unsigned number, unsigned times);

public:
    Multiset(unsigned n, unsigned k);

    Multiset(const Multiset& other);
    Multiset& operator=(const Multiset& other);

	Multiset(Multiset&& other) noexcept;
	Multiset& operator=(Multiset&& other) noexcept;

    ~Multiset();


    void addNumber(unsigned num);

    unsigned getCountOfOccurrences(unsigned num) const;

    void printSet() const;

	void printAsInMemory() const;

	void saveToBinaryFile(const char* fileName) const;
	void readFromBinaryFile(const char* fileName);

	friend Multiset intersection(const Multiset& lhs, const Multiset& rhs);
	friend Multiset unify(const Multiset& lhs, const Multiset& rhs);

	friend Multiset complement(Multiset& set);
};

Multiset::Multiset(unsigned n, unsigned k) {
	this->maxNumber = n;
	set_kBits(k);
	setBucketsCount(/*k*///);
/*	setMaxOccurences(/*k*///);
/*
	buckets = new uint8_t[bucketsCount]{ 0 };
}

Multiset::Multiset(const Multiset& other) {
	copyFrom(other);
}
Multiset& Multiset::operator=(const Multiset& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Multiset::Multiset(Multiset&& other) noexcept {
	moveFrom(std::move(other));
}
Multiset& Multiset::operator=(Multiset&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Multiset::~Multiset() {
	free();
}

void Multiset::free() {
	delete[] buckets;
	buckets = nullptr;

	maxNumber = bucketsCount = maxOccurrences = kBits = 0;
}
void Multiset::copyFrom(const Multiset& other) {
	bucketsCount = other.bucketsCount;

	for (unsigned i = 0; i < bucketsCount; i++)
		buckets[i] = other.buckets[i];

	maxNumber = other.maxNumber;
	bucketsCount = other.bucketsCount;
	maxOccurrences = other.maxOccurrences;
}
void Multiset::moveFrom(Multiset&& other) {
	buckets = other.buckets;
	other.buckets = nullptr;

	maxNumber = other.maxNumber;
	bucketsCount = other.bucketsCount;
	maxOccurrences = other.maxOccurrences;
	kBits = other.kBits;

	other.maxNumber = other.bucketsCount = other.maxOccurrences = other.kBits = MultisetConstants::DEF_VALUE;
}

void Multiset::addNumber(unsigned num) {

	//unsigned bucket = num / elementsInBucket;
	//unsigned index = num % elementsInBucket;
	unsigned bucket = getBucketIndex(num);
	unsigned index = getNumberIndexInBucket(num);

	uint8_t& currBucket = buckets[bucket];
	uint8_t mask = 1;
	unsigned occurrences = getCountOfOccurrences(num);

	mask <<= index * kBits;

	switch (occurrences)
	{
	case 0:
	case 2:
	{
		currBucket |= mask;
		return true;
	}
	case 1: {
		mask = ~mask;
		currBucket &= mask;
		mask = ~mask;
		mask <<= 1;
		currBucket |= mask;
		return true;
	}
	default: return false;
	}*/
/*
	if (num > maxNumber) {
		/*return false;
		return;
	}

	unsigned countOccur = getCountOfOccurrences(num);
	if (maxOccurrences <= countOccur) {
		/*return false;
		return;
	}
	incrementOccurences(num, countOccur + 1);
	/*return true;
}

uint8_t Multiset::getMask(unsigned toShift) const {
	uint8_t mask = (1 << toShift);
	return mask;
}
unsigned Multiset::getIndex(unsigned bitPositionInBuckets, unsigned currentBit) const {
	unsigned index = (bitPositionInBuckets + currentBit) / 8;
	return index;
}
unsigned Multiset::toShiftWith(unsigned bitPositionInBuckets, unsigned currentBit) const {
	unsigned offset = (bitPositionInBuckets + currentBit) % 8;
	return offset;
}

void Multiset::addNumberMultipleTimes(unsigned number, unsigned times) {
	if (times > maxOccurrences) {
		times = maxOccurrences;
	}
	for (unsigned i = 0; i < times; i++) {
		addNumber(number);
	}
}

void Multiset::incrementOccurences(unsigned number, unsigned occurrences) {

	unsigned bitPositionInBuckets = number * kBits;

	for (unsigned i = 0; i < kBits; i++) {

		unsigned bucketIndex = getIndex(bitPositionInBuckets, i);
		unsigned toShift = toShiftWith(bitPositionInBuckets, i);

		uint8_t mask = getMask(toShift);
		uint8_t maskOf_kBits = getMask(i);

		if (occurrences & maskOf_kBits) {
			buckets[bucketIndex] |= mask;
		}
		else {
			buckets[bucketIndex] &= ~mask;
		}

		//if the number is in two buckets
		if ((toShift == MultisetConstants::MAX_INDEX_IN_BUCKET) && (i < kBits - 1)) {
			bucketIndex++;
		}
	}
}
unsigned Multiset::getCountOfOccurrences(unsigned num) const {
	/*unsigned bucket = num / elementsInBucket;
	unsigned index = num % elementsInBucket;

	uint8_t& currBucket = buckets[bucket];
	uint8_t mask = 1;
	mask <<= index * 2;
	bool isFirstUp = ((currBucket & mask) == mask);
	mask <<= 1;
	bool isSecondUp = ((currBucket & mask) == mask);

	return (isFirstUp * (1 << 0) + isSecondUp * (1 << 1)); // 2^0 and 2^1
	if (num > maxNumber) {
		return 0;
	}

	unsigned bitPosition = num * kBits;

	unsigned bucketIndex = bitPosition / MultisetConstants::MAX_K_BITS;
	unsigned bitOffset = bitPosition % MultisetConstants::MAX_K_BITS;

	unsigned result = MultisetConstants::DEF_VALUE; //0

	for (unsigned i = 0; i < kBits; i++) {

		uint8_t mask = getMask(bitOffset + i);

		if (buckets[bucketIndex] & mask /*(1 << (bitOffset + i))) {
			uint8_t maskOf_kBits = getMask(i);

			result |= maskOf_kBits /*(1 << i);
		}
	}

	return result;
}

void Multiset::printNumber(unsigned num, unsigned occurances) const {
	for (unsigned i = 0; i < occurances; i++)
		std::cout << num << " ";
}
void Multiset::printSet() const {
	std::cout << '{';
	for (unsigned i = 0; i <= maxNumber; i++)
	{
		unsigned occurrences = getCountOfOccurrences(i);
		printNumber(i, occurrences);
	}
	std::cout << '}';
}

void Multiset::printBits(uint8_t current) const
{
	int startIndex = 8 - 1;
	for (int j = startIndex; j >= 0; j--)
	{
		std::cout << ((current >> j) & 1) << " ";
	}
	std::cout << " | ";
}
void Multiset::printAsInMemory() const
{
	int startInd = 8 - 1;

	for (unsigned i = 0; i < bucketsCount; i++)
	{
		printBits(buckets[i]);
	}
}

/*unsigned Multiset::getBucketIndex(unsigned number) const {
	/*unsigned indexInSet = number * kBits;
	unsigned bucketIndex = indexInSet / 8;

	return bucketIndex;
	return (((number + 1) * kBits + 7) / 8) - 1;
}
unsigned Multiset::getNumberIndexInBucket(unsigned number) const {
	//unsigned indexInSet = (number + 1) * kBits;
	//unsigned indexInBucket = indexInSet % 8;

	//return  /*7 -  8 - indexInBucket;
	return number % elementsInBucket;
}

void Multiset::setBucketsCount() {
	/*unsigned countOfCellsForNumbers = (n + 1) * kBits; //+1 because of zero
	bucketsCount = countOfCellsForNumbers / 8 + 1;

	//if ((countOfCellsForNumbers % 8 == 0) && (countOfCellsForNumbers >= 8)) {
	//	this->bucketsCount = bucketsCount;
	//}
	//else {
	//	this->bucketsCount = bucketsCount + 1; //because if bucketsCount = 25, 25 / 8 = 3, but the count of buckets that should be allocated must be 4, so I add 1
	//}

	bucketsCount = ((this->maxNumber + 1) * this->kBits + 7) / 8;
}
void Multiset::setMaxOccurences() {
	if (areValidBits(kBits)) {
		maxOccurrences = (1 << kBits) - 1;
	}
	else {
		return;
	}
}
void Multiset::set_kBits(unsigned kBits) {
	if (areValidBits(kBits)) {
		this->kBits = kBits;
	}
	else {
		return;
	}
}

bool Multiset::areValidBits(unsigned kBits) const {
	return (kBits >= 1 && kBits <= 8);
}

void Multiset::saveToBinaryFile(const char* fileName) const {

	if (!fileName) {
		throw std::exception("fileName if null pointer!");
	}

	std::ofstream ofs(fileName, std::ios::binary);

	if (!ofs.is_open()) {
		throw std::exception("file could NOT open successfully!");
	}

	ofs.write((const char*)&maxNumber, sizeof(unsigned));

	ofs.write((const char*)&bucketsCount, sizeof(unsigned));

	ofs.write((const char*)&kBits, sizeof(unsigned));

	ofs.write((const char*)&maxOccurrences, sizeof(unsigned));

	ofs.write((const char*)buckets, bucketsCount * sizeof(uint8_t));

	ofs.close();
}
void Multiset::readFromBinaryFile(const char* fileName) {

	if (!fileName) {
		throw std::exception("fileName if null pointer!");
	}

	std::ifstream ifs(fileName, std::ios::binary);

	if (!ifs.is_open()) {
		throw std::exception("file could NOT open successfully!");
	}

	ifs.read((char*)&maxNumber, sizeof(unsigned));

	ifs.read((char*)&bucketsCount, sizeof(unsigned));

	ifs.read((char*)&kBits, sizeof(unsigned));

	ifs.read((char*)&maxOccurrences, sizeof(unsigned));

	ifs.read((char*)buckets, bucketsCount * sizeof(uint8_t));

	ifs.close();
}

Multiset intersection(const Multiset& lhs, const Multiset& rhs) {

	if (lhs.maxNumber != rhs.maxNumber) {
		return Multiset(0, 0);
	}

	unsigned maxNumberInIntersection = std::min(lhs.maxNumber, rhs.maxNumber);
	unsigned kBitsInIntersection = std::min(lhs.kBits, rhs.kBits);

	Multiset result(maxNumberInIntersection, kBitsInIntersection);

	for (unsigned i = 0; i <= maxNumberInIntersection; i++) {

		unsigned occurencesInLhs = lhs.getCountOfOccurrences(i);
		unsigned occurencesInRhs = rhs.getCountOfOccurrences(i);

		unsigned occurencesInIntersect = (occurencesInLhs < occurencesInRhs) ?
									      occurencesInLhs : occurencesInRhs;

		if (occurencesInIntersect > 0) {
			result.addNumberMultipleTimes(i, occurencesInIntersect);
		}
	}
	return result;
}
Multiset unify(const Multiset& lhs, const Multiset& rhs) {

	if (lhs.maxNumber != rhs.maxNumber) {
		return Multiset(0, 0);
	}

	unsigned kBitsInUnify = std::min(lhs.kBits, rhs.kBits);

	Multiset result(lhs.maxNumber, kBitsInUnify);

	for (unsigned i = 0; i <= lhs.maxNumber; i++) {

		unsigned occurencesInLhs = lhs.getCountOfOccurrences(i);
		unsigned occurencesInRhs = rhs.getCountOfOccurrences(i);

		unsigned occurencesInUnify = occurencesInLhs + occurencesInRhs;

		result.addNumberMultipleTimes(i, occurencesInUnify);
	}
	return result;
}

Multiset complement(Multiset& multiset) {

	for (unsigned i = 0; i <= multiset.maxNumber; i++) {

		unsigned occurences = multiset.getCountOfOccurrences(i);

		unsigned complementOccurences = multiset.maxOccurrences - occurences;

		multiset.incrementOccurences(i, complementOccurences);
	}
	return multiset;
}
*/

int main() {
	//Multiset set(5,4);
	//set.addNumber(2);
	//set.addNumber(2);
	//set.addNumber(2);
	//set.addNumber(1);
	//set.addNumber(0);
	//set.addNumber(0);
	//set.addNumber(4);
	//set.addNumber(5);
	//set.addNumber(5);
	//set.addNumber(5);

	//set.printSet();
	//std::cout << std::endl;
	//set.printAsInMemory();
	//std::cout << std::endl;

	//Multiset set2(5, 4);
	///*set2.addNumber(2);
	//set2.addNumber(2);
	//set2.addNumber(2);
	//set2.addNumber(1);
	//set2.addNumber(0);
	//set2.addNumber(0);*/
	//set2.addNumber(3);
	//
	//set2.printSet();
	//std::cout << std::endl;
	//set2.printAsInMemory();
	//std::cout << std::endl;

	//Multiset set3(5, 4);
	//set3 = unify(set, set2);
	//
	//set3.printSet();
	//std::cout << std::endl;
	//set3.printAsInMemory();

	//std::cout << std::endl;

	//set.complement();
	//set.printAsInMemory();
	//std::cout << std::endl;
	//set.printSet();

	Multiset set1(5, 4);
	set1.addNumber(2);
	set1.addNumber(2);
	set1.addNumber(4);
	set1.addNumber(5);

	set1.printSet();
	std::cout << std::endl;


	/*Multiset set2(6, 4);
	set2.addNumber(2);
	set2.addNumber(3);
	set2.addNumber(5);

	Multiset diff = difference(set1, set2);
	diff.printSet();*/
}