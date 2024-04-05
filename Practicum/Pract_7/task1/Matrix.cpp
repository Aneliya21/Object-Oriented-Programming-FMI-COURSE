#include "Matrix.h"

void Matrix::free() {
	for (size_t i = 0; i < rowsCount; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = nullptr;

	rowsCount = 2;
	colsCount = 2;
}
void Matrix::copyFrom(const Matrix& other) {
	rowsCount = other.rowsCount;
	colsCount = other.colsCount;

	matrix = new int*[rowsCount];

	for (size_t i = 0; i < rowsCount; i++) {
		matrix[i] = new int[colsCount];
	}

	for (size_t i = 0; i < rowsCount; i++) {
		for (size_t j = 0; j < colsCount; j++) {
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

void Matrix::initMatrix(int initValue) {
	for (size_t i = 0; i < rowsCount; i++) {
		for (size_t j = 0; j < colsCount; j++) {
			matrix[i][j] = initValue;
		}
	}
}

Matrix::Matrix(size_t rows, size_t cols):rowsCount(rows), colsCount(cols) {
	matrix = new int* [rowsCount];
	for (size_t i = 0; i < rowsCount; i++) {
		matrix[i] = new int[colsCount];
	}
	initMatrix(0);
}

Matrix::Matrix(const Matrix& other) {
	copyFrom(other);
}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Matrix::~Matrix() {
	free();
}

void Matrix::printMatrix() const {
	for (size_t i = 0; i < rowsCount; i++) {
		for (size_t j = 0; j < colsCount; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

Matrix& Matrix::operator+=(const Matrix& other) {
	if ((rowsCount = other.rowsCount) && (colsCount = other.colsCount)) {
		for (size_t i = 0; i < rowsCount; i++) {
			for (size_t j = 0; j < colsCount; j++) {
				matrix[i][j] += other.matrix[i][j];
			}
		}
	}
	return *this;
}
Matrix& Matrix::operator-=(const Matrix& other) {
	if ((rowsCount == other.rowsCount) && (colsCount == other.colsCount)) {
		for (size_t i = 0; i < rowsCount; i++) {
			for (size_t j = 0; j < colsCount; j++) {
				matrix[i][j] -= other.matrix[i][j];
			}
		}
	}
	return *this;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	Matrix lhsCopy(lhs);
	lhsCopy += rhs;
	return lhsCopy;
}
Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
	Matrix lhsCopy(lhs);
	lhsCopy -= rhs;
	return lhsCopy;
}


Matrix& Matrix::operator*=(const Matrix& other) {
	//to do !!!!
    return *this;
}
Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
	Matrix lhsCopy(lhs);
	lhsCopy *= rhs;
	return lhsCopy;
}

int* Matrix::operator[](size_t index) {
	return matrix[index];
}
const int* Matrix::operator[](size_t index) const {
	return matrix[index];
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.rowsCount == rhs.rowsCount && lhs.colsCount == rhs.colsCount) {
		for (size_t i = 0; i < lhs.rowsCount; i++) {
			for (size_t j = 0; j < lhs.colsCount; j++) {
				if (lhs.matrix[i][j] != rhs.matrix[i][j])
					return false;
			}
		}
		return true;
	}
	return false;
}
bool operator!=(const Matrix& lhs, const Matrix& rhs) {
	return !(lhs == rhs);
}