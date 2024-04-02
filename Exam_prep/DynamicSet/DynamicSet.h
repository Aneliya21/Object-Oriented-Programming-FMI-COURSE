#include <iostream>
#pragma once

class DynamicSet {
	unsigned char* set = nullptr;
	unsigned maxNumber = 0;
	unsigned bucketsCount = 0;

	void copyFrom(const DynamicSet& other);
	void free();

	unsigned getBucketsCount(unsigned maxNumber);
	unsigned getBucketIndex(unsigned num) const;

public:
	DynamicSet() = default;
	DynamicSet(unsigned maxNumber);
	DynamicSet(const DynamicSet& other);
	DynamicSet& operator=(const DynamicSet& other);
	~DynamicSet();

	void add(unsigned number);
	void remove(unsigned number);
	bool contains(unsigned number) const;

	void print() const;

	DynamicSet Union(const DynamicSet& other);
	DynamicSet Intersection(const DynamicSet& other);

};

