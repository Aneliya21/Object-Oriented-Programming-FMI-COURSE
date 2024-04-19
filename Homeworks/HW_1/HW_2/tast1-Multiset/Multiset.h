#pragma once
#include <iostream>
#include <fstream>

#include "MultisetConstants.h"

//SOURCES: https://github.com/desiish/OOP_Pract_2023_2024/blob/main/Pract06/Multiset/Multiset.cpp
//         KAMELIA TODOROVA, GROUP 4, COURSE 2 and ROSITSA ILIEVA, GROUP 4, COURSE 2


//ostava da napravq:
//	da probvam da opravq printInMemory
//	testove na vsichko
//  razlika!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

class Multiset {
private:
	uint8_t* buckets = nullptr;

	unsigned maxNumber = MultisetConstants::DEF_VALUE; //0

	unsigned bucketsCount = MultisetConstants::DEF_VALUE; //0

	unsigned maxOccurrences = MultisetConstants::DEF_VALUE; //0

	unsigned kBits = MultisetConstants::DEF_VALUE; //0

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
	friend Multiset difference(const Multiset& lhs, const Multiset& rhs);

	Multiset& complement();

private:
	void free();
	void copyFrom(const Multiset& other);
	void moveFrom(Multiset&& other);

	void printNumber(unsigned num, unsigned occurrences) const;
	void printBits(uint8_t current) const;

	void setBucketsCount();
	void setMaxOccurences();
	void set_kBits(unsigned kBits);

	bool areValidBits(unsigned kBits) const;

	void incrementOccurences(unsigned number, unsigned occurrences);

	uint8_t getMask(unsigned toShift) const;
	unsigned getIndex(unsigned bitPositionInBuckets, unsigned currentBit) const;
	unsigned toShiftWith(unsigned bitPositionInBuckets, unsigned currentBit) const;

	void addNumberMultipleTimes(unsigned number, unsigned times);
};

