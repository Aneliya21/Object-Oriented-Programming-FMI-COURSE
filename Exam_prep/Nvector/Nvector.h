#include <iostream>
#include <fstream>

class Nvector {
	int* vector = nullptr;
	size_t size = 0;

	void copyFrom(const Nvector& other);
	void free();

public:
	Nvector() = default;

	Nvector(size_t size);
	Nvector(const Nvector& other);
	Nvector& operator=(const Nvector& other);
	~Nvector();

	size_t getSize() const;

	void setSize(size_t size);

	int getElementFromVector(size_t index);

	friend Nvector operator+(const Nvector& lhs, const Nvector& rhs);
	friend Nvector operator-(const Nvector& lhs, const Nvector& rhs);

	Nvector& operator+=(const Nvector& other);
	Nvector& operator-=(const Nvector& other);

	friend Nvector operator*(const Nvector& vector, size_t scalar);

	Nvector& operator*=(size_t scalar);

	friend std::ostream& operator<<(std::ostream& os, const Nvector& vect);
	friend std::istream& operator>>(std::istream& is, Nvector& vect);

	bool operator|=(const Nvector& other) const; //perpendicular
	bool operator|(const Nvector& other) const; //parallel

};