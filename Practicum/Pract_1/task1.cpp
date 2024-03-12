/*Да се създаде структура, която представя комплексно число.
Създайте функция, които връща сбора и такава, която връща произведението на 2 комплексни числа.
Създайте подходяща функция за принтиране на комплексно число.*/

#include <iostream>

struct Complex {
	int real = 0;
	int imaginary = 0;
};

Complex& addOperation(Complex& lhs, const Complex& rhs) {
	lhs.real += rhs.real;
	lhs.imaginary += rhs.imaginary;

	return lhs;
}

Complex addOperation(const Complex& lhs, const Complex& rhs) {
	Complex result{ 0,0 };
	result.real += (lhs.real + rhs.real);
	result.imaginary += (lhs.imaginary + rhs.imaginary);

	return result;
}

Complex& multiplyOperation(Complex& lhs, const Complex& rhs) {
	Complex lhsCpy = lhs;
	lhs.real = ((lhsCpy.real * rhs.real) - (lhsCpy.imaginary * rhs.imaginary));
	lhs.imaginary = ((lhsCpy.real * rhs.imaginary) + (lhsCpy.imaginary * rhs.real));

	return lhs;
}

Complex multiplyOperation(const Complex& lhs, const Complex& rhs) {
	Complex result{ 0,0 };
	result.real += ((lhs.real * rhs.real) - (lhs.imaginary * rhs.imaginary));
	result.imaginary += ((lhs.real * rhs.imaginary) + (lhs.imaginary * rhs.real));

	return result;
}

void printComplex(const Complex& num) {
	std::cout << num.real << "+" << num.imaginary << "i" << std::endl;
}

int main() {
	Complex n1{2, 7};
	Complex n2{ 3, -4 };

	printComplex(addOperation(n1, n2));
}