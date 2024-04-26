#include <iostream>
#include <fstream>
#include "MyString.h"

class StringVector {
public:
	StringVector();
	StringVector(size_t size);

	StringVector(const StringVector& other);
	StringVector(StringVector&& other) noexcept;

	StringVector& operator=(const StringVector& other);
	StringVector& operator=(StringVector&& other) noexcept;

	~StringVector();


	void push_back(const MyString& toAdd);
	void push_back(MyString&& toAdd);

	void pop_back();

	void insert(const MyString& toInsert);
	void insert(MyString&& toInsert);

	void erase(size_t atIndex);

	void clear();

	MyString& operator[](size_t index);
	const MyString& operator[](size_t index) const;

	bool empty() const;

	size_t getSize() const;

	friend std::ostream& operator<<(std::ostream& os, const StringVector& vector);
	friend std::istream& operator>>(std::istream& is, StringVector& vector);

private:
	void copyFrom(const StringVector& other);
	void moveFrom(StringVector&& other);
	void free();

	void resize(size_t newCapacity);


	MyString* stringVector = nullptr;
	size_t size = 0;
	size_t capacity = 16;
};