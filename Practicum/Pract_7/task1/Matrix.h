#include <iostream>

class Matrix {
	int** matrix = nullptr;
	size_t rowsCount = 2;
	size_t colsCount = 2;

	void free();
	void copyFrom(const Matrix& other);

	void initMatrix(int initValue);

public:

	Matrix() = default;
	Matrix(size_t rows, size_t cols);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	void printMatrix() const;

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);

	int* operator[](size_t index);
	const int* operator[](size_t index) const;

	friend bool operator==(const Matrix& lhs, const Matrix& rhs);
	friend bool operator!=(const Matrix& lhs, const Matrix& rhs);
};
Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);
