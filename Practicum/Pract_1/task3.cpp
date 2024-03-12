/*Създайте структура, описваща студент. Всеки студент се определя чрез:

факултетен номер(петцифрени цели числа);
курс (∀студент е в първи, втори, трети или четвърти курс);
средна оценка за курса.
Създайте подходящо параметризирана функция initStudent(...); която въвежда коректни данни за студент.
Да се напише функция, която принтира студент.*/

#include <iostream>

namespace HelperFunctions{
	size_t getCountOfDigitsInNumber(int number) {
		size_t size = 0;
		while (number != 0) {
			number /= 10;
			size++;
		}
		return size;
	}
	bool isNumberWithFiveDigits(int number) {
		return getCountOfDigitsInNumber(number) == 5;
	}
	bool isAverageGradeValid(double averageGrade) {
		return averageGrade >= 0 && averageGrade <= 6;
	}
}

enum Course {
	Undefined = 0,
	First = 1,
	Second = 2,
	Third = 3,
	Fourth = 4
};

struct Student {
	int fn = 0;
	Course course = Course::Undefined;
	double averageGrade = 0.0;
};

void setCourse(Student& student, int n) {
	switch (n) {
	case 1:
		student.course = Course::First;
	case 2:
		student.course = Course::Second;
	case 3:
		student.course = Course::Third;
	case 4:
		student.course = Course::Fourth;
	default:
		student.course = Course::Undefined;
	}
}

void initStudent(Student& student) {
	std::cin >> student.fn;
	while (!HelperFunctions::isNumberWithFiveDigits(student.fn)) {
		std::cerr << "Invalid faculty number!" << std::endl;
		std::cin >> student.fn;
	}

	int course;
	std::cin >> course;
	setCourse(student, course);

	std::cin >> student.averageGrade;
	while (!HelperFunctions::isAverageGradeValid(student.averageGrade)) {
		std::cerr << "Average grade is NOT valid!" << std::endl;
		std::cin >> student.averageGrade;
	}
}

void printStudent(const Student& student) {
	std::cout << "Faculty number: " << student.fn << ", "
			<< "Course: " << student.course << ", "
			<< "Average grade: " << student.averageGrade << std::endl;
}

int main() {
	Student st1{ 12345, Course::First, 4.4 };
	Student st2;
	Student st3{ 65323, Course::Third, 3.5 };
	printStudent(st1);
	initStudent(st2);
}